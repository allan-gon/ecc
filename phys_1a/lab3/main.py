import matplotlib.pyplot as plt
import pandas as pd
import numpy as np


# def r2(function: ptype, x_data: pd.Series, y_data: pd.Series) -> float:
#     rss = sum((y_data - function(x_data)) ** 2)
#     tss = sum((y_data - y_data.mean()) ** 2)
#     return 1 - (rss / tss)


def gen_data() -> np.polynomial.polynomial.Polynomial:
    # setup
    disp = pd.read_csv("./data/data.csv")["distance(cm)"]
    df = pd.DataFrame({
        "time (sec/60)": [i for i in range(len(disp))],
        "displacement (cm)": disp,
    })

    # velocity
    df["velocity (cm/sec)"] = df["displacement (cm)"].diff() * 60
    # avg velocity
    avg_vel = []
    for i in range(df.shape[0]):
        try:
            avg_vel.append((df["velocity (cm/sec)"][i] + df["velocity (cm/sec)"][i + 1])/2)
        except:
            avg_vel.append(np.NaN)
    df["avg_vel (cm/sec)"] = avg_vel
    # save data
    df.to_csv("./data/created.csv", index=False)
    return


def graph():
    # setup
    gen_data()
    # read in data
    df = pd.read_csv("./data/created.csv")
    # position time
    plt.scatter(df["time (sec/60)"], df["displacement (cm)"])
    # avgerage velocity time
    plt.scatter(df["time (sec/60)"], df["avg_vel (cm/sec)"])
    # 5th order polynomial fit
    df.dropna(inplace=True) # dropping nans so fit doesn't fail
    func = np.polynomial.Polynomial.fit(df["time (sec/60)"], df["velocity (cm/sec)"], 5)
    # accel func ae. velocity derivative
    derivative = func.deriv()
    print(f"Function: {func}\nDerivative: {derivative}")
    # fit line
    plt.plot(df["time (sec/60)"], func(df["time (sec/60)"]))
    # acceleration function
    plt.scatter(df["time (sec/60)"], derivative(df["time (sec/60)"])) # * 60
    # show the graph
    plt.show()
    # coef_det = r2(func, df["time(60th of a second)"], df["avg_vel"])
    return


if __name__ == "__main__":
    graph()
# I think the graph i saw has different y axes, that's why accel looks diff.
# accel is on it's on y, and vel/distance share an axis
# my accel is fine just is in "the wrong spot" because it shares an axis on mine
# which it shouldnt

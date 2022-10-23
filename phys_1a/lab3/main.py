import matplotlib.pyplot as plt
import pandas as pd
import numpy as np

plt.style.use("fivethirtyeight")


def r2(function, x_data, y_data) -> float:
    rss = sum((y_data - function(x_data)) ** 2)
    tss = sum((y_data - y_data.mean()) ** 2)
    return 1 - (rss / tss)


def gen_data() -> np.polynomial.polynomial.Polynomial:
    # setup
    disp = pd.read_csv("./data/data.csv")["distance(cm)"]
    df = pd.DataFrame({
        "Time (s/60)": [i for i in range(len(disp))],
        "x (cm)": disp,
    })
    # time for velocity
    df["Vtime (sec/60)"] = df["Time (s/60)"] + 0.5
    # velocity
    df["Vave (cm/sec)"] = df["x (cm)"].diff() * 60
    # Calc average accel
    df["Aave (cm/sec^2)"] = df["Vave (cm/sec)"].diff()
    # save data
    df.to_csv("./data/created.csv", index=False)
    return


def graph():
    # setup
    gen_data()
    # read in data
    df = pd.read_csv("./data/created.csv")
    # Changed for fig, ax
    fig, ax1 = plt.subplots()
    ax2 = ax1.twinx() # a copy of ax1
    # position time
    ax1.scatter(df["Time (s/60)"], df["x (cm)"], label="position", color="#008FD5")
    # average velocity time
    ax1.scatter(df["Vtime (sec/60)"], df["Vave (cm/sec)"], label="velocity", color="#F96950")
    # average accel time
    ax2.scatter(df["Time (s/60)"], df["Aave (cm/sec^2)"] * 60, label="Aave", color="#E0DE36")
    # 5th order polynomial fit
    df.dropna(inplace=True) # dropping nans so fit doesn't fail

    # polynomial fit
    func = np.polynomial.Polynomial.fit(df["Vtime (sec/60)"], df["Vave (cm/sec)"], 6)
    # accel func ae. velocity derivative
    derivative = func.deriv()
    # # used for finding critical points
    # sec_der = derivative.deriv()
    # ax2.plot(df["Time (s/60)"], sec_der(df["Time (s/60)"]) * 60, label="Second Derivative")
    # fit line
    ax1.plot(df["Time (s/60)"], func(df["Time (s/60)"]), label=f"Velocity fit: {func.convert()}", color="#F96950")
    # acceleration function     
    ax2.plot(df["Time (s/60)"], derivative(df["Time (s/60)"]) * 60, label=f"Acceleration: {derivative.convert()}", color="#0FA60F") # softer green
    # axis labels
    ax1.set_xlabel("Time (s/60)")
    ax1.set_ylabel("velocity (cm/sec)")
    ax2.set_ylabel("acceleration (cm/sec^2)")
    ax2.set_ylim(top=1000, bottom=-4000)
    # show the graph
    fig.legend(fontsize="small")
    plt.text(50.3, 680, f"Velocity Fit R^2: {r2(func, df['Time (s/60)'], df['Vave (cm/sec)'])}", fontsize="small")
    plt.subplots_adjust(left=.1, right=.9, top=.8)
    plt.show()

    # show the values of the functions
    print(f"Function: {func.convert()}\nDerivative: {derivative.convert()}")
    print(f"Flat part of derivative: {derivative(np.arange(10,31)).mean() * 60}")
    return


def best_r2(x_data, y_data, max_deg, min_deg = 1) -> int:
    scores = {}
    for i in range(min_deg, max_deg + 1):
        foo = np.polynomial.Polynomial.fit(x_data, y_data, i)
        scores[i] = r2(foo, x_data, y_data)
    print(scores)
    return max(scores)


if __name__ == "__main__":
    graph()

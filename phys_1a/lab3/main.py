from numpy.polynomial.polynomial import Polynomial as ptype
from numpy.polynomial import Polynomial
import matplotlib.pyplot as plt
import pandas as pd


def gen_data_from_raw():
    df = pd.read_csv("./data.csv").reset_index()
    df["time(60th of a second)"] = [i for i in range(1, df.shape[0] + 1)]
    df["avg_vel"] = 60 * df["distance(cm)"].diff()

    # r2, coefs = [], []
    # for i in range(1, 7): # for degrees 1-8
    #     c = polyfit(df["time(60th of a second)"], df["avg_vel"], i)
    #     coefs.append(c)
    #     func = poly1d(c) # get coefs of fit function
    #     # df[f"pred_deg_{i}"] = func(df["time(60th of a second)"]) # get data points
    #     r2.append(r2_score(df["time(60th of a second)"], func(df["time(60th of a second)"])))

    # print(f"Coefs:\n{coefs}\n\nR^2:\n{r2}")

    df.to_csv("./gen_data.csv", index=False)


def r2(function: ptype, x_data: pd.Series, y_data: pd.Series) -> float:
    rss = sum((y_data - function(x_data)) ** 2)
    tss = sum((y_data - y_data.mean()) ** 2)
    return 1 - (rss / tss)


if __name__ == "__main__":
    df = pd.read_csv("./gen_data.csv")
    # df.drop(["distance(cm)", "index"], axis=1, inplace=True)
    # df.to_csv("./temp.csv", index=False)
    plt.scatter(df["time(60th of a second)"], df["distance(cm)"])
    plt.scatter(df["time(60th of a second)"], df["avg_vel"])
    df.dropna(inplace=True)

    func = Polynomial.fit(df["time(60th of a second)"], df["avg_vel"], 5)
    coef_det = r2(func, df["time(60th of a second)"], df["avg_vel"])
    print(func.convert())

    # derivative = func.convert().deriv()
    # df["accel"] = 60 * derivative(df["time(60th of a second)"])

    plt.text(
        40,
        230,
        f"R-squared: {coef_det}\nEquation: {func.convert()}",
        bbox=dict(facecolor="red", alpha=0.5),
        wrap=True,
    )
    plt.plot(
        df["time(60th of a second)"], func(df["time(60th of a second)"])
    )  # graph it
    # plt.scatter(df["time(60th of a second)"], df["accel"])
    plt.show()
    # # gen_data_from_raw()

# TODO:
# Maybe dont use convert. Look here: https://numpy.org/doc/stable/reference/generated/numpy.polynomial.polynomial.Polynomial.html#numpy.polynomial.polynomial.Polynomial
# which do you want to use, scaled or not, if not i have to also not use the deriv impl

# dont round
# try calculating r squared by hand

from numpy.polynomial.polynomial import Polynomial
import matplotlib.pyplot as plt
from numpy import log10, log
import pandas as pd


def main():
    df = pd.read_csv("./data.csv")
    df["log_x"] = df["log_x"].apply(log10)
    df["log_f"] = df["log_f"].apply(log10)
    # log-log dataset
    print(df["log_x"])
    print(df["log_f"])

    log_fit = Polynomial.fit(df["log_x"], df["log_f"], 1)
    plt.scatter(df["log_x"], df["log_f"])
    plt.plot(df["log_x"], log_fit(df["log_x"]), label=log_fit, color="r")
    plt.legend()
    plt.show()
    # # semi-log dataset
    # semi_fit = Polynomial.fit(df["semi_x"], log(df["semi_p"]), 1)
    # plt.scatter(df["semi_x"], log(df["semi_p"]))
    # plt.plot(df["semi_x"], semi_fit(log(df["semi_p"])), label=semi_fit, color="r")
    # plt.legend()
    # plt.show()

    # plt.semilogy(df["semi_x"], df["semi_p"], base=np.e)
    # plt.title("Semi-Log Data Set # 502")
    # plt.xlabel("x (m)")
    # plt.ylabel("ln(P (watt))")
    # plt.show()
    # plt.loglog(df["length"], df["period"])
    # plt.title("Pendulum Experiment")
    # plt.xlabel("log(length (cm))")
    # plt.ylabel("log(period (sec))")
    # plt.show()


if __name__ =="__main__":
    main()

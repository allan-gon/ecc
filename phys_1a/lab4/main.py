import matplotlib.pyplot as plt
import numpy as np
import pandas as pd


def main():
    df = pd.read_csv("./data.csv")
    plt.loglog(df["log_x"], df["log_f"])
    plt.show()
    plt.semilogy(df["semi_x"], df["semi_p"], base=np.e)
    plt.show()
    plt.loglog(df["length"], df["period"])
    plt.show()


if __name__ =="__main__":
    main()

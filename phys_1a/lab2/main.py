from sklearn.metrics import r2_score
from numpy import polyfit, poly1d
import matplotlib.pyplot as plt
import pandas as pd


def gen_data_from_raw():
    df = pd.read_csv("./data.csv").reset_index()
    df["time(60th of a second)"] = [i for i in range(1, df.shape[0] + 1)]
    df["avg_vel"] = 60 * df["distance(cm)"].diff()

    # r2 = []
    # for i in range(1, 7): # for degrees 1-8
    #     func = poly1d(polyfit(df["time(60th of a second)"], df["avg_vel"], i)) # get coefs of fit function
    #     df[f"pred_deg_{i}"] = func(df["time(60th of a second)"]) # get data points
    #     r2.append(r2_score(df["time(60th of a second)"], df[f"pred_deg_{i}"]))

    df.to_csv("./gen_data.csv", index=False)


if __name__ == "__main__":
    df = pd.read_csv("./gen_data.csv")
    plt.scatter(df["time(60th of a second)"], df["distance(cm)"])
    plt.scatter(df["time(60th of a second)"], df["avg_vel"])
    df.dropna(inplace=True)

    coefs = polyfit(df["time(60th of a second)"], df["avg_vel"], 5)
    equation = " + ".join([f"{coefs[i]}x^{4-i}" if i != 3 else str(coefs[i]) for i in range(4)])
    func = poly1d(coefs)
    df["pred_deg_4"] = func(df["time(60th of a second)"])
    r2 = r2_score(df["time(60th of a second)"], df[f"pred_deg_{4}"])
    
    plt.text(40, 230, f"R-square: {r2}\n{equation}", bbox=dict(facecolor='red', alpha=0.5), wrap=True)
    plt.plot(df["time(60th of a second)"], df[f"pred_deg_4"]) # graph it
    plt.show()
    # gen_data_from_raw()

from random import randint
from math import ceil
import plotly.express as px
import pandas as pd
from numpy.polynomial import Polynomial
# from os import system


# def clear():
#     _ = input("Enter any key to continue: ")
#     system("cls")


def generate_data():
    with open("./data/lab2_data.csv", "w+") as file:
        if file.read() != "mass_1(g),mass_2_min(g),mass_2_max(g),mass_2_best(g)\n":
            file.write("mass_1(g),mass_2_min(g),mass_2_max(g),mass_2_best(g)\n")

    MASS_1 = 411.4
    MASS_2_MIN = 149
    MASS_2_MAX = 150
    MEW_K = ((MASS_2_MIN + MASS_2_MAX) / 2) / MASS_1

    for i in range(6):
        with open("./data/lab2_data.csv", "a") as file:
            low_bound = ceil((MEW_K * (MASS_1 + (i * 100))) + randint(-2, 2)) # whatever the estimate is, add noise to it, and since weights are no smaller than 1 gram round up a gram always 
            file.write(f"{MASS_1 + (i * 100)},{low_bound},{low_bound + 1},{low_bound + .5}\n") # save the masses


def graph():
    df = pd.read_csv("./data/lab2_data.csv")
    df["error"] = df["mass_2_max(g)"] - df["mass_2_min(g)"]
    fig = px.scatter(
        df, x="mass_1(g)", y="mass_2_best(g)",
        error_y="error",
        trendline="ols"
    )
    fig.show()


def main():
    # generate_data()
    graph()


if __name__ == "__main__":
    # main()
    df = pd.read_csv("./data/lab2_data.csv")
    func = Polynomial.fit(df["mass_1(g)"], df["mass_2_best(g)"], 1)
    slope_min, slope_max = round((150 - 332) / (411.4 - 911.4), 4), round((149 - 333) / (411.4 - 911.4), 4)
    print(slope_min, round(float(str(func.convert()).split(" ")[2]), 4), slope_max)

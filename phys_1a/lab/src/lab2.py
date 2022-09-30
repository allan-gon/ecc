import plotly.express as px
from os import system
from math import ceil
import pandas as pd


def clear():
    _ = input("Enter any key to continue: ")
    system("cls")


def collect_data(first_time = True):
    if not first_time:
        with open("./data/lab2_data.csv", "w") as file:
            file.write("mass_1(g),mass_2_min(g),mass_2_max(g),mass_2_best(g)\n")
    cont_collect_data = True
    while cont_collect_data:
        clear()
        try:
            mass_1 = float(input("Enter the weight of mass_1: "))
            cont_collect_data = False
        except ValueError:
            continue
    strs = ["1st", "2nd", "3rd", "4th", "5th", "6th"]
    idx = 0
    while idx < 6:
        clear()
        try:
            if idx == 1:
                mew_k = ceil(mass_2_max / mass_1)
            if idx != 0:
                print(f"Try {mew_k * mass_1} for mass_2 max")
            mass_2_min = float(input(f"Enter the {strs[idx]} mass_2 min: "))
            mass_2_max = float(input(f"Enter the {strs[idx]} mass_2 max: "))
            mass_2_best = (mass_2_min + mass_2_max) / 2
            idx += 1
            with open("./data/lab2_data.csv", "a") as file:
                file.write(f"{mass_1},{mass_2_min},{mass_2_max},{mass_2_best}\n")
            mass_1 += 100
        except ValueError:
            continue


def setup():
    with open("./data/lab2_data.csv", "r") as file:
        content = file.read() 
    if content != "mass_1(g),mass_2_min(g),mass_2_max(g),mass_2_best(g)\n":
        while True:
            clear()
            overwrite = input("Are you sure you want to overwrite the current data (Y/N): ").upper()
            if overwrite == "Y":
                collect_data(False)
                break
            elif overwrite == "N":
                break
    else:
        collect_data(True)


def graph():
    clear()
    df = pd.read_csv("./data/lab2_data.csv")
    fig = px.scatter(
        df, x="mass_1(g)", y="mass_2_best(g)",
        error_y="mass_2_max(g)", error_y_minus="mass_2_min(g)",
        trendline="ols"
    )
    fig.show()


def main():
    setup()
    graph()


if __name__ == "__main__":
    main()

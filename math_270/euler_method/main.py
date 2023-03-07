import matplotlib.pyplot as plt
from sympy import sympify, symbols


def main(x_0: float, y_0: float, x_f: float, h: float, expr: str) -> None:
    X, Y = symbols("x y")
    expr = sympify(expr)
    x, y = [x_0], [y_0]
    
    while x[-1] != x_f:
        y.append(y[-1] + h*expr.subs({X: x[-1],Y: y[-1]}))
        x.append(x[-1] + h)

    plt.plot(x, y)
    plt.savefig("graph.jpg")
    print(x)
    print(y)

if __name__ == "__main__":
    main(1, 0, 4, 1, "x^2 -y")

- **ASK IF NEED TRIG SUB OR PARTIAL FRAC**. be earnest, do i really need to study this

# Exact cont.
- for exact, $\phi(x, y) = C$ is the general solution

Ex:
- $xcos(xy)y' + 3x^2 = e^yy' - cos(xy)y$
- $xcos(xy)y' + 3x^2 - e^yy' + cos(xy)y = 0$
- $ 3x^2 + cos(xy)y + (xcos(xy) - e^y)y'= 0$
- $\frac {\partial M}{\partial y} = -sin(xy)xy + cos(xy)$
- $\frac {\partial N}{\partial x} = cos(xy) - sin(xy)xy$
    - this is exact
- $\int M dx = x^3 + sin(xy) + g(y)$
- $\int N dy = sin(xy) - e^y + g(x)$
- sol: $x^3 + sin(xy) - e^y = C$
    - found out $g(y) = -e^y$ because that the piece $\int N dy$ has that $\int M dx$ doesn't

## Changing to exact
- suppose we have a diff eq of the form $M(x, y) + N(x, y)y' = 0$ then if $\frac {M_y - N_x}{N} = f(x)$ an int fact of $e^{\int f(x) dx}$ makes the diff eq exact. if $\frac {M_y - N_x}{M} = g(y)$ then use int fact $e^{\int g(y) dy}$

Ex:
- $5x^6y^3+ \frac {2}{x} + (3x^7y^2 + \frac {x^2}{y})y' = 0$
    - $\frac {\partial M}{\partial y} = 15x^6y^2$
    - $\frac {\partial N}{\partial x} = 21x^6y^2 + \frac {2x}{y}$
    - $M_x - N_y \neq 0$ therefore not exact
    - $\frac {M_x -N_y}{N} = \frac {-2}{x}$
- int fact: $e^{\int \frac {-2}{x}} \equiv x^{-2}$
- distributing it: $5x^4y^3 + \frac {2}{x^3} + (3x^5y^2 + \frac {1}{y})y' = 0$
- $\int P dx = x^5y^3 - \frac {1}{x^2} + f(y)$
- $\int Q dy = x^5y^3 + ln|y| + g(x)$
- sol: $x^5y^3 - \frac {1}{x^2} + ln|y| = C$

# Summary of techniques
- `Linear`: $y' + f(x)y = g(x)$
    - use int fact $e^{\int f(x) dx}$ (mult both sides)
- `Bernoulli`: $y' + f(x)y = g(x)y^n$
    - substitute $u = y^{1 - n}$
- `Homogenous`: $y' = F(\frac {y}{x})$
    - substitute $V = \frac {y}{x}$
- `Seperable`: $g(y)y' = f(x)$
- `Exact`: $M(x, y) + N(x, y) = 0$
    - check is exact by $M_y = N_x$
- `Exact w/ Int Fact`: tbd. examples above. remeber can use eother integrating factor so if bot a pure dunction of one variable use the other

# TODO
- suggested exercises
- review guide
- create note sheet

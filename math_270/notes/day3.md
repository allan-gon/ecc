# 1.4 cont
## Seperable Diff Eqs
Ex:
- $y' = y^3 cos(3x); y(0) = 1; y(\frac {\pi}{2}) = 0$
    - $\int y^{-3} dy = \int cos(3x) dx$
    - **NOTE**: dividing by y is a concern. $y^3 \neq 0$ then check if it is a solution which will be used at the end
    - $\frac {-1}{2y^2} = \frac {sin(3x)}{3} + C$
    - sol set: $y=0; y^2 = \frac {1}{\frac {-2}{3} sin(3x) +C}$
        - no general solution
    - plugging in $y(0) = 1$; $C = 1$
        - $y = 0$ doesn't work so the solution plugging in C is a unique solution
    - plugging in $y(\frac {\pi}{2}) = 0$; $y(x) = 0$ is the sol. The IVP vioated our assumption for the sol so use the other one

Ex:
- $y' = y$ determine all the solutiona and state if it has general
    - $\int \frac {1}{y} dy = \int 1 dx$
        - $y \neq 0$ if $y = 0; y' = 0; y' = y$
        - $y = 0$ is a solution
    - $ln|y| = x + C$
    - $y = e^{x + C}$
    - $y = Ce^x$
        - General solution because $C = 0$ yeilds $y = 0$

Ex:
- $2x^2yy'-y^2 = 1 - 2yy'$ find all sol, state if general, $y(1) = -1$
    - $2x^2yy' + 2yy' = 1 + y^2$
    - $2yy'(x^2 + 1) = 1 + y^2$
    - $\frac {2yy'}{1 + y^2} = \frac {1}{x^2 + 1}$
    - $\int \frac {2y}{1 + y^2} dy = \int \frac {1}{x^2 + 1} dx$
    - $ln|1 + y^2| = arctan(x) + C$
        - this is a general solution
    - plugging in $y(1) = -1$; $C = ln(2) - \frac {\pi}{4}$

# 1.6
## Linear Diff Eqs
- of the form: $y' + g(x)y = f(x)$
- `Integrating Factor`: a choice of factor to multiply both sides by so that it's easier to solve
    - $e^{\int g(x) dx}$
    - claim: $LHS = \frac {d}{dx}(e^{\int g(x) dx}y)$
    - expanding it we see this is true
- Integrate boths sides with respect to x
    - general sol: $e^{\int g(x) dx} y = \int e^{\int g(x) dx} f(x) dx$

Ex:
- find all sol to: $y' + 4y = \frac {x^3}{e^{4x}}$
    - $g(x) = 4$
    - integrating factor: $e^{4x}$
- $e^{4x}y' + e^{4x}4y = \frac {x^3}{e^{4x}} e^{4x}$
- $e^{4x}y' + e^{4x}4y = x^3$ => $\int \frac {d}{dx} (e^{4x}y) = \int x^3$
- $y = \frac {x^4}{4e^{4x}} + \frac {C}{e^{4x}}$
- this is a general sol

Ex:
- "": $y' + \frac {5}{x}y = \frac {sin(x)}{x^4}$
    - $g(x) = \frac {5}{x}$
    - int fact: $e^{5ln(x)}$ => $e^{ln(x^5)}$ => $x^5$
- $x^5y' + \frac {5}{x}yx^5 = \frac {sin(x)}{x^4}x^5$
- $x^5y' + 5x^4y = xsin(x)$
- $\int \frac {d}{dx} (x^5y) = \int xsin(x)$
- $x^5y = -xcos(x) + sin(x) + C$
    - general sol

Ex:
- "": $yy'- \frac {x^7y}{x + 1} = \frac {7y^2}{x}$; $y(1) = 2$
    - $y'- \frac {x^7}{x + 1} = \frac {7y}{x}$
        - bc divide by y, $y \neq 0$; $0 = 0$
    - $y' - \frac {7y}{x} = \frac {x^7}{x + 1}$
    - $g(x) = - \frac {7}{x}$
    - int fact: $e^{\int -7ln(x)}$ => $\frac {1}{x^7}$
    - $\frac {1}{x^7} y' - \frac {1}{x^7} \frac {7y}{x} = \frac {1}{x^7} \frac {x^7}{x + 1}$
    - $\frac {1}{x^7} y' - \frac {7y}{x^8} = \frac {1}{x + 1}$
    - $\int \frac {d}{dx} (x^{-7}y) = \int \frac {1}{x + 1}$
    - $x^{-7}y = ln|x + 1| + C$
    - $y = x^7{ln|x + 1|} + Cx^7$
    - no general solution but this equation & $y = 0$ are the solution set
    - plugging in, $C = 2 - ln(2)$

# 1.8
## Intro to change of variable
- if you have a diff eq that doesnt fit the previous formats by changing the variables this becomes a format we know how to solve
- `Homogeneous 1st order diff eq`: $y' = F(\frac {y}{x})$; Then a substitution of the form $V = \frac {y}{x}$ will make a homoheneous 1st order diff eq seperable

- **Proof**
    - $y' = F(\frac {y}{x})$
    - $V = \frac {y}{x}, y = xV, y' = V +xV'$
        - **NOTE**: this is a change of the dependent variable
    - $V + xV' = F(V)$ => $\frac {1}{F(V) - V} = \frac{1}{x}$
        - seperable by definition
# Trig Integrals
- $\int sin(x) = -cos(x); \int cos(x) = sin(x); \int tan(x) = \ln |sec(x)|$
- $\int sec(x) = \ln |sec(x) + tan(x)|; \int sec^2(x) = tan(x); \int cot = - \ln |csc(x)|$
- $\int csc^2(x) = -cot(x); \int sec(x)tan(x) = sec(x); \int csc(x)cot(x) = -csc(x)$

# Properties of Exponents
- $a^{m+n} = a^m \cdot a^n$
- $a^{m-n} = a^m / a^n$

# Properties of logs
- $\ln |m^n| = n \ln |m|$
- $\ln |mn| = \ln |m| + \ln |n|$
- $\ln |\frac {m}{n}| = \ln |m| - \ln |n|$

# Methods of Solving Diff eqs
## Separable
- of the form: $g(y)y\ = f(x)$

## Linear
- of the form: $f_n(x)y^{(n)} + f_{n-1}(x)y^{(n-1)} + ... + f_1(x)y' + f_0(x)y = F(x)$
- examples:
    - $y' + y = 2x$
    - $xy' - 2y = x^5$
- solved using this substitution: $e^{\int f_0(x) dx}$

## Change of Variable
- of the form: $y' = F(x, y)$
- substitute: $V = \frac {y}{x}$

## Bernoulli
- of the form $y' + p(x)y = q(x)y^n$
- substitute: $u = y^{1-n}$

## Exact
- of the form: $M(x, y) + N(x, y)y' = 0$
- if $M_y = N_x$ simply integrate $\int M dx; \int Ny$
    - remember the int of M is missing $g(y)$ and the int of N is missing $f(x)$
- by looking at the two see hte missing piece, plug it in, and finally set it equal to $C$

## Exact w/ Int Fact
- if $\frac {M_y - N_x}{N} = f(x)$ use this integrating factor: $e^{\int f(x)}$
- alternatively if $\frac {M_y - N_x}{M} = g(y)$ use this integrating factor: $e^{\int g(y)}$

# Theoroms
## General Sol
- n unknown constants where N is the order
- let $y=f(x)$ be a sol. NTS $y=f(x)$ can be written as the sol by considering an IVP (make sure to write matching initial conds) $y(0) = f(x); y'(0) = f'(0)$
- solve the system of equation $f(0), f'(0)$ for the constants in terms of $f(0), f'(0)$
- plug this in. You should see that this is the proposed solutiion given some choice of constants

## EU for Linear DE
- given a linear DE in standard form, if all the functions of x are continuous on some interval I, then any IVP of the form $y(x_0) = z_0, y'(x_0) = z_1, ..., y^{(n-1)}(x_0) = z_0{n-1}; x_0 \in I$ will have a unique sol 

## EU from 1st ODE
- given an IVP: $y' = F(x, y); y(x_0) = y_0$ if $F(x, y)$ and $\frac {\partial F}{\partial y}$ are continuous around ($x_0,y_0$) the IVP will have a unique sol

# Methods of solving 2nd order diff eq
## Case 0 (missing y and y')
- of the form: $y'' = f(x)$
- simply take a double integral

## Case 1 (missing y)
- of the form: $y'' = f(x, y')$
- substitute $u = y'; u' = y''$

## Case 2 (missing x)
- $y'' = f(y, y')$
- substitute $V = y'; V'V = y''$
    - **NOTE** y is treated as the independent variable

## Gotchas
- When getting to a sol to a diff eq you can treat the constants as just that, but to solve for the constants, differentiate the sol so that the relation holds $y = cx^3; y = 3cx^2$
- `Piece Wise`: solve each part but at the end you need to solve for the constants in terms of one of them by passing in the values at the intersection and solving

## Misc
- do LHS RHS

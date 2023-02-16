TODO: suggested exercises (file section) 1.1-1.4. take a look at supplemental videos

# Sectioon 1.2
- existence and uniqueness theorom cont.

Ex:
- $x^2 y'' + 3y = 3xy'$
- verify $y = c_1 x + c_2 x^3$ is a sol to diff eq
    - $y' = c_1 + 3 c_2 x^2$
    - $y'' = 6 c_2 x$
    - $x^2 (6 c_2 x) + 3 (c_1 x +  c_2 x^3) = 3x (c_1 + 3 c_2 x^3)$
    - $9 c_2 x^3 + 3 c_1 x = 3 c_1 x + 9 c_2 x^3$
- prove (using EU theorom) this is the general sol (ae. this is the only family of solutions)
    - num const = order of diff eq: order 2 and 2 unknown const
    - is every sol of this form: 
        - let $y = g(x)$ be a solution to our diff eq
        - need to show (NTS) $g(x)$ can be written as $c_1 x + c_2 x^3$ for some $c_1, c_2$
        - lets consider the associated IVP $x^2 y'' + 3y = 3xy'$ with $y(1) = g(1); y'(1) = g'(1)$
        - this means $y = g(x)$ solves this IVP
        - change the diff eq into standard form: $y'' - \frac {3}{x}y' + \frac {3}{x^2}y = 0$
        - now check if cont at x = a (here 1): $f_1(1) =  \frac {-3}{1}; f_0(1) = \frac {3}{1^2}; F(1) = 0$
        - by the EU theorom of IVP's, there is a unique solution.
        - note that $y = g(x)$ is a sol t othis IVPt
        - now check if $y = c_1x + c_2x^3$ solves this IVP
            - $y(1) = c_1 + c_2 \equiv g(1)$
            - $y'(1) = c_1 + 3c_2 \equiv g'(1)$
            - solve this system of equations: $c_2 = \frac {g'(1) - g(1)}{2}; c_1 = \frac {3}{2} g(1) - \frac {1}{2} g'(1)$
        - for this IVP $y = g(x)$ is a sol and $y = \frac {g'(1) - g(1)}{2} x^3  + (\frac {3}{2} g(1) - \frac {1}{2} g'(1)) x$
        - Thus $y = c_1 x + c_2 x^3$ is a general sol
- What actually happened?
    - found a sol
    - made ivp
    - found unique sol for ivp
    - showed that the two solutions are equivalent

# Section 1.3
## Existence and Uniqqueness Theorom for 1st order diff eq
- suppose we have an IVP of the form $y' = f(x, y)$ (ae. 1st order y derivative left, x and y on right no derivatives). If $f(x, y), \frac {\partial f} {\partial y}$ are both continuous at $(a, b)$ then this IVP will have a unique sol

## Visualization of 1st order diff eqs (Slope Field)
- a graph where you plot slopes
- the slope is determined by plugging $(a, b)$ into $f(x, y)$
- Ex in ipad

# Section 1.4
## Solving 1st Order Diff Eq
- `Seperable`: $g(y) y' = f(x)$
    - becomes $g(y) \frac {dy}{dx} = f(x)$ => $\int g(y) dy = \int f(x) dx + C$
    - **Note**: this is always general solution

Ex:
- $y' = x^2 e^y + e^y$ => $y' = e^y (x^2 + 1)$ => $\frac {1}{e^y} \frac {dy}{dx} = x^2 + 1$ => $\int \frac {1}{e^y} dy = \int x^2 + 1 dx$
- => $-e^{-y} = \frac {x^3}{3} + x + C$ => $y = -\ln(- \frac {x^3}{3} - x + C)$
- IVP: $y(1) = 0$ => $e^0 = - \frac {1}{3} - 1 + C$ => $C =  \frac {7}{3}$

# Questions
- wdym need to do a similar proof? For this specific theorom it seems pretty self evident so...
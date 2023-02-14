# Syllabus
- a lot of useful stuff in files
- a playlist on canvas that is useful
- suggested problems in files
- need book for these questions so find it on libgen

# Intro (1.1/1.2)
- `def`: an equation involving derivatives
- will be studying `Ordinary Diff Eq`: derivative is a single variable derivative
- there's also `Partial Diff Eq`: derivative is partial
    - **NOT STUDYING THIS**

## Terminolgy
- `Order`: the highest derivative present in the eq
- `linear`: if a diff eq can be written in the form: $f_n(x)y^n + f_{n-1}(x)y^{(n-1)} + ... + f_1(x)y' + f_0(x)y = F(x)$
    - **note** the "exponent" is the derivate order actually
    - just means looks like some function of x times some derivative of y
    - **note** the `linear standard form`: $y^n + g_{n-1}(x)y^{(n-1)} + ... = G(x)$
    - just means divide by lead function
- otherwise `non-linear`

Ex:

1. 1st order non-linear (bc function of y): $y' - x^4 = y^3$
2. 3rd order linear (def includes y so fine): $x^2 y' + 5y = xy^{'''} + sin(x)$
3. 2nd order non-linear (derivative has a function of y): $y^{''} y + x = 1$

- `solution`: function (or relation) that when plugged in results in identity on interval $I$

Ex:

1. is $y = sin(x) - x$ a solution to $y'' + y = x^2$ ?
    - no because, $y'' = -sin(x)$ and $y'' + y = -x$ finally $-x \neq x^2$
2. is $xe^x$ a solution to $xy' - x^2e^x = y$?
    - yes because, $y' = e^x + xe^x$ and $xy' - x^2e^x = y \equiv xe^x = xe^x$

- `General Solution`: family of solutions that involves n unknown constants and every solution is part of the family for some choice of $C_1, ..., C_n$
    - **Note** not all diff eq have a general solutions
    - needs to be a single family. family is required

Ex:

1. $y' = x$
    - general solution: $y = x^2/2 + C$
2. $y' = y^2 x$
    - no general solution bc 2 solutions but one is $y = 0$ which doesn't involve a choice of the constant $C$

- `Initial Vlaue Problem (IVP)`: nth order diff eq with n-conditions of the form: $y(a) = b_0, y'(a) = b_1, ..., y^{(n-1)}(a) - n_{n-1}$
    - sol to IVP satisfies diff eq and initial conditions

## Existence and Uniqueness Theorem for Liner Diff Eqs
- If we have an nth order linear IVP in standard form and if $f_{n-1}(x), ..., f(x), f_0(x), F(x)$ are all continuous at $x = a$ then the IVP will have a unique solution
    - here $a$ is the value of x the intial conditions relate to
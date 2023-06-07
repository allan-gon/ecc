# Constant Coefficient Differential Equations
- DE with constants as the coefficients to the derivatives of y so of this form: $c_n y^{(n)} + c_{n-1} y^{(n-1)} + \dots + c_1 y' + c_0 y = F(x)$
  
## Homogenous
- just means $F(x) = 0$

### How to Solve
- Re-write the derivatives of $y^{(n)}$ with a differential operator to the same power $D^n$
- treat as polynomial and factor
    - if degree $>$ 2 then factoring may be difficult so us polynomial division
    - there's a thm that says a root must be evenly divisible by the constant at the end so have a finite pool of factors to try
- roots will return basis elements of the solution space

| roots | Basis elements |
|---|---|
| $root = a, a$ is real | $e^{ax}$
| $r = a \pm bi$ | $e^{ax} \cos(bx), e^{ax} \sin(bx)$

- **NOTE**: roots with multiplicities result in multiple basis elements with increasing powers of $x$
- example sol: $y = c_1 e^{3x} + c_2 xe^{3x} + c_3 \cos(5x) + c_4 \sin(5x)$

## Non-homogenous
- means $F(x)$ is a function
- requires annihilation

### How to Solve
- solve the homogenous equation
- get a trial solution by finding the annihilator and applying it to both sides
- simplify $y_T$ by omitting terms from $y_H$
- get $y_P$ by plugging $y_T$ into the original DE and back solving for the constants
- final answer is $y_H + y_P$ possibly can combine terms to further simplify

| Term | Annihilator |
|---|---|
| $e^{ax}$ | $D-a$ |
| $x^k e^{ax}$ | $(D-a)^{k + 1}$ |
| $x^k$ | $D^{k+1}$ |
| $e^{ax} \cos(bx), e^{ax} \sin(bx)$ | $D^2 -2aD + (a^2 + b^2)$ |
| $x^k e^{ax} \cos(bx), x^k e^{ax} \sin(bx)$ | $(D^2 -2aD + (a^2 + b^2))^{k + 1}$ |
| $\cos(bx), \sin(bx)$ | $D^2 + b^2$ |

- **NOTE**: if 2 terms are summed then the annihilator is the product of each term's annihilator

# Cauchy Euler Differential Equations
- nth order Cauchy-Euler:
    - $x^n y^{(n)} + a_{n - 1} x^{n - 1} y^{(n - 1)} + \dots + a_1 xy' + a_0 y = 0$
- substitute: $x = e^z, z = \ln|x|$
- $xy' = D, x^2y'' = D(D - 1), \dots, x^n y^{(n)} = D(D - 1)(D - 2) \dots (D - (n - 1))$
    - with $D$ being a differential operator in terms of $z$ so you must substitute at the end


# Variation of Parameters
- when the thing to annihilate is not simple

### How to solve
- solve homogenous
    - lets say you get basis elements $A, B, C, \dots$ to solve the homogenous equation
- let $u_1 A, \dots, u_n C$ be solutions
- set up a wronskian of the basis elements augmented with $\vec 0$ but the last element is the thing to annihilate
- solve this system
    - **NOTE**: you're solving for $u_1', \dots, u_n'$
- integrate and plug into the 'sol'
    - this is particular so still need: $y = y_H + y_P$

# Eigenvalues
- to find eigenvalues simply solve for $\lambda: \det(A - \lambda I_n) = 0$
    - really means cofactor expand a matrix a whose diagonal look like $c - \lambda$ and find the roots
- might need the quadratic formula for this
    - this may mean finding complex roots
    - these come in conjugate pairs

# Eigenvectors
- each eigenvalue has an eigenvector
- to find simply solve for $(A - \lambda I_n) \vec v_\lambda = 0$
    - means $A - \lambda I_n$ augmented with the zero matrix
- the resultant vector will have n parameters
- if $n \ne mul(\lambda)$
    - matrix is defective

## Complex eigenvalues
- Now suppose we have $\lambda = a + bi$ with $\vec v = \vec r + i \vec s$
    - and complex conjugate pair
- yeilds sols:
    - $\vec u(t) = e^{at} (\cos(bt) \vec r - \sin(bt) \vec s)$
    - $\vec v(t) = e^{at} (\cos(bt) \vec s + \sin(bt) \vec r)$
    - **NOTE**: these are just the vectors so if asked to solve a system of DE make sure top multiply each vector by a constant
    
# Solving Systems of DE
- find eigenvalues
- find eigenvectors
- solution: $\vec x(t) = c_1 e^{\lambda_1 t} \vec v_{1P} + \dots + c_n e^{\lambda_n t} \vec v_{nP}$
    - where $\vec v_{kP}$ is the corresponding eigenvector but particular
    - choose $\vec v_1 \dots \vec v_n$ to be LI

## Defective
- the 1st 2 steps are the same but finding eigenvectors has caveats
    - by the multiplicty, it will be $2, 1$ for $mul = 3$ or for $2, 2$ or $3, 1$ for $mul = 4$
    - try lowest order bu $(A - \lambda I_n)^n \vec v_n = 0$
        - note if $(A - \lambda I_n)^n = \vec 0$ this is the highest order
    - if this is the highest order 
        - choose and a vector of this form such that it's not order 1
        - choose another such that it's LI from the previous
        - find their corresponding order 1 by $\vec v_n = A \cdot \vec u_n$
    - otherwise you need order 3 so simple choose vec such that not order 2 or order 1
        - find the order 2 by $\vec v_2 = A \cdot \vec v_3$
        - find order 1 by $\vec v_1 = A \cdot \vec v_2$
- use the formula to write make sure to only chain where appropriate
- formula:
    - let $\vec v_k$ be the generalized kth order eigenvector
        - $e^{\lambda t} \vec v$
        - $e^{\lambda t}(\vec v_2 + t \vec v)$
        - $e^{\lambda t} (\vec v_3 + t \vec v_2 + \frac{1}{2} t^2 \vec v)$
        - $\vdots$
        - $e^{\lambda t}(\vec v_k + t \vec v_{k-1} + \dots + \frac {1}{(k - 1)!} t^{k-1} \vec v)$
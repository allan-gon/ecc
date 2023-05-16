# Reminders
- TH Exam 3 due thursday 5/18
- Sug ex 8.1,8.2
- TH Quiz/Exam 4 posted Thursday 5/18
- Exam 4 (chpt 7, 8, 9)

# Section 8.1 Linear Differential Operators
- `differential operator`: $D$ is a *linear transformation* $D: C_\infin (\R) \rightarrow C_\infin (\R)$ defined by $D(f(x)) = f'(x)$
    - just defining the derivative and a linear transformation
    - **NOTE**: higher order derivatives can be viewed as composition. ex: $D \circ D: C_\infin (\R) \rightarrow C_\infin (\R)$
        - $D \circ D (f(x)) = f''(x)$
    - higher order derivates written as $D^n$
- `linear differential operator`: $L$ is a linear transformation $L: C_\infin (\R) \rightarrow C_\infin (\R)$
    - $L = D^n + a_{n-1}(x)D^{n-1} + \dots + a_1(x)D + a_0(x)$
    - **NOTE**: $L(y) = y^n + a_{n-1}(x)y^{(n-1)} + \dots + a_1(x)y' + a_0(x)y$

### Example
- let $L = D^2 -3xD + x^2$
- determine $L(\sin(x))$
    - $(\sin(x))'' -3x(\sin(x))' + x^2(\sin(x)) \Rightarrow - \sin(x) -3x \cos(x) + x^2 \sin(x)$

- `linear differential equation`: recall lin diff eq was a diff eq of the form $y^{(n)} + a_{n-1}y^{(n-1)} + \dots +  a_1(x)y' + a_0(x)y = F(x)$. This is equivalent to $L(y) = F(x)$ in linear diff operator notation
- `homogenous linear diff eq`: recall homogenous doff eq of the form $y^{(n)} + a_{n-1}y^{(n-1)} + \dots +  a_1(x)y' + a_0(x)y = 0$. In linear diff eq operator notation $L(y) = 0$.
    - the sol set to the homogenous system is the $ker(L)$
- `EU thm for LDE`: if you  have a LDE: $y^{(n)} + a_{n-1}y^{(n-1)} + \dots +  a_1(x)y' + a_0(x)y = F(x)$ with IVP $y(x_0) = c_1, y'(x_0) = c_2, \dots, y^{(n-1)}(x_0) = c_n$. If  $a_{n-1}(x), \dots, a_0(x), F(x)$ are all continuous at $x_0$ then there exists a unique sol
    - $L(y) = F(x)$ with same IVP at $x_0$ then IVP has unique sol
    - `regular`: if $a_{n-1}(x), \dots, a_0(x), F(x)$ are all continuous everywhere we call the diff eq regular

## Theoroms/Proofs
- `big thm`: let $L$ be an nth order linear diff operator. Then $\dim (ker(L)) = n$
- proof: NTS $\exists$ a basis for $ker(L)$ that consits of functions $u_1, \dots, u_n$
- define $u_1, \dots, u_n$ as follows
    - let $u_1$ be sol to $L(y) = 0$ with IVP $y(x_0) = 1, ,y'(x_0) = 0, \dots, y^{(n-1)}(x_0) = 0$
    - let $u_2$ be sol to $L(y) = 0$ with IVP $y(x_0) = 0, ,y'(x_0) = 1, \dots, y^{(n-1)}(x_0) = 0$
    - $\vdots$
    - let $u_n$ be sol to $L(y) = 0$ with IVP $y(x_0) = 0, ,y'(x_0) = 0, \dots, y^{(n-1)}(x_0) = 1$
        - **NOTE**: all these are guaranteed to exist by EU thm for LDE
- NTS $u_1, \dots, u_n$ LI
    - $W(u_1, u_2, \dots, u_n) = \begin{pmatrix} u_1 & u_2 & \dots & u_n \\ u_1' & u_2' & \dots & u_n' \\ \vdots & \vdots & \ddots & \vdots \\ u_1^{(n - 1)} & u_2^{(n - 1)} & \dots & u_n^{(n - 1)} \end{pmatrix}$
    - $W(u_1, u_2, \dots, u_n)(x_0) = \begin{pmatrix} u_1(x_0) & u_2(x_0) & \dots & u_n(x_0) \\ u_1'(x_0) & u_2'(x_0) & \dots & u_n(x_0)' \\ \vdots & \vdots & \ddots & \vdots \\ u_1^{(n - 1)}(x_0) & u_2^{(n - 1)}(x_0) & \dots & u_n^{(n - 1)}(x_0) \end{pmatrix}$
    - $\Rightarrow \begin{pmatrix} 1 & 0 & \dots & 0 \\ 0 & 1 & \dots & 0 \\ \vdots & \vdots & \ddots & \vdots \\ 0 & 0 & \dots & 1 \end{pmatrix}$
    $W(u_1, u_2, \dots, u_n)(x_0) = 1 \ne 0$ so $u_1, u_2, \dots, u_n$ LI
    - $QED$

- let $w \in ker(L)$ NTS $w \in span(u_1, u_2, \dots, u_n)$
- since $w \in ker(L)$, $L(w) = 0$
    - $w(x_0) = c_1, w'(x_0) = c_2, \dots, w^{(n - 1)}(x_0) = c_n$
- claim: $w = c_1 u_1 + c_2 u_2 + \dots + c_n u_n$
- NTS $u_1, \dots, u_n$ spanning set for $ker(L)$
    - consider IVP: $L(y) = 0$. $y(x_0) = c_1, y'(x_0) = c_2, \dots, y^{(n - 1)}(x_0) = c_n$
    - clearly w is a sol. can check: 
        - $c_1 u_1(x_0) + c_2 u_2(x_0) + \dots + c_n u_n(x_0) \Rightarrow c_1 (1) + c_2(0) + \dots + c_n(0) = c_1$
        - $c_1 u_1'(x_0) + c_2 u_2'(x_0) + \dots + c_n u_n'(x_0) \Rightarrow c_1 (0) + c_2(1) + \dots + c_n(0) = c_2$
        - $\vdots$
        - $c_1 u_1^{(n - 1)}(x_0) + c_2 u_2^{(n - 1)}(x_0) + \dots + c_n u_n^{(n - 1)}(x_0) \Rightarrow c_1 (0) + c_2(0) + \dots + c_n(1) = c_n$
    - so $c_1 u_1 + c_2 u_2 + \dots + c_n u_n$ is also a sol to IVP
    - by EU thm for LDE $W = c_1 u_1 + c_2 u_2 + 
    dots + c_n u_n$
    - so $w \in span(u_1, \dots, u_n)$
    - thus $u_1, \dots, u_n$ is a basis
    - $QED$

## More Defintions
- `solution space`: the solutions to a homogenous LDE
- `general sol`: if $u_1 ... u_n$ is a basis for $ker(L)$ then $y = c_1 u_1 + \dots + c_n u_n$ is the general sol

## Another thm/proof
- `thm`: consider the non-homogenous LDE $L(y) = F(x)$. let $u_1 \dots u_n$ be a basis for $ker(L)$ and $y_p$ be a sol to $L(y) = F(x)$. Then every sol to $L(y) = F(x)$ is of the form $y = c_1 u_1 + \dots + c_n u_n + y_p$
- proof: let $w$ be any sol to $L(y) = F(x)$. consider $w - yp$
    - $L(w - y_p) = L(w) - L(y_p) = F(x) - F(x) = 0$
    - so $w - y_p \in Ker(L)$
    - so $w - y_p = c_1 u_1 + \dots + c_n u_n \Rightarrow w = c_1 u_1 + \dots + c_n u_n + y_p$

# Section 8.2 Constant Coefficient Homogenous Linear Differential Equations
- `const coeff hom LDE`: of the form $y^{(n)} + k_{n - 1} + \dots + k_1 y' + k_0 y = 0$ with $k_{n - 1}, \dots, k_1, k_0$ constants
- `polynomial diff operator`: if you phrase this in terms of the operator notation: $(D^n + k_{n - 1}D^{n - 1} + \dots + k_1 D + k_0)(y) = 0$
    - ex: $y'' - 7y' + 12 y = 0 \equiv (D^2 - 7D + 12)(y) = 0$
    - $(D - 3) \circ (D - 4)(y) = 0$
- Fact: $y = e^{ax}$ is a solution to $(D - a)(y) = 0$
    - proof: $(D - a)(e^{ax}) = (e^{ax})' - a(e^{ax}) = ae^{ax} - ae^{ax} = 0$
- Fact: $y = x^{k - 1} e^{ax}$ is a sol to $(D - a)^k (y) = 0$
    - proof by induction: base case $k = 1$ NTS $y = e^{ax}$ is a sol to $(D - a)(y) = 0$. we showed this above
    - inductive hypothesis: assume $y = x^{k - 1} e^{ax}$ is a sol to $(D - a)^k (y) = 0$
    - prove: $y = x^k e^{ax}$ is a sol to $(D - a)^{k + 1} (y) = 0$
    - proof: $(D - a)^{k + 1} (x^k e^{ax}) = (D - a)^k (D - a) (x^k e^{ax})$
        - $(D -a)^k ((x^k e^{ax})' - a(x^k e^{ax}))$
        - $(D -a)^k (kx^{k - 1} + ax^k e^{ax} - ax^k e^{ax})$
        - $(D - a)^k (kx^{k -1} e^{ax})$
        - $k(D - a)^k (x^{k - 1} e^{ax})$ IH
        - $k \cdot 0 = 0$
- Fact: $e^{ax}, xe^{ax}, \dots, x^{k - 1}e^{ax}$ are all LI

### Example
- solve $y'' - 7y' + 12y = 0$
    - 2nd order, const coeff
    - $(D^2 -7D + 12)(y) = 0$
        - sol space $ = ker(L)$
        - $\dim (ker(L)) = 2$
    - $(D - 3)(D - 4)(y) = 0$
    - sols to the factors are $e^{3x}, e^{4x}$ respectively. len = 2, dim = 2 so basis
    - gen sol: $y = c_1 e^{3x} + c_2 e^4x$
     - **TAKEAWAY**: for simple example like this simply factor and the gen sol is simply a linear combination of $e^{ax}$ where a is the number in the factor
- solve $y''' + 6y'' + 9y' = 0$
    - $(D^3 + 6D^2 + 9D)(y) = 0$
        - $\dim (ker(L)) = 3$ because 3rd order
    - $(D)(D + 3)^2(y) = 0$
        - $e^{0x} = 1$
        - $e^{-3x}$
        - $xe^{-3x}$ this gut comes from the repeated root. for higher repetition just add another element with an increased in power x
    - gen sol: $y = c_1 (1) + c_2 (e^{-3x}) + c_3 (xe^{-3x})$

## Complex Roots
- `euler thm`: $e^{a + bi} = e^a (\cos(b) + i \sin(b))$
    - $e^{(a + bi)x} = e^{ax} (\cos(bx) + i \sin(bx))$
- complex roots come in conjugate pairs
    - $e^{(a + bi)x} = e^{ax} (\cos(bx) + i \sin(bx))$
        - simplified: $v_1 = e^{ax} \cos(bx) + ie^{ax} \sin(bx)$
    - $e^{(a - bi)x} = e^{ax} (\cos(-bx) + i \sin(-bx))$
        - simplified: $v_2 = e^{ax} \cos(bx) - ie^{ax} \sin(bx)$
    - $v_1 + v_2 = 2e^{ax} \cos(bx)$
        - $\frac {v_1 + v_2}{2} = e^{ax} \cos(bx)$
    - $v_1 - v_2 = 2ie^{ax} \sin(bx)$
        - $\frac {-i(v_1 - v_2)}{2} = e^{ax} \sin(bx)$

## Summary
- const coeff homogenous DE can alway be written as $P(D)(y) = 0$ whe $P$ is a polynominal
- approach: facotr the polynomial
- real root $a \rightarrow e^{ax}$
- commplex conjugate pair $a \pm bi \rightarrow e^{ax} \cos(bx), e^{ax} \sin(bx)$
- if multiplicity > use $x(\dots), x^2(\dots), \dots$ as needed

### Example
- find unique sol to: $y''' + 4y' = 0; y(0) = 1, y'(0) = 2, y''(0) = 12$
    - $(D^3 + 4D)(y) = 0$
        - $\dim (ker(L)) = 3$
    - $(D)(D^2 + 4)(y) = 0$
    - $e^{0x} = 1$
    - the other roots are $\pm 2i$
        - so $0 \pm 2i$
    - $e^{0x} \cos(2x) = \cos(2x)$
    - $e^{0x} \sin(2x) = \sin(2x)$
    - gen sol: $y = c_1 (1) + c_2 \cos(2x) + c_2 \sin(2x)$
    - to solve for the constants, plug in. could use matrix to solve
        - $1 = c_1 + c_2$
        - $2 = 2c_3 \Rightarrow c_3 = 1$
        - $12 = -4c_2 \Rightarrow c_2 = -3$
        - back solving: $c_1 = 4$
# Section 4.4 cont.
## Example
- consider the vectors $\{ \begin{bmatrix} 1 & 3 \\ 0 & 4 \end{bmatrix}, \begin{bmatrix} -1 & 0 \\ 1 & 0 \end{bmatrix}, \begin{bmatrix} 1 & 6 \\ 1 & 8 \end{bmatrix} \}$ in $M_2 (\R)$
    - is $\begin{bmatrix} -2 & -3 \\ 1 & -4 \end{bmatrix}$ in the span of those vectors
        - $\begin{bmatrix} -2 & -3 \\ 1 & -4 \end{bmatrix} =  c_1\begin{bmatrix} 1 & 3 \\ 0 & 4 \end{bmatrix} + c_2 \begin{bmatrix} -1 & 0 \\ 1 & 0 \end{bmatrix} + c_3 \begin{bmatrix} 1 & 6 \\ 1 & 8 \end{bmatrix}$
        - $\left(\begin{array}{ccc|c} 1 & -1 & 1 & -2 \\ 3 & 0 & 6 & -3 \\ 0 & 1 & 1 & 1 \\ 4 & 0 & 8 & -4 \end{array}\right)$
            - this was created by each element became a component of the matrix. all elems of 11 became row 1
        - to ref: $\left(\begin{array}{ccc|c} 1 & -1 & 1 & 2 \\ 0 & 1 & 1 & 1 \\ 0 & 0 & 0 & 0 \\ 0 & 0 & 0 & 0\end{array}\right)$
        - consistent because rank rules
        so vector is in the span
- Consider the vectors $\{ x^3 + 1, x^3 + x^2, x^3 + x \}$ in $P_3 (\R)$
    - Is  $3x^3 + x^2 + x + 2$ in the span of these vectors?
    - $\left(\begin{array}{ccc|c} 1 & 1 & 1 & 3 \\ 0 & 1 & 0 & 1 \\ 0 & 0 & 1 & 1 \\ 1 & 0 & 0 & 2 \end{array}\right)$
        - got by coeff of $x^n$ is row
        - to ref
        - inconsistent so no

# Theorom
- `thm`: Let $v_1...v_n \in V$. Then $span(v_1...v_n)$ is a *subspace* of $V$

## Proof
- NTS: closure properties

### $\oplus$
- Let $u, w  \in span(v_1...v_n)$
- NTS $u + w \in span(v_1...v_n)$
    - $u = c_1 v_1 + ... + c_n v_n$
    - $w = k_1 v_1 + ... + k_n v_n$
    - $u + w = c_1 v_1 + k_1 w_1 + ... + c_n v_n + k_n v_n$
    - $\Rightarrow u + w = (c_1 + k_1)v_1 + ... + (c_n + k_n) v_n$
- $QED$

### $\odot$
- let $u \in span(v_1 ... v_n)$
- NTS: $ku \in span(v_1 ... v_n)$
    - $u = c_1 v_1 + ... + c_n v_n$
    - $ku = kc_1 v_1 + ... + k c_n v_n$
- $QED$

## Ex
- do the vectors $(1, 1, 0), (0, 1, 1), (1, 2, 2)$ span $\R^3$?
    - gen elem $(a, b, c)$
    - does $c_1 (1, 1, 0) + c_2 (0, 1, 1) + c_3 (1, 2, 2) = (a, b, c)$ always have solutions for any $a, b, c$?
    - $\left(\begin{array}{ccc|c} 1 & 0 & 1 & a \\ 1 & 1 & 2 & b \\ 0 & 1 & 2 & c \end{array}\right)$
    - to ref: $\left(\begin{array}{ccc|c} 1 & 0 & 1 & a \\ 0 & 1 & 1 & b - a \\ 0 & 0 & 1 & c - b + a \end{array}\right)$
    - consistent so yes again be cause rank rules
- fo the vectors $\begin{bmatrix} 1 & 0 \\ 0 & 0 \end{bmatrix}, \begin{bmatrix} 0 & 0 \\ 0 & 1 \end{bmatrix}, \begin{bmatrix} 0 & 1 \\ 1 & 0 \end{bmatrix}$ span $M_2 (\R)$?
    - $\left(\begin{array}{ccc|c} 1 & 0 & 0 & a \\ 0 & 0 & 1 & b \\ 0 & 0 & 1 & c \\ 0 & 1 & 0 & d \end{array}\right)$
    - to ref: $\left(\begin{array}{ccc|c} 1 & 0 & 0 & a \\ 0 & 1 & 0 & d \\ 0 & 0 & 1 & c \\ 0 & 0 & 0 & b - c \end{array}\right)$
    - inconsistent if $b \neq c$ so no
    - follow up: what does $span(\begin{bmatrix} 1 & 0 \\ 0 & 0 \end{bmatrix}, \begin{bmatrix} 0 & 0 \\ 0 & 1 \end{bmatrix}, \begin{bmatrix} 0 & 1 \\ 1 & 0 \end{bmatrix})$ look like?
        - $S = \{ \begin{bmatrix} a & b \\ b & d \end{bmatrix} \}$
        - the two b's are because the value of the b and c slot are tied together
        - btw this subspace is for symmetric matrices in $M_2 (\R)$

# Section 4.5 Linear (In)Dependence
- `def`: A set of vectors $v_1 ... v_n \in V$ are said to be linearly independent if the only solution to $c_1 v_1 + ... + c_n v_n = 0$ is $c_1 = ... = c_n = 0$

## Example
- Are the vectors $\{ x^2 + 3x + 1, x^2 + 1, x + 1, x^2 -x + 1 \}$ linearly independentin $P_2 (\R)$
    - $\left(\begin{array}{cccc|c} 1 & 1 & 0 & 1 & 0 \\ 3 & 0 & 1 & -1 & 0 \\ 1 & 1 & 1 & 1 & 0 \end{array}\right)$
    - to ref: $\left(\begin{array}{cccc|c} 1 & 1 & 0 & 1 & 0 \\ 0 & -3 & 1 & -4 & 0 \\ 0 & 0 & 1 & 0 & 0 \end{array}\right)$
    - consistent with inf sol so dependent
    - \# of equations > dimension so must be dependent

- `thm`: A set of vectors $v_1 ... v_n$ is linearly dependent if and only if at least one vector is a linear combination of the others

### Proof
- NTS: if $v_1 ... v_n$ dependent then at least of vector is a lin combo than the others
    - there are $c_1 ... c_n$ bot all $0: c_1 v_1 + ... + c_n v_n = 0$
    - let $c_k \neq 0$
    - $c_1 v_1 + ... + c_k v_k + ... + c_n v_n = 0$
    - $c_1 v_1 + ... +  c_n v_n = - c_k v_k$
    - because $c_k \neq 0 \Rightarrow v_k = \frac {-c_1}{c_k} v_1 + ... + \frac {-c_n}{c_k} v_n$
- NTS: if at least one vector is a linear combination of the others then $v_1 ... v_n$ is dependent
    - $v_k = c_1 v_1 + ... + c_n v_n$
    - now consider $-c_1 v_1 -c_2 v_2 + ... + 1 v_k + ... -c_n v_n$
    - $\Rightarrow -c_1 v_1 -c_2 v_2 + ... + c_1 v_1 + ... + c_n v_n + ... -c_n v_n$
    - $\Rightarrow 0$
    - because we chose at least one constant to $\neq 0$ while the linear combination $= 0$ lineararly dependent
- $QED$

- `thm`: if $vn$ is a linear combination of $v_1 ... v_{n-1}$ then the $span(v_1 ... v_n) = span(v_1 ... v_{n-1})$
    - means you can remove the LD vec and still have the same span

## Proof
- assume $v_n$ is lin combo of $v_1 ... v_{n - 1}$
- NTS: $span(v_1 ... v_n) = span(v_1 ... v_{n-1})$
- NTS: Let $w \in span(v_1 ... v_n)$ then $w \in span(v_1 ... v_{n-1})$
    - $w = k_1 v_1 + ... + k_{n-1} v_{n-1} + k_n v_n$
        - $v_n = c_1 v_1 + ... + c_{n-1} v_{n-1}$
    - $\Rightarrow k_1 v_1 + ... + k_{n-1} (c_1 v_1 + ... + c_{n-1} v_{n-1}) + k_n v_n$
    - $\Rightarrow (k_1 + k_n c_1) v_1 + ... + (k_{n-1} + k_n c_{n-1}) v_{n-1}$
    - $\Rightarrow l_1 v_1 + ... + l_{n-1} v_{n-1}$
- $QED$

- **Corrallary**: every LD set of vectors has a LI subset w/ the same span

## 3 Props in LI/LD
- any set of vectors that include $\vec 0$ is LD
- a set of 2 vectors in LD $\Leftrightarrow v_1 = kv_2$
- every set of LD vectors contains a subset of LI vectors

# LI/LD in Function Spaces
- `Wronskian`: let $f_1 (x) ... f_n (x)$ be a set of function in $F_n (\R)$. THe *Wronskian* is the function defined as $W(x) = \det \begin{pmatrix} f_1 (x) & \dots & f_n (x) \\ f_1'(x) & \dots & f_n'(x) \\ \vdots \\ f_1^{(n-1)}(x) & \dots & f_n^{(n-1)}(x) \end{pmatrix}$
- `thm`: a set of functions $f_1(x) ... f_n(x)$ is LI if $W(x_0) \neq 0$ for some $x_0$
    - **Note**: If $W(x) = 0$ uniformly then no info

## Ex
- are the functions $e^x, x, 1$ LI or LD in $F_3 (\R)$
- Wronskian: $ \det \begin{pmatrix} e^x & x & 1 \\ e^x & 1 & 0 \\ e^x & 0 & 0 \end{pmatrix}$
    - probably learn cofactor expansion
    - wronskian = $W(x) = -e^x$
    - consider $W(0) - = e^0 = -1 \neq 0$. By thm LI

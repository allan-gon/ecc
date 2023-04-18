# Sumamry of 4.2 (Vector Spaces)
- vector space $V$
    - objects (called vectors $\vec v$)
    - field of scalars ($\R$)
    - 2 operations ($\oplus, \odot$)
        - vector addition & scalar on vector multiplication
        - must satisfy 10 properties
- additional properties of vector spaces
    - $\vec 0$ is unique
    - $0 \odot \vec v = \vec 0(\forall \vec v)$
    - $k \odot \vec 0 = \vec 0 (\forall k)$
    - $- \vec v$ unique
    - $- \vec v = -1 \odot \vec v (\forall \vec v)$
    - if $k \odot \vec v = \vec 0$ either $k = 0$ or $\vec v = \vec 0$

## Proof of 1
- Prove $\vec 0$ is unique
- Assume $\vec 0_1$ and $\vec 0_2$ are both zero vectors in $V$
- NTS: $\vec 0_1 = \vec 0_2$
    - $\vec 0_1 \oplus \vec 0_2 = \vec 0_1$ (by P5)
    - $\vec 0_2 \oplus \vec 0_1 = \vec 0_2$ (by P5)
    - these two statements are the same by communativity (by P3) QED

## Proof of 3
- NTS: $k \odot \vec 0 = \vec 0$
- let $\vec v \in V$
- $k \odot (\vec v \oplus \vec 0)$
    - $k \odot \vec v$
    - $(k \odot \vec v) \oplus (k \odot \vec 0)$
    - $k \odot \vec v = (k \odot \vec v) \oplus (k \odot \vec 0)$
    - $k \odot \vec 0$ acts like $\vec 0$ but $\vec 0$ is unique so $k \odot \vec 0 = \vec 0$

- Common vector spaces
    - $\R_n: (a_1, a_2, ..., a_n)$
    - $P_n(R)$ polynomials of degree n or less $p(x) = a_n x^n + a_{n - 1} x^{n - 1} + ... + a_1 x + a_0$
    - $M_{n \times m}(\R)$ nxm matrices w/ real elements $A = \begin{bmatrix} a_{11} & \ldots & a_{1_n} \\ \vdots & \ddots & \vdots \\ a_{m1} & \ldots & a_{mn} \end{bmatrix}$
        - $M_n(\R)$ nxn square matrices with real elements
    - $F^n(\R)$ functions that are atleast n times differentiable
        - $F^0(\R)$ continuous functions
        - think absolute value. it's continuous but not differentiable
        - $f^\infin(\R)$ functions that are infinitetly differentiable

# Section 4.3 Subspaces
- `Subspace`: let $S$ be a non-empty subset of vector space $V$. If $S$ is a vector space under the same operations of $V$ then $S$ is said to be a subspace of $V$
    - `thm`: a non-empty subset $S$ of a vector space $V$ is a subspace **if any only if** it is closed under $\oplus$ & $\odot$

## Proof
- NTS: if $S$ is a subspace then $S$ is closed under $\oplus$ and $\odot$
    - because $S$ is a vector space, it is closed under $\oplus$ & $\odot$
- NTS: $S$ is closed under $\oplus$ & $\odot$ then $S$ is a subspace
    - NTS: P1 - P10 hold for S
        - By assumption P1, P2 hold
        - Since we are working with the same $\oplus$ & $\odot$ P3, P4, P7, P8, P9, P10 hold
        - P5 is true since $S$ is closed under $\odot$ and $\vec 0 = 0 \odot \vec v$
        - P6 is true since $S$ is closed under $\odot$ and $- \vec v = -1 \odot \vec v$

- **NOTE**: Zero vector check
    - if $\vec 0 \notin S$ then $S$ is not a subspace (this is one dir check)

## Examples
- Consider $S = \{ A \in M_2 (\R) : A \}$ is invertible. Is $S$ a subspace of $M_2 (\R)$?
    - **No** by the zero vector check
    - alternately, you can add 2 vectors and end with a non-invertible matrix so not closed under $\oplus$
    - could've showed not closed under $\odot$ by $0 \odot \vec v = \vec 0$ which is not invertible
- Consider $S = \{ A \in M_2 (\R), A \}$ is not invertible $$. Is $S$ a subspace
    - **No**, not closed under $\oplus$
- Consider $S = \{ p(x) \in P_2 (\R): p'(1) = 0 \}$. Is $S$ a subspace of $P_2 (\R)$
    - Attempt to prove closure properties
        - let $p(x), q(x) \in S$
        - NTS: $(p(x) \oplus q(x))'(1) = 0$
            - $(p'(x) \oplus q'(x))(1) \Rightarrow p'(1) \oplus q'(1) \Rightarrow 0 + 0$
        - let $p(x) \in S$ and $k$ a scalar
        - NTS: $(kp(x))'(1) = 0$
            - $k(p'(x))(1) \Rightarrow k \times 0 = 0$
        - QED. $S$ is a subspace of $P_2 (\R)$
    - alternate way by general element
        - $p(x) \in P_2 (\R) \Rightarrow p(x) = ax^2 + bx + c$
        - $p'(1) = 0 \Rightarrow 2a +b = 0$
        - $b = -2a$
        - gen elem: $p(x) = ax^2 + (-2a)x + c$
        - let $p(x), q(x) \in S$
        - NTS: $p(x) \oplus q(x) \in S$
            - $p(x) = a_1 x^2 + (-2a_1)x + c_1$
            - $q(x) = a_2 x^2 + (-2a_2)x + c_2$
            - $p(x) + q(x) = (a_1 + a_2) x^2 + (-2a_1 -2a_2)x + (c_1 + c_2)$
            - $p(x) + q(x) = a_2 x^2 + (-2a_3)x + c_3$
            - do same for $\odot$
            - QED

# Two Important Subspaces
- `Null space`: let $A$ me an mxn matrix. Set of vectors $x: Ax = 0$
    - `thm`: the nullspace(A) is a subsapce of $\R^n$
    - proof: Let $x, y \in nullspace(A)$
    - NTS: $x + y \in nullspace(A)$
    - NTS $A(x + y) = 0$
        - $Ax + Ay \Rightarrow 0 + 0 = 0$
    - let $x \in nullspace(A)$, $k$ scalar
    - NTS: $kx \in nullspace(A)$
    - NTS: $A(kx) = 0$
        - $k(Ax) \Rightarrow k(0) = 0$

- Consider the nth order linear homogeneous diff eq $y^{(n)} + f_{n - 1}(x) y^{(n -1)} + ... f_1 (x)y' + f_0 (x)y = 0$. The sols to this dif eq form a subsapce of $F^n (\R)$
    - proof: let $y = g_1(x), g_2(x)$ be sols to this diff eq
    - NTS: $g_1(x) + g_2(x)$ is a sol to this diff eq
        - $(g_1(x) + g_2(x))^{(n)} + f_{n - 1}(x)(g_1(x) + g_2(x))^{(n - 1)} ... + f_1(x)(g_1(x) + g_2(x))' + f_0(x)(g_1(x) + g_2(x))$
        - $((g_1(x))^{(n)} + (g_2(x))^{(n)}) + ... + f_1(x)(g_1'(x) + g_2'(x)) + f_0(x)(g_1'(x) + g_2'(x))$
        - $(g_1(x))^{(n)} + ... + f_1(x)g_1'(x) + f_0(x)g_1(x) + (g_2(x))^{(n)} + ... + f_1(x)g_2'(x) + f_0(x)g_2(x)$
        - $\Rightarrow 0 + 0 = 0$
    - let $y = g(x)$ be a sol, $k$ a scalar
    - NTS: $y = kg(x)$ is a sol
        - $(kg(x))^{(n)} + ... + f_1(x)(kg(x))' + f_0(x)(kg(x))$
        - $\Rightarrow k(g(x)^{(n)} + ... + f_1(x)g'(x) + f_0(x)g(x))$
        - $\Rightarrow k(0) = 0$
        QED

- Let $V$ be a vector space. Then $S = \{ \vec 0 \}$ is the trivial subsapce

# Section 4.4
- `Linear Combination`: let $v_1 ... v_n$ be vectors in $V$. let $c_1 ... c_n$ be scalars. Then $v = c_1 v_1 + ... + c_n v_n$ is called a linear combination of v_1 ... v_n
- `Span`: let $v_1 ... v_n$ be vectors in $V$. $Span(v_1 ... v_n) = \{ v: v$ is a linear combination of $v_1 ... v_n \}$
    - `thm`: $Span(v_1 ... v_n)$ is a subspace of $V$

## Examples
- consider the vectors $p_1(x) = x^2 + 3x + 1, p_2(x) = x^2 - 1, p_3(x) = x^2 + x + 2$. Determine if the following are in $Span(p_1(x), p_2(x), p_3(x))$
    - $p(x) = 3x^2 + 4x + 3$
        - prospect = constant * each func
        - prospect coeffs = consants
        - make matrix
        - get to ref
        - if ranks match then consistent then sols
    - **NOTE**: looks like to make matrix just transpose vectors
    - $q(x) = x^2 + 4x + 4$
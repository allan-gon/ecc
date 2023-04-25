# TODO
- TH Quiz 3

# Recap
- $v_1 ... v_n$ *spans* $V$ if $\forall v \in V$
    - $v = c_1 v_1 + ... + c_n v_n$
- $v_1 ... v_n$ are LI if the only sol to $c_1 v_1 + ... + c_n v_n = 0$ is $c_1 = ... = c_n = 0$
- $v_1 ... v_n$ are LD if you can find sol to $c_1 v_1 + ... + c_n v_n = 0$ with at least one $c_k \neq 0$

# Section 4.6 Basis and Dimension
- `basis`: A set of vectors $v_1 ... v_n$ that are LI and span $V$ are said to be a basis for $V$
    - basis is the smallest spanning set
- `finite dimensional`: is a basis exists for $V$ then $V$ is said to be finite dimensional
- `infinite dimensional`: if no basis exists for $V$ then we say $V$ is infinite dimensional
- `thm`: let $V$ be the finite dimensional vector space. Then every basis of $V$ has the same number of elements
    - let $v_1 ... v_n$ be a basis for $V$
    - let $u_1 ... u_m$ be a set of vectors in $V$
        - if $m > n$ NTS: $u_1 ... u_m$ is LD
            - $c_1 u_1 + ... + c_m v_m = 0$
            - $v_1 ... v_n \Rightarrow$ spanning set + LI
            - $\left(\begin{array}{c}u_1 = a_{11} v_1 + ... + a_{1n} v_n \\ u_2 = a_{21} v_1 + ... + a_{2n} v_n \\ \vdots \\ u_m = a_{m1} v_1 + ... + a_{mn} v_n\end{array}\right)$
            - $c_1 (a_{11} v_1 + ... + a_{1n} vn) + ... + c_m (a_{m1} v_1 + ... + a_{mn} v_n)$
            - $(c_1 a_11 + ... + c_m a_{m1}) v_1 + ... + (c_1 a_1n + ... + c_m a_{mn}) v_n = 0$
            - $\left(\begin{array}{c} c_1 a_{11} + ... + c_m a_{m1} = 0 \\ \vdots \\ c_1 a_{1n} + ... + c_m a_{mn} = 0 \end{array}\right)$
            - homogenous, $n$ eqs, $m$ vars. $m > n$ so inf sol with at least $m - n > 0$ fp
        - if $m < n$
            - proof by contradiction. Assume $u_1 ... u_m$ is a basis
            - by case 1 $v_1 ... v_n$ must be linearly dependent since it has more vectors than $u_1 ... u_m$ which is a basis. This is a contradiction since $v_1 ... v_n$ is a basis which means it LI thus $u_1 ... u_m$ is not a basis
- `dimension`: the length of a basis (ae. number of vectors in a basis)

## Dimensions of common vector spaces
- $\dim (\R^n) = n$
- $\dim (P_n (\R)) = n + 1$
    - standard basis for $P_2 (\R) = \{ 1, x, x^2 \}$
- $\dim (M_{m \times n} (\R)) = m \cdot n$
    - standard basis for $M_{2 \times 1} (\R) = \{ \begin{bmatrix} 1 \\ 0 \end{bmatrix}, \begin{bmatrix} 0 \\ 1 \end{bmatrix} \}$

- `thm`: let $\dim (V) = n$ then if $v_1 ... v_n$ is LI $\Rightarrow v_1 ... v_n$ is basis
    - NTS: $v_1 ... v_n$ spans $V$
    - let $v \in V$. NTS: $v \in span(v_1 ... v_n)$
    - consider $v_1 ... v_n, v$
    - by previous proof $v_1 ... v_n, v$ LD
        - $c_1 v_1 + ... + c_n v_n + kv = 0$ has non-trivial sol. We know $k \neq 0$ since $v_1 ... v_n$ LI
        - $v = \frac {-c_1}{k} v_1 + ... + \frac {-c_n}{k} v_n$
        - $v \in span(v_1 ... v_n)$
- `thm`: let $\dim (V) = n$. Then $v_1 ... v_n$ be a spanning set of $V \Rightarrow v_1 ... v_n$ basis
    - NTS: $v_1 ... v_n$ LI
    - proof by contradiction. assume $v_1 ... v_n$ LD
    - we can find a subset of $v_1 ... v_n$ LI and spans $V$
    - we would have a basis for $V$ with less than $n$ vectors
    - contradicts $\dim (V) = n$ thus $v_1 ... v_n$ LI

## Summary
- let $v_1 ... v_k$ be a set of vectors in $V$
- let $\dim (V) = n$
- Case 1. $k < n$
    - Not a spanning set. Not a basis.
- Case 2. $k > n$
    - LD. Not a basis.
- Case 3. $k = n$
    - if spanning, LI, basis
    - if not span, LD, not a basis
    - so have to check span or LI

## Examples
- Do $\{ \begin{bmatrix} 4 & 7 \\ 5 & 8 \end{bmatrix}, \begin{bmatrix} -1 & 2 \\ 3 & 0 \end{bmatrix}, \begin{bmatrix} 4 & 4 \\ 8 & 2 \end{bmatrix} \}$ span $M_2 (\R)$
    - $\dim (M_2 (\R)) = 4$
    - $3 < 4$
- Do $\{ x^2 + x + 1, 2x + 1, x^2 -x, -x^2 + x \}$ span $P_2(\R)$
    - $\dim (P_2 (\R)) = 3$
    - $4 > 3$ so no info related to span
    - $\left(\begin{array}{cccc|c} 1 & 0 & 1 & -1 & a \\ 1 & 2 & -1 & 1 & b \\ 1 & 1 & 0 & 0 & c \end{array}\right)$
    - to ref: $\left(\begin{array}{cccc|c} 1 & 0 & 1 & -1 & a \\ 0 & 2 & -2 & 2 & b - a \\ 0 & 0 & 0 & 0 & c - \frac {a}{2} - \frac{b}{2} \end{array}\right)$
    - inconsistent if $c - \frac {a}{2} - \frac{b}{2} \neq 0$
    - **not** a spanning set
- Are $\{ (4, 0, 1, 1), (1, -1, 1, 1), (3, -1, 2, 2) \}$ LI in $\R^4$
    - $\dim (\R^4) = 4$
    - $3 < 4$ so no info related to LI
    - $\left(\begin{array}{ccc|c} 4 & 1 & 3 & 0 \\0 & -1 & -1 & 0 \\ 1 & 1 & 2 & 0 \\ 1 & 1 & 2 & 0\end{array}\right)$
    - to ref: $\left(\begin{array}{ccc|c} 1 & 1 & 2 & 0 \\ 0 & -1 & -1 & 0 \\ 0 & 0 & -2 & 0 \\ 1 & 1 & 2 & 0\end{array}\right)$
    - consistent with unique sol so **IS** LI
- Are $\{ x^3 + 5x + 4, x^3 + 1, x^3 + x + 2, x^2 + 5x, x^3 - 6x, x + 7 \}$ LI in $P_3 (\R)$
    - $\dim (P_3 (\R)) = 3$
    - $6 > 3$ so LD
- Is $\{ \begin{bmatrix} 0 & 1 & 2 \\ 3 & 4 & 5 \end{bmatrix}, \begin{bmatrix} -1 & 2 & 5 \\ 0 & 1 & 8 \end{bmatrix}, \begin{bmatrix} 0 & 1 & 1 \\ 1 & 1 & 0 \end{bmatrix} \}$ a basis for $M_{2 \times 3} (\R)$
    - $\dim (M_{2 \times 3} (\R)) = 6$
    - $3 < 6$ so not a basis
- Is $\{ \begin{bmatrix} 1 & 0 \\ 0 & 0 \end{bmatrix}, \begin{bmatrix} 1 & 1 \\ 0 & 0 \end{bmatrix}, \begin{bmatrix} 1 & 1 \\ 1 & 0 \end{bmatrix}, \begin{bmatrix} 1 & 1 \\ 1 & 1 \end{bmatrix} \}$ a basis for $M_2 (\R)$
    - $\dim (M_2 (\R)) = 4$
    - $4 = 4$ so have to check one of span, LI/LD
    - LI check: $\left(\begin{array}{cccc|c} 1 & 1 & 1 & 1 & 0 \\ 0 & 1 & 1 & 1 & 0 \\ 0 & 0 & 1 & 1 & 0 \\ 0 & 0 & 0 & 1 & 0 \end{array} \right)$
    - unique sol so LI $\Rightarrow$ is basis

# Dimension of Subspaces
- `thm`: let $S$ be a subspace of finite dimensional $V$. Then $\dim (S) \le \dim (V)$
    - **NOTE**:  the `trivial subspace` (just $\vec 0$) is defined as having dimension 0

## Examples
- Consider $S = \{ A : A \in M_3 (\R), A^T = A \}$
    - prove $S$ is a subspace of $M_3 (\R)$
        - NTS: closed under $\oplus$ & $\odot$
        - let $A, B \in S$
        - NTS: $A + B \in S$
            - NTS: $A + B = (A + B)^T$
            - $A^T + B^T \Rightarrow A + B = A + B$
        - NTS: $kA \in S$
            - NTS:  $k A^T = kA$
            - $k A^T \Rightarrow kA = kA$
        - $QED$
    - Find a basis for $S$ and give $\dim (S)$
        - $\dim (S) \le \dim (M_3 (\R)) = 9$
        - General element of $S$: $\begin{bmatrix} a & b & c \\ b & d & e \\ c & e & f \end{bmatrix}$
        - basis: $\{ \begin{bmatrix} 1 & 0 & 0 \\ 0 & 0 & 0 \\ 0 & 0 & 0 \end{bmatrix}, \begin{bmatrix} 0 & 1 & 0 \\ 1 & 0 & 0 \\ 0 & 0 & 0 \end{bmatrix}, \begin{bmatrix} 0 & 0 & 1 \\ 0 & 0 & 0 \\ 1 & 0 & 0 \end{bmatrix}, \begin{bmatrix} 0 & 0 & 0 \\ 0 & 1 & 0 \\ 0 & 0 & 0 \end{bmatrix}, \begin{bmatrix} 0 & 0 & 0 \\ 0 & 0 & 1 \\ 0 & 1 & 0 \end{bmatrix}, \begin{bmatrix} 0 & 0 & 0 \\ 0 & 0 & 0 \\ 0 & 0 & 1 \end{bmatrix} \}$
            - the process what make gen sol and choose var = 1 all else 0 loop
        - $\dim (S) = 6$

- Consider $S = \{ p(x) \in P_4 (\R), p(2) = p(-2) = 0 \}$
    - prove $S$ is a subpsace of $P_4 (\R)$
        - let $p(x), q(x) \in S$
        - NTS: $p(x) + q(x) \in S$
            - NTS: $p(x) + q(x)(2) = p(x) + q(x)(-2) = 0$
            - $p(x) + q(x)(2) = 0 + 0 = 0$
            - $p(x) + q(x)(-2) = 0 + 0 = 0$
        - NTS: $k p(x) \in S$
            - $k p(x)(2) = k p(x)(-2) = 0$
            - $k p(x)(2) = k 0 = 0$
            - $k p(x)(-2) = k 0 = 0$
        - $QED$
    - Determine basis and dimension of S
        - gen elem: $p(x) = (x - 2) (x + 2) (ax^2 + bx + c)$
        - basis: $\{ (x - 2) (x + 2) (x^2), (x - 2) (x + 2) (x) (x - 2) (x + 2) \}$
        - $\Rightarrow \{ x^4 - 4x^2, x^3 - 4x, x^2 -4 \}$
        - $\dim = 3$
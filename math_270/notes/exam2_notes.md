# Basic Operations
- `Matrix add/sub` & `Scalar add/sub`: element wise
- `Matrix Multiplication`: let $R_i$ be a row of the left matrix, $C_j$ be a column of the right matrix, and $e_{ij}$ be element of resultant matrix. Then $e_{ij} = R_i \cdot C_j$
    - ex: $A = \begin{bmatrix} a & b \\ c & d\end{bmatrix}; B = \begin{bmatrix} w & x \\ y & z\end{bmatrix}; AB = \begin{bmatrix} aw + by & ax + bz \\ cw + dy & cx + cz\end{bmatrix}$
    - **note**: requires nxm and mxp matrix and results in nxp
    - def incase I need it for proof: $\sum \limits_{n=1}^{n} A_{ij} B_{ji}$
- `Transpose`: rows become columns
    - ex: $A = \begin{bmatrix} a & b \\ c & d\end{bmatrix}; A^T = \begin{bmatrix} a & c \\ b & d\end{bmatrix}$
- `Trace`: sum of diagonal $\sum A_{ii}$
- `UT`: 0's in top right; `LT`: 0's in bottom left; `Diagonal`: both UT and LT
- `Symmetric`: $A^T = A$; `Skew Symmetric`: $A^T = - A$

# ERO's
- if you augment the indentity and take that matrix to rref the augmented portion is the inverse of the orignal matrix
- if you take a matrix to ref (technically can be UT, LT, or diag) the product of the diagonal is the determinant except
    - for every swap of rows multiply the det by $-1^n$
    - for every scale multiply the `determinant` by $\frac {1}{scale}$
        - ex: $R_1 \rightarrow \frac {1}{2}R_1$ then $2det$

# Rank
- Consider a system $Ax = b$ w/ A mxn, x nx1, b mx1 then
    - if $rank(A^{\char"0023}) = rank(A) = n$ there is a `unique sol`
    - $rank(A^{\char"0023}) \neq rank(A)$ `no sol` (more specifically $rank(A^{\char"0023}) = rank(A) + 1$)
    - $rank(A^{\char"0023}) = rank(A) < n$ `inf sol` with $n - rank(A)$ params
    - `big theorom`: if $rank(A^{\char"0023}) = rank(A)$ `consistent`. if $rank(A^{\char"0023}) \neq rank(A)$ `inconsistent`
    - `homogenous version` (constants = 0):
        - always have sol $x = 0$
        - unique sol of $x = 0$ if $rank(A) = n$
        - inf sol (includes $x = 0$) if $rank(A) < n$

# Property of Transpose
- $(A + B)^T = A^T + B^T$
- $(AB)^T = B^T A^T$

# Property of Inverse
- $(AB)^{-1} = B^{-1} A^{-1}$
- $(A^T)^{-1} = (A^{-1})^T$

# Determinant
- Def for Proof:
    - `determinant`: let $A$ be an nxn matrix. $det(A) = \sum \limits_{n!}^{} \sigma(p_1, p_2 ... p_n)a_{1p_1} a_{2p_2} ... a_{np_n}$
- `Thm`: $A$ is invertible $\leftrightarrow det(A) \neq 0$

## Properties
- $det(A^T) = det(A)$
- $det(A^{-1}) = \frac {1} {det(A)}$
- $det(kA) = k^n det(A)$

# Vector Spaces
Let $u, v, w \in V$. Let $k_1, k_2$ be scalars
- Closures under $\oplus$
    - $u \oplus v \in V$ ($\forall u, v \in V$)
    - if you add 2 vectors inside a given vector space, the sum should also exist in that space
- Closure under $\odot$
    - $k_1 \odot u \in V$ ($\forall u \in V, \forall k_1$ in field)
- $\oplus$ is Commutatuve
    - $u \oplus v \equiv v \oplus u$
- $\oplus$ is associative
    - $(u \oplus v) \oplus q \equiv u \oplus (v \oplus w)$
- $\exists$ a **zero vector**, denoted $\vec 0$ such that
    - $v \oplus \vec 0 = v$ $\forall v \in V$
- Additive inverse
    - $\forall v \in V \exists -v \in V$ such that
        - $v \oplus (-v) = \vec 0$
- Unit property
    - $1 \odot v = v$ $\forall v \in V$
- Associativity of scalar multiplication
    - $k_1 \odot (k_2 \odot v) \equiv (k_1 k_2) \odot V$
- Scalar multiplication over vector addition
    - $k_1 \odot (u \oplus v) \equiv (k_1 \odot u) \oplus (k_1 \odot v)$
- Scalar addition over scalar multiplication
    - $(k_1 + k_2) \odot u \equiv (k_1 \odot) \oplus (k_2 \odot u)$
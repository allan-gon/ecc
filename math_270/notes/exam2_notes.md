# Basic Operations
- `Matrix add/sub`: element wise
- `Scalar add/sub`: element wise
- `Matrix Multiplication`: let $R_i$ be a row of the left matrix, $C_j$ be a column of the right matrix, and $e_{ij}$ be element of resultant matrix. Then $e_{ij} = R_i \cdot C_j$
    - ex: $ A = \begin{bmatrix} a & b \\ c & d\end{bmatrix}; B = \begin{bmatrix} w & x \\ y & z\end{bmatrix}; AB = \begin{bmatrix} aw + by & ax + bz \\ cw + dy & cx + cz\end{bmatrix}$
    - **note**: requires nxm and mxp matrix and results in nxp
- `Transpose`: rows become columns
    - ex: $ A = \begin{bmatrix} a & b \\ c & d\end{bmatrix}; A^T = \begin{bmatrix} a & c \\ b & d\end{bmatrix}$
- `Trace`: sum of diagonal $\sum A_{ii}$

# ERO's
- if you augment the indentity and take that matrix to rref the augmented portion is the inverse of the orignal matrix
- if you take a matrix to ref (technically can be UT, LT, or diag) the product of the diagonal is the determinant except
    - for every swap of rows multiply the det by $-1^n$
    - for every scale multiply the determinant by $\frac {1}{scale}$
        - ex: $R_1 \rightarrow \frac {1}{2}R_1$ then $2

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
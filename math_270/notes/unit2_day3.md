# TODO
- start working on TH quiz

# 2.4 recap
- `row echelon form`
    - 0 rows at the bottom
    - 1st non-zero elem in ant non-zero row is a 1 (leading 1s)
    - each leading 1 below the st row is to the right of all previous leading 1s
- `rank`: number of non-zero rows in ref
    - if A is mxn. rank(A) $\leq m$ and also $\leq n$ ae. rank is constrained by dimensions
- `elementary row operations`
    - $R_i \Leftrightarrow R_j$
    - $kR_i (k \neq 0)$
    - $R_i \rightarrow R_i + kR_j$
    - **NOTE**: ERO's dont impact the solution set
    - eros ensure the resultant matrix is row equivalent ($A \sim B$)

# Section 2.5 Solving Systems of Linear Equatons
## Gaussian Elimination
- take a sys of lin eq and consider the augmented matrix
- put it in REF
- use back substitution to solve for variables
- **important**:  avoid parameterizing leading 1s

## Rank
- Consider a system $Ax = b$ w/ A mxn, x nx1, b mx1 then
    - $rank(A^{\char"0023}) = rank(A)$ or $rank(A^{\char"0023}) = rank(A) + 1$
    - if $rank(A^{\char"0023}) = rank(A) = n$ there is a `unique sol`
    - $rank(A^{\char"0023}) \neq rank(A)$ `no sol`
    - $rank(A^{\char"0023}) = rank(A) < n$ `inf sol` with $n - rank(A)$ params
    - `big theorom`: if $rank(A^{\char"0023}) = rank(A)$ `consistent`. if $rank(A^{\char"0023}) \neq rank(A)$ `inconsistent`
    - `homogenous version` (constants = 0):
        - always have sol $x = 0$
        - unique sol of $x = 0$ if $rank(A) = n$
        - inf sol (includes $x = 0$) if $rank(A) < n$

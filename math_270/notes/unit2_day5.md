# NOTE
- have meeting today so ask what im missing
    - something listed on canvas additional resources matrix properties at the end page 4. properties of determinent
    - section 3.3 another computatioal method of finde=ing determinant. cofactor expansion. supplemental video
- these proofs will ruin you on the exam. hammer this stuff

# Chpt 3 Determinant
- `permutation`: an ordering
    - total number of permutations is $n!$
- Let $(p_1, p_2, ..., p_n)$ be a permutation. Then the number of inversions written $N((p_1, p_2, ..., p_n))$ is counting all the $p_i > p_j$ w/ $i < j$
    - ae. given a list of numbers sum up the number of numbers to the right of it that are greater than itself
    - also number of adjacent swaps to put in order
- Thm: let $(p_1, p_2, ..., p_n)$ be a permutation. Define $\sigma(p_1 p_i p_j p_n)$ -1$ (sign of permutation as in even or odd inversions). $\sigma(p_1 p_i p_j p_n) = - \sigma(p_1 p_j p_i p_n)$.
    - ae. swapping two elements of a permutation reverses the sign
- `determinant`: let $A$ be an nxn matrix. $det(A) = \sum \limits_{n!}^{} \sigma(p_1, p_2 ... p_n)a_{1p_1} a_{2p_2} ... a_{np_n}$
    - only square matrices
    - scalar
- Ex on ipad

## 3.2 Properties of Determinant
- `Thm`: let $A$ be and UT, LT, or Diag mat. The $det(A) = a_{11} a_{22} a_{nn}$

## ERO's and Det
- $A \sim B$ via $R_i \leftrightarrow R_j$
    - $det(B) = - det(A)$
- $A \sim B$ via $R_i \rightarrow KR_i$
    - det(B) = kdet(A)
- $A \sim B$ via $R_i \rightarrow R_i + kR_j$
    - $det(B) = det(A)$

### Corrollaries
- $B = kA$
    - $det(B) = k^n det(A)$
- if $A \sim B$ then $\exists$ non-zero scalar $c$:
    - $det(B) = c det(A)$

- `Thm`: $A$ is invertible $\leftrightarrow det(A) \neq 0$
    - bc $det(A) \neq 0$ $A \sim I_n$ therefore invertible
    - actually useless for my code

## Properties of Det
- the 1st few are eros and det and corrollaries
- $det(A^T) = det(A)$
- $A = ...$
    - unfinished
- had to leave at this point
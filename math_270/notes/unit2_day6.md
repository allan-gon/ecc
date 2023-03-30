# Reminders
- Exam 2 next thursday
    - do the review
    - make a note sheet
    - covers chpt 2 (except 2.7), chpt 3, and 4.2
    - review sessions monday, friday

# Summary of Chpt 3
- let $A$ be an nxn matrix
- $det(A) = \sum \limits_{n!}^{} \sigma (p_1, ..., p_n)a_{1p_1}...a_{np_n}$
- the following are equivalent
    - $A$ is invertible
    - $rank(A) = N$
    - $A \sim I_n$
    - $det(A) \neq 0$
    - $Ax = b$ will always have a unique sol $x = A^{-1}b$
- if any of those is not true all are False

## Det Ex
- consider $\begin{bmatrix}
1 & 3 & 0 & 2 \\
-3 & 4 & 5 & 1 \\
2 & 6 & 1 & 4 \\
0 & 13 & 6 & 0
\end{bmatrix}$
- remember any swap multiply det by -1, any raw scale multiply det by the inverse of the scale
- $\rightarrow \begin{bmatrix}
1 & 3 & 0 & 2 \\
0 & 13 & 5 & 7 \\
0 & 0 & 1 & 0 \\
0 & 13 & 6 & 0
\end{bmatrix}$
- $\rightarrow \begin{bmatrix}
1 & 3 & 0 & 2 \\
0 & 13 & 5 & 7 \\
0 & 0 & 1 & 0 \\
0 & 0 & 1 & -7
\end{bmatrix}$
- $\rightarrow \begin{bmatrix}
1 & 3 & 0 & 2 \\
0 & 13 & 5 & 7 \\
0 & 0 & 1 & 0 \\
0 & 0 & 0 & -7
\end{bmatrix}$
- $det(A) = 1(13)(1)(-7) = -91$
    - never swapped never scaled so det is the same
- $rank(A) = 4$
    - known from ref but also since $det(A) \neq 0; rank(A) = n = 4$
- $det(A^{-1}) = \frac {-1}{91}$
    - we atleast know it exists
    - also $rank(A^{-1}) = 4$
- $det(A^T) = 91$

## Proof using def of det
- need to pefine a matrix $B$ listing out the contents of each row then use def
- for proving ERO 3. Distrubute then show that the right hand sife is 0 by expanding around the row and the similar row. Note that there with be an oscillating sum where those two rows are switched therefore the right hand side is 0 so the left hand side (which matches $det(A)$) works QED

- 

# Questions
- ...
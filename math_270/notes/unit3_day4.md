# Reminder
- TH quiz next week thursday 5/4
- Exam 3 in 2 weeks 5/11
    - covers chapt 4, 5, 6
- review will be up weekend

# Final Piece of 4.6
- $F_\infty (\R)$ is infinite dimensional
- we will show $\{ 1, x, x^2, ..., x^n \}$ is linearly independent in $F_\infty (\R) \forall n$
- $W(x) = \begin{bmatrix} 1 & x & x^2 & \dots & x^n \\ 0 & 1 & 2x & \dots & nx^{n - 1} \\ \vdots & \vdots & \vdots & \ddots & \vdots \\ 0 & 0 & 0 & \dots & n! \end{bmatrix} = 1 (1) ... (n!) \neq 0$
- $W(x_0) \neq 0$ for any $x_0$, we only need a single $x_0$ there for functions are LI

# Change of Basis
- `thm`: let $B = \{ v_1 ... v_n \}$ be a basis for $V$. Then $v \in V$ has a unique representation in terms of $v_1 ... v_n$

## Proof
- assume $v = c_1 v_1 + ... + c_n v_n$ and $v = k_1 v_1 + ... + k_n v_n$
- NTS: $c_1 = k_1 ... c_n = k_n$
    - $c_1 v_1 + ... + c_n v_n = k_1 v_1 + ... + k_n v_n$
    - $(c_1 - k_1) v_1 + ... + (c_n - k_n) v_n = 0$
    - because basis & $= 0$ LI sp $c_1 - k_1 = c_n - k_n = 0$ $\Rightarrow c_1 = k_1, ..., c_n = k_n$

# Change of basis Matrix
- `def`: let $B = \{ v_1 ... v_n \}$ be a basis. Let $v = c_1 v_1 + ... + c_n v_n$. Then $[v]_B = \begin{bmatrix} c_1 \\ \vdots \\ c_n \end{bmatrix}$ be the representation of the $v$ in basis $B$
- `thm`: let $B = \{ v_1 ... v_n \}$ be a basis for $V$. Let $B_2$ be a basis for $V$. Then the matrix $A_{B_2 \leftarrow B_1} = \begin{bmatrix} [v_1]_{B_2} & \dots & [v_n]_{B_2} \end{bmatrix}$ is called the change of basis matrix
- then $\forall v \in V, A_{B_2 \leftarrow B_1} [v]_{B_1} = [v]_{B_2}$
    - **NOTE**: if you take the inverse of this matrix you get the change of basis the other way (ae. $(A_{B_2 \leftarrow B_1})^{-1} = A_{B_1 \leftarrow B_2}$)

## Example:
- let $V = M_2 (\R)$
- $B_1 = \{ \begin{bmatrix} 1 & 0 \\ 0 & 0 \end{bmatrix}, \begin{bmatrix} 0 & 1 \\ 1 & 0 \end{bmatrix}, \begin{bmatrix} 0 & 0 \\ 0 & 1 \end{bmatrix}, \begin{bmatrix} 0 & 1 \\ -1 & 0 \end{bmatrix} \}$
- $B_2 = \{ \begin{bmatrix} 1 & 0 \\ 0 & 0 \end{bmatrix}, \begin{bmatrix} 1 & 1 \\ 0 & 0 \end{bmatrix}, \begin{bmatrix} 1 & 1 \\ 1 & 0 \end{bmatrix}, \begin{bmatrix} 1 & 1 \\ 1 & 1 \end{bmatrix} \}$
- let $v = \begin{bmatrix} 3 & 3 \\ 1 & 4 \end{bmatrix}$
- Find $[v]_{B_1}$
    - $\left(\begin{array}{cccc|c} 1 & 0 & 0 & 0 & 3 \\ 0 & 1 & 0 & 1 & 3 \\ 0 & 1 & 0 & -1 & 1 \\ 0 & 0 & 1 & 0 & 4 \end{array}\right)$
    - to ref: $\left(\begin{array}{cccc|c} 1 & 0 & 0 & 0 & 3 \\ 0 & 1 & 0 & 1 & 3 \\ 0 & 0 & 1 & 0 & 4 \\ 0 & 0 & 1 & -2 & -2 \end{array}\right)$
    - $c_4 = 1, c_3 = 4, c_2 = 2, c_1 = 3$
    - $[v]_{B_1} = \begin{bmatrix} 3 \\ 2 \\ 4 \\ 1\end{bmatrix}$
        - this is the constant multiplied by element of basis at same index such that when summed you get $v$ out
- Find $A_{B_2 \leftarrow B_1} = \begin{bmatrix} [v_1]_{B_2} & [v_2]_{B_2} & [v_3]_{B_2} & [v_4]_{B_2} \end{bmatrix}$
    - those are column vectors
    - $[v_1]_{B_2} = \left(\begin{array}{cccc|c} 1 & 1 & 1 & 1 & 1 \\ 0 & 1 & 1 & 1 & 0 \\ 0 & 0 & 1 & 1 & 0 \\ 0 & 0 & 0 & 1 & 0 \end{array}\right)$
    - $\begin{bmatrix} 1 \\ 0 \\ 0 \\ 0 \end{bmatrix}$
    - $[v_2]_{B_2} = \left(\begin{array}{cccc|c} 1 & 1 & 1 & 1 & 0 \\ 0 & 1 & 1 & 1 & 1 \\ 0 & 0 & 1 & 1 & 1 \\ 0 & 0 & 0 & 1 & 0 \end{array}\right)$
    - $\begin{bmatrix} -1 \\ 0 \\ 1 \\ 0 \end{bmatrix}$
    - $[v_3]_{B_2} = \left(\begin{array}{cccc|c} 1 & 1 & 1 & 1 & 0 \\ 0 & 1 & 1 & 1 & 0 \\ 0 & 0 & 1 & 1 & 0 \\ 0 & 0 & 0 & 1 & 1 \end{array}\right)$
    - $\begin{bmatrix} 0 \\ 0 \\ -1 \\ 1 \end{bmatrix}$
    - $[v_1]_{B_2} = \left(\begin{array}{cccc|c} 1 & 1 & 1 & 1 & 0 \\ 0 & 1 & 1 & 1 & 1 \\ 0 & 0 & 1 & 1 & -1 \\ 0 & 0 & 0 & 1 & 0 \end{array}\right)$
    - $\begin{bmatrix} -1 \\ 2 \\ -1 \\ 0 \end{bmatrix}$
- $A_{B_2 \leftarrow B_1} = \begin{bmatrix} 1 & -1 & 0 & 0 \\ 0 & 0 & 0 & 2 \\ 0 & 1 & -1 & -1 \\ 0 & 0 & 1 & 0 \end{bmatrix}$
- **THIS WILL NOT BE ON IN CLASS PORTION**
- Use $[v]_{B_1}$ to determine $[v]_{B_2}$
    - $[v]_{B_2} = A_{B_2 \leftarrow B_1} \cdot [v]_{B_1}$
    - $[v]_{B_2} = \begin{bmatrix} 1 & -1 & 0 & 0 \\ 0 & 0 & 0 & 2 \\ 0 & 1 & -1 & -1 \\ 0 & 0 & 1 & 0 \end{bmatrix} \cdot \begin{bmatrix} 3 \\ 2 \\ 4 \\ 1 \end{bmatrix} = \begin{bmatrix} 0 \\ 2 \\ -3 \\ 4 \end{bmatrix}$
    - if you have different basis, they're all conncted by a matrix multiplication
    - if you have an vector in $B_1$ you can make it in $B_2$ by a matrix multiplication instead of setting up the system of linear equations

# Section 4.8 Rowspace, Colspace, Nullspace
- Let $A$ be and $m \times n$ matrix
- `def`: 
    - $rowspace(A)$ is span of rows, subspace of $\R^n$
    - $colspace(A)$ is span of columns, subspace of $\R^m$
    - $nullspace(A)$ is sols to $Ax=0$, subspace of $\R^n$
    - note: $\dim (nullspace(A))$ is called the $nullity(A)$
    - $\dim (rowspace(A)) = \dim (colspace(A)) = rank(A)$
- How to find basis:
    - row: put $A$ into ref use non-zero rows
    - col: put $A$ into ref, use **ORIGINAL** cols corresponding to pivot position
    - null: put $A$ into ref and solve the homogenous system

## Example
- $A = \begin{bmatrix} 1 & 0 & 2 & 1 & 1 \\ 2 & 0 & 5 & 1 & 1 \\ 2 & 0 & 4 & 2 & 2 \\ 0 & 0 & 1 & -1 & 0\end{bmatrix}$
- determine basis for rowspace
    - ref: $\begin{bmatrix} 1 & 0 & 2 & 1 & 1 \\ 0 & 0 & 1 & -1 & -1 \\ 0 & 0 & 0 & 0 & 1 \\ 0 & 0 & 0 & 0 & 0\end{bmatrix}$
    - basis: $\{ \begin{bmatrix} 1 & 0 & 2 & 1 & 1 \end{bmatrix}, \begin{bmatrix} 0 & 0 & 1 & -1 & -1 \end{bmatrix}, \begin{bmatrix} 0 & 0 & 0 & 0 & 1 \end{bmatrix}\}$
- give dimension for rowspace
    - 3
- determine basis for colspace
    - $\{ \begin{bmatrix} 1 \\ 2 \\ 2 \\ 0 \end{bmatrix}, \begin{bmatrix} 2 \\ 5 \\ 4 \\ 1 \end{bmatrix}, \begin{bmatrix} 1 \\ 1 \\ 2 \\ 0 \end{bmatrix} \}$
- give dimension for colspace
    - 3
- determine basis for nullspace
    - $\left(\begin{array}{ccccc|c} 1 & 0 & 2 & 1 & 1 & 0 \\ 0 & 0 & 1 & -1 & -1 & 0 \\ 0 & 0 & 0 & 0 & 1 & 0 \\ 0 & 0 & 0 & 0 & 0 & 0\end{array}\right)$
    - $x_5 = 0, x_4 = t, x_3 = t, x_2 = s, x_1 = -3t$
    - $nullpsace(A) = \begin{bmatrix} -3t \\ s \\ t \\ t\\ 0 \end{bmatrix}$
    - basis: $\{ \begin{bmatrix} 0 \\ 1 \\ 0 \\ 0\\  0 \end{bmatrix}, \begin{bmatrix} -3 \\ 0 \\ 1 \\ 1\\  0 \end{bmatrix} \}$
        - just did gen elem thing
- give dimension for nullspace
    - 2

- $\dim (row) = \dim (col) = rank(A)$
- $rank(A) + nullity = n$ where $n$ is number vars/cols

# Section 4.9 Rank Nullity Thm
- `thm`: let $A$ be $m \times n$. Then $rank(A) + nullity(A) = n$

## Proof
- recall from cahpter 2 $Ax = 0$
    - has unique solution in $rank(A) = n$ that's $(x = 0)$
    - has inf sol with $n - rank(A)$ free param if $rank(A) < n$
- case 1: assume $rank(A) = n$
    - then $Ax = 0$ has unique sol $x = 0$ which means $nullsapce(A) = \{ \vec 0 \}$
    - $nullity(A) = 0$
    - $rank(A) + nullity(A) = n + 0 = n$
- case 2: assume $rank(A) < n$
    - then $Ax = 0$ has infinite solution with $n - rank(A)$ free param
    - $nullity(A) = n - rank(A)$
    - $rank(A) + nullity(A) = rank(A) + n - rank(A) = n$

## 2 follow-ups
- `thm`: $Ax = b$ is consistent $\Leftrightarrow b \in colspace(A)$
- `thm`: suppose $Ax = b$ has solutions. Further suppose $x_p$ is a solution and $x_1 ... x_k$ are a basis for $Ax = 0$. Then every solution for $Ax = b$ can be wriiten as $x = x_p + c_1 x_1 + ... + c_k v_k$

## Example
- consider the system of equations: $\left(\begin{array}{ccccc|c} 1 & 2 & 0 & 1 & 1 & 1 \\ 1 & 3 & 1 & 1 & 2 & 3 \\ 2 & 4 & 0 & 2 & 3 & 5 \end{array}\right)$
- ref: $\left(\begin{array}{ccccc|c} 1 & 2 & 0 & 1 & 1 & 1 \\ 0 & 1 & 1 & 0 & 1 & 2 \\ 0 & 0 & 0 & 0 & 1 & 3 \end{array}\right)$
- nullspace: $\begin{bmatrix} 2t - s \\ -1 -t \\ t \\ s \\ 3 \end{bmatrix}$
- particular sol: $\begin{bmatrix} 0 \\ -1 \\ 0 \\ 0 \\ 3 \end{bmatrix} + \begin{bmatrix} 2t \\ -t \\ t \\ 0 \\ 0 \end{bmatrix} + \begin{bmatrix} -s \\ -1 \\ 0 \\ 0 \\ 3 \end{bmatrix}$
# Reminders
- TH Quiz 4 this thursday
- Exam 4 & TH Exam 4 next thursday
- sug ex: 7.1,7.2,8.1-8.3,8.7,8.8,9.1-9.4

# Section 9.1 1st Order Linear Systems
- $\frac{dx_1}{dt} = a_{11}(t)x_1(t) + \dots + a_{1n}(t)x_n(t) + b_1(t)$ 
- $\vdots$
- $\frac{dx_n}{dt} = a_{n1}(t)x_1(t) + \dots + a_{nn}(t)x_n(t) + b_n(t)$
    - homogenuos if $b_1(t) = \dots = b_n(t) = 0$
- `def`: a sol to a system of DE is $x_1(t) \dots x_n(t)$ that makes eery solution true $\forall t$
- `def`: an IVP for a 1st order system is a set of initial conditions $x_1(t_0) = \alpha_1, \dots, x_n(t_0) = \alpha_n$

### Example
- $x_1'(t) = 3x_1(t) + 4x_2(t)$
- $x_2'(t) = x_1(t) + 3x_2(t)$
- $x_1(0) = 1, x_2(0) = 2$
- rewrite:
    - $x_1'(t) - 3x_1(t) - 4x_2(t) = 0$
    - $- x_1(t) + x_2'(t) - 3x_2(t) = 0$
- now in diff op notation
    - $(D-3)(x_1) - 4x_2 = 0$
    - $-x_1 + (D-3)(x_2) = 0$
- to eliminate need a term to be the same, apply $(D-3)$ to eq 2
    - $(D-3)(x_1) - 4x_2 = 0$
    - $-(D-3)(x_1) + (D-3)^2(x_2) = 0$
- adding them:
    - $((D-3)^2 - 4)(x_2) = 0$
- expanded:
    - $(D^2 - 6D + 5)(x_2) = 0$
    - $(D-1)(D-5)(x_2) = 0$
    - $x_2 = c_1 e^t + c_2e^{5t}$
- solve for $x_1$ by plugging into eq 2
    - $c_1 e^t + 5c_2e^{5t} = x_1(t) + 3(c_1 e^t + c_2e^{5t})$
    - $-2 c_1 e^t + 2c_2 e^{5t} = x_1(t)$
- plugging into original for the IVP
    - $1 = -2c_1 + 2c_2$
    - $2 = c_1 + c_2$
    - $c_2 = \frac {5}{4}$
    - $c_1 = \frac {3}{4}$
- sol:
    - $x_1(t) = -\frac{3}{2} e^t + \frac{5}{2}e^{5t}$
    - $x_2(t) = \frac{3}{4} e^t + \frac{5}{4}e^{5t}$
- $x'(t) = \begin{bmatrix} 3 & 4 \\ 1 & 3 \end{bmatrix} x(t)$
- $x(t) = \begin{bmatrix} x_1(t) \\ x_2(t) \end{bmatrix}$
- $x(0) = \begin{bmatrix} 1 \\ 2 \end{bmatrix}$
- $x(t) = e^t \begin{bmatrix} \frac {-3}{2} \\ \frac{3}{4} \end{bmatrix} + e^{5t} \begin{bmatrix} \frac{5}{2} \\ \frac{5}{4} \end{bmatrix}$

# 9.2 Vector Formulation
- A 1st order system of linear DE can be written in `vector form` as: $x'(t) = A(t) x(t) + b(t)$
    - $A(t)$ is an $n \times n$ matrix function
    - all other are $n \times 1$ column vector functions
    - the system mis homogenous if $b(t) = \vec 0$
    - IVp has intial conditon $x(t_0) = \vec \alpha$
    - **NOTE**: $x(t)$ is a $n \times 1$ column vector function. We say $x(t) \in V_n(\R)$ which is the vector space of all $n \times 1$ column vector functions
`def`: let $\vec x_1(t), \vec x_2(t), \dots, \vec x_n(t) \in V_n(\R)$. Then the `Wronskian` of $\vec x_1, \dots, \vec x_n$ is $W(\vec x_1, \vec x_2, \dots, \vec x_2)(t) = \det(\begin{bmatrix} \vec x_1(t) & \vec x_2(t) & \dots & \vec x_n(t) \end{bmatrix})$
- `thm`: $W(\vec x_1, \vec x_2, \dots, \vec x_2)(t_0) \ne 0 \Rightarrow \vec x_1, \dots, \vec x_n$ are LI in $V_n(\R)$

### Proof
- assume $W(\vec x_1, \dots, \vec x_n)(t_0) \ne 0$
- NTS: $\vec x_1, \dots, \vec x_n$ are LI in $V_n(\R)$
- NTS: $c_1 \vec x_1 + \dots + c_n \vec v_n = \vec 0 \Rightarrow c_1 = \dots = c_n = 0$
- Let $c_1 \vec x_1 + c_n \vec x_n = \vec 0$
- $\begin{bmatrix} \vec x_1 & \dots & \vec x_n \end{bmatrix} \begin{bmatrix} c_1 \\ \vdots \\ c_n \end{bmatrix} = \begin{bmatrix} 0 \\ \vdots \\ 0 \end{bmatrix}$
- consider this at $t = t_0$
- $\det(\begin{bmatrix} \vec x_1 & \dots & \vec x_n \end{bmatrix}) \ne 0$ by assumption
    - so this matrix has full rank
    - so system has unique sol
    - sol must be $c_1 =  \dots = c_n = 0$

# 9.3 Results on Systems
- `EU thm` for 1st order linear systems
    - $\vec x'(t) = A(t) \vec x(t) + \vec b(t)$
    - $\vec x(t_0) = \vec \alpha$
    - $A(t), \vec b(t)$ continuous $\Rightarrow$ unique sol
- `thm`: $\vec x'(t) = A(t) \vec x(t)$
    - then to sol space is a dimension $n$ subspace of $V_n(\R)$

### Proof
- thm: $\vec x'(t) = A(t) \vec x(t)$
- NTS: sol set is a dimension $n$ subspace of $V_n(\R)$
- subspace
    - $\vec x'(t) = A(t) \vec x(t)$
    - $\vec x'(t) - A(t) \vec x(t) = 0$
    - $(D-A(t))(x(t)) = 0$
    - let $T$ be the transformation $T = D - A(t)$
        - it is clear that $T$ is linear
    - sol set = $ker(T)$
    - $ker(T)$ is a known subspace thus sol set is subspace
- dimension
    - consider the following IVPs
    - $\vec x'(t) = A(t) \vec x(t)$
        - $\vec x(t_0) = \vec e_1, \dots, \vec x(t_0) = \vec e_n$
            - $e_n$ are the col vectors that have a 1 in the ith position and 0's every where else
    - EU thm tells us each has unique sol
        - sols: $\vec x_1(t), \dots, \vec x_n(t)$
    - claim $\vec x_1(t), \dots, \vec x_n(t)$ is a basis for sol space
    - NTS: $\vec x_1(t), \dots, \vec x_n(t)$ are LI
        - $W(\vec x_1, \dots, \vec x_n)(t) = \det( \begin{bmatrix} \vec x_1(t) & \dots & \vec x_n(t) \end{bmatrix})$
        - consider $t=t_0$
        - $W(\vec x_1, \dots, \vec x_n)(t) = \det( \begin{bmatrix} e_1 & \dots & \vec e_n \end{bmatrix})$
        - $W(\vec x_1, \dots, \vec x_n)(t) = I_n = 1 \ne 0$
        - LI
    - NTS: $\vec x_1(t), \dots, \vec x_n(t)$ is a spanning set
    - let $\vec u(t)$ be a sol to $\vec x'(t) = A(t) \vec x(t)$
    - NTS: $\vec u(t) = c_1 \vec x_1(t) + \dots + c_n \vec x_n(t)$
    - consider the IVP: $\vec x'(t) = A(t) \vec x(t)$ with $\vec x(t_0) = \vec u(t_0)$
        - it should be clear $\vec u(t)$ is a sol
    - Recall: $\vec x_1(t) = e_1, \dots, \vec x_n(t) = e_n$
        - since $e_1, \dots, e_n$ form a basis for $\R^n$,  $\exists c_1 \dots c_n: \vec u(t_0) = c_1 e_1 + \dots + c_n e_n$
    - consider then $c_1 \vec x_1(t) + \dots + c_n \vec x_n(t)$ is also a sol to IVP
    - because EU: $\vec u(t) = c_1 \vec x_1(t) + \dots + c_n \vec x_n(t)$
    - $QED$

## Corollaries
- $\vec x'(t) = A(t) \vec x(t) + b(t)$
    - has general sol: $\vec x(t) = c_1 \vec x_1 (t) + \dots + c_n \vec x_n (t) + \vec x_p (t)$
    - where $\vec x_1, \dots, \vec x_n$ are a basis to the homogenous and $\vec x_p$ is a particular sol

# 9.4 Constant coefficient systems
- $\vec x'(t) = A \vec x(t)$
- let $A$ have eigenvalue $\lambda$ and eigenvector $\vec v$
    - ae $A \vec v = \lambda \vec v$
- consider $\vec x(t) = e^{\lambda t} \vec v$
- claim its a solution to the system
- lhs $\vec x'(t) = \lambda e^{\lambda t} \vec v$
- rhs $A \vec x(t) = Ae^{\lambda t} \vec v \equiv e^{\lambda t} \lambda \vec v$
- works for non-defective matrices

### Example
- consider the system:
    - $\vec x(t) = \begin{bmatrix} 2 & 1 & 2 \\ 1 & 2 & 2 \\ 1 & 1 & 3 \end{bmatrix} \vec x_t$
    - equiv expanded:
        - $x_1'(t) = 2x_1(t) + x_2(t) + 2x_3(t)$
        - $\vdots$
- find $\lambda$
    - $\det (\begin{bmatrix} 2 & 1 & 2 \\ 1 & 2 & 2 \\ 1 & 1 & 3 \end{bmatrix}) = 0$
    - by cofactor expansion: $\lambda ^3 - 7 \lambda ^2 + 11 \lambda - 5 = 0$
    - by factoring/polynomial division: $(\lambda - 1)^2(\lambda - 5) = 0$
- find $v$
    - $\lambda = 1$
        - $\left(\begin{array}{ccc|c} 1 & 1 & 2 & 0 \\ 1 & 1 & 2 & 0 \\ 1 & 1 & 2 & 0 \end{array}\right)$
        - $\vec v_1 = \begin{bmatrix} -t - 2s \\ t \\ s \end{bmatrix}$
    - $\lambda = 5$
        - $\left(\begin{array}{ccc|c} -3 & 1 & 2 & 0 \\ 1 & -3 & 2 & 0 \\ 1 & 1 & -2 & 0 \end{array}\right)$
        - $\vec v_5 = \begin{bmatrix} t \\ t \\ t \end{bmatrix}$
- because non-defective
    - gen sol: $\vec x(t) = c_1 e^t \begin{bmatrix} -1 \\ 1 \\ 0 \end{bmatrix} + c_2 e^t \begin{bmatrix} -2 \\ 0 \\ 1 \end{bmatrix} + c_3 e^{5t} \begin{bmatrix} 1 \\ 1 \\ 1 \end{bmatrix}$
        - this was basis to $\vec v_\lambda \cdot e^{\lambda t} $

# Basic aug
- $\left(\begin{array}{c}\end{array}\right)$
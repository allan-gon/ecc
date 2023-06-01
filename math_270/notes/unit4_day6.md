# Reminders
- TH Exam 4
- Review Guide

## Summary of 9.1-9.3
- `system of linear DE`: vector form $\vec x'(t) = A(t) \vec x(t) + \vec b(t)$
    - $A(t)$ constant coefficient
    - $\vec b(t) = \vec 0$
- if `homogenous`, the solution set is a dimension $n$ subspace of $V_n(\R)$
- `general solution` to $\vec x'(t) = A(t) \vec x(t) + \vec b(t)$ is:
    - $\vec x(t) = c_1 \vec x_1(t) + \dots + c_n \vec x_n(t) + \vec x_p(t)$
- `EU thm`: IVP
    - $\vec x'(t) = A(t) \vec x(t) + \vec b(t)$
    - $\vec x(t_0) = \vec \alpha$
    - then as long as $A(t), \vec b(t)$ are continuous $\exists$ a unique solution

## Summary of 9.4
- constant coeff homogenous: $\vec x'(t) = A \vec x(t)$
- `thm`: if $A$ is *non-defective* then the basis for the solution space coomes from elements of the form:
    - $e^{\lambda t}v$ 
        - with $\lambda$ the *eigenvalues* and $v$ LI *eigenvectors*
    - the LI comment is because an eigenvalue can have multiple eigenvectors so just make sure to get one from each eigenvalue

### Example
- $x_1'(t) = x_1(t) + 3x_2(t)$
- $x_2'(t) = 4x_1(t) + 5x_2(t)$
- find gen sol
- vector form:
    - $\begin{bmatrix} 1 & 3 \\ 4 & 5 \end{bmatrix} \begin{bmatrix} x_1 \\ x_2 \end{bmatrix} = \begin{bmatrix} 0 \\ 0 \end{bmatrix}$
    - $\vec x'(t) = \begin{bmatrix} 1 & 3 \\ 4 & 5 \end{bmatrix} \vec x(t)$
- find eigenvalues
    - $\det (\begin{bmatrix} 1 - \lambda & 3 \\ 4 & 5 - \lambda \end{bmatrix}) = 0$
    - $(1 - \lambda)(5 - \lambda) - (3)(4) = 0$
    - $\lambda = 7, -1$
- find eigenvectors
    - $\left(\begin{array}{cc|c} 1 - \lambda & 3 & 0 \\ 4  & 5 - \lambda  & 0 \end{array}\right)$
    - $\lambda = 7$
    - $E_7 = \{ \begin{bmatrix} \frac{1}{2}t \\ t \end{bmatrix} \}$
    - $\lambda = -1$
    - $E_{-1} = \{ \begin{bmatrix} \frac{-3}{2}t \\ t \end{bmatrix} \}$
- gen sol: $\vec x(t) = c_1 e^{7t} \begin{bmatrix} \frac{1}{2} \\ 1 \end{bmatrix} + c_2 e^{-t} \begin{bmatrix} \frac{-3}{2} \\ 1 \end{bmatrix}$

# Complex Eigenvalues
- come in complex conjugate pairs, true for eigenvectors too
- `thm`: if $\vec w_1(t) = \vec u(t) + i \vec v(t), \vec w_2(t) = \vec u(t) - i \vec v(t)$ are both sol to homogenous linear system, then $\vec u(t)$ and $\vec v(t)$ are sols

### Proof
- Recall solution set is a subspace (ae. closed under $\oplus, \odot$)
- $\frac {1}{2} (\vec w_1(t) + \vec w_2(t)) = \vec u(t) \Rightarrow \vec u(t)$ is a sol
- $\frac {-1}{2} i (\vec w_1 - \vec w_2) = \vec (t) \Rightarrow \vec v(t)$ is a sol

## Notes cont

- Now suppose we have $\lambda = a + bi$ with $\vec v = \vec r + i \vec s$
    - and complex conjugate pair
- yeilds sols:
    - $e^{(a + bi)t} (\vec r + i \vec s)$
        - $\Rightarrow (e^{at} (\cos(bt) + i \sin(bt)))(\vec r + i \vec s)$
        - $\Rightarrow e^{at}((\cos(bt) + i \sin(bt))(\vec r + i \vec s))$
        - $\Rightarrow e^{at} ((\cos(bt) \vec r - \sin(bt) \vec s) + (\cos(bt) \vec s + \sin(bt) \vec r) i)$
    - $\vec u(t) = e^{at} (\cos(bt) \vec r - \sin(bt) \vec s)$
    - $\vec v(t) = e^{at} (\cos(bt) \vec s + \sin(bt) \vec r)$

### Example
- $\vec x'(t) = \begin{bmatrix} 1 & 1 \\ -2 & 3 \end{bmatrix} \vec x(t)$
- find $\lambda$
    - $\lambda = 2 \pm i$
- choose one of the pair to work on. chose $\lambda = 2 + i$
- find $v$
    - $E_{2 + i} = \{ \begin{bmatrix} (\frac {1}{2} - \frac{1}{2} i)t \\ t \end{bmatrix} \}$
    - $(\begin{bmatrix} \frac{1}{2} \\ 1 \end{bmatrix} + \begin{bmatrix} - \frac {1}{2} \\ 0 \end{bmatrix} i) t$
- sol:
    - $\vec x(t) = c_1 e^{2t}(\cos(t) \begin{bmatrix} \frac{1}{2} \\ 1 \end{bmatrix} - \sin(t) \begin{bmatrix} - \frac{1}{2} \\ 0 \end{bmatrix}) + c_2 e^{2t}(\cos(t) \begin{bmatrix} - \frac{1}{2} \\ 0 \end{bmatrix}) + \sin(t) \begin{bmatrix} \frac{1}{2} \\ 1 \end{bmatrix}$
- **NOTE**: easier to write solution if explicitly write $a, b, \vec r, \vec s$

# Section 9.5 Defective Coefficient Matrix
- means: $\exists \lambda: \dim(E_\lambda) <$ multiplicity $\lambda$
- `generalized eigenvector`: of order $n$ is a vector $\vec u : (A - \lambda I_n)^n \vec u = \vec 0$ and $(A - I_n)^k \vec u \ne \vec 0$ for $k < n$ 
    - $(A - \lambda I_n) \vec u = \vec v$

- `thm`: additional LI sols can be found as follows:
    - Let $\vec v$ be an eigenvector with eigenvalue $\lambda$
    - let $\vec v_k$ be the generalized kth order eigenvector
        - $e^{\lambda t} \vec v$
        - $e^{\lambda t}(\vec v_2 + t \vec v)$
        - $e^{\lambda t} (\vec v_3 + t \vec v_2 + \frac{1}{2} t^2 \vec v)$
        - $\vdots$
        - $e^{\lambda t}(\vec v_k + t \vec v_{k-1} + \dots + \frac {1}{(k - 1)!} t^{k-1} \vec v)$

### Example
- $\vec x'(t) = \begin{bmatrix} 3 & 2 \\ -2 & -1 \end{bmatrix} \vec x(t)$
- find $\lambda$
    - $\lambda = 1$ multiplicity 2
- find $\vec v$
    - $E_{-1} \{ \begin{bmatrix} -t \\ t \end{bmatrix} \}$
    - $\dim (E_{-1}) <$ multiplicity $-1$
- defective. missing 1 eigenvector so find the generalized 2nd order eigenvector
    - $(A - \lambda I_n)^2 \vec u = 0$ BUT ALSO $(A - \lambda I_n) \vec u \ne \vec 0$
    - $(A - \lambda I_n)^2 = \begin{bmatrix} 2 & 2 \\ -2 & -2 \end{bmatrix} \cdot \begin{bmatrix} 2 & 2 \\ -2 & -2 \end{bmatrix} = \begin{bmatrix} 0 & 0 \\ 0 & 0 \end{bmatrix}$
    - $\left(\begin{array}{cc|c} 0 & 0 & 0 \\ 0 & 0 & 0 \end{array}\right)$
    - potential order 2 eigenvectors $= \{ \begin{bmatrix} t \\ s \end{bmatrix} \}$
        - choose order 2 by avoiding order 1
    - $\vec u = \begin{bmatrix} 1 \\ 0 \end{bmatrix}$
        - now find correspoding order 1
    - $(A - \lambda I_n) \cdot \vec u = \begin{bmatrix} 2 & 2 \\ -2 & -2 \end{bmatrix} \cdot \begin{bmatrix} 1 \\ 0 \end{bmatrix} = \begin{bmatrix} 2 \\ -2 \end{bmatrix}$
- sol:
    - $\vec x(t) = c_1 e^t \begin{bmatrix} 2 \\ -2 \end{bmatrix} + c_2 e^t (\begin{bmatrix} 1 \\ 0 \end{bmatrix} + t \begin{bmatrix} 2 \\ -2 \end{bmatrix})$
        - const times order one + const times order 2

### Example
- $\vec x'(t) = \begin{bmatrix} 1 & 1 & 1 & 0 \\ 0 & 1 & 0 & 1 \\ 0 & 0 & 1 & 1 \\ 0 & 0 & 0 & 1 \end{bmatrix} \vec x(t)$
- find eigenvalues
    - $(1 -\lambda)^4 = 0$
    - $\lambda = 1$ multiplicity 4
- find $\vec v$
    - $E_1 = \{ \begin{bmatrix} t \\ -s \\ s \\ 0 \end{bmatrix} \}$
    - defective
- missing 2 eigenvectors so need 3rd order
- well kind of, could be order 3 and 1 or order 2 and 2
    - $(A - \lambda I_n)^2 \vec u = 0$ but $(A - \lambda i_n) \ne \vec 0$
    - $(A - \lambda I_n)^2 = \begin{bmatrix} 0 & 1 & 1 & 0 \\ 0 & 0 & 0 & 1 \\ 0 & 0 & 0 & 1 \\ 0 & 0 & 0 & 0 \end{bmatrix} \cdot \begin{bmatrix} 0 & 1 & 1 & 0 \\ 0 & 0 & 0 & 1 \\ 0 & 0 & 0 & 1 \\ 0 & 0 & 0 & 0 \end{bmatrix} = \begin{bmatrix} 0 & 0 & 0 & 2 \\ 0 & 0 & 0 & 0 \\ 0 & 0 & 0 & 0 \\ 0 & 0 & 0 & 0 \end{bmatrix}$
    - $\left(\begin{array}{cccc|c} 0 & 0 & 0 & 2 & 0 \\ 0 & 0 & 0 & 0 & 0 \\ 0 & 0 & 0 & 0 & 0 \\ 0 & 0 & 0 & 0 & 0 \end{array}\right)$
    - potential order 2: $\{ \begin{bmatrix} t \\ s \\r \\ 0 \end{bmatrix} \}$
        - somehow this signifies need order 3
            - luckily avoiding the potential order 2 and order 1 will yeild the order 3
    - chose: $\vec u_3 = \begin{bmatrix} 0 \\ 0 \\ 0 \\ 1 \end{bmatrix}$
    - find $\vec u_2$
        - by $(A - \lambda I_n) \cdots \vec u_3$
        - $\vec u_2 = \begin{bmatrix} 0 \\ 1 \\ 1 \\ 0 \end{bmatrix}$
    - find $\vec u_1$
        - by $(A - \lambda I_n) \cdot \vec u_2$
        - $\vec u_1 = \begin{bmatrix} 2 \\ 0 \\ 0 \\ 0 \end{bmatrix}$
- sol:
    - $c_1 e^t \begin{bmatrix} 2 \\ 0 \\ 0 \\ 0 \end{bmatrix} + c_2 e^t (\begin{bmatrix} 0 \\ 1 \\ 1 \\ 0 \end{bmatrix} + t \begin{bmatrix} 2 \\ 0 \\ 0 \\ 0 \end{bmatrix}) + c_3 e^t(\begin{bmatrix} 0 \\ 0 \\ 0 \\ 1 \end{bmatrix} + t \begin{bmatrix} 0 \\ 1 \\ 1 \\ 0 \end{bmatrix} + \frac{1}{2} t^2 \begin{bmatrix} 2 \\ 0 \\ 0 \\ 0 \end{bmatrix}) + c_4 e^t \begin{bmatrix} 0 \\ -1 \\ 1 \\ 0 \end{bmatrix}$

# Questions for OH 
- how do i know need order 3

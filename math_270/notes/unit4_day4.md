# Reminders
- TH Quiz due next thursday
    - can do Q1-Q4, EC 1 & 2
- TH Exam due 6/8
    - can do Q1, Q2
- Sug ex
    - 8.1-8.3, 8.7, 8.8, 7.1, 7.2
- Exam 4 on 6/8
- Review guide is up

# Section 8.8 Cauchy Euler DE
- `Cauchy Euler`: $x^n y^{(n)} + a_{n - 1} x^{n - 1} y^{(n - 1)} + \dots + a_1 x y' + a_0 y = F(x)$
    - substitute: $x = e^z; z = \ln|x|$
    - $xy' = \frac {dy}{dz} = D$
        - in terms of $z$
    - $x^2 y'' = D (D - 1)$
    - $\vdots$
    - $x^n y^{(n)} = D(D - 1) \dots (D - (n - 1))$

### Homogenous Example
- find gel sol to: $x^4 y^{(4)} + 4x^3 y''' + 3x^2 y'' -xy' + y = 0$
- substitute: $(D(D - 1)(D - 2)(D - 3) + 4D(D - 1)(D - 2) + 3D(D - 1) - D + 1)y = 0$
    - $\Rightarrow (D(D - 1)(D - 2)(D - 3) + 4D(D - 1)(D - 2) + 3D(D - 1) - (D - 1))y = 0$
    - $\Rightarrow ((D - 1)(D(D-2)(D-3) + 4D(D-2) + 3D - 1))y = 0$
    - $\Rightarrow (D-1)(D^3 - 5D^2 + 6D + 4D^2 - 8D + 3D -1)y = 0$
    - $\Rightarrow (D-1)(D^3 - D^2 + D - 1)y = 0$
    - $\Rightarrow (D-1)(D^2(D-1)+1(D-1))y = 0$
    - $\Rightarrow (D-1)^2(D^2 +1)y = 0$
- roots:
    - $1$ multiplicity $2$
    - $\pm i$
- $y = c_1 e^z + c_2 ze^z + c_3 \cos(z) + c_4 \sin(z)$
- undo substitution: $y = c_1 x + c_2 \ln |x|x + c_3 \cos(\ln|x|) + c_4 \sin(\ln|x|)$

### Non-homogenous Example
- $x^2 y'' - 6y = 5x^3$
- start with homogenous
    - $(D(D-1) - 6)y = 0$
    - $(D^2 - D - 6)(y) = 0$
- roots:
    - $3$
    - $1$
- $y_H = c_1 e^{3z} + c_2 e^{-2z}$
- substitute back: $y_H = c_1 x^3 + c_2 x^{-2}$
- for $y_P$ put in linear standard form (leading y derivative is empty)
- LSF: $y'' - \frac{6}{x^2} y = 5x$
- VOP: $\left(\begin{array}{cc|c} x^3 & x^{-2} & 0 \\ 3x^2 & -2x^{-3} & 5x \end{array}\right)$
- first row is basis for $y_H$
    - to ref: $\left(\begin{array}{cc|c} x^3 & x^{-2} & 0 \\ 0 & 1 & -x^4 \end{array}\right)$
    - $u_2 ' = -x^4$
    - $u_1 ' = \frac{1}{x}$
- $u_2 = \frac{-1}{5} x^5$
- $u_1 = \ln|x|$
- $y_P = \ln|x|x^3 + \frac{-1x^3}{5}$
- $y = c_1 x^3 + c_2 x^{-2} + \ln|x|x^3 + \frac{-1}{5} x^3$
- $y = c_1 ^* x^3 + c_2 x^{-2} + \ln|x|x^3$

# Sections 7.1 & 7.2
- Question: Let $A$ be an $n \times n$ matrix
    - Consider vectors $v: Av = \lambda v$ with $\lambda$ a scalar.
    - the vector simply becomes a scalar multiple of it self
- `def`: let $A$ be an $n \times n$ matrix. Let $v$ be and $n \times 1$ vector. let $\lambda$ be a scalar. If $Av = \lambda v$ then $\lambda$ is said to be an `eigenvalue` with `eigenvector` $v$

## How to Determine $\lambda, v$
- $Av = \lambda v$
- $Av - \lambda v = 0$
- $Av - \lambda I_n v = 0$
- $(A - \lambda I_n)v = 0$
    - rank must be non-full for non trivial sol
    - can check if $\det (A - \lambda I_n) = 0$
- eigenvalues are exactly the sols to $\det (A - \lambda I_n) = 0$
- **Matrix $A$ has eigencalues $\lambda \Leftrightarrow \det (A - \lambda I_n) = 0$**

### Example
- $A = \begin{bmatrix} 5 & 1 \\ 1 & 5 \end{bmatrix}$
- $A - \lambda I_n = \begin{bmatrix} 5 & 1 \\ 1 & 5 \end{bmatrix} - \lambda \begin{bmatrix} 1 & 0 \\ 0 & 1 \end{bmatrix}$
    - $\Rightarrow \begin{bmatrix} 5 - \lambda & 1 \\ 1 & 5 - \lambda \end{bmatrix}$
- $\det = (5-\lambda)^2 - 1 = 0$
    - $\Rightarrow 25 - 10 \lambda + \lambda ^2 + 1 = 0$
- $\lambda = 4, \lambda = 6$
- egienvectors: solve for $v$ since we have $\lambda$
    - $\lambda = 4: \left(\begin{array}{cc|c} 1 & 1 & 0 \\ 1 & 1 & 0 \end{array}\right)$
    - got this by $A - \lambda I_n$ and augmenting $0$, solving will result in eigenvector
- for $\lambda = 4$ eigenvectors: $\{ \begin{bmatrix} -t \\ t \end{bmatrix} \}$
- $\lambda = 6: \left(\begin{array}{cc|c} -1 & 1 & 0 \\ 1 & -1 & 0 \end{array}\right)$
- for $\lambda = 6$, eigenectors: $\{ \begin{bmatrix} t \\ t \end{bmatrix} \}$

## Additional Def + Conceptual Results
- suppose we have $A$ with eigenvalue $\lambda$
then we define the `eigenspace` for $\lambda$ as $E_{\lambda} = \{ v: Av = \lambda v \}$
    - $E_\lambda$ is a subspace of $\R^n (\Complex^n)$
    - $A$ is composed for real numbrs but the eigenvalues may be complex
- `thm`: $\dim (E_\lambda) \le$ multiplicity of $\lambda$
- `non-defective` : matrix $A$ is said to be non-defective is $\dim(E_\lambda) =$ multiplicity of $\lambda$ for all eigenvalues. Otherwise $A$ is said to be defective

### Example
- $A = \begin{bmatrix} 3 & 1 \\ -1 & 5 \end{bmatrix}$
- determive all eigenvalues, vectors, dimension of all eigenspaces, and state if $A$ is defective
- eigenvalues
    - $\begin{bmatrix} 3 - \lambda & 1 \\ -1 & 5 - \lambda \end{bmatrix}$
    - $(3 - \lambda)(5 - \lambda) - (1)(-1) = 0$
    - $\lambda^2 -8 \lambda + 16 = 0$
    - $\lambda = 4$ multiplicity 2
- eigenvectors
    - $\left(\begin{array}{cc|c} -1 & 1 & 0 \\ -1 & 1 & 0 \end{array}\right)$
    - eigenvectors: $\{ \begin{bmatrix} t \\ t \end{bmatrix} \}$
- $\dim(E_4) = 1$
- $A$ is defective

### Example
- $A = \begin{bmatrix} 1 & 1 & 2 \\ 0 & 2 & 2 \\ 0 & 1 & 3 \end{bmatrix}$
- eigenvalues
    - $\begin{bmatrix} 1 - \lambda & 1 & 2 \\ 0 & 2 - \lambda & 2 \\ 0 & 1 & 3 - \lambda \end{bmatrix}$
    - **NEED**: cofactor expansion
    - $(1 - \lambda) \begin{bmatrix} 2 - \lambda & 2 \\ 1 & 3 - \lambda \end{bmatrix}$
        - expanded along col 1 because 0's
    - $(1 - \lambda)(\lambda - 1)(\lambda - 4) = 0$
    - $\lambda = 1$ multiplicity 2
    - $\lambda = 4$
- eigenvectors
    - $\lambda = 1, \left(\begin{array}{ccc|c} 0 & 1 & 2 & 0 \\ 0 & 1 & 2 & 0 \\ 0 & 1 & 2 & 0 \end{array}\right)$
    - eigenvector: $\{ \begin{bmatrix} t \\ -2s \\ s \end{bmatrix} \}$
    - $\dim (E_1) = 2$
    - $\lambda = 4, \left(\begin{array}{ccc|c} -3 & 1 & 2 & 0 \\ 0 & -2 & 2 & 0 \\ 0 & 1 & -1 & 0 \end{array}\right)$
    - ref: $\left(\begin{array}{ccc|c} -3 & 1 & 2 & 0 \\ 0 & -1 & 1 & 0 \\ 0 & 0 & 0 & 0 \end{array}\right)$
    - eigenvector: $\{ \begin{bmatrix} t \\ t \\ t \end{bmatrix} \}$
    - $\dim(E_4) = 1$
- $A$ is non-defective as all $\dim(E_\lambda) =$ multiplicity $\lambda$

- `thm`: eigenvectors from distinct eigenvalues are linearly independent
- `thm`: if $A$ is non-defective then you can form a basis for $\R^n (\Complex^n)$ using the eigenvectors

## Complex eigenvalues and eigenvectors
- `thm`: if $\lambda$ is a complex eigenvalue with eigenvector $v$ for matrix $A$, then the (conjugate) $\bar \lambda$ is also an eigenvalue with eigenvector $\bar v$

### Proof
- assume $Av = \lambda v$
- NTS: $A \bar v = \bar \lambda \bar v$
    - $Av = \lambda v$
    - $\bar{Av} = \bar{\lambda v}$
    - $A \bar v = \bar \lambda \bar v$
        - only works because we are working with real value matrices


### Example
- $A = \begin{bmatrix} 0 & 2 \\ -8 & 0 \end{bmatrix}$
- eigenvalues:
    - $\det(\begin{bmatrix} - \lambda & 2 \\ -8 & - \lambda \end{bmatrix}) = 0$
    - $\lambda^2 + 16 = 0$
    - $\lambda = \pm 4i$
- eigenvectors:
    - $\left(\begin{array}{cc|c} -4i & 2 & 0 \\ -8 & -4i & 0 \end{array}\right)$
    - to ref: $\left(\begin{array}{cc|c} 4 & 2i & 0 \\ 0 & 0 & 0 \end{array}\right)$
    - vector: $\{ \begin{bmatrix} \frac {-1}{2} it \\ t \end{bmatrix} \}$
    - $\dim(E_{4i}) = 1$
    - conjugate negates complex part
    - vector: $\{ \begin{bmatrix} \frac {1}{2} it \\ t \end{bmatrix} \}$
- non-defective
- `Example matrix`: $\begin{bmatrix} 1 & 2 & 3\\
4 & 5 &6\end{bmatrix}$

# TODO
- sugessted ex: 2.1, 2.2
- take home quiz goes up tomorrow. Due on 30th

# Section 2.1 Matrices
- `matrix`: a collection of mathematical objects written in a row/col format
    - ex: $A = \begin{bmatrix} 2 & 3 \\ 4 & \pi \\ 0 & -1 \end{bmatrix}$
- the objects are called elements
- `size`: row x col. In the above column 3 x 2
- refrencing a specific element is: $A_{21}$ where this refrences the 4. The subcript in the index 2,1
- `square matrix`: a matrix whose size is nxn
- `equal`: 2 matrices are equal if
    - same size
    - share all elements in the respective indices: $A_{ij} = B_{ij}; \forall i,j$
- `vector`: 1xn matrix is a `row vector`. an nx1 matrix is a `column vector`
- `Transpose`: let A be an nxm matrix, $A^T$ is an mxn matrix. $(A^T)_{ij} = A_{ji}$
    - ex: $A = \begin{bmatrix} 3 & 0 \\
    -5 & 2\\ 8 & 4\end{bmatrix}; A^T = \begin{bmatrix}3 & -5 & 8\\ 0 & 2 & 4\end{bmatrix}$

## Some Special Square Definition
- **Note**: only apply to square matrices
- `Symmetric`: $A^T = A$
- `Skew Symmetric`: $A^T = -A$
- `Upper Triangular`: $A_{ij} = 0; i>j$ ae. everything below diagonal is 0
    - ex: $\begin{bmatrix}0 & 1 & 2\\0 & 0 & 3\\0 & 0 & 0\end{bmatrix}$
- `Lower Triangular`: $A_{ij} = 0; i<j$ e. everything above the diagonal is 0
- `Diagonal`: $A_{ij} = 0; i \neq j$ ae. when the diagonal is the **only** non-zero part
- these definitions say where zeros **must** be. There can be zeros in other partw but there must be zeros in accordance to the definitions
- `Trace`: $tr(A) = \sum \limits_{k=1}^{n} A_{kk}$ ae. scalar that's the sum of diagonal
- `matrix function`: matrix where elements are functions. You can plug in values for the variable and get out a matrix of values

# Operations
- `Matrix Addition`: it's an element wise sum  resulting in a matrix of the same size. Implied that the matrices are the same size. **SIZE MUST MATCH**
- `Scalar Multiplication`: an element wise multiplication between the element and the scalar: $kA; (kA)_{ij} = kA_{ij}$
- `Matrix Multiplication`: A is mxn, B is nxp. AB is a mxp matrix with $[AB]_{ij} = \sum \limits_{k=1}^{n} A_{ik}B_{kj}$
    - example in ipad
    - i'm doting each row vector with each column vector to build the new matrix
    - $AB \neq BA$ **NOT COMMUTATIVE**

### Properties of Matrix Multiplication
- matrix multiplication **is** associative. $A(BC) \equiv (AB)C$
- it distributes: $A(B + C) \equiv AB + AC$
- 

# Other Defs
- `Zero Matrix`: an ymatrix where all elements are 0
- `Power Notation for Matrices`: if A is a square matrix and k is a positive whole number: $A^k = A \cdot A \cdot ... \cdot A$
- `Identity Matrix`: square, diagonal matrix whose non-zero elements are 1
    - multiplying any matrix by it's identity matrix yeild the original matrix: $A \cdot I_n \equiv A; I_n \cdot A \equiv A$

### Properties of Transpose
- given A is mxn, B is mxn, C is nxp
- $(A^T)^T \equiv A$
- $(A + B)^T \equiv A^T + B^T$
- $(kA)^T \equiv kA^T$
- **Special**: $(AC)^T \equiv C^T \cdot A^T$

## Calculus of Matrix Functions
- derivatives and integrals are done element wise
- for integrals, we add c so the best way to express this is to add a matrix of different constants the integral of your matrix function

# NOTE
- element proofs just mean reduce the operation to operations on elements and show that the result is equivalent
- multiplication requires using sum notation
- these horrid proofs may appear on the exam
# 2.6 Matrix Inverse
- the following is in regards to square matrices
- `uniqueness of matrix inverses theorom`: if $\exists B: AB = BA = I_n$
- `inverse`: $A^{-1}$, a matrix is called invertible if <- exists
    - called non-invertible if it doesn't have an inverse
- `thm`: if its invertible $Ax = b$ has unqie sol $x = A^{-1}b$
- `main thm`: $A$ is invertible if and only if $rank(A) = n$
- to solve for an inverse simply augment the identity then change $A$ into rref. The augmented portion is the inverse
- you have like no proofs down. theyre pretty simple but you're gonna have a tough time
- `directional theorom`: if $AB = I_n$ then $B = A^{-1}$
    - this allows us to only check one direction

## Properties
- $(A^{-1})^{-1} = A$
- $(AB)^{-1} = B^{-1}A^{-1}$
- $(A^T)^{-1} = (A^{-1})^T$

# 2.8 IMT
- $A$ is invertible
- $Ax = b$ has unqiue sol $\forall b$
- $Ax = 0$ has unqie sol $x = 0$
- $rank(A) = n$
- $A \sim I_n$
- everything here means the same thing
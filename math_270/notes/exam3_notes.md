# Subspaces
- to prove $S$ is a subspace for $V$, $S$ must be
    - closed under $\odot$
    - closed under $\oplus$
- **NOTE**: a quick way to disprove is if the $\vec 0 \notin S$
- also, closed just means preforming the operation results in an object inside the same space

# Basis and Dimension
- finding a basis means finding the general element and iterating through parameters setting one to 1 and the rest to 0
- dimension is the number of vectors is the basis

# Linear Dependence
- if the only sol to $c_1 v_1 + \dots + c_n v_n = 0$ is $c_1 =  \dots = c_n = 0$
- set up a homogenous system of equations and if infinite solutions LD, unique sol LI
- any set that includes $\vec 0$ is LD
- let $v_1 ... v_k$ be a set of vectors in $V$
- let $\dim (V) = n$
- Case 1. $k < n$
    - Not a spanning set. Not a basis.
- Case 2. $k > n$
    - LD. Not a basis.
- Case 3. $k = n$
    - if spanning, LI, basis
    - if not span, LD, not a basis
    - so have to check span or LI
- wronskian: if you can find one value for which the wronskian is non-zero it's LI

# Span
- to check is $v \in$ span of $V$ unravel the vectors into matrices and if it's consistent (ie. has solution(s)) it's in the span
- if you have less vectors than dimension automatically not a aspanning set

# Row/Col Space
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
- `rank nullity thm`: let $A$ be $m \times n$. Then $rank(A) + nullity(A) = n$
    - note: $\dim (nullspace(A))$ is called the $nullity(A)$

# Inner Product
- define an `inner product` to be a mapping $<u, v> \rightarrow \R$. The input is 2 vectors and the output is a scalar that satisfies 4 properties:
    - $<u, u> \ge 0$ **AND** $<u, u> = 0 \Leftrightarrow u = 0_V$ (the subscript indicates $\vec 0 \in V$)
    - $<u, v> = <v, u>$
    - $<ku, v> = k<u, v>$
    - $<u + v, w> = <u, w> + <v, w>$
- def: let $V$ be an inner product space. Then the norm of a vector $u$ is $\lVert u \rVert = \sqrt{<u, u>}$
- `orthogonal`: let $v, w$ be vectors in IP space. if $<v, w> = 0$ then $v, w$ are orthogonal ($\perp$)

## Gram Schmidt Process
- `def`: projection of $v$ onto $u$: $P(v, u) = \frac {<v, u>}{<u, u>} u$
- let $v_1 \dots v_n$ be a basis for IP space $V$
- construct $u_1 \dots u_n$ tp be an orthogonal basis for the IP space $V$
    - $u_1 = v_1$
    - $u_2 = v_2 - P(v_2, u_1)$
    - $u_3 = v_3 - P(v_3, u_2) - P(v_3, u_1)$
    - $\vdots$
    - $u_n = v_n - P(v_n, u_{n-1}) - \dots - P(v_n, u_1)$
- `noramlize`: divide each basis element by its magnitude

# Linear Transformations
- `def`: let $V, W$ be vector spaces. Then a mapping $T$ is called a linear transformation written as $T:V \rightarrow W$ if
    - $T(v_1 + v_2) = T(v_1) + T(v_2)$
    - $T(kv) = k T(v)$

## Kernel, Range
- `kernel`: to find the kernel, set $T(v) = 0_w$
    - unravel into matrix and solve
    - a non trivial solution means the kernel has something other than $\vec 0$
- $T: V \rightarrow W$. $T$ is a LT
    - $V$ is the domain
    - $W$ is the co-domain
- $kr(T) \subseteq V$
- $kr(T) \{ v \in V: T(v) = 0_w \}$
    - everything that gets mapped to 0
    - subspace of $V$ always contains $\vec 0$
- $Rng(T) \subseteq W$
- $Rng(T) = \{ w \in W: \exists v \in V w/ T(v) = w \}$
    - everything in the co-domain which is covered by the transformation
    - solving for $Rng$ means first solving $Ker$, use ranl nullity thm to solve for dim, is general $T(v)$ to get $Rng$, and get the basis by inputting 0 and 1 for parameters in $Rng$
    - if gen elem has more params then dimension, rewrite
- `general rank nullity thm`: $\dim(ker(T)) + \dim(Rng(T)) = \dim(V)$
    - **NOTE**: $\dim(ker(T)) \le \dim(V)$
    - $\dim(Rng(T)) \le \dim(W)$
- `1-to-1`: $T: V \rightarrow W$ is 1-to-1 if $T(v_1) = T(v_2) \Rightarrow v_1 = v_2$
    - each element of the domain, when transformed, maps to a single distinct element of the co-domain. this only happens if the kernel is just 0
    - $ker(T) = \{ 0_V \}$
    - $\dim (ker(T)) = 0$
- `onto`: $T: V \rightarrow W$ is ontoi if $\forall w \in W \exists v \in V: T(v) = w$ (ae. domain when transformed covers the entire co-domain)
    - $Rng(T) = W$
    - $\dim(Rng(T)) = \dim(W)$

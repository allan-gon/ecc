# Reminders
- exam 3 on thursday
- 1 sheet of notes
- covers 4.3 - 4.9, 5.1 - 5.3, 6.1, 6.3, 6.4
- there is a review guide

# Section 6.1, 6.3, 6.4
- def: $V, W$ are vector spaces. $T: V \rightarrow W$ is a mapping. $T$ is a `linear transformation` if
    - $T(v_1 + v_2) = T(v_1) + T(v_2)$ (ae. distributes over addition)
    - $T(kv) = kT(v)$ (ae. distibutes over scalasr multiplication)

### Example
- $T: \R^2 \rightarrow \R^3$ defined by $T(a, b) = (a, b^2, a)$ is not a LT
    - counter example 1: $v_1 = (1, 2); v_2 = (3, 4)$
        - $T((1, 2) + (3, 4)) = T((4, 6)) = (4, 36, 4)$
        - $T((1, 2)) + T((3, 4)) = (1, 4, 1) + (3, 16, 3) = (4, 20, 4)$
        - they are not equal

## Kernel, Range
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
- `general rank nullity thm`: $\dim(ker(T)) + \dim(Rng(T)) = \dim(V)$
    - **NOTE**: $\dim(ker(T)) \le \dim(V)$
    - $\dim(Rng(T)) \le \dim(W)$
- `onto`: means transformation covers entire co-domain

### Example
- $T: P_3 (\R) \rightarrow \R^5$
- $T(p(x)) = (p(-2), p'(-1), p(0), p'(1), p(2))$
- this is a LT
- eval $T(x^3 - x + 1)$
    - $(-5, 2, 1, 2, 7)$
- determine $ker(T)$, basis, dim
    - not onto because going lower dim $\rightarrow$ higher dim
    - $ker(T) \subseteq P_3(\R)$
    - let $p(x) \in ker(T)$
    - $T(p(x)) = (0, 0, 0, 0, 0)$
    - $T(ax^3 + bx^2 + cx + d) = (0, 0, 0, 0, 0)$
    - $(-8a + 4b - 2c + d, 3a - 2b + c, d, 3a + 2b + c, 8a + 4b + 2c + d) = (0, 0, 0, 0, 0)$
        - this is just plugging in the gen elem to the transformation
    - $\left(\begin{array}{cccc|c} -8 & 4 & -2 & 1 & 0 \\ 3 & -2 & 1 & 0 & 0 \\ 0 & 0 & 0 & 1 & 0 \\ 3 & 2 & 1 & 0 & 0 \\ 8 & 4 & 2 & 1 & 0 \end{array}\right)$
    - ref: $\left(\begin{array}{cccc|c} 1 & - \frac {1}{2} & \frac {1}{4} & - \frac {1}{8} & 0 \\ 0 & - \frac {1}{2} & \frac {1}{4} & \frac {3}{8} & 0 \\ 0 & 0 & 2 & 3 & 0 \\ 0 & 0 & 0 & 1 & 0 \\ 0 & 0 & 0 & 0 & 0 \end{array}\right)$
    - $rank(A) = rank(A^{\#}) = n$ so $ker(T) = \{ 0 \}$
    - $\dim(ker(T)) = 0$
    - **NOTE**: dimension of just the $\vec 0$ is $0$
    - basis for $ker(T)$ is $\empty$ 
- repeat for $Rng(T)$
    - $Rng(T) \subseteq \R^5$
    - $\dim(Rng(T)) = \dim(P_3(\R)) - \dim(ker(T)) = 4$
    - $Rng(T) = \{ (-8a + 4b - 2c + d, 3a - 2b + c, d, 3a + 2b + c, 8a + 4b + 2c + d) \}$
    - basis $ = \{ (-8, 3, 0, 3, 8), (4, -2, 0, 2, 4), (-2, 1, 0, 1, 2), (1, 0, 1, 0, 1) \}$

### Another example
- $T: \R^4 \rightarrow M_2 (\R)$
- $T((a, b, c, d)) = \begin{bmatrix} a + 2b &  c - d \\ d - c & 2a + 4b -2c + 2d \end{bmatrix}$
- $ker(T), \dim(ker(T)),$ basis for $ker(T)$
    - $ker(T) \subseteq \R^4$
    - let $v \in ker(T)$
    - $T(v) = \begin{bmatrix} 0 & 0 \\ 0 & 0 \end{bmatrix}$
    - $\begin{bmatrix} a + 2b &  c - d \\ d - c & 2a + 4b -2c + 2d \end{bmatrix} = \begin{bmatrix} 0 & 0 \\ 0 & 0 \end{bmatrix}$
    - $\left(\begin{array}{cccc|c} 1 & 2 & 0 & 0 & 0 \\ 0 & 0 & 1 & -1 & 0 \\ 0 & 0 & -1 & 1 & 0 \\ 2 & 4 & -2 & 2 & 0 \end{array}\right)$
    - ref: $\left(\begin{array}{cccc|c} 1 & 2 & 0 & 0 & 0 \\ 0 & 0 & 1 & -1 & 0 \\ 0 & 0 & 0 & 0 & 0 \\ 0 & 0 & 0 & 0 & 0 \end{array}\right)$
    - $arnk(A) = rank(A^{\#}) < n$
    - $4 - 2 = 2$ params
    - $ker(T) = \{ (-2t, t, s, s) \}$
    - basis $= \{ (-2, 1, 0, 0) , (0, 0, 1, 1) \}$
    - $\dim(ker(T)) = 2$
- repeat for $Rng(T)$
    - $\dim(Rng(T)) = \dim(M_2(\R)) - \dim(ker(T)) = 4 - 2 = 2$
    - basis $= \{ \begin{bmatrix} a + 2b &  c - d \\ d - c & 2a + 4b -2c + 2d \end{bmatrix}, \}$
        - here there are 4 params but dim says only 2 so rephrase.
        - choose $a + 2b = r; c - d = p$ 
    - gen elem: $\{ \begin{bmatrix} r &  p \\ -p & 2r - 2p \end{bmatrix} \}$
    - basis $= \{ \begin{bmatrix} 1 &  0 \\ 0 & 2 \end{bmatrix}, \begin{bmatrix} 0 &  1 \\ -1 & - 2 \end{bmatrix} \}$

## Next Thing
- `1-to-1`: $T: V \rightarrow W$ is 1-to-1 if $T(v_1) = T(v_2) \Rightarrow v_1 = v_2$
    - each element of the domain, when transformed, maps to a single distinct element of the co-domain. this only happens if the kernel is just 0
    - $ker(T) = \{ 0_V \}$
    - $\dim (ker(T)) = 0$
- `onto`: $T: V \rightarrow W$ is ontoi if $\forall w \in W \exists v \in V: T(v) = w$ (ae. domain when transformed covers the entire co-domain)
    - $Rng(T) = W$
    - $\dim(Rng(T)) = \dim(W)$

### Proofs via rank nullity thm
- $T: M_{3 \times 2} (\R) \rightarrow P_4(\R)$ is NOT 1-to-1
    - NTS: $T$ is not 1-to-1
    - NTS: $\dim(ker(T)) > 0$
    - $\dim(ker(T)) = \dim(V) - \dim(Rng(T)) \Rightarrow \dim(M_{3 \times 2} (\R)) - \dim(Rng(T)) = 6 - \dim(Rng(T))$
    - since $Rng(T) \subseteq P_4(\R), \dim(Rng(T)) \le 5$
    - so $\dim(ker(T)) \ge 1 > 0$
- $T: \R^6 \rightarrow P_4 (\R)$ with $\dim(ker(T)) = 2$ is NOT onto
    - NTS: $\dim(Rng(T)) < \dim(W)$
    - $\dim(Rng(T)) = \dim(R^6) - \dim(ker(T)) = 6 - 2 = 4$
    - $4 < 5$
- $T: M_3 (\R) \rightarrow P_8 (\R), T$ is onto therefore also 1-to-1
    - NTS: $\dim(ker(T)) = 0$
    - $\dim(ker(T)) = \dim(M_3) - \dim(Rng(T))$
        - because onto, $\dim(Rng(T)) = \dim(W)$
    - $\dim(ker(T)) = 9 - 9 = 0$

## More terms (TH Exam)
- `isomorphism`: $T: V \rightarrow W$ and $T$ is both 1-to-1 and onto. $T$ is called an isomorphism
- Properties of LT
    - $T_1: V \rightarrow  W$ and $T_2: V \rightarrow W$
        - $T_1 + T_2: V \rightarrow W$ is a LT
    - $T: V \rightarrow W$
        - $kT: V \rightarrow W$ is a LT
    - $T_1: V \rightarrow W$ and $T_2: W \rightarrow U$
        - $T_1 \circ T_2: V \rightarrow U$ is LT

### Proof of 3
- NTS: $T_2 \circ T_1 (v_1 + v_2) = T_2 \circ T_1 (v_1) + T_2 \circ T_1 (v_2)$
    - $T_2(T_1(v_1) + T_1(v_2)) = T_2(T_1(v_1)) + T_2(T_1(v_2))$
- NTS: $T_2 \circ T_1 (kv) = T_2(T_1(kv)) = T_2(kT_1(v)) = kT_2(T_1(v))$
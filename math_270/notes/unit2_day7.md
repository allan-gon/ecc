# Reminders
- Exam 2 on thursday
    - 6 Q's
    - 1 sheet of notes
    - bring own paper
    - Covers chpt 2 (except 2.7), chpt 3, and 4.2
    - **note**: q12 is for take home
- Take Home Exam 2 due 4/20

# 4.2
## Vector Spaces
- `vector space`: a collection of **objects** called vectors with a field of scalars and two operations denoted $+$ (vec add) and $\cdot$ (scalar mul)
    - `field of scalars`
        - $\R$
        - $\Complex$
    - sometimes to be super clear be denote. this is because $+$ and $\cdot$ doesn't necessarily mean the normal addition of multiplication we are used to
        - $+ \equiv \oplus$
        - $\cdot \equiv \odot$

that satisfies the following 10 properties

Let $u, v, w \in V$. Let $k_1, k_2$ be scalars
- Closures under $\oplus$
    - $u \oplus v \in V$ ($\forall u, v \in V$)
    - if you add 2 vectors inside a given vector space, the sum should also exist in that space
- Closure under $\odot$
    - $k_1 \odot u \in V$ ($\forall u \in V, \forall k_1$ in field)
- $\oplus$ is Commutatuve
    - $u \oplus v \equiv v \oplus u$
- $\oplus$ is associative
    - $(u \oplus v) \oplus q \equiv u \oplus (v \oplus w)$
- $\exists$ a **zero vector**, denoted $\vec 0$ such that
    - $v \oplus \vec 0 = v$ $\forall v \in V$
- Additive inverse
    - $\forall v \in V \exists -v \in V$ such that
        - $v \oplus (-v) = \vec 0$
- Unit property
    - $1 \odot v = v$ $\forall v \in V$
- Associativity of scalar multiplication
    - $k_1 \odot (k_2 \odot v) \equiv (k_1 k_2) \odot V$
- Scalar multiplication over vector addition
    - $k_1 \odot (u \oplus v) \equiv (k_1 \odot u) \oplus (k_1 \odot v)$
- Scalar addition over scalar multiplication
    - $(k_1 + k_2) \odot u \equiv (k_1 \odot) \oplus (k_2 \odot u)$
- `Common Vector Spaces`:
    - $\R^n$ vectors: $(x_1, x_2, ..., x_n)$ $\vec 0 = (0, 0, ..., 0)$
    - $\Complex^n$ vectors: $(x_1, x_2, ..., x_n)$
        - $x_i \in \Complex$
        - $\vec 0 = (0, 0, ..., 0)$
    - $M_{m \times n}(\R)$ vectors: $\begin{bmatrix} a_{11} & ... & a_{1n} \\ \vdots & \ddots \\ a_{m1} & ... & a_{mn}\end{bmatrix}$
        - $\vec 0 = 0_{m \times n}$
    - $P_n(\R)$ vectors: $a_n x^n + a_{n-1} x^{n-1} + ... + a_0$
        - $\vec 0 = 0$
    - $C_n(\R)$, $F_n(\R)$, or n as a superscript
        - Space of all functions that are at least n times differentiable
        - called the function space
        - vectors: $f(x)$
        - $\vec 0$: $f(x) = 0$
- all this is to say "vectors" are objects that live in a space not necesarrily traditional vectors
- big example of verifying in ipad
- if any property breaks then not a vector space

## Addition Properties of Vector Space
- Given $V$ is a vector space
    - $\vec 0$ is unique
    - $0 \odot v = \vec 0$
    - $k \odot \vec 0 = \vec 0$
    - Additive inverses are unique
    - $-1 \odot v = -v$
    - $k \odot v = \vec 0$
        - then $k = 0$ or $v = \vec 0$
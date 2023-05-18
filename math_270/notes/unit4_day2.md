# Reminder
- 8.1 - 8.3, 8.7

# 8.2 Const Coeff Homog DE
- Recall: if $L$ is a linear dif operator then the sols to $L(y) = 0$ (ie. $ker(L)$) is an n-dimensional subspace (with $n =$ order of diff eq)
    - the order determines the size of the solution space to linear homogenous diff op
- const coeff DE: $L$ is a polynomial diff operator

| factors of $L$ | roots | Basis elements |
|---|---|---|
| $(D - a)$ | $root = a, a$ is real | $e^{ax}$
| $(D - (a + bi))(D - (a - bi))$ | $r = a \pm bi$ | $e^{ax} \cos(bx), e^{ax} \sin(bx)$
- **NOTE**: roots with multiplicity greater than one contribute basis elements of the form
    - $(\dots), x (\dots), \dots, x^{m - 1}(\dots)$
        - the parantheses mean whatever the basis element is
        - the takeaway is when a root exists more than once you add basis elements and for each add multiply it by an increasing power of x

### Example
- $y''' + 4y'' + y' - 26y = 0$. Find gen sol
- to diff op
    - $(D^3 + 4D^2 + D - 26)(y) = 0$
    - use rational root theorom which says if real roots exists they much easily divide into the constant
        - here for 26 this means 1, -1, 2, -2, 13, -13, 26, -26
    - try $r = 2$ this works so this is a root now facotr that out by polynomial division
    - $(r - 2)(r^2 + 6r + 13) = 0$
    - now quadratic equation to find remaining roots: $r = -3 \pm 2i$
        - $r = 2 \Rightarrow e^{2x}$
        - $r = -3 \pm 2i \Rightarrow e^{-3x} \cos(2x), e^{-3x} \sin(2x)$
- gen elem: $y = c_1 e^{2x} + c_2^{-3x} \cos(2x) + c_3 e^{-3x} \sin(2x)$

### Example
- Find gel sol: $(D - 2)^3 (D^2 + 9)^2 D^4(y) = 0$
    - order 11
- roots: $r = 2$ multiplicity 3 $,r = \pm 3i$ multiplicity 2  $,r = 0$ multiplicity 4
- gen elem: $y = c_1 e^{2x} + c_2 xe^{2x} + c_3 x^2 e^{2x} + c_4 \cos(3x) + c_5 \sin(3x) + c_6 x \cos(3x) + c_7 x \sin(3x) + c_8 + c_9 x + c_10 x^2 + c_11 x^3$

### Example
- Find unique sol: $y'' - 2y' - 3y = 0; y(0) = 5, y'(0) = 3$
- $(D^2 - 2D - 3)(y) = 0$
    - $(D - 3)(D + 1)(y) = 0$
    - $r = 3, r = -1$
- gen sol: $y = c_1 e^{3x} + c_2 e^{-x}$
    - $5 = c_1 + c_2$
- $y' = 3c_1 e^{3x} -c_2 e^{-x}$
    - $3 = 3 c_1 - c_2$
- $\left(\begin{array}{cc|c} 5 & 1 & 1 \\ 3 & 3 & -1 \end{array}\right)$
- $c_1 = 2, c_2 = 3$
- unique sol: $y = 2 e^{3x} + 3 e^{-x}$

# Section 8.3) Method of Annihilators
### Motivating Example
- find gen sol: $y'' - 6y' + 8y = 6e^x$
- const coeff, non-homogenous
- recall thm: gen sol to non-homogenous can be written as $y = y_H + y_P$ (the homogenous sols + particular sol)
    - homogenous: $y'' - 6y' + 8y = 0$
    - $(D^2 - 6D + 8)(y) = 0$
        - $(D - 4)(D - 2)(y) = 0$
    - homogenous gen sol: $y_H = c_1 e^{2x} + c_2 e^{4x}$
- applt $(D - 1)$ to both sides beacause $D - 1$ results in a basis elemnt  that looks $6 e^x$
    - $(D - 1)(D^2 - 6D + 8)(y) = (D - 1)(6e^x)$
    - $(D - 1)(D^2 - 6D + 8)(y) = 6e^x - 6e^x$
    - $(D - 1)(D^2 - 6D + 8)(y) = 0$
    - Trial sol: $y_T = A_1 e^x + A_2 e^{2x} + A_3 e^{4x}$
        - **NOTE**: some of these elements are in the homogenous sol so ommit them for the next step
    - Trial sol: $y_T = A_1 e^x$
- plug into original DE
    - $A_1 e^x - 6 A_1 e^x + 8A_1 e^x = 6e^x$
    - $3A_1 e^x = 6e^x$
    - $A_1 = 2$
- gen sol: $y = c_1 e^{2x} + c_2 e^{4x} + 2e^x$

## Annihilators for Specific Terms
| Term | Annihilator |
|---|---|
| $e^{ax}$ | $(D - a)$ |
|$e^{ax} \cos(bx), e^{ax} \sin(bx)$| $(D^2 - 2abD + a^2 + b^2)$ |
| $x^k e^{ax}$ | $(D - a)^{k + 1}$ |
| $x^k e^{ax} \cos(bx), x^k e^{ax} \sin(bx)$ | $(D^2 - 2abD + a^2 + b^2)^{k + 1}$ |

- if $L_1$ annihilates $f(x)$, $L_2$ annihilates $g(x)$ then $L_1 \cdot L_2$ annihilates $f(x) + g(x)$

### Example
- find the simplest annihilator for the following termss
    - $x^2 e^{5x}$
        - $(D - 5)^{3}$
    - $x^3 + 7e^{-x}$
        - really $x^3 e^{0x}$
        - $(D^4)7(D + 1)$
    - $5 \sin(2x) + 6 \cos(x)$
        - $a = 0, b = 2$ then $a = 0, b = 1$
        - $(D^2 + 4)(D^2 + 1)$
    - $3e^x + 8x^2 e^x - 9e^{-x}$
        - $(D - 1)^3 (D + 1)$
            - $(D - 1) \in (D - 1)^3$ so simplest is 3 power
    - $\cos^2 (x)$
        - $\equiv \frac {1}{2} + \frac {1}{2} \cos(2x)$
        - $(D)(D^2 + 4)$

### Example
- find gen sol: $(D^4 + D^2)(y) = cos(x)$
- work on homogenous
- $(D^2)(D^2 + 1)(y) = 0$
    - basis elements: $0$ multiplicity 2, $\pm i$
- $y_H = c_1 + c_2 x + c_3 \cos(x) + c_4 \sin(x)$
- find annihilator
    - $(D^2 + 1)$
    apply to both sides
    - $(D^2 + 1)^2(D^2)(y) = 0$
    - $y_T = A_1 \cos(x) + A_2 \sin(x) + A_3 x \cos(x) + A_4 x \sin(x) + A_5 + A_6 x$
    - ommit terms in homogenous: $y_T = A_3 x \cos(x) + A_4 x \sin(x)$
- plus into original diff eq: $4A_3 \sin(x) + A_3 x \cos(x) -4A_4 \cos(x) + A_4 x \sin(x) -2A_3 \sin(x) - A_3x \cos(x) + 2A_4 \cos(x) - A_4 x \sin(x) = \cos(x)$
    - $\Rightarrow 2A_3 \sin(x) - 2A_4 \cos(x) = \cos(x)$
    - $A_3 = 0, A_4 = \frac {-1}{2}$
- gen sol: $y = c_1 + c_2 x + c_3 \cos(x) + c_4 \sin(x) - \frac {1}{2} x \sin(x)$

### Example
- find the simplest form of $y_T$: $(D - 2)^2 (D^2 + 4)(D - 3)(y) = 4e^{2x} + 2x^2$
- homogeneous:
    - $r = 3, r = 2$ multiplicity 2, $r = \pm 2i$
    - $y_H = c_1 e^{2x} + c_2 xe^{2x} + c_2 \cos(2x) + c_4 \sin(2x) + c_5 e^{3x}$
- annihilator:
    - $(D - 2)(D^3)$
    - apply
    - $(D - 2)(D^3)(D - 2)^2 (D^2 + 4)(D - 3)(y) = 0$
    - $\Rightarrow (D^3)(D - 2)^3 (D^2 + 4)(D - 3)(y) = 0$
        - $r = 2$ multiplicity 2, $r = \pm 2i, r = 3, r = 0$ multiplicty 3
    - $y_T = A_1 e^{2x} + A_2 xe^{2x} + A_3 x^2 e^{2x} + A_4 \cos(2x) + A_5 \sin(2x) + A_6 e^{3x} + A_7 + A_8 x + A_9 x^2$
    - remove elements from homogeneous: $y_T = A_3 x^2 e^{2x} + A_7 + A_8 x + A_9 x^2$

# Project Related
- look at phind to freshen up on futures, this is the way
- make app 'speed up' for the user by async loading and passing a future into ocr function
- make viewing a specific document easier by making pdf and a button to launch the pdf
- make app a single exec file the depends on folders
- make a setup file which download the 
- at present i believe the app depends on
    - ./data
    - ./model
- model should probably be part of the binary
- data holds both the documents and the database
    - this must remain
- **GOTCHAS**: paths will be awful to debug remember MEIPASS
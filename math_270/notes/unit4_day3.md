# Question
- why when term squared in the annihilator can we ommit the power?
    - powers will remove multiplicities of the factors so unless there's a power of x no need to have the power

# Reminders
- TH Quiz due thursday 6/1
    - can do Q1 - Q3, EC #1
- review guide 4 is up
- Sug ex: 8.1-8.3, 8.7, 8.8
- TH Exam 4 due thursday 6/8
    - can do Q1, Q2

# 8.3 Recap
| Term | Annihilator |
|---|---|
| $e^{ax}$ | $D-a$ |
| $x^k e^{ax}$ | $(D-a)^{k + 1}$ |
| $x^k$ | $D^{k+1}$ |
| $e^{ax} \cos(bx), e^{ax} \sin(bx)$ | $D^2 -2aD + (a^2 + b^2)$ |
| $x^k e^{ax} \cos(bx), x^k e^{ax} \sin(bx)$ | $(D^2 -2aD + (a^2 + b^2))^{k + 1}$ |
| $\cos(bx), \sin(bx)$ | $D^2 + b^2$ |

- **NOTE**: if 2 terms are summed then the annihilator is the product of each term's annihilator
    - also k is an integer

## Example
- $y'' -2y' -8y = 8e^{4x} + 16x$
- solve homogenous
    - $(D^2 - 2D -8)y = 0$
    - $(r - 4)(r + 2)$
    - $y_H = c_1 e^{4x} + c_2 e^{-2x}$
- solve annihilator
    - annihilator: $(D - 4)(D^2)$
    - apply to both sides
    - $(D - 4)(D^2)(D - 4)(D + 2)y = 0$
    - $\Rightarrow D^2 (D - 4)^2 (D+2)y = 0$
    - $y_T = A_1 + A_2 x + A_3 e^{4x} + A_4 xe^{4x} + A_5 e^{-2x}$
    - simplify by ommitting homogrnous components
    - $y_T = A_1 + A_2 x + A_4 xe^{4x}$
    - plug $y_T$ into original DE
    - $y_T' = A_2 + A_4 e^{4x} + 4A_4 xe^{4x}$
    - $y_T'' = 4A_4 e^{4x} + 4A_4 e^{4x} + 16A_4 xe^{4x}$
    - $8A_4 e^{4x} + 16A_4 xe^{4x} -2A_2 -2A_4 e^{4x} - \ 8A_4 xe^{4x} - 8A_1 -8A_2 x - 8A_4 xe^{4x} = 8e^{4x} + 16x$
    - $6A_4 e^{4x} - 2A_2 - 8A_1 - 8A_2 x = 8e^{4x} + 16x$
        - $6A_4 = 8$
        - $-2A_2 - 8A_1 = 0$
        - $-8A_2 = 16$ 
    - back solving: $A_2 = -2, A_1 = \frac {1}{2}, A_4 = \frac {4}{3}$
- gen sol: $y = c_1 e^{4x} + c_2 e^{-2x} + \frac {1}{2} - 2x + \frac {4}{3} xe^{4x}$

# Section 8.7 Variation of Parameters
## Second order
- $y'' + a_1 y' + a_2 y = F(x)$
- assume: $y_H = c_1 y_1 + c_2 y_2$
- Suppose $y_p = u_1 y_1 + u_2 y_2$ with $u_1, u_2$ as functions
- $y_p ' = u_1 ' y_1 + u_1 y_1 ' + u_2 ' y_2 + u_2 y_2'$
    - Assume: $u_1 ' y_1 + u_2 ' y_2 = 0$
- $\Rightarrow y_p ' = u_1 y_1 ' + u_2 y_2 '$
- $y_p '' = u_1 ' y_1 ' + u_1 y_1 '' + u_2 ' y_2 ' + u_2 y_2 ''$
- plugging in: $(u_1 ' y_1 ' + u_1 y_1 '' + u_2 ' y_2 ' + u_2 y_2 '') + a_1 (u_1 y_1 ' + u_2 y_2 ') + a_2 (u_1 y_1 + u_2 y_2)$
    - **NOTE**: $u_1 y_1 + u_2 y_2$ from homogenous and there are terms that appear in DE so all those go to $0$
- $\Rightarrow u_1' y_1 ' + u_2 ' y_2 ' = F(x)$
- now have sys of eq:
    - $u_1 ' y_1 + u_2 ' y_2 = 0$
    - $u_1' y_1 ' + u_2 ' y_2 ' = F(x)$
- solve for $u's$:
- $\begin{bmatrix} y_1 & y_2 \\ y_1 ' & y_2 '\end{bmatrix} \begin{bmatrix} u_1 ' \\ u_2 ' \end{bmatrix} = \begin{bmatrix} 0 \\ F(x) \end{bmatrix}$
    - since Wronskian is non-zero this system will have a unique solution

### Example
- $y'' + y = \sec(x)$
- homogenous: $y'' + y = 0$
    - $(D^2 +1)y = 0$
    - $y_H = c_1 \cos(x) + c_2 \sin(x)$
- variation of parameters: $y_p = u_1 \cos(x) + u_2 \sin(x)$ with $u_1 ' , u_2 '$ eing solutions to $\left(\begin{array}{cc|c} \cos(x) & \sin(x) & 0 \\ - \sin(x) & \cos(x) & \sec(x) \end{array}\right)$
- to ref: mulp row by sin, cos so they can clear
    - $\left(\begin{array}{cc|c} \sin(x) \cos(x) & \sin^2(x) & 0 \\ 0 & 1 & 1 \end{array}\right)$
    - $u_2 ' = 1, u_1 ' = - \tan(x)$
- solve for $u_1, u_2$
    - $u_1 = x, u_2 = \ln|\cos(x)|$
- $y_p = \ln|\cos(x)| \cos(x) + x \sin(x)$
- gen sol: $y = c_1 \cos(x) + c_2 \sin(x) + \ln|\cos(x)| \cos(x) + x \sin(x)$

### Example
- $y'' - 2y' + y = \frac{e^x}{\sqrt{1 - x^2}}$
- homogenous: $(D^2 - 2D + 1)y = 0$
    - $y_H = c_1 e^x + c_2 xe^x$
- $y_p = u_1 y_1 + u_2 y_2$ with $u_1 ', u_2 '$ sols to  $\left(\begin{array}{cc|c} e^x & xe^x & 0 \\ e^x & e^x + xe^x & \frac{e^x}{\sqrt{1 - x^2}} \end{array}\right)$
    - to ref: $\left(\begin{array}{cc|c} e^x & xe^x & 0 \\ 0 & e^x & \frac{e^x}{\sqrt{1 - x^2}} \end{array}\right)$
    - $u_2 ' =  \frac{1}{\sqrt{1 - x^2}}$
    - $u_1 ' =  \frac{-x}{\sqrt{1 - x^2}}$
- solve for $u_1, u_2$
    - $u_2 = \arcsin(x)$
    - $u_1 = \sqrt{1 - x^2}$
- plug into $y_p = \sqrt{1 - x^2} e^x + \arcsin(x) xe^x$
- gen sol: $y = c_1 e^x + c_2 xe^x + \sqrt{1 - x^2} e^x + \arcsin(x) xe^x$

## VoP for nth Order
- $L(y) = F(x)$ with $y_1 \dots y_n$ a basis for $y_H$. Then $y_p = u_1 y_1 + \dots + u_n y_n$ with $u_1', \dots, u_n'$ solving $\left(\begin{array}{ccc|c} y_1 & \dots & y_n & 0 \\ y_1' & \dots &  y_n' & 0 \\ \vdots & & & \vdots \\ y_1^{(n-1)} & \dots & y_n^{(n-1)} & F(x) \end{array}\right)$
- the meaning is thsi process will always produce particular solution

### Example
- $(D - 1)^3y = \frac {e^x}{x^3}$
- $y_H = c_1 e^x + c_2 xe^x + c_3 x^2 e^x$
- $y_P = u_1 y_1 + u_2 y_2 + u_3 y_3$ with $u_1', u_2', u_3/$ solving $\left(\begin{array}{ccc|c} e^x & xe^x & x^2 e^x & 0 \\ e^x & e^x + xe^x & 2xe^x + x^2 e^x & 0 \\ e^x & 2e^x + xe^x & 2e^x + 4xe^x + x^2 e^x & \frac{e^x}{x^3} \end{array}\right)$
    - divide rows by $e^x$ and more stuff to ref: $\left(\begin{array}{ccc|c} 1 & x & x^2 & 0 \\ 0 & 1 & 2x & 0 \\ 0 & 0 & 2 & \frac {1}{x^3} \end{array}\right)$
    - $u_3' = \frac {1}{2x^3}$
    - $u_2' = - \frac {1}{x^2}$
    - $u_1' = \frac {1}{2x}$
- $u_1 = \frac {\ln|x|}{2}, u_2 = \frac {1}{x}, u_3 = - \frac {1}{4x^2}$
- $y_P = \frac {\ln|x|}{2} e^x + \frac {1}{x} xe^x - \frac {1}{4x^2} x^2 e^x$
    - $\Rightarrow y_P = \frac {\ln|x|}{2} e^x + \frac {3e^x}{4}$
- $y = c_1 e^x + c_2 xe^x + c_3 x^2 e^x + \frac {\ln|x|}{2} e^x + \frac {3e^x}{4}$
    - could further simplify

## Cauchy Euler DE
### Example
- $x^2 y'' - 4x y' + 6y = 0$
    - 8.1 tells us sol space is dim 2
- substitution: $x = e^z, z = \ln |x|$  *change the independent variable*
    - think of as $y(z(x))$
- $\frac {dy}{dx} = \frac {dy}{dz} \frac {dz}{dx}$
    - $\frac {dy}{dx} = \frac {dy}{dz} \frac {1}{x}$
    - $\frac {dy}{dz} = x \frac {dy}{dx}$
    - $ \frac {d}{dx} (\frac {dy}{dx}) = \frac{d}{dx} (\frac {dy}{dz} \frac {1}{x})$
        - $\Rightarrow \frac{d^2 y}{dx^2} = \frac {d^2 y}{dz^2} \frac {dz}{dx} \frac {1}{x} + \frac {dy}{dz} \frac {-1}{x^2}$
        - $\Rightarrow x^2  \frac{d^2 y}{dx^2} = \frac {d^2 y}{dz^2} - \frac {dy}{dz}$
- pluggin in: $(\frac {d^2 y}{dz^2} - \frac {dy}{dz}) - 4 \frac {dy}{dz} + 6y = 0$
    - $\Rightarrow y'' - 5y' + 6y = 0$
    - $y$ in terms of $z$
- solve normally: $y_H = c_1 e^{2z} + c_2 e^{3z}$
    - $\Rightarrow y_H = c_1 e^{2 \ln |x|} + c_2 e^{3 \ln |x|}$
    - $\Rightarrow y_H = c_1 x^2 + c_2 x^3$

# Summary + generalization
- nth order Cauchy-Euler:
    - $x^n y^{(n)} + a_{n - 1} x^{n - 1} y^{(n - 1)} + \dots + a_1 xy' + a_0 y = 0$
- substitute: $x = e^z, z = \ln|x|$
- $xy' = D, x^2y'' = D(D - 1), \dots, x^n y^{(n)} = D(D - 1)(D - 2) \dots (D - (n - 1))$
    - with $D$ being a differential operator in terms of $z$ so you must substitute at the end

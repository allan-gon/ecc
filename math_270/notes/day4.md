# 1.8 cont.
## Review example

Ex (seperable):
- find all sol to: $x^3y' = \frac {x^4e^x}{cos(y)}; y(0) = \pi$
- $\int cos(y) dy = \int xe^x dx$
    - $u = x; du = dx; v = e^x; dv = e^x$
- $sin(y) = x e^x - \int e^x dx$
- $sin(y) = xe^x - e^x + C$
- $0 = 0 - 1 + C$
- $C = 1$
- **NOTE**: if the theorom doesn't apply it means no information not a negation of the theorom

Ex (linear and piecewise):
- $y' + \frac {1}/{x}y = f(x); f(x) = 2 | x < 1; f(x) = x + 1 | x \geq 1$
- int fact: $e^{ln|x|} \equiv x$
- $xy' + y = x f(x)$
- $xy = \int x f(x) dx$
- integrate each however the constants in one of the parts is depends on the other one. Ensure continuity where they meet
- $xy = x^2 + C_1; xy = \frac {x^3}{3} + \frac {x^2}{2} + C_2$
- $1 + C_1 = \frac {1}{3} + \frac {1}{2} + C_2$
- $C_2 = \frac {1}{6} + C_1$
- now replace $C_2$ in the answer in terms of $C_1$

## Change of Variable cont.
- `homogenous`: diff eq of the form: $y' = F(\frac {y}{x})$
- theorom:  a substitution of $V = \frac {y}{x}$ changes homogenous to seperable

Ex:
- $xyy' = 2y^2 - 16x^2; y(1) = 2; y(0) = 0$
- $y' = \frac {2y^2 - 16x^2}{xy} \equiv 2 \frac {y}{x} - 16 \frac {1}{ \frac {y}{x}}; y \neq 0$
- $V = \frac {y}{x}, y = xV, y' = V + xV'$
- $V + xV' = 2v - \frac {16}{V}$
- $xV' = V - \frac {16}{V}; V - \frac {16}{V} \neq 0$
- $\int \frac {1}{V - \frac {16}{V}} dv = \int \frac {1}{x} dx$
- $\int \frac {V}{V^2 - 16} dv = \int {1}{x} dx$
- by u-sub: $\frac {ln|V^2 - 16|}{2} = ln|x| + C$
- simplyfing: $V^2= Cx^2 + 16$
- plugging in V: $(\frac {y}{x})^2 = Cx^2 - 16$
- $C = -12$
- plugging $y = 0$ into diff eq yeilds no sol
- plugging $V - \frac {16}{V} = 0$ (in terms of x and y) into the diff eq yeilds an identity
- even though there the previous 2 checks worked, they dont apply to the IVP because not $y(1) = 2$, for this reason, the diff eq hasa unique sol
- possible sol set: $(\frac {y}{x})^2 -16 = CX^2, y = 4x, y = -4x$
- for 2nd IVP the latter 2 are solutions

Ex:
- $xy' = xsec(\frac {2y}{x}) + y$
- $y' = sec(2 \frac {y}{x}) + \frac {y}{x}$
- $V = \frac {y}{x}, xV = y, y' = xV' + V$
- $xV' + V = sec(2V) + V$
- $xV' = sec(2V)$
- $\int \frac {1}{sec(2V)} dv = \int \frac {1}{x} dx ; sec(2V)\neq 0$ **Note**: this never happens because sec range doesn't contain 0
- $\int cos(2V) = ln|x| + C$
- $\frac {sin(2V)}{2} = ln|x| + C$
- $sin(\frac {2y}{x}) = 2ln|x| + C$
- this is a general sol. no check needed because range thing

## Bernoulli
- `bernoulli`: of the form: $y' + f(x)y = g(x)y^n$
    - a substituition of the form $u = y^{1-n}$ will make bernoulli to linear
- Proof:
    - $y' + f(x)y = g(x)y^n$
    - $u = y^{1-n}; u' = (1-n)y^{-n}y'$
    - $y^{-n}y' + f(x)y^{1-n} = g(x); y \neq 0$
    - plugging in the subs: $\frac {1}{1-n} u' + f(x)u = g(x)$
    - this is linear
    
Ex:
- $y^4y' + \frac {1}{x} y^5 = \frac {1}{5x^6 + 5}$
- $y' + \frac {1}{x} y = \frac {1}{5x^6 + 5} y^{-4}; y^4 \neq 0$
    - checking this, $y = 0$ is not a solution
- $u = y^{5}; u' = 5y^4y'$
- $\frac {1}{5} u' + \frac {1}{x} u = \frac {1}{5x^6} + 5$
- int fact: $e^{\int \frac {5}{x}} \equiv x^5$
- $x^5u = \int \frac {5x^5}{5x^6 + 5}$
- $x^5u = \frac {ln|x^6 + 1|}{6} + C$
- plugging in u: $x^5y^5 = \frac {ln|x^6 + 1|}{6} + C$

Ex:
- $y' + \frac {3}{x}y = y^{\frac {4}{3}}$
- $u = y^{\frac {-1}{3}}; u' = \frac {1}{3} y^{\frac {-4}{3}}y'$
- rearranging: $y^{\frac {-4}{3}}y' + \frac {3}{x}y^{\frac{-1}{3}} = 1; y \neq 0$
    - $y = 0$ is a solution
- substitute: $3u' + \frac {3}{x}u = 1$
    - int factor: $e^{\int \frac {-1}{x}} \equiv \frac {1}{x}$
- $\frac {u}{x} = \frac {1}{3} \int \frac {1}{x} dx$
- $u = \frac {-x}{3}ln|x| + Cx$
- substituting u: $\frac {1}{y^3} = \frac {-x}{3}ln|x| + Cx$
- no general sol because $y=0$ works

# 1.9 Exact Diff Eq
- of the form: $M(x, y) + N(x, y)y' = 0$ to be *exact* there must be: $\frac {\partial M}{\partial x} = M(x, y); \frac {\partial N}{\partial y} = N(x, y)$
- `check for exactness`: given $M(x, y) + N(x, y)y' = 0$ if $\frac {\partial M}{\partial y} = \frac {\partial N}{\partial x}$ then it's exact
- `theorom`: general sol: $\phi(x, y) = C$
    - $\phi_x(x, y) \equiv \frac {\partial}{\partial x}$

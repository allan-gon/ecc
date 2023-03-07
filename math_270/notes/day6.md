# TODO
- do the study guide
- create a note sheet
- go to zoom OH tomorrow
- review sessions
    - Monday 9-10 am
    - Tuesday 2-3 pm
- make a point to practice the word problem to diff eq

# Applications 1.5/1.7
## In class paper 1
- prop = $y=kx$
- inv prop = $y=k/x$
- $\frac {dP}{dt} = K(C_{cap} - P)(P - Thresh)$
    - plugging in: $\frac {dP}{dt} =  \frac {1}{72}(15000 - P)(P - 2000)$
    - equlibriums: p = 15000, p = 2000
- part c just is plug and chug into diff eq around equilibrium sols to see how rate of change changes . really just care about sign of slope not value
- for the last part no equilibrium because P depends on t, there's no sol of the form P = C. It's instead of teh form P = g(t)

## In Class Paper 2
- 

## Numeric Methods 1.10 (Euler Method)
- given a 1st order IVP $y' = F(x, y); y(a) = b$, approximate $y(c)$
- a step size h
- define $x_0 = a$
    - $x_k = x_{k-1} + h$
- $y_0 = b$
- $y_k = y_{k-1} + hf(x_{k-1}, y_{k-1})$

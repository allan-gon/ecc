# Rules
- Non-zero numbers are significant number regardless of position

Ex: 126 -> 3 sig fig, 95 -> 2 sig fig, 4873 -> 4 sig fig

- Zeros that are in-between non-zero numbers are significant

Ex: 101 -> 3 sig fig, 5006 -> 4 sig fig

- Trailing zeros, that is any zero right of a non-zero, aren't significant unless there is a decimal

Ex: 100 -> 1 sig fig, 100. -> 3 sig fig, 100.0 -> 4 sig fig

- Leading zeros aren't significant

Ex: 0.0153 -> 3 sig fig, 0.0010080 -> 5 sig fig

- in scientific notation, sig figs are calculated from the left portion

Ex: 2.53 x 10^4 -> 3 sig fig

- `addition/subtraction`: get the exact answer and keep the number of sig figs the least precise term has

Ex: 2.314 + 5.23 = 7.544 => 7.54 3 sig figs because 5.23 is less precise than 2.314

- `multiplication/division`: get the exact answer and keep the least amount of sig figs present in the terms

Ex: 9.6 x 7 = 67.2 => 70 1 sig fig because 7

- chaining operations: when chaining operations, get the exact answer but as you solve keep track of what term has how many sig figs. After, use the sig figs you kept track of to adequately round

Ex 1: 7.35 x 4.265 + 7.34 => 7.35 x 4.265 = 31.34775 (3 sig figs)

31.34775 + 7.34 = 38.68775 => 38.7

(3 sig fig)  (3 sig fig)

Ex 2: (8.46 - 5.312) / 2.8 => 8.46 - 5.312 = 3.148 (3 sig fig)

3.148 / 2.8 = 1.1242857143 => 1.1

(3 sig fig) (2 sig fig)

# Rounding
- rounding starts at the 1st sig fig
- can round normally, looking past 1 digit only

Ex: 0.0425 to 1 sig fig = 0.04, 36500 + 143.56 = 36643.56 => 36600 3 sig figs because 36500 is less precise

- rounding to a sig fig higher than present is done with scientific notation

Ex: 100 to 2 sig fig = 1.0 X 10^2, 100 to 4 sig fig = 1.000 x 10^2
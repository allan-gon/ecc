# Theorom
- let A, B be UT, LT, or Diagonal matrices of the same size
- A+B is UT, LT, or Diagonal
- kA us UT, LT, Diag
- AB is UT, LT, or Diag
- the type of matrix is preserved given the 2 matrices are the same type

- `proof by properties`

# Section 2.3
## Systems of Equations
- `homogenous`: if all of the constants are 0 then the system is this
- `consistent`: solutions exist
- `inconsistent`: no solutions
- some examples and stuff in ipad

# Section 2.4 
- `row echelon form`
    - all zero rows are at the bottom of the matrix
    - leading elements in any nonzero row is 1
    - any element below a leading 1 is 0
        - this means in the same column or in a row below but to the left of this leading 1

## Elementary Row Operations (EROs)
- you can move around any row (R1 <-> R2)
- you can add any 2 rows (R1 -> R1 + R2)
- you can multiply a row by any non-zero number (R -> kR)
- these rules applied to and augmented matrix do **NOT** impact sol set
- `theorom`: every matrix is row equivalent to a matrix in row echelon form
- `rank`: number of non-zero rows in row echelon form

## Algo I care about
- locate 1st non-zero column (pivot col)
- let the 1st row of the pivot column be the pivot position
- use row interchange to put a non-zero value in pivot position
- use scalar multi to make pivot position = 1
- use scalar multiple addition to make the column below the pivot position = 0
- now consider the sub matrix 1 row below and on column to the right

- `Reduced row echelon form`: matrix in REF but also every value above a leading 1 in the same column is 0
- rref is unique ref is not

# Question
- how do auto graders check if REF is correct then if it's not unqiue. I understand they're equivalent but they look quite different so if it's not simply checking the values of the matrix what do you do?
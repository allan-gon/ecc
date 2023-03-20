class ShapeMismatch(Exception):
    def __init__(self, *args: object) -> None:
        super().__init__(*args)


class Matrix:
    def __init__(self, rows: list[list[float]]) -> None:
        """
        Requires a list of lists of numbers
        """
        row_length = len(rows[0])
        for row in rows:
            if len(row) != row_length:
                raise ValueError("All rows must be the same size")
            for val in row:
                if not isinstance(val, (int, float)):
                    raise ValueError("All elements of a row must be numbers")
        self.data: list[list[float]] = rows
        self.size = (len(rows), len(rows[0]))

    def __str__(self) -> str:
        max_len = max(len(str(num)) for row in self.data for num in row)
        output = ""
        for row in self.data:
            output += "|"
            for num in row:
                output += str(num).ljust(max_len) + " "
            output += "|\n"
        return output

    def __eq__(self, right: object) -> bool:
        if isinstance(right, Matrix):
            if self.size == right.size:
                for row_idx, row in enumerate(self.data):
                    for col_idx, val in enumerate(row):
                        if val != right.data[row_idx][col_idx]:
                            return False
                return True
        return False

    def __ne__(self, right: object) -> bool:
        if isinstance(right, Matrix):
            if self.size == right.size:
                for row_idx, row in enumerate(self.data):
                    for col_idx, val in enumerate(row):
                        if val != right.data[row_idx][col_idx]:
                            return True
                else:
                    return False
            return True
        return True

    def __add__(self, right: object):
        data = []
        if isinstance(right, Matrix):
            if self.size == right.size:
                for row_idx, row in enumerate(self.data):
                    temp = []
                    for col_idx, val in enumerate(row):
                        temp.append(val + right.data[row_idx][col_idx])
                    data.append(temp)
            else:
                raise ValueError("Can only add matrices of same size")
        else:
            raise ValueError("Can only add matrices")
        return Matrix(data)

    def __sub__(self, right: object):
        data = []
        if isinstance(right, Matrix):
            if self.size == right.size:
                for row_idx, row in enumerate(self.data):
                    temp = []
                    for col_idx, val in enumerate(row):
                        temp.append(val - right.data[row_idx][col_idx])
                    data.append(temp)
            else:
                raise ValueError("Can only subtract matrices of same size")
        else:
            raise ValueError("Can only subtract matrices")
        return Matrix(data)

    def __mul__(self, scalar):
        data = []
        if isinstance(scalar, (int, float)):
            for _, row in enumerate(self.data):
                temp = []
                for _, val in enumerate(row):
                    temp.append(val * scalar)
                data.append(temp)
        else:
            raise ValueError("Can only use the * operator to multiply by a scalar")
        return Matrix(data)

    def __rmul__(self, scalar):
        return self.__mul__(scalar)

    def __truediv__(self, scalar):
        return (1 / scalar) * self

    def __rtruediv__(self, scalar):
        return (1 / scalar) * self

    def __neg__(self):
        return -1 * self

    def is_square(self) -> bool:
        return self.size[0] == self.size[1]

    def transpose(self):
        data = []
        for col_idx in range(self.size[1]):
            temp = []
            for row in self.data:
                temp.append(row[col_idx])
            data.append(temp)
        return Matrix(data)

    def is_symmetric(self) -> bool:
        return self.transpose() == self

    def is_skew_symmetric(self) -> bool:
        return self.transpose() == -self

    def trace(self) -> float:
        return sum(
            [
                self.data[i][j]
                for j in range(self.size[1])
                for i in range(self.size[0])
                if i == j
            ]
        )

    def identity(self):
        if self.is_square():
            return Matrix(
                [
                    [1 if i == j else 0 for i in range(self.size[0])]
                    for j in range(self.size[0])
                ]
            )
        raise ShapeMismatch("Only square matrices have an identity matrix")

    def mat_mul(self, other):
        data = []
        if isinstance(other, Matrix):
            if self.size[-1] == self.size[0]:
                # for every row
                transposed = other.transpose()
                for row in self.data:
                    temp = []
                    # transpose to make indexing easier
                    for col in transposed.data:
                        elem = 0
                        # dot it with every column
                        for idx, value in enumerate(row):
                            elem += value * col[idx]
                        temp.append(elem)
                    data.append(temp)
                return Matrix(data)
            raise ShapeMismatch(
                f"Can't multiply matrices with size: {self.size} and {other.size}"
            )
        raise ValueError("Can only multiply matrix with matrix")

    def __pow__(self, number: int):
        # incomplete since neg exp and non int exp are real bu not
        # implemented
        if self.is_square():
            if isinstance(number, int):
                if number >= 0:
                    if number == 0:
                        return self.identity()
                    result = self
                    for _ in range(1, number):
                        result = result.mat_mul(self)
                    return result
                raise ValueError("Exponent must be positive")
            raise ValueError("Exponent must be an integer")
        raise ShapeMismatch("Matrix exponentiation is only defined for square matrices")

    def to_ref(self):
        ...

    def to_rref(self):
        ...


if __name__ == "__main__":
    x = Matrix([1, 2, 3])
    print(x)
    # TODO: testing

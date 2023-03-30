from copy import deepcopy
from vector import Vector


class Matrix:
    def __init__(self, rows: list[Vector]) -> None:
        if not isinstance(rows, (list, tuple)):
            raise ValueError("Rows argument must be a list or tuple of vectors")
        size = dict()
        for row in rows:
            if not isinstance(row, Vector):
                raise ValueError("All elements of the rows parameter must be vectors")
            if "size" not in size:
                size["size"] = len(row)
            elif len(row) != size["size"]:
                raise ValueError("All vectors must be same length")
        self._data = rows

    def __copy__(self):
        return Matrix([vec.copy() for vec in self])

    def __str__(self) -> str:
        # extra final new line
        justifications = []
        for col_idx in range(len(self[0])):
            max_width = 0
            for row in self:
                if row[col_idx] == int(row[col_idx]):
                    row[col_idx] = int(row[col_idx])
                width = len(str(row[col_idx]))
                if width > max_width:
                    max_width = width
            justifications.append(max_width)

        string = ""
        for row in self:
            string += "|"
            for idx, col in enumerate(row):
                string += str(col).ljust(justifications[idx])
                if idx != (len(self[0]) - 1):
                    string += " "
            string += "|\n"
        return string

    def __getitem__(self, idx: int) -> Vector:
        return self._data[idx]

    def __setitem__(self, idx: int, val: Vector):
        self._data[idx] = val

    def __len__(self) -> int:
        return len(self._data)

    def __eq__(self, right) -> bool:
        if not isinstance(right, Matrix):
            return False
        if self.size() != right.size():
            return False
        for idx, vec in enumerate(self):
            if vec != right[idx]:
                return False
        return True

    def __ne__(self, right) -> bool:
        return not (self == right)

    def __add__(self, right):
        if not isinstance(right, Matrix):
            raise ValueError("Can only add 2 matrices together")
        if self.size() != right.size():
            raise ValueError("Can only add matrices of same size")
        new_data = []
        for idx, vec in enumerate(self):
            new_data.append(vec + right[idx])
        return Matrix(new_data)

    def __sub__(self, right):
        if not isinstance(right, Matrix):
            raise ValueError("Can only add 2 matrices together")
        if self.size() != right.size():
            raise ValueError("Can only add matrices of same size")
        new_data = []
        for idx, vec in enumerate(self):
            new_data.append(vec - right[idx])
        return Matrix(new_data)

    def size(self) -> tuple[int]:
        return (len(self), len(self[0]))

    def __mul__(self, right):
        if isinstance(right, (int, float)):
            return Matrix([right * vec for vec in self])
        elif isinstance(right, Matrix):
            if self.size()[1] == right.size()[0]:
                transposed = right.transpose()
                new_data = []
                for row in self:
                    temp = []
                    for col in transposed:
                        temp.append(row.dot(col))
                    new_data.append(Vector(temp))
                return Matrix(new_data)
            raise ValueError(
                f"Can't multiply matrix of size {self.size()}, {right.size()}"
            )
        raise ValueError("Can only multiply scalars or matrices")

    def __rmul__(self, right):
        if isinstance(right, (int, float)):
            return self.__mul__(right)

    def __pow__(self, exponent):
        if not isinstance(exponent, int):
            raise ValueError("Exponent must be integer")
        current = self
        while exponent > 1:
            current *= self
            exponent -= 1
        return current

    def __truediv__(self, right):
        if isinstance(right, (int, float)):
            return self * (1 / right)
        raise ValueError("Matrix only divisible by real number")

    def __neg__(self):
        return self * -1

    def is_square(self) -> bool:
        size = self.size()
        return size[0] == size[1]

    def is_symmetric(self) -> bool:
        return self == self.transpose()

    def is_skew_symmetric(self) -> bool:
        return self.transpose() == -self

    def transpose(self):
        new_data = []
        for col_idx in range(len(self[0])):
            temp = []
            for row in self:
                temp.append(row[col_idx])
            new_data.append(Vector(temp))
        return Matrix(new_data)

    def trace(self) -> float:
        total = 0
        for i in range(len(self)):
            total += self[i][i]
        return total

    def identity(self):
        if not self.is_square():
            raise ValueError("Identity matrix only exists for square matrices")
        new_data = []
        for row_idx in range(len(self)):
            temp = []
            for col_idx in range(len(self)):
                if row_idx == col_idx:
                    temp.append(1)
                else:
                    temp.append(0)
            new_data.append(Vector(temp))
        return Matrix(new_data)

    def is_consistent(self) -> bool:
        if len(self[0]) <= 1:
            raise ValueError("Matrix is non-augmented (too short)")
        non_aug = Matrix([Vector(vec._data[:-1]) for vec in self])
        return self.rank() == non_aug.rank()

    def to_ref(self):
        curr_row_idx = 0
        mat = deepcopy(self)

        # log operations
        with open("operations", "w") as file:
            # loop through all columns
            while curr_row_idx < len(mat):
                lm_lz_idx = dict()
                # of the remaining rows
                for row_idx, row in enumerate(mat[curr_row_idx:], curr_row_idx):
                    if "row_idx" not in lm_lz_idx:
                        lm_lz_idx["row_idx"] = row_idx
                    # find left most leading non-zero
                    for col_idx, elem in enumerate(row):
                        if elem != 0:
                            if "col_idx" not in lm_lz_idx:
                                lm_lz_idx["col_idx"] = col_idx
                            elif col_idx < lm_lz_idx["col_idx"]:
                                lm_lz_idx["col_idx"] = col_idx
                                lm_lz_idx["row_idx"] = row_idx
                            break
                # if no leading non-zero
                if "col_idx" not in lm_lz_idx:
                    # stop bc in ref
                    break
                else:
                    # log
                    file.write(f"swap {curr_row_idx} {lm_lz_idx['row_idx']}\n")
                    # swap rows
                    mat[curr_row_idx], mat[lm_lz_idx["row_idx"]] = (
                        mat[lm_lz_idx["row_idx"]],
                        mat[curr_row_idx],
                    )
                    # log
                    file.write(
                        f"divide {curr_row_idx} {mat[curr_row_idx][lm_lz_idx['col_idx']]}\n"
                    )
                    # make curr row leading 1
                    mat[curr_row_idx] = (
                        mat[curr_row_idx] / mat[curr_row_idx][lm_lz_idx["col_idx"]]
                    )
                    # clear the rows below
                    curr_row_idx += 1
                    for row_idx, row in enumerate(mat[curr_row_idx:], curr_row_idx):
                        lead_nz = row[lm_lz_idx["col_idx"]]
                        if lead_nz != 0:
                            # log
                            file.write(
                                f"subtract {row_idx} {lead_nz} {curr_row_idx - 1}\n"
                            )
                            mat[row_idx] = row - (lead_nz * mat[curr_row_idx - 1])
        return mat

    def to_rref(self):
        mat = self.to_ref()
        # log operations
        with open("operations", "a") as file:
            # loop rows in reverse
            for row_idx in [-i for i in range(1, len(mat) + 1)]:
                lnz_idx = dict()
                # find non-zero elem
                for col_idx, elem in enumerate(mat[row_idx]):
                    if elem != 0:
                        lnz_idx["col_idx"] = col_idx
                        break
                if "col_idx" in lnz_idx:
                    # clear above
                    for above_row_idx in [
                        -j for j in range((-1 * row_idx) + 1, len(mat) + 1)
                    ]:
                        above_nz = mat[above_row_idx][lnz_idx["col_idx"]]
                        # log
                        file.write(f"subtract {above_row_idx} {above_nz} {row_idx}\n")
                        mat[above_row_idx] = mat[above_row_idx] - (
                            mat[row_idx] * above_nz
                        )
        return mat

    def rank(self) -> int:
        ref = self.to_ref()
        rank = 0
        for vec in ref:
            for elem in vec:
                if elem:
                    rank += 1
                    break
        return rank

    def inverse(self):
        if not self.is_square():
            raise ValueError("Can only calc inverse matrix for square matrices")
        if self.rank() != len(self):
            raise ValueError("Rank doesn't equal number of rows/cols so non-invertable")

        # this will log what to do
        self.to_rref()
        mat = self.identity()
        # unpack operations
        with open("operations", "r") as file:
            contents = [line.split() for line in file.readlines()]
        # use operations
        for line in contents:
            if line[0] == "subtract":
                mat[int(line[1])] = mat[int(line[1])] - (
                    float(line[2]) * mat[int(line[3])]
                )
            elif line[0] == "divide":
                mat[int(line[1])] = mat[int(line[1])] / float(line[2])
            elif line[0] == "swap":
                mat[int(line[1])], mat[int(line[2])] = (
                    mat[int(line[2])],
                    mat[int(line[1])],
                )
        return mat

    def det(self) -> float:
        if not self.is_square():
            raise ValueError("Determinant only defined for square matrices")
        # this call gives me info i need in the file
        temp = self.to_ref()
        determinant = 1
        scalar = 1
        sign = 0

        for i in range(len(self)):
            # required because can have 0 in ref
            scalar *= temp[i][i]
        with open("operations", "r") as file:
            contents = [line.split() for line in file.readlines()]
        for line in contents:
            if line[0] == "swap":
                if line[1] != line[2]:
                    sign += 1
            elif line[0] == "divide":
                scalar *= float(line[2])
        return determinant * scalar * (((-1) ** sign))


if __name__ == "__main__":
    # TODO: more thorough testing
    A = Matrix(
        [
            Vector([0, 0, 3, 0]),
            Vector([1, 2, 0, 1]),
            Vector([1, 2, 0, 2]),
            Vector([2, 5, 1, 2]),
        ]
    )

    print(f"Rank: {A.rank()}")
    print(f"det(A): {A.det()}")
    print(f"det(A^-1): {A.inverse().det()}")
    print(A.inverse())
    # what in the wolfram alpha non-sense
    # how to test
    # proabably don't care. Not making high preformance, production, code

    # consistent + rank = num vars unqie sol
    # rank doesnt match = no sol

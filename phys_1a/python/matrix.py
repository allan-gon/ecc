from ast import Not


class ShapeMismatch(Exception):
    pass


class Matrix:

    def __init__(self, mat: list[list[float]]):
        self.matrix = []
        # verify shape
        for row in mat:
            if len(row) != len(mat[0]):
                raise ShapeMismatch
            # verify type
            for val in row:
                if not isinstance(val, (int, float)):
                    return NotImplemented
            # if tests passed save the row
            self.matrix.append(row)
    

    def det(self) -> float:
        num_cols = len(self.matrix[0])
        num_rows = len(self.matrix)
        for i in range(len(i)):
            ...
            # TODO: get this to work

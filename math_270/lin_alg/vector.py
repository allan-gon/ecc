from math import acos, pi


class Vector:
    def __init__(self, elems: list[float]) -> None:
        self._data = []
        for num in elems:
            if not isinstance(num, (int, float)):
                raise ValueError("All elements must be real numbers")
            else:
                self._data.append(num)

    def __copy__(self):
        return Vector([i for i in self._data])

    def __str__(self) -> str:
        return f"|{' '.join([str(num) for num in self._data])}|"

    def __getitem__(self, idx: int) -> float:
        return self._data[idx]

    def __setitem__(self, idx: int, val: float) -> float:
        if not isinstance(val, (int, float)):
            raise ValueError("Elements must be real numbers")
        self._data[idx] = val

    def __len__(self) -> float:
        return len(self._data)

    def __eq__(self, right) -> bool:
        if not isinstance(right, Vector):
            return False
        if len(self) != len(right):
            return False
        for idx, val in enumerate(self):
            if val != right[idx]:
                return False
        return True

    def __ne__(self, right) -> bool:
        return not (self == right)

    def __add__(self, right):
        """Becuase this is vec to vec there is no need for radd"""
        if not isinstance(right, Vector):
            raise ValueError("Can only add vector to vector")
        if len(self) != len(right):
            raise ValueError("Can only add vectors of same size")

        new_data = []
        for idx, val in enumerate(self):
            new_data.append(val + right[idx])
        return Vector(new_data)

    def __sub__(self, right):
        if not isinstance(right, Vector):
            raise ValueError("Can only add vector to vector")
        if len(self) != len(right):
            raise ValueError("Can only add vectors of same size")

        new_data = []
        for idx, val in enumerate(self):
            new_data.append(val - right[idx])
        return Vector(new_data)

    def __mul__(self, right):
        if not isinstance(right, (int, float)):
            raise ValueError("Can only scale vector by real number")
        return Vector([right * num for num in self])

    def __rmul__(self, right):
        return self.__mul__(right)

    def __truediv__(self, right):
        return self.__mul__(1 / right)

    def __neg__(self):
        return Vector([-num for num in self])

    def norm(self) -> float:
        total = 0
        for val in self:
            total += val**2
        return total ** (1 / 2)

    def dot(self, right) -> float:
        if not isinstance(right, Vector):
            raise ValueError("Can only dot vectors")
        if len(self) != len(right):
            raise ValueError("Can only dot vectors of equal size")

        dot_product = 0
        for idx, val in enumerate(self):
            dot_product += val * right[idx]
        return dot_product

    def cross(self, right):
        ...

    def angle_with(self, right, radians: bool = True) -> float:
        if not isinstance(right, Vector):
            raise ValueError("Can only find angle between vectors")
        if len(self) != len(right):
            raise ValueError("Can only find angle between vectors of same size")
        ang_rad = acos(self.dot(right) / (self.norm() * right.norm()))
        return ang_rad if radians else (ang_rad * 180) / pi

    def to_unit(self):
        return Vector((self / self.norm()))

    def is_orthoganol(self, right) -> bool:
        return not self.dot(right)

    def is_parallel(self, right) -> bool:
        ...


if __name__ == "__main__":
    # if matrix[index] return a vector then does matrix[idx][idx] return a specific elem
    x = Vector(1, 0, 0)
    y = Vector(0, 0, 1)
    print(x.is_orthoganol(y))
    # TODO: implement the last 2 functions

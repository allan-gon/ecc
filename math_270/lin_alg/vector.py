class Vector:
    def __init__(self, *args: float) -> None:
        for num in args:
            if not isinstance(num, (int, float)):
                raise ValueError("All elements must be real numbers")
        else:
            self._data = tuple(num for num in args)

    def __str__(self) -> str:
        return f"|{' '.join([str(num) for num in self._data])}|"

    def __getitem__(self, index) -> float:
        return self._data[index]

    def __len__(self) -> float:
        return len(self._data)

    def __add__(self, other):
        if not isinstance(other, Vector):
            raise ValueError("Can only add vector to vector")
        if len(self) != len(other):
            raise ValueError("Can only add vectors of same size")

        new_data = []
        for idx, val in enumerate(self):
            new_data.append(val + other[idx])
        return Vector(*new_data)
    
    def __sub__(self, other):
        if not isinstance(other, Vector):
            raise ValueError("Can only add vector to vector")
        if len(self) != len(other):
            raise ValueError("Can only add vectors of same size")

        new_data = []
        for idx, val in enumerate(self):
            new_data.append(val - other[idx])
        return Vector(*new_data)


if __name__ == "__main__":
    x = Vector(1, 2, 3)
    y = Vector(1, 2, 3)
    print(x - y)

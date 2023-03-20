from unittest import TestCase, main
from random import randint
from matrix import Matrix


def gen_data() -> list[list[int]]:
    data = []
    nums_rows = randint(1, 10)
    num_cols = randint(1, 10)
    for _ in range(nums_rows):
        temp = []
        for _ in range(num_cols):
            temp.append(randint(-1000, 1000))
        data.append(temp)
    return data


class TestMatrix(TestCase):
    def test_invalid_instantiation(self):
        with self.assertRaises(TypeError):
            Matrix()

        # create an matrix where the last row is 1 column longer than the rest
        bad_shape = gen_data()
        bad_shape.append([bad_shape[-1][-1] for _ in range(len(bad_shape[-1]) + 1)])
        # create a matrix with invalid type in it
        contains_str = gen_data()
        contains_str[-1][-1] = "Bad string"

        with self.assertRaises(ValueError):
            Matrix(bad_shape)
            Matrix(contains_str)

    def test_valid_instantiation(self):
        single_row = [[1, 2, 3]]
        single_col = [[1], [2], [3]]
        random_shaped = gen_data()

        for data in (single_row, single_col, random_shaped):
            self.assertIsInstance(Matrix(data), Matrix)


if __name__ == "__main__":
    main()

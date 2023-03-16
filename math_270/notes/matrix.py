class BadInput(Exception):
    def __init__(self, *args: object) -> None:
        super().__init__(*args)


class Matrix:
    def __init__(
        self,
        *args: float,
        rows: list[list[float]] = None,
        cols: list[list[float]] = None
    ) -> None:
        """
        Can instantiate by passing in only rows, only columns, or a single row element by element
        """

        # user only passed in columns
        if (len(*args) == 0) and (not rows) and cols:
            if not isinstance(cols, list):
                raise BadInput("The Column Parameter must be a list")
            # ensure shape is consistent
            shape_0 = cols

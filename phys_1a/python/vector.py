from math import sin, cos, acos, pi
from tkinter import X


class ShapeMismatch(Exception):
    pass


class Vector:

    def __init__(self, *components: float) -> None:
        self.components = []
        for component in components:
            self.components.append(float(component))


    def __str__(self):
        return f"<{', '.join([str(comp) for comp in self.components])}>"


    def __len__(self) -> int:
        return len(self.components)


    def __add__(self, other):
        if isinstance(other, Vector):
            if len(self) == len(other):
                return Vector(*[self.components[i] + other.components[i] for i in range(len(self))])
            raise ShapeMismatch
        return NotImplemented


    def __sub__(self, other):
        if isinstance(other, Vector):
            if len(self) == len(other):
                return Vector(*[self.components[i] - other.components[i] for i in range(len(self))])
            raise ShapeMismatch
        return NotImplemented


    def __rmul__(self, other):
        if isinstance(other, (float, int)):
            return Vector(*[other*comp for comp in self.components])
        return NotImplemented


    def norm(self) -> float:
        magnitude = 0
        for component in self.components:
            magnitude += component**2
        return magnitude**(1/2)
    

    def dot(self, other) -> float:
        if isinstance(other, Vector):
            if len(self) != len(other):
                raise ShapeMismatch
            else:
                dot_product = 0
                for i in range(len(self)):
                    dot_product += self.components[i] * other.components[i]
                return dot_product
        return NotImplemented
    

    def cross(self, other):
        if isinstance(other, Vector):
            ...
        return NotImplemented

    
    def angle_between(self, other, in_radians: bool = True) -> float:
        if isinstance(other, Vector):
            if len(self) == len(other):
                answer = acos(self.dot(other) / (self.norm() * other.norm()))
                if in_radians:
                    return answer
                return answer * (180 / pi)
            else:
                raise ShapeMismatch
        return NotImplemented


    def from_ang_hyp(self, angle: float, hypotenuse_len: float, axis: str, is_radians: bool = True):
        """
        Calculates the vector components from an angle and it's magnitude. 
        The components are returned in a new object
        @param angle: float, the angle the vector makes with a positive axis
        @param hypotenuse_len: float, the magnitude of the vector
        @param axis: str, the axis the angle is relative to
        return
        """
        # TODO: if i dont know the quadrant, the signs have no garuntee of being correct
        if isinstance(angle, (int, float)):
            if isinstance(hypotenuse_len, (int, float)):
                if is_radians:
                    x_comp = hypotenuse_len*cos(angle)
                    y_comp = hypotenuse_len*sin(angle)
                else:
                    x_comp = hypotenuse_len*cos(angle * (pi / 180))
                    y_comp = hypotenuse_len*sin(angle * (pi / 180))
                if axis.lower() == "x":
                    return Vector(x_comp, y_comp)
                elif axis.lower() == "y":
                    return Vector(y_comp, x_comp)
                elif axis.lower() == "z":
                    return NotImplemented # TODO: 
                else:
                    raise ValueError
            else:
                NotImplemented
        else:
            return NotImplemented
    

    def to_unit(self) -> str:
        """
        Return a string representation of the vector in terms of the unit vectors
        """
        letters = "ijklmnopqrstuvwxyz"
        if len(self) == 0:
            raise NotImplemented # TODO: ...
        else:
            scaled = [f"{round(self.components[i]/self.norm(), 3)}{letters[i]}" for i in range(len(self))]
        return " + ".join(scaled)

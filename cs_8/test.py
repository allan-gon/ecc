heights = [2.01, 1.91, 2.06]
min_heigh_diff = min([abs(i - j) for j in heights for i in heights])
print(min_heigh_diff) # problem when i -j is really i - i
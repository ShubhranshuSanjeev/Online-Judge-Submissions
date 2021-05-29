import math
a = float(input())
b = float(input())
c = float(input())

determinant = math.sqrt((b**2)-(4*a*c))
root1 = ((-b) + determinant)/(2*a)
root2 = ((-b) - determinant)/(2*a)
print(root1)
print(root2)

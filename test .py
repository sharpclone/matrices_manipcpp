import numpy as np

# Read the matrix from file
filename = "/home/mihu/Documents/Workspace/Hw/matrice/PR5.in"
matrix = np.loadtxt(filename)

# Find the inverse of the matrix
inverse = np.linalg.inv(matrix)

# Print the inverse
print("Inverse of the matrix:")
print(inverse)

# Multiply the matrix by its inverse to check
result = np.dot(matrix, inverse)

# Print the result
print("Matrix multiplied by its inverse:")
print(result)

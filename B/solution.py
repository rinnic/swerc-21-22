from sys import stdin

n = int(input())
matrix = [line.strip().split(" ") for line in stdin.readlines()]

solution = 0

#brute force coordinates generation
for i in range(0, n):
  for j in range(0, n):
    for x in range(1, n - i):
      for y in range(1, n - j):
        # I check the 4 possible arrangments
        if matrix[i][j] < matrix[i][j+y] and matrix[i+x][j] < matrix[i+x][j+y]:
          solution += 1
          continue
        if matrix[i][j] > matrix[i][j+y] and matrix[i+x][j] > matrix[i+x][j+y]:
          solution += 1
          continue
        if matrix[i][j] < matrix[i+x][j] and matrix[i][j+y] < matrix[i+x][j+y]:
          solution += 1
          continue
        if matrix[i][j] > matrix[i+x][j] and matrix[i][j+y] > matrix[i+x][j+y]:
          solution += 1
          continue
        print(solution)
print(solution)
  
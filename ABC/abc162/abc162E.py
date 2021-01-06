import math
from functools import reduce

def gcd(A):
    return reduce(math.gcd, A)

n, k = map(int, input().split())
A =[]
for i in range (n+1):
    A.append(i)

c_list = list[itertools.combinations(A, k)]
print(c_list)
"""
sum = 0
for i in range(1, n+1):
    for j in range(1, n+1):
        for k in range(1, n+1):
            A = {i, j, k}
            print(gcd(A))
            sum += gcd(A)

print(sum)
"""

import math
from functools import reduce

def gcd(*numbers):
    return reduce(math.gcd, numbers)

n = int(input())

sum = 0
for i in range(1, n+1):
    for j in range(1, n+1):
        for k in range(1, n+1):
            sum += gcd(i,j,k)

print(sum)

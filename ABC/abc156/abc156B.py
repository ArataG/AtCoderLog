import sys
import os
f = open('input.txt', 'r')
sys.stdin = f

#imput
n, k = map(int,input().split())

for i in range(10**9):
    if n < k**i:
        ans = i
        break

print(ans)

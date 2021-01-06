import sys
import os
f= open('158_C_input.txt', 'r')
sys.stdin = f

#input
A, B = map(int,input().split())
#消費税0.08 0.1
import math

ans = -1

for n in range(1001):##最大値を間違えていた#1000回くらいならfor文まわしちゃえばよいという発想
        if math.floor(n*0.08) == A and math.floor(n*0.1) == B:
            ans = int(n)
            break

print(ans)

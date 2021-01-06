import sys
import os
f= open('input.txt', 'r')
sys.stdin = f

#imput
a,b,c = map(int,input().split())

#swap
a, b = b, a
a, c = c, a

print(a,b,c)

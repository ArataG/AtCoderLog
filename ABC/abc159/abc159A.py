import sys
import os
f= open('159_A_input.txt', 'r')
sys.stdin = f

N,M = map(int,input().split())

ans = 0
if N > 1:
    ans += N*(N-1)/2

if M > 1:
    ans += M*(M-1)/2

print(int(ans))

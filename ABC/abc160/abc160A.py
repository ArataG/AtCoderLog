import sys
import os
f= open('160_A_input.txt', 'r')
sys.stdin = f

#imput
S = list(input())

if S[2] == S[3] and S[4] == S[5]:
    print('Yes')
else:
    print('No')

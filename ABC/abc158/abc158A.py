import sys
import os
f= open('158_A_input.txt', 'r')
sys.stdin = f

#input
S = input()
ans = 'Yes'
if S == 'AAA':
    ans = ('No')
if S == 'BBB':
    ans = ('No')

print(ans)

#output

import sys
import os
f= open('160_B_input.txt', 'r')
sys.stdin = f
#input
N = int(input())

#
ans = 0
flag = True
flag2 = True

while flag:

    if N < 500:
        flag = False
    else:
        ans += 1000
        N-= 500

while flag2:

    if N < 5:
        flag2 = False
    else:
        ans+=5
        N -= 5

print(ans)

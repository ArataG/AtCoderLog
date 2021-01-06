import sys
import os
f= open('input.txt', 'r')
sys.stdin = f


def check(i, n, x):
    if ((i//n)!=(x//n)):
        return False
    else:
        return True


#
N, M = map(int,input().split())
A = [list(map(int,input().split())) for i in range(M)]
A.sort()

K = []
#全探索
for i in range(N*10):
    #print(i)
    for m in range(M):
        if check(i, A[m][0], A[m][1]):
            K.append(i)
        else:
            K.append(-1)
print(min(K))

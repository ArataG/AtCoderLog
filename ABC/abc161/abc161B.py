import sys
import os
f= open('input.txt', 'r')
sys.stdin = f

#input
N, M = map(int,input().split())
A = list(map(int,input().split()))

#count num
count = 0
for i in range(N):
    if A[i] * 4 * M >= sum(A): #A[i] = sum(A)/(4*M)
        count +=1

#Check availavle N
if count >= M:
    print("Yes")
else:
    print("No")

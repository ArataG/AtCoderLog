import sys
import os
f= open('160_C_input.txt', 'r')
sys.stdin = f

#
N, X, Y = map(int,input().split())

'''
#print(len(A))
#print(A[0]-A[1])
#Maxの差
Ma=0
for i in range(N-1):
    if Ma < A[i+1]-A[i]:
        Ma = A[i+1]-A[i]

if Ma < A[0]+ K-A[N-1]:
    Ma = A[0]+ K-A[N-1]

#k-n
ans = K-Ma
#print(Ma)
print(ans)
'''

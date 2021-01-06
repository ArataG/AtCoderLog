import sys
import os
f= open('160_D_input.txt', 'r')
sys.stdin = f

#
N,X,Y = map(int,input().split())

print(N)

#base
for k in range(1,N-1):
    if k <= Y-X:
        ans= N-k
        ans += Y-X-k

    elif k > Y-X and N-k-1 >= Y-X:
        ans= N-k
        ans += -(Y-X-k)

    #if N-k == Y-X-1:
    #    ans = 1
    if N-k-1 < Y-X:
        ans = 0

    print(ans)

#if X == 0 or Y == N

    #else:
    #    print(N-i-(Y-X))


# Y-X > K

'''
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

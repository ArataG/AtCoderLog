import sys
import os
f= open('input.txt', 'r')
sys.stdin = f


#
N, M = map(int,input().split())
A = [list(map(int,input().split())) for i in range(M)]
A.sort()

flag = True

for i in range(M-1):
    if (A[i][0]==A[i+1][0]) & (A[i][1]!=A[i+1][1]):
        flag = False

ans = [0]*3
for i in range(M):
    if A[i][0] == 1:
        ans[0] = A[i][1]
    elif A[i][0] == 2:
        ans[1] = A[i][1]
    elif A[i][0] == 3:
        ans[2] = A[i][1]


if (N == 3) & (ans[0] == 0):
    flag = False

if (N == 2) & (ans[1] == 0):
    flag = False

if flag:
    n = 3-N
    for i in range(n):
        ans.pop(0) #iの位置のアイテムをリストから削除し，このアイテムを返す
    for i in range(len(ans)):
       print(ans[i], end='')
else:
    print(-1)




"""

#同じ桁に違う数字
for i in range(M):
    A[i][0] == A[i][0]

#一桁目に０
if N == 2:
    pass
elif N == 3:
    for i in range(M):
        pass


#それ以外は
for i in range(M):
    ans.insert(A[i][0],A[i][1]) #iの位置にアイテムｘを追加
print(ans)
for i in range(1,6,2):
    print(ans[i], end="")
"""



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

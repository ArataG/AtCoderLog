import sys
import os
f= open('input.txt', 'r')
sys.stdin = f
A = [list(map(int,input().split())) for i in range(3)]
N = int(input())
b = [int(input()) for i in range(N)]
C = sum(A, [])
#print(C)
#8通り調べればよい
for i in range(N):
    for j in range(len(C)):
        if b[i] == C[j]:
            C[j] = 0


flag = False
#print(C)
#
if C[0] == C[1]==C[2]:
    flag = True
if C[3] == C[4]==C[5]:
    flag = True
if C[6] == C[7]==C[8]:
    flag = True
#
if C[0] == C[3]==C[6]:
    flag = True
if C[1] == C[4]==C[7]:
    flag = True
if C[2] == C[5]==C[8]:
    flag = True
#
if C[0] == C[4]==C[8]:
    flag = True
if C[2] == C[4]==C[6]:
    flag = True

if flag:
    print("Yes")
else:
    print("No")

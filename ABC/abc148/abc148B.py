n = int(input())
S, T = input().split()

A = []
for i in range(n):
    A.append(S[i])
    A.append(T[i])

for i in range(len(A)):
    print(A[i], end = "")

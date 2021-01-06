n = int(input())
S = input()

A  = []
for i in range(n):
    if S[i] == "R":
        A.append(-1)
    if S[i] == "G":
        A.append(-2)
    if S[i] == "B":
        A.append(3)

cnt = 0
for i in range(0, n):
    for j in range(i+1, n):
        for k in range(j+1, n):
            if A[i]+A[j]+A[k]== 0:
                if (j - i) != (k - j):
                    cnt += 1

print(cnt)

A = "ABCDEFGHIJKLMNOPQRSTUVWXYZABCDEFGHIJKLMNOPQRSTUVWXYZ"
n = int(input())
S = input()

ANS = []*n
for i in range(len(S)):
    x = A.index(S[i])
    ANS.append(A[n+x])
for i in range(len(ANS)):
    print(ANS[i], end = "")

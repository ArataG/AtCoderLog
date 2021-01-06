S = input()

if len(S) == 1:
    print(0)
else:
    n = len(S)//2
    cnt = 0
    for i in range(n):
        if S[i] != S[-(1+i)]:
            cnt += 1
    print(cnt)

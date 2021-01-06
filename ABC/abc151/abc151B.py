n, k, m = map(int,input().split())
A = list(map(int, input().split()))
ans = 0
sum = sum(A)
for i in range(0, 110):
    ans = i
    if (i + sum) >= (m * n):
        break

if ans > k:
    print("-1")
else:
    print(ans)

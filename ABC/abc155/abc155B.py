n = int(input())
A = list(map(int,input().split()))

flag = True
for i in range(n):
    if A[i]%2 == 0:
        if (A[i]%3 != 0) and (A[i]%5) != 0:
            flag = False

if flag:
    print("APPROVED")
else:
    print("DENIED")

"""
6min30s
"""

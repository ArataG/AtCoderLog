n = int(input())
S = input()

if n%2 == 0:
    p = n//2
    if S[:p] == S[p:]:
        print("Yes")
    else:
        print("No")
else:
    print("No")

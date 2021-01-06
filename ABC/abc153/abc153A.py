H, A = map(int, input().split())
ans = 0
ans = H//A
if H%A != 0:
    ans += 1

print(ans)

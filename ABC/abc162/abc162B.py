n = int(input())
cnt = 0
sum = 0
while cnt < n:
    cnt += 1
    if (cnt%3 != 0) and (cnt%5 != 0):
        sum += cnt



print(sum)

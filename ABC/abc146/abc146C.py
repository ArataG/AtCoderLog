import sys
import os
f= open('input.txt', 'r')
sys.stdin = f
#

a, b, x = map(int, input().split())
high = 10 ** 9 + 1
low  = 0
while high - low > 1: #ここが０だとループぬけれない
    mid = (high + low) // 2
    if (a * mid + b * len(str(mid))) <= x:
        low = mid
    else:
        high = mid
print(low)

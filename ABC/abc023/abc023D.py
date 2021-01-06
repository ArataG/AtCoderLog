
import sys
import os
f= open('023_D_shagekiou.txt', 'r')
sys.stdin = f

N = int(input())
B = [tuple(map(int, input().split())) for _ in range(N)]
#print(B)

def check(x):
    Ti = sorted([(x-h)//s for h, s in B]) #各風船iが高さｘに到達するまでの時間
    #print(Ti)
    for i, t in enumerate(Ti):
        #print(i, t)
        if i > t:
            return False
    return True  # all i<t ：左側を二分探索＞

#Binary Search
left = -1 #low −１＜mid が　０の可能性があるから
right = 10**16 #high xの最大値

while right-left > 1:
    mid = left + (right-left)//2 #leftが−のとき，＋のとき

    if check(mid):
        right = mid
    else:
        left = mid
    #print(check(mid))
    #print(right, left, mid)

print(right)

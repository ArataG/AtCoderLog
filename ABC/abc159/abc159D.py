#list.insert(i,x) ＃iの位置にアイテムｘを追加
import sys
import os
f= open('159_D_input.txt', 'r')
sys.stdin = f


N = int(input())
A = list(map(int,input().split()))

#print(A)
#x = A.count(1) #リストの中の値がｘである個数を返す
base = 0
m = 0
ans = 0
for i in range(1,N+1):
    x = A.count(i)
    if x > 1:
        base += int(x*(x-1)/2)

    m = A.count(A[i-1])

    if m == 1:
        ans = base
        #print(ans)
    elif m == 2:
        ans = base -1
        #print(ans)
    else:
        ans = int(base-m*(m-1)/2+(m-1)*(m-2)/2)
        #print(ans)

    print(ans)

'''
for i in range(N):
    m = A.count(A[i])
    #print(m)
    if m == 1:
        ans = base
        print(ans)
    elif m == 2:
        ans = base -1
        print(ans)
    else:
        ans = int(base-m*(m-1)/2+(m-1)*(m-2)/2)
        print(ans)
'''

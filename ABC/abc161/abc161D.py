import sys
import os
f= open('input.txt', 'r')
sys.stdin = f

#input
from collections import deque
k = int(input())

Q = deque(range(1, 10)) #るんるん数を格納するキュー
# Q: 1 2 3 4 5 6 7 8 9

for i in range(k):
  x = Q.popleft()
  #x = 1 <--  Q: 2 3 4 5 6 7 8 9
  last_digit = x % 10 # 1 一番目の桁の値
  z = 10*x + last_digit #11

  if last_digit != 0:
    Q.append(z-1)
    # Q: 2 3 4 5 6 7 8 9 <--10
  Q.append(z)
  # Q: 2 3 4 5 6 7 8 9 10 <--11
  if last_digit != 9:
    Q.append(z+1)
    # Q: 2 3 4 5 6 7 8 9 10 11 <--12
print(x)

"""
10 11 12 は　１桁目が１のときに，二桁目に続くことができる数字を格納している．y = x % 10 # 1 一番目の桁の値が０で続くことができるのは，０と１のみ，
同様に，　y＝９のときに，続くことができる値は8と9
上記をif文で条件わけしてもわかりやすいかも
for i in range(k):
  x = Q.popleft()
  #x = 1 <--  Q: 2 3 4 5 6 7 8 9
  last_digit = x % 10 # 1 一番目の桁の値
  if last_digit == 0:
        Q.append(10*x + 0)
        Q.append(10*x + 1)

  elif last_digit == 9:
        Q.append(10*x + 8)
        Q.append(10*x + 9)

  else: # 1<=last_digit <=8
        Q.append(10*x + last_digit - 1)
        Q.append(10*x + last_digit)
        Q.append(10*x + last_digit + 1)
print(x)

"""

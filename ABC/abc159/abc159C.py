import sys
import os
f= open('159_C_input.txt', 'r')
sys.stdin = f

L = int(input())
V = (L/3)**3
print(V)

#import math
#input
'''
a,b,c = map(int,input().split())

#すべて整数で解いてしまう
if 4*a*b < (c-a-b)*(c-a-b) and c-a-b>0:
    print('Yes')
else:
    print('No')


#print(H)
#print(a)

#print(math.sqrt(a))
#例外処理が？ 浮動小数点だとおもうけれど．．．
#if a + b + 2*math.sqrt(a)*math.sqrt(b) < c:
'''

'''
if  2*math.sqrt(a)*math.sqrt(b) < c-a-b:
    print('Yes')
else:
    print('No')

'''




''''
if math.sqrt(a)+math.sqrt(b) < math.sqrt(c):
    print('Yes')
else:
    print('No')

(a, b, c) = (249999999, 250000000, 999999998) などのケースで WA となってしま
います。

'''

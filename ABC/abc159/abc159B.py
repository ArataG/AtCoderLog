import sys
import os
f= open('159_B_input.txt', 'r')
sys.stdin = f

S = list(input())
#print(S)
#print(len(S))

a=int((len(S)-1)/2)

def is_kaibun(kaibun):
    for i in range(len(kaibun)//2):
        if kaibun[i] != kaibun[-i-1]:
            return False
    return True

if is_kaibun(S) and is_kaibun(S[:a]) and is_kaibun(S[a+1:]):
        print('Yes')

else:
    print('No')




'''
#input
H,W = map(int,input().split())
#print(H)

if H == 1 or W == 1:
    pass#print(1)

if H*W%2 == 0:
    print(int(H*W/2))
else:
    print(int(H*W//2 + 1)
#output
#output
'''

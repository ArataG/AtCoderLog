import sys
import os
f= open('158_B_input.txt', 'r')
sys.stdin = f

N, A, B = map(int,input().split())

q, x = divmod(N, A+B)
#q = N//(A+B)
#x = N % (A+B)
ans = q*A+int(min(x,A))
'''
、N を A + B で割った余りと A の大小関係が重要で、
N を A + B で割った余りを R とすると、min(R, A) だけ含まれます。

'''


print(ans)


"""
ans = 0
cc = N
for n in range(N):
    for a in range(A):
        ans +=1
        N -=1
        if N < 0:
            break
        for b in range(B):
            N -= 1
            if N < 0:
                break

print(ans)
"""

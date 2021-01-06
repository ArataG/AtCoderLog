import math
n = int(input())
X = [0]*n
Y = [0]*n
for i in range(n):
    X[i],Y[i] = map(int, input().split())

X.append(X[0])
Y.append(Y[0])

#階乗を求める再帰関数
def factional(n):
    print(n)
    if n == 1:
        return 1
    return n * factional(n-1)


def length(X1, Y1, X2, Y2):
    l = (X2-X1)**2 + (Y2-Y1)**2
    return math.sqrt(l)

sum = 0
for i in range(n):
    sum += length(X[i],Y[i],X[i+1],Y[i+1])
#print(sum)
ans = sum * 2/n
print(ans)

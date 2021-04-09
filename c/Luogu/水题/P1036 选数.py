import math as m

prime = []
a = []
used = [] * 20
n = 0
k = 0
count = 0


def findPrime(n):
    x = [0]*(n+1)
    x[0] = 1
    x[1] = 1
    for i in range(2, m.sqrt(n)):
        if x[i] == 0:
            for j in range(2, m.sqrt(n)):
                x[i*j] = 1
    for item in x:
        if x[item] == 0:
            global prime
            prime.append(x[item])


def func(kx, s):
    if(kx == 0):
        if s in prime:
            global count
            count += 1
    else:
        for item in a:
            if a[item] not in used:
                used[kx] = a[item]
                func(kx-1, s+a[item])
                used[kx] = None


tmp = input().split()
n = int(tmp[0])
k = int(tmp[1])
a = input().split()
for item in a:
    a[item] = int(a[item])
maxn = 0
for item in a:
    maxn += a[item]
findPrime(maxn)
func(k, 0)
print(count)

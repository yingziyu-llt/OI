a = input()
a = a.split()
k = int(a[0])
m = int(a[1])
n = 1
count  = 1
while not n % m ==k:
    count = count + 1
    n = n * 10 + 1
print(count)

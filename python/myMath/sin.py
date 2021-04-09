import fact

def mysin(x, n):
    i = 1
    ans = 0
    for i in range(0, n):
        if (i % 4 == 3):
            ans -= pow(x, i)/fact.fact(i)
        elif (i % 4 == 1):
            ans += pow(x, i)/fact.fact(i)
    return ans

if __name__ == "__main__":
    x = float(input("输入要计算的正弦值"))
    x = x - (x // (2 * 3.14159265)) * (2 * 3.14159265)
    n = 100
    ans = mysin(x, n)
    print(ans)

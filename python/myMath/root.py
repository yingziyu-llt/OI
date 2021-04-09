import pow
import abs


def root(x, n, xi):
    """注意：x是被开方数，n是开方次数，n是正整数,xi是允许的误差"""
    l = -100000000000000000000
    r = 10000000000000000000
    mid = (l + r) / 2
    while abs.abs(x - pow.pow(mid, n)) > xi:
        if x - pow.pow(mid, n) > 0:
            l = mid
        else:
            r = mid
        return mid

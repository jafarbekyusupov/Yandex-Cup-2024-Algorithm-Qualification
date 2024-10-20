import math

def lcm(x, y):
    return x * y // math.gcd(x, y)

def rif(X, a, b, c):
    lcab = lcm(a, b)
    lcbc = lcm(b, c)
    lcac = lcm(a, c)
    lcabc = lcm(lcab, c)
    cnt = (X // lcab) + (X // lcbc) + (X // lcac)
    cnt -= 3 * (X // lcabc)
    return cnt

def nvalid(a, b, c, n):
    l, h = 1, 10**18
    while l <= h:
        mid = (l + h) // 2
        if rif(mid, a, b, c) >= n:
            h = mid - 1
        else:
            l = mid + 1
    return l if l <= 10**18 else -1

a, b, c = map(int, input().split())
n = int(input())
print(nvalid(a, b, c, n))

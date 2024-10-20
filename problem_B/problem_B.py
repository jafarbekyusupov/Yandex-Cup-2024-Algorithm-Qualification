#NOT WORKING WA AT TEST 2 => FUKC YANDEX

t = int(input())
for z in range(t):
    c = 0
    n = int(input())
    h = list(map(int, input().split()))
    i = 1
    while i < n - 1:
        if h[i] > h[i - 1] and h[i] > h[i + 1]:
            c += 2
            
            j = 2
            while (i - j >= 0 and i + j < n) and (h[i] > h[i - j] and h[i] > h[i + j]):
                c += 2
                j += 1
            
            i += j
        else:
            i += 1
    
    print(c)

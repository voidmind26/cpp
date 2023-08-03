t = int(input())
for i in range(0, t):
    [n, k] = list(map(int, input().split(" ")))
    a = list(map(int, input().split(" ")))
    sum = 0
    ssum = 0
    for i in a:
        sum += i
        ssum += i*i
    l = 1
    r = 2e9
    r = int(r)
    l = int(l)
    ans = 0
    while 1:
        if (l >= r):
            ans = l
            break
        mid = int((l+r)/2)
        if mid*mid*4*n+4*sum*mid+ssum >= k:
            r = mid
        else:
            l = mid+1
    print(ans)

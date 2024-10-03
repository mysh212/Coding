# Author : ysh
# 2024/09/27 Fri 21:57:18
for i in range(int(input())):
    a,b = [int(i) for i in input().split()]
    f = [int(i) for i in input().split()]
    q = [int(i) for i in input().split()]
    pre = set(q)
    ans = {}

    for k in range(a):
        left = (k + 1)
        right = (a - k)
        now = ((left * right) - 1)
        # print([k, now], end = ' ')
        if now in pre:
            ans[now] = ans.get(now,0) + 1
    
    # print('')
    
    for k in range(a - 1):
        left = k + 1
        right = (a - k - 1)
        now = left * right
        if now in pre:
            ans[now] = ans.get(now,0) + (f[k + 1] - f[k] - 1)

    for i in q:
        print(ans.get(i,0),end = ' ')

    # print(ans)
    
    print('')
# Author : ysh
# 2024/11/20 Wed 16:12:43
# https://codeforces.com/contest/1362/problem/B
for _ in range(int(input())):
    n = int(input())
    f = set([int(i) for i in input().split()])
    c = False
    for i in range(1, (max(f) << 1) + 1):
        if f == set([j ^ i for j in f]):
            print(i)
            c = True
            break
    if not c:
        print(-1)
quit()
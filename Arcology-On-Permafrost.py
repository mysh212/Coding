# Author : ysh
# 2025/04/10 Thu 11:26:16
# https://codeforces.com/contest/2084/problem/D
for _ in range(int(input())):
    a, b, c = [int(i) for i in input().split()]
    # f = [0] * a
    l = max((a // (b + 1)), c)
    f = [i % l for i in range(a)]
    # print(f)
    print(' '.join(map(str, f[:a])))
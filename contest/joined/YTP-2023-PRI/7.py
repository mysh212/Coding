# Author : ysh
# 2023/07/28 Fri 14:04:29
import sys

input = sys.stdin.readline
print = sys.stdout.write
for _ in range(int(input())):
    f = []
    for i in range(int(input())):
        f.append([int(j) for j in input().split()])

    ans = 0
    last = 0
    c = True
    for i in f:
        if i[1] != 0:
            c = False
            break

    if c:
        ans = ans + 1

    c = True

    last = f[0][0] / f[0][1]
    for i in f:
        if i[0] != i[1]:
            c = False
            break

    if c:
        ans = ans + 1

    print(f'{ans}\n')
    continue

quit()
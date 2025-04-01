# Author : ysh
# 2024/12/06 Fri 13:29:43
# https://atcoder.jp/contests/abc382/tasks/abc382_d
a,b = [int(i) for i in input().split()]
now = []

def check(x: int, mmin: int):
    print(now)
    if mmin > b:
        return
    if x == a:
        print(' '.join([str(i) for i in now]))
        return
    for i in range(mmin + 10, b + 1):
        now.append(mmin)
        check(x + 1, i)
        now.pop()

check(0, 1)
quit()
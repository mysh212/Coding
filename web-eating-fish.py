# Author : ysh
# 2024/09/18 Wed 21:52:12
# https://judge.citrc.tw/contest/22/problem/2-6
# RE
f = [input().split() for i in range(int(input()))]

p = set()
for i in f:
    if i[0] not in p: print(f'welcome, {i[1]}');p.add(i[0]);
    else: print(f'sorry, email {i[0]} has been used');

quit()
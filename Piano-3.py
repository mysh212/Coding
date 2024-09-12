# Author : ysh
# 2024/09/08 Sun 20:07:17
# https://atcoder.jp/contests/abc369/tasks/abc369_b
f = (lambda x: [[i for i in x if i[1] == 'L'],[i for i in x if i[1] == 'R']])([input().split() for i in range(int(input()))])

ans = 0

for i in f:
    for j in range(1,len(i)):
        # print(i,j)
        ans = ans + abs(int(i[j][0]) - int(i[j - 1][0]))

print(ans)
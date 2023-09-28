# Author : ysh
# 2023/07/09 Sun 23:08:57
a,b = [int(i) for i in input().split()]
for i in sorted([[int(i) for i in input().split()] for j in range(a)]):
    print(' '.join([str(j) for j in i]))
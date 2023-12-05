# Author : ysh
# 2023/11/30 Thu 23:34:03
for i in range(int(input())):
    a,b = [float(i) for i in input().split()]
    print([round(a,int(b)),int(a)][b == 0])
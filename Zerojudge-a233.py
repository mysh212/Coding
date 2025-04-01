# Author : ysh
# 2024/12/14 Sat 22:00:49
print((lambda x: ' '.join([str(i) for i in sorted([int(j) for j in input().split()])]))(input()))
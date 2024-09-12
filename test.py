# Author : ysh
# 2024/08/14 Wed 00:49:40

print((lambda x: __import__('math').ceil(__import__('math').sqrt(12 * x[0])) + x[1] + 1)([int(i) for i in input().split()]))
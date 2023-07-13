# Author : ysh
# 2023/07/10 Mon 15:25:13
a = input().split()[0]
print('\n'.join(sorted([' '.join([str(i) for i in input().split()]) for i in range(int(a))])))
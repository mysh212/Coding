# Author : ysh
# 2026/09/19 Sat 09:09:55
for _ in range(int(input())):
    c, h, o = [int(i) for i in input().split()]
    print('Saturated' if (c << 1) - 4 == h else 'Unsaturated')

quit()
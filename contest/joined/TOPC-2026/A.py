# Author : ysh
# 2026/09/19 Sat 09:03:01
a, b, c = ([int(i) for i in input().split()])
if a + c == b << 1:
    print(f'secret {c - b}')
else:
    print('not secret')

quit()
# Author : ysh
# 01/24/2023 Tue 21:38:06.08
a = []
def check(x):
    if len(a) >= x + 1:
        return a[x]
    if x == 0:
        a.append(0)
        return 1
    tmp = check(x - 1) * x
    a.append(tmp)
    return tmp

while True:
    try:
        n = int(input())
        print(f'{n}!\n{check(n)}')
    except:
        break
quit()
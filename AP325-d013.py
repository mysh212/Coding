# Author : ysh
# 07/14/2022 Thu 23:03:13.65
x = 0
y = 0
z = 0
def check(a):
    if a == 1:
        return x
    tmp = check(a >> 1)
    if a & 1 == 1:
        return (tmp * tmp * x) % z
    else:
        return (tmp * tmp) % z
b = [int(i) for i in input().split()]
x = b[0]
y = b[1]
z = b[2]
print(check(y))
quit()
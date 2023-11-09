# Author : ysh
# 2023/09/16 Sat 11:11:51
def sig(i):
    return (2 ** i) - 1

def siginv(x):
    now = 1
    ans = 0
    while x > 0:
        x = x - now
        now = now <<1
        ans = ans + 1
    return ans

a,b = [int(i) for i in input().split()]
h = height = siginv(a)
left = sig(h) - a

ans = 0

for x in range(1,h + 1):
    larger = sig(h - (x - 1)) - min(left,(2 ** (h - x))) - 1
    smaller = x - 1
    if smaller >= b or x > h:
        continue
    if b >= smaller + 1 and b <= a - larger:
        ans = ans + (2 ** (x - 1))
    # print(smaller + 1,a - larger)

print(ans)
quit()
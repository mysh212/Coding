# Author : ysh
# 2026/11/05 Thu 16:35:22
l, r = [int(i) for i in input().split()]

if l > r:
    l, r = r, l

pointer = -1
ans = 0

R = 64
for i in range(R, -1, -1):
    mask = 1 << i

    if r & mask: ans = ans | mask;
    if (l & mask) == (r & mask):
        continue

    pointer = i
    break

if pointer == -1:
    print(ans)
    quit()

ans = ans & (ans - 1)

if ans >= l:
    print(ans)
    quit()

for i in range(pointer, -2, -1):
    if i == -1:
        print(ans | 1)
        quit()
    mask = 1 << i
    now = ans | mask
    if not l <= now <= r:
        print(ans | (mask << 1))
        quit()

quit(-1)
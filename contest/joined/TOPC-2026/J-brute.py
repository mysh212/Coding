# Author : ysh
# 2026/09/19 Sat 09:17:49
def check(n: int):
    ans = 1e200
    for i in range(60):
        for j in range(60):
            ans = min(abs((1 << i) + (1 << j) - n), ans)

    return ans

print(check(int(input())))
# Author : ysh
# 11/22/2022 Tue 16:35:31.25
ans = 0
for i in range(1,int(input()) + 1):
    if i % 2 == 0 or i % 3 == 0 or i % 5 == 0:
        ans = ans + 1
print(int(input()) - ans)
quit()
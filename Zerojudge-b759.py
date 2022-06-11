# Author : ysh
# 06/11/2022 Sat  9:35:11.75
a = input()
for i in range(len(a)):
    print(a[i:] + a[:i])
quit()
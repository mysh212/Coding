# Author : ysh
# 2024/09/27 Fri 21:46:22
for i in range(int(input())):
    n = int(input())
    f = [int(i) for i in input().split()]
    tmp = max(f)
    ans = []
    for i in range(len(f)):
        if f[i] == tmp:
            ans.append(i)
    if len(f) & 1 and len([i for i in ans if not i & 1]) == 0:
        print(max(f) + (len(f) >> 1))
    else:
        print(max(f) + ((len(f) + 1) >> 1))
    
quit()
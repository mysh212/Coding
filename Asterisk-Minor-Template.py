# Author : ysh
# 03/01/2023 Wed 11:38:52.35
# https://codeforces.com/contest/1796/problem/B
for i in range(int(input())):
    a = input()
    b = input()
    if a[0] == b[0]:
        print(f'YES\n{a[0]}*')
    elif a[::-1][0] == b[::-1][0]:
        print(f'YES\n*{a[::-1][0]}')
    else:
        d = False
        for i in range(len(a) - 1):
            c = a[i:i + 2]
            if b.find(c) != -1:
                print(f'YES\n*{c}*')
                d = True
                break
        if not d:
            print('NO')
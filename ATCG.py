# Author : ysh
# 02/03/2023 Fri 22:14:43.51
# https://codeforces.com/gym/425267
a = {'A':'T','T':'A','C':'G','G':'C'}
for i in range(int(input())):
    n = input()
    for j in input()[::-1]:
        print(a[j],end = '')
    print('')
quit()

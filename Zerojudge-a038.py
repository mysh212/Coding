# Author : ysh
# 06/20/2022 Mon 11:56:53.81
c = True
for i in input()[::-1]:
    if(i == '0' and c == True):
        continue
    c = False
    print(i,end = '')
quit()
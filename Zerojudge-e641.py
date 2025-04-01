# Author : ysh
# 2024/12/11 Wed 20:52:14
while True:
    try:
        pre = {
            1:set(['B','F','P','V']),
            2:set(['C','G','J','K','Q','S','X','Z']),
            3:set(['D','T']),
            4:set(['L']),
            5:set(['M','N']),
            6:set(['R']),
        }
        last = -1
        for i in input():
            c = False
            for j in range(1,6 + 1):
                if i in pre[j]:
                    c = True
                    if j == last:
                        continue
                    print(j,end = '')
                    last = j
            if not c:
                last = -1
        print('')
    except:
        break
quit()
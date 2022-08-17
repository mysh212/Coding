# Author : ysh
# 08/16/2022 Tue 16:53:37.42
b = []
llast = 0
last = 0
for i in range(100001):
    last = last ^ i
    llast = llast ^ last
    b.append(llast)
    # last = last ^ i 
# print(b[:10])
while True:
    try:
        a = [int(i) for i in input().split()]
        if a[1] < a[0]:
            tmp = a[0]
            a[0] = a[1]
            a[1] = tmp
        print(b[a[1]] ^ b[a[0] - 1])
    except:
        break
quit()
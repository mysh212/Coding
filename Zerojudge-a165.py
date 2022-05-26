# Author : ysh
# 04/24/2022 Sun 19:10:15.88
a = 380000000
c = False
while True:
    print(a)
    for i in range(10):
        if i == 0:
            continue
        if ((a % (pow(10,i))) % i) != 0:
            a = a + 1
            c = True
            break
    if c == False:
        if str(a).find('0') != -1:
            continue
        print(a,end = '')
        quit()
    if c == True:
        c = False
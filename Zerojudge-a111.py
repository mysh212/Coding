# Author : ysh
# 09/04/2022 Sun 13:39:52.61
while True:
    try:
        a = int(input())
        if a == 0:
            quit()
        print(a * (a + 1) * ((a << 1) + 1) // 6)
    except:
        quit()
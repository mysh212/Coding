# Author : ysh
# 01/01/2023 Sun 22:00:31.32
def check(n):
    mmin = 0
    for i in n:
        mmin = mmin + int(i)
    return str(mmin)

while True:
    try:
        n = input()
        if n == '0':
            break
        while len(n) > 1:
            n = check(n)
        print(n)
    except:
        break
quit()
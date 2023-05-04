# Author : ysh
# 03/18/2023 Sat  9:49:26.53
import sys
while True:
    try:
        a = [int(i) for i in sys.stdin.readline().split()]
        sys.stdout.write(str((a[0] * a[1]) % a[2]) + '\n')
    except:
        break
quit()
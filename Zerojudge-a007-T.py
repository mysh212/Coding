# Author : ysh
# 06/19/2022 Sun  7:48:01.26
import random
f = open('0.in','w')
for i in range(int(input())):
    f.write(str(random.randint(1900000000,2000000000)) + '\n')
f.close()
quit()
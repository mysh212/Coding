# Author : ysh
# 09/07/2022 Wed 11:03:14.17
import re
while True:
    try:
        print(len(re.findall('(\w+)',input())))
    except:
        break
quit()
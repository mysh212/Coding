# Author : ysh
# 11/06/2022 Sun 11:42:10.75
for i in range(2):
  n = 0
  for j in range(int(input())):
    n = n + (int(input()) // 17)
  print(n)
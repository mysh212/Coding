# Author : ysh
# 2023/07/28 Fri 16:19:25
def check(j) -> int:
    i = j
    if len(i) <= 2:
        return 1
    if i.find('001') == -1:
        return 1
    now = i.find('001')
    ans = 0
    while i.find('001') != -1:
        i = '0' + i[i.find('001') + 3:]
        ans = ans + check(i)
    return ans
    
    
def ck(i):
    return check(i[::-1])
    

a = input()
n = input()
print(ck(a))
for i in [int(i) for i in input().split()]:
    a = a[:i] + ['0','1'][a[i] == 0] + a[i + 1:]
    print(ck(a))
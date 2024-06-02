# Author : ysh
# 2024/05/15 Wed 21:03:14
f = input().replace(' ','').split('+')



pre = ['A','B','C','D']

def check(x,now):
    now = [str(i) for i in now]
    aans = False
    for i in x:
        ans = True
        for j in range(len(pre)):
            i = i.replace(f'{pre[j]}\'','0' if now[j] == '1' else '1')
            i = i.replace(pre[j],now[j])
        if i.find('0') != -1:
            ans = False
        aans = aans or ans
    return aans

def get_re(x: int,l: int):
    ans = [0 for _ in range(l)]
    for i in range(l):
        if x & (1 << i):
            ans[i] = 1
    return ans[::-1]

for i in range(1 << len(pre)):
    print(get_re(i,len(pre)),1 if check(f,get_re(i,len(pre))) else 0)

quit()
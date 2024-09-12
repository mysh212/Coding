# Author : ysh
# 2024/09/11 Wed 22:19:22
from core.general import *

n = [i.replace('^','').replace('*','').replace('(','').replace(')','').replace('-','+-').replace('++-','+-').replace(' ','').replace('\t','') for i in input().split(')(')]

print(n)

p = set([i for i in ''.join(n) if not i.isdigit() and i not in ['+','-','*','^']])
print(p)

t = 0
tmp = {}
for i in p: tmp[i] = t;t = t + 1;

print(tmp)
p = tmp

m = len(p)

def textmulti(a: list, b: list) -> list:
    if a == []: return b
    if b == []: return a
    tmp = {}
    # debug([a, b])
    for i in a: tmp[i[0]] = i[1]
    for j in b: tmp[j[0]] = tmp.get(j[0], 0) + j[1]
    return list([[i, tmp.get(i)] for i in tmp])

def multi(a: list, b: list) -> list:
    # debug(a)
    # debug(b)
    return [a[0] * b[0], textmulti(a[1],b[1])]

# print(textmulti([['A', 1], ['B', 2]],[['A', 3], ['D', 1024], ['C', 6]]))

# print([i.split(['+', '-']) for i in n])

def split_item(x: str, template: list = ['+']) -> list:
    ans = [x]
    for i in template:
        now = []
        for j in ans:
            for k in j.split(i):
                now.append(k)
        ans = now
    return ans

def get_item(x: str) -> list:
    # warning(x)
    
    c = ''
    for i in range(len(x) + 1):
        if i == len(x): x = '';break;
        if x[i].isdigit() or x[i] == '-': c = c + x[i];
        # elif i == len(x) - 1: x = '';break;
        else: x = x[i:];break;
    c = 1 if c == '' else int(c)

    ans = []
    # info([c, x])
    for j in x:
        if j.isalpha(): ans.append([j, 0]);
        else: ans[len(ans) - 1][1] = ans[len(ans) - 1][1] * 10 + int(j);\
    
    # error((c, ans))
    
    for i in range(len(ans)):
        if ans[i][1] == 0:
            ans[i][1] = 1

    # debug([c, ans])
    return [c, ans]

    return [int(left) if left != '' and left != '-' else [1, -1][left == '-'] , [[ans, int(right) if right != '' else 1]]]

# debug([[get_item(j) for j in split_item(i)] for i in n])

def text_rollback(x: list) -> str:
    ans = []
    warning(x)
    for i in x[1]:
        ans.append(f'{i[0]}^{i[1]}' if i[1] != 1 else str(i[0]))
    return ((str(x[0]) + '*') if x[0] != 1 else '') + '*'.join(ans)

def rollback(x: list) -> str:
    return ' + '.join([text_rollback(j) for j in x]).replace(' + -',' - ').replace(' - 1*',' - ').replace('*','').replace('^','')

now = [[1,[]]]
debug([split_item(i) for i in n])
for i in [[get_item(j) for j in split_item(i)] for i in n]:
    # now = multi(now,i)
    tmp = []
    for j in range(len(now)):
        for k in range(len(i)):
            debug([now[j], i[k]])
            tmp.append(multi(now[j], i[k]))
    now = (tmp)
debug(now)

for i in range(len(now)):
    now[i] = ([now[i][0], sorted(now[i][1])])

ans = []
for i in now:
    c = False
    for j in range(len(ans)):
        if ans[j][1] == i[1]:
            ans[j][0] += i[0]
            c = True
            break
    if not c:
        ans.append(i)

now = []

for i in ans:
    if i[0] == 0: continue;
    # c = False
    pre = []
    for j in i[1]:
        if j[1] != 0: pre.append(j)
    if pre == []: continue;
    now.append(i)

# now = ans

print(rollback(now))
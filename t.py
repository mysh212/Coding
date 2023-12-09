# Author : ysh
# 2023/12/10 Sun 00:43:15

ff = open('4.in','r')
t = 0
r = 0
q = 0
for i in ff:
    q = q + 1
    if '79' in i.split(' ')[1].split(','):
        t = t + 1
        if '123' in i.split(' ')[1].split(','): r = r + 1;
print(q,t,r)



# quit()

f = open('2.in','r')
g = open('4.out','r')

def trim(s):
    while s[::-1][0] == ' ': s = s[::-1][1:][::-1]
    while s[0] == ' ': s = s[1:]
    s = ' '.join([str(j) for j in sorted([int(i) for i in s.split(' ')])])
    return s;

ans = []
for i in f:
    if len(i.split(' => ')) != 2:
        continue
    tmp = i.replace('\n','').split(' => ')
    ans.append([trim(tmp[0].replace(',',' ')),trim(tmp[1].replace(',',' '))])

aans = []
for i in g:
    if len(i.split(' => ')) != 2:
        continue
    tmp = i.replace('\n','').split(' => ')
    aans.append([trim(tmp[0]),trim(tmp[1])])

print(ans[:5])
print(aans[:5])

print([i for i in ans if i not in aans][:10])
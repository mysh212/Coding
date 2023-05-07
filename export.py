# Author : ysh
# 06/24/2022 Fri  7:53:26.26
def geturl(a):
    try:
        ff = open(a,'r')
        a = 0
        for i in ff:
            a = a + 1
            if a == 3:
                if i[:4] == '// h':
                    return i[3:]
                break
        return '-1'
    except:
        return '-1'
e = {}
f = open('mc.info')
for i in f:
    e[i[34:len(i) - 1]] = i[:26]
f.close()
# print(e)
def getcode(a):
    try:
        ff = open(a,'r')
        a = ''
        for i in ff:
            a = a + i
        return a
    except:
        return '-1'
a = {}
d = {}
f = open('tags.info','r')
c = 0
for i in f:
    c = c + 1
    b = [j for j in i.split()]
    if a.get(b[0],'') == '':
        a[b[0]] = '###### tags: ' + ' `' + b[1] + '`'
        d[b[1]] = d.get(b[1],0) + 1
        continue
    a[b[0]] = a.get(b[0],'') + ' `' + b[1] + '`'
    d[b[1]] = d.get(b[1],0) + 1
for j in sorted(a.keys()):
    # if a.get(j).find('DP') == -1:
    #     continue
    if geturl(j) == '-1':
        if j[:9] == 'Zerojudge':
            id = j[10:14]
            url = 'https://zerojudge.tw/ShowProblem?problemid=' + str(id)
            print('***[' + j + '](' + url + ')***\n' + a.get(j))
            # print(':::spoiler ***code***\n```cpp=1\n' + getcode(j) + '\n```\n:::')
            print('>[time=' + e.get(j,'').replace('.',',').replace('/',',') + ']\n\n')
            print('[***<font color = \'#AAAAAA\'>code</font>***](https://github.com/mysh212/Coding/blob/master/' + j + ')\n')
            continue
        if j[:5] == 'AP325':
            id = j[6:10]
            url = 'https://judge.tcirc.tw/ShowProblem?problemid=' + str(id)
            print('***[' + j + '](' + url + ')***\n' + a.get(j))
            # print(':::spoiler ***code***\n```cpp=1\n' + getcode(j) + '\n```\n:::')
            print('>[time=' + e.get(j,'').replace('.',',').replace('/',',') + ']\n\n')
            print('[***<font color = \'#AAAAAA\'>code</font>***](https://github.com/mysh212/Coding/blob/master/' + j + ')\n')
            continue
        if j[:5] == 'tcirc':
            id = j[6:10]
            url = 'https://judge.tcirc.tw/ShowProblem?problemid=' + str(id)
            print('***[' + j + '](' + url + ')***\n' + a.get(j))
            # print(':::spoiler ***code***\n```cpp=1\n' + getcode(j) + '\n```\n:::')
            print('>[time=' + e.get(j,'').replace('.',',').replace('/',',') + ']\n\n')
            print('[***<font color = \'#AAAAAA\'>code</font>***](https://github.com/mysh212/Coding/blob/master/' + j + ')\n')
            continue
        print('***' + j + '***\n' + a.get(j))
        # print(':::spoiler ***code***\n```cpp=1\n' + getcode(j) + '\n```\n:::')
        print('>[time=' + e.get(j,'').replace('.',',').replace('/',',') + ']\n\n')
        print('[***<font color = \'#AAAAAA\'>code</font>***](https://github.com/mysh212/Coding/blob/master/' + j + ')\n')
        continue
    print('***[' + j + '](' + geturl(j) + ')***\n' + a.get(j))
    # print(':::spoiler ***code***\n```cpp=1\n' + getcode(j) + '\n```\n:::')
    print('>[time=' + e.get(j,'').replace('.',',').replace('/',',') + ']\n\n')
    print('[***<font color = \'#AAAAAA\'>code</font>***](https://github.com/mysh212/Coding/blob/master/' + j + ')\n')
print(':::spoiler ***algorithm***')
for j in sorted(d.keys()):
    print('***' + j + '*** ' + str(d.get(j)))
print(':::')
print('總題數:' + ' ' + str(c))
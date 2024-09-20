lis = []
tag = []
first = 1
with open('IMDB-Movie-Data.csv', 'r') as file: #讀檔
    for line in file:
        row = line.strip().split(',')
        if first:
            tag = row
            first = 0
        else:
            d = {}
            for i in range(len(tag)):
                if tag[i] == 'Actors' or tag[i] == 'Genre': #有多項，建為list
                    tmp = row[i].split('|')
                    tmp = [e if e[0]!=' ' else e[1:] for e in tmp]
                    d[tag[i]] = tmp
                else:
                    d[tag[i]] = row[i]
            if d['Revenue (Millions)'] != '':
                lis.append(d)

def q1():
    tmp = [e for e in lis if e['Year'] == '2016'] #抓年份
    tmp = sorted(tmp, key = lambda x : -float(x['Rating'])) #照rating排
    p = 0
    for i in range(3):
        print('#', i+1)
        print(tmp[p]['Title'])
        while p+1 < len(tmp) and tmp[p]['Title'] == tmp[p+1]['Title']: #找同分
            p += 1
            print(tmp[p]['Title'])
        p += 1
        print()
        
def q2():
    d = {}
    for e in lis:
        revenue = float(e['Revenue (Millions)'])
        for em in e['Actors']: #抓演員
            if em in d:
                d[em].append(revenue)
            else:
                d[em] = [revenue]
    ma = 0
    for e in d:
        ma = max(ma, sum(d[e])/len(d[e])) #算平均
    ans = []
    for e in d:
        if sum(d[e])/len(d[e]) == ma:
            ans.append(e)
    for e in ans:
        print(e)

def q3():
    tmp = [float(e['Rating']) for e in lis if 'Emma Watson' in e['Actors']]
    print(sum(tmp) / len(tmp))

def q4():
    d = {}
    for e in lis:
        se = set(e['Actors'])
        if e['Director'] in d:
            d[e['Director']] = d[e['Director']] | se #合併set
        else:
            d[e['Director']] = se
    ma = 0
    for e in d:
        ma = max(ma, len(e))
    ans = sorted(d, key = lambda x : -len(d[x]))
    p = 0
    for i in range(3):
        print('#', i+1)
        print(ans[p])
        while p+1 < len(ans) and len(d[ans[p]]) == len(d[ans[p+1]]):
            p += 1
            print(ans[p])
        p += 1
        print()

def q5():
    d = {}
    for e in lis:
        se = set(e['Genre'])
        for em in e['Actors']:
            if em in d:
                d[em] = d[em] | se
            else:
                d[em] = se
    ans = sorted(d, key = lambda x : -len(d[x]))
    p = 0
    for i in range(2):
        print('#', i+1)
        print(ans[p])
        while p+1 < len(ans) and len(d[ans[p]]) == len(d[ans[p+1]]):
            p += 1
            print(ans[p])
        p += 1
        print()

def q6():
    mad = {} #最大年
    mid = {} #最小年
    for e in lis:
        year = int(e['Year'])
        for em in e['Actors']:
            if em in mad:
                mad[em] = max(mad[em], year)
                mid[em] = min(mid[em], year)
            else:
                mad[em] = year
                mid[em] = year
    ans = []
    for e in mad:
        ans.append((e, mad[e] - mid[e]))
    ans = sorted(ans, key = lambda x : -x[1])
    p = 0
    print(ans[p][0])
    while p+1 < len(ans) and ans[p][1] == ans[p+1][1]:
        p += 1
        print(ans[p][0])
    
def q7(): #DSU
    dad = {}

    def f(s): #找祖先
        if s == dad[s]:
            return s
        return f(dad[s])
    
    def comb(s1, s2): #合併
        dad1 = f(s1)
        dad2 = f(s2)
        dad[dad1] = dad2
        return
    
    for e in lis: #初始化
        for em in e['Actors']:
            dad[em] = em
    
    for e in lis:
        e0 = e['Actors'][0]
        for em in e['Actors']:
            if em in dad:
                comb(e0, em)
            else:
                dad[em] = em
    cnt = 1
    ans = []
    for e in dad:
        if e != 'Johnny Depp' and f(e) == f('Johnny Depp'):
            ans.append(e)
            print(cnt, e)
            cnt += 1    
    print(sorted(ans))

# print('Q1 :')
# q1()
# print('\nQ2 :')
# q2()
# print('\nQ3 :')
# q3()
# print('\nQ4 :')
# q4()
# print('\nQ5 :')
# q5()
# print('\nQ6 :')
# q6()
print('\nQ7 :')
q7()  
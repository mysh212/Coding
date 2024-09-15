# Author : ysh
# 2024/09/14 Sat 17:05:53
pre = ['Rank','Title','Genre','Director','Actors','Year','Runtime (Minutes)','Rating','Votes','Revenue (Millions)','Metascore']

def read_from_file(name: str) -> str:
    return open(name,'r').read()

def parse_split(x: str) -> list:
    return [i.strip() for i in x.split('|')]

f = [i.split(',') for i in read_from_file('IMDB-Movie-Data.csv').split('\n') if len(i.split(',')) == len(pre)]
pre = f[0]
f = f[1:]

ans = []
for i in f:
    tmp = {}
    for j in range(len(pre)):
        tmp[pre[j]] = i[j]
    if tmp['Revenue (Millions)'] == '': continue;
    ans.append(tmp)

f = ans

print('Top-3 movies with the highest ratings in 2016: ')
print([i['Title'] for i in sorted(f,key = (lambda x: x['Rating'])) if i['Year'] == '2016'][::-1][:3])
print('')

print('The actor generating the highest average revenue: ')
tmp = {}

actors_rating, actors_rev, actors_ct, actors_revct = {}, {}, {}, {}
for i in f:
    now = [j.strip() for j in i['Actors'].split('|')]
    rev = i['Revenue (Millions)']
    rating = i['Rating']
    for j in now:
        actors_rating[j] = actors_rating.get(j, 0.0) + float(rating)
        actors_ct[j] = actors_ct.get(j, 0) + 1
        if rev == '': continue;
        actors_rev[j] = actors_rev.get(j, 0.0) + float(rev) if rev != '' else 0
        actors_revct[j] = actors_revct.get(j, 0) + 1

for i in actors_rev:
    actors_rev[i] = actors_rev[i] / actors_revct[i]

print([i for i in actors_rev if actors_rev.get(i) == max([actors_rev[i] for i in actors_rev])])
print('')

print('The average rating of Emma Watson\'s movies: ')
print(actors_rating['Emma Watson'] / actors_ct['Emma Watson'])
# print(sum([float(i['Rating']) for i in f if 'Emma Watson' in parse_split(i['Actors'])]) , len([i for i in f if 'Emma Watson' in parse_split(i['Actors'])]))
print('')

print('Top-3 directors who collaborate with the most actors: ')
tmp = {}
for i in f:
    a, b = i['Director'], set([j.strip() for j in i['Actors'].split('|')])
    now = tmp.get(a, set())
    for i in b: now.add(i)
    tmp[a] = now

print([[i for i in sorted(list(tmp), key = (lambda x: len(tmp[x])))[::-1] if len(tmp[i]) == j] for j in sorted(list(set([len(tmp[i]) for i in tmp])))[::-1][:3]])
print('')

print('Top-2 actors playing in the most genres of movies: ')
tmp = {}
for i in f:
    a, b = parse_split(i['Actors']), parse_split(i['Genre'])
    for i in a:
        now = tmp.get(i, set())
        for j in b:
            now.add(j)
        tmp[i] = now

print([[i for i in sorted(list(tmp), key = (lambda x: len(tmp[x]))) if len(tmp[i]) == j] for j in sorted(list(set([len(tmp[i]) for i in tmp])))[::-1][:2]])
# print(sorted(list(tmp['Brad Pitt'])))
print('')

print('Top-3 actors whose movies lead to the largest maximum gap of years: ')
tmp = {}
for i in f:
    years = int(i['Year'])
    actor = parse_split(i['Actors'])
    for i in actor:
        now = tmp.get(i, [years, years])
        now = [min(years, now[0]), max(now[1], years)]
        tmp[i] = now

print([[i for i in sorted(list(tmp), key = (lambda x: (tmp[x][1] - tmp[x][0]))) if (tmp[i][1] - tmp[i][0]) == j] for j in sorted(list(set([(tmp[i][1] - tmp[i][0]) for i in tmp])))[::-1][:1]])
print('')

color = [i for i in range(len(tmp) + len(list(set([i['Director'] for i in f]))))]

t = 0
re = {}
for i in list(set([i['Director'] for i in f])):
    re[i] = t
    t = t + 1
for j in tmp:
    re[j] = t
    t = t + 1

assert(t == len(color))

def ff(x: int) -> int:
    if color[x] == x: return x;
    color[x] = ff(color[x])
    return color[x]

def mg(a: int, b: int):
    color[ff(a)] = ff(b)

for i in f:
    a, b = i['Director'], parse_split(i['Actors'])
    for i in b:
        mg(re[i],re[a])

print('Find all actors who collaborate with Johnny Depp in direct and indirect ways: ')
for i in re:
    if i == 'Johnny Depp':
        ans = 0
        for j in range(len(color)):
            if ff(j) == ff(re.get(i)):
                ans = ans + 1
        print([j for j in re if ff(re[i]) == ff(re[j]) and j != i])
        print([ans - 1])
        quit()

print(f'The person who named \'Johnny Depp\' does not exist.')
quit()
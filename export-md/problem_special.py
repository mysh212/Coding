# Author : ysh
# 2024/01/24 Wed 21:35:45
def if_bad_problem(x: str) -> str:
    n = 1
    r = x.split('\n')
    if len(r) < 3: return ''
    t = r[2].split(' ')
    if len(t) < 2: return ''
    if t[1] == 'BP':
        return '{% note danger %}\n本題被回報為卡常題，問題著重於與主要演算法無關的壓常，做題前請三思並請勿花費不必要的時間於此處。\n{% endnote %}\n'
    return ''

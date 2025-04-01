# Author : ysh
# 2025/03/22 Sat 15:38:23
def strlint(x, y):
    return (lambda t: (x[:t] + x[t + 1:]) if not t == -1 else x)(x.find(y))

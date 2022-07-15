import random
a = "QWASZXEDCRFVTGBYUHJNMIOKLP"
print("26 10000")
print("ABCDEFG")
print("HIJKLMNOPQRSTUVWXYZ")
for i in range(49998):
    s = ""
    for j in range(100):
        s = s + random.choice(a)
    print(s)
quit()
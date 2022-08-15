# Author : ysh
# 08/13/2022 Sat 19:06:21.10
import pyautogui
import random
import time
print('input delay:',end = '')
a = float(input())
# pyautogui.displayMousePosition()
while True:
    random.seed(time.time())
    time.sleep(random.random() * a)
    pyautogui.click()
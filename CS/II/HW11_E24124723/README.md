# 使用說明

## 編譯

> 以 `Windows` 系統示範

```bash
g++ main.cpp -o main.exe -O2 -g -std=c++20 -static-libgcc -DLOCAL
```

執行

```bash
call main.exe
```

## 已編譯執行檔

`main.exe` ***for Windows*** \
`main.o` ***for Linux***

## 使用說明

輸入 $[0,3]$ 來移動玩家。

### 圖例

`P` **玩家** \
`#` **牆壁** \
`M` **怪物** \
`X` **輸掉的怪物**

> ~~是說到現在還沒有人能打贏怪物喔~~
import sys

try:
    f = 0
    while (1):
        f = f + 1
        a = input()
        a = a.split(" ")
        a = list(map(int, a))
        max = -1
        x = 0
        y = 0
        if (len(a) == 1):
            max = a[0]
            x = 0
            y = 0
        else:
            for i in range(len(a)):
                for j in range(i, len(a)):
                    tmp = a[i]
                    for k in range(i + 1, j + 1):
                        tmp *= a[k]
                    if max < tmp:
                        max = tmp
                        x = i
                        y = j
                    if max == tmp:
                        if (y - x) > (j - i):
                            x = i
                            y = j
        print("Case", f, end=":")
        print(" ", end="")
        print(int(max), x, end="")
        print("-", end="")
        print(y)

except EOFError:
    sys.exit()

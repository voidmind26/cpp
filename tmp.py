s = input()
ls = []
for i in range(len(s)):
    ls.append(s[i])

l = len(ls)
for i in range(l-1):
    nxt = []
    for j in range(len(ls)-1):
        if ls[j] == 'p':
            if ls[j+1] == 'r' or ls[j+1] == 'p':
                nxt.append('p')
            else:
                nxt.append('s')
        elif ls[j] == 's':
            if ls[j+1] == 's' or ls[j+1] == 'p':
                nxt.append('s')
            else:
                nxt.append('r')

        else:
            if ls[j+1] == 's' or ls[j+1] == 'r':
                nxt.append('r')
            else:
                nxt.append('p')
    ls = nxt
    print(''.join(ls))


pattern = []
for i in (0,1):
    for j in (0,1):
        for k in (0,1):
            pattern.append((i,j,k))

for expr1,expr2,fx in pattern:
    flag1 = ((not bool(expr1)) and bool(expr2)) or ((not bool(expr1) and not bool(expr2) and bool(fx)))

    flag2:bool
    if expr1:
        flag2 = False
    elif expr2:
        flag2 = True
    else:
        flag2 = bool(fx)
    # print(flag1,flag2,flag1 == flag2)
    assert(flag1 == flag2)

print("eq")
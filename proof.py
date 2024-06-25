# Proof of Program Equivalency
# range of the commit
# 3b0ddcb147c5aea8485c13a3f03626bc770735aa
# 298ea775d3eb3b61b118965801c26a4058b4aaf6


def pattern():
    for i in (False, True):
        for j in (False, True):
            for k in (False, True):
                yield (i,j,k)

for expr1,expr2,fx in pattern():
    flag1 = ((not expr1) and expr2) or ((not expr1 and not expr2 and fx))

    flag2:bool
    if expr1:
        flag2 = False
    elif expr2:
        flag2 = True
    else:
        flag2 = fx
    # print(flag1,flag2,flag1 == flag2)
    assert(flag1 == flag2)

print("eq")
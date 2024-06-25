
def pattern():
    for i in (False, True):
        for j in (False,True):
            yield i,j

for expr1,expr2 in pattern():
    assert(not ((not expr1 and expr2) and (expr1 and not expr2)))

print("all True")
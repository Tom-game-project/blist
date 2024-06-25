
# ((lst_tmp1 || !lst_tmp2) && (!lst_tmp1 || lst_tmp2) && lt(lst_tmp1->data, lst_tmp2->data)))
# (!((lst_tmp1 != NULL) ^ (lst_tmp2 != NULL)) && lt(lst_tmp1->data, lst_tmp2->data));

def pattern():
    for i in (False, True):
        for j in (False,True):
            yield i,j

for lst_tmp1,lst_tmp2 in pattern():
    print(
        lst_tmp1,lst_tmp2,
        (lst_tmp1 or not lst_tmp2) and (not lst_tmp1 or lst_tmp2),
        not (lst_tmp1 ^ lst_tmp2)
    )
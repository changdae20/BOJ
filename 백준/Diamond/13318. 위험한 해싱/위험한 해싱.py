def mult_poly(arr1,arr2):
    ans = {}
    for deg1,co1 in arr1.items():
        for deg2,co2 in arr2.items():
            if (deg1+deg2) in ans.keys():
                ans[deg1+deg2] += co1*co2
            else:
                ans[deg1+deg2] = co1*co2
    return ans

p29 = {}
p29[0] = 1
p29[6189] = 1
p29[11437] = -1

p31 = {}
p31[0] = 1
p31[5450] = -1
p31[25999] = 1

p37 = {}
p37[0] = 1
p37[16300] = -1
p37[12066] = 1

p41 = {}
p41[0] = 1
p41[15566] = 1
p41[4471] = -1

p43 = {}
p43[0] = 1
p43[22207] = 1
p43[11801] = -1

p47 = {}
p47[0] = 1
p47[50582] = -1
p47[12874] = 1

p53 = {}
p53[0] = 1
p53[21401] = -1
p53[8080] = 1

p59 = {}
p59[0] = 1
p59[35436] = 1
p59[25655] = -1

p61 = {}
p61[0] = 1
p61[36880] = 1
p61[25056] = -1

p67 = {}
p67[0] = 1
p67[30660] = -1
p67[6484] = 1

ans = mult_poly(p29,p31)
ans = mult_poly(ans,p37)
ans = mult_poly(ans,p41)
ans = mult_poly(ans,p43)
ans = mult_poly(ans,p47)
ans = mult_poly(ans,p53)
ans = mult_poly(ans,p59)
ans = mult_poly(ans,p61)
ans = mult_poly(ans,p67)

print("k" * 266469)
for i in range(266469):
    if i in ans.keys():
        print(chr( ord("k") + ans[i] ),end="")
    else:
        print("k",end="")
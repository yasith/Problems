a = "ejp mysljylc kd kxveddknmc re jsicpdrysirbcpc ypc rtcsra dkh wyfrepkym veddknkmkrkcdde kr kd eoya kw aej tysr re ujdr lkgc jv qz"

b = "our language is impossible to understandthere are twenty six factorial possibilitiesso it is okay if you want to just give up zq"

n = int(raw_input())

for i in range(n):

    line = raw_input()
    line2 = ""
    for ch in line:
        line2 += b[a.find(ch)]

    print "Case #%d:" %(i+1),
    print line2

print

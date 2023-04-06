M, N = map(int,input().split())

if N==1:
    for i in range(M):
        print(i+1)

elif N==2:
    for i in range(M):
        for j in range(i+1,M):
            print(i+1,j+1)
elif N==3:
    for i in range(M):
        for j in range(i+1,M):
            for k in range(j+1,M):
                print(i+1,j+1,k+1)
elif N==4:
    for i in range(M):
        for j in range(i+1,M):
            for k in range(j+1,M):
                for l in range(k+1,M):
                    print(i+1,j+1,k+1,l+1)
elif N==5:
    for i in range(M):
        for j in range(i+1,M):
            for k in range(j+1,M):
                for l in range(k+1,M):
                    for m in range(l+1,M):
                        print(i+1,j+1,k+1,l+1,m+1)
elif N==6:
    for i in range(M):
        for j in range(i+1,M):
            for k in range(j+1,M):
                for l in range(k+1,M):
                    for m in range(l+1,M):
                        for n in range(m+1,M):
                            print(i+1,j+1,k+1,l+1,m+1,n+1)
elif N==7:
    for i in range(M):
        for j in range(i+1,M):
            for k in range(j+1,M):
                for l in range(k+1,M):
                    for m in range(l+1,M):
                        for n in range(m+1,M):
                            for o in range(n+1,M):
                                print(i+1,j+1,k+1,l+1,m+1,n+1,o+1)
elif N==8:
    for i in range(M):
        for j in range(i+1,M):
            for k in range(j+1,M):
                for l in range(k+1,M):
                    for m in range(l+1,M):
                        for n in range(m+1,M):
                            for o in range(n+1,M):
                                for p in range(o+1,M):
                                    print(i+1,j+1,k+1,l+1,m+1,n+1,o+1,p+1)
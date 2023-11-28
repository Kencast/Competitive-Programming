A,B,C=map(str,input().split())

def Alove(A,B,C):
    lista=[]
    lista.append(A+B+C)
    lista.append(B+A+C)
    lista.append(B+C+A)
    lista.append(C+A+B)
    lista.append(C+B+A)
    lista.append(A+C+B)
    res=lista[0]
    for i in range(1,6):
        if(int(res)<int(lista[i])): res=lista[i]
    return res

print(Alove(A,B,C))
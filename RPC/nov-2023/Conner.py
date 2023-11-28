T=int(input())

def euclides(a,b):
    while b:
        a,b=b,a%b
    return a

def MCM(a,b):
    return abs(a*b)//euclides(max(a,b),min(b,a))

while(T):
    A,B,C,N=map(int,input().split())
    A+=1
    B+=1
    C+=1
    res=N//A + N//B + N//C #aqui sumo la cardinalidad de A,B,C
    var1=MCM(A,B)
    res-=N//var1 #quito A intersecado con B
    res-=N//MCM(B,C) #quito B intersecado con C
    res-=N//MCM(C,A) #quito C intersecado con A
    var1=MCM(var1,C)
    res+=N//var1 #sumo A intersecado con B intersecado con C
    print(res)
    T-=1
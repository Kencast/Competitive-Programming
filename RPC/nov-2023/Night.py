
n=int(input())
cont=0
i=1
res=[0]

def fun(a):
    return ((a+1)*(a+2))//2

aux=0
while aux<n:
    aux=res[i-1]+fun(i)
    res.append(aux)
    i+=1
print(i-1)
def buscar(sup):
    inf=1
    m=(inf+sup)//2
    while inf+1<sup:
        if res[m]>n: sup=m
        else: inf=m
        m=(inf+sup)//2
    return inf

while n>=3:
    i=buscar(i)
    n-=res[i]
    cont+=i
    
print(cont, n)
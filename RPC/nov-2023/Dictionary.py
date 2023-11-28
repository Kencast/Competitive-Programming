n, q=map(int, input().split())

dict=[]

for i in range(n):
    s=str(input())
    dict.append(s)

dict=sorted(dict)
mapa ={}

def buscar(pal):
    inf=0
    sup=n
    m=(inf+sup)//2
    while inf+1<sup:
        if dict[m]>pal: sup=m
        else: inf=m
        m=(inf+sup)//2
    return inf



while q:
    a, b=map(str, input().split())
    if a in mapa: p=mapa[a]
    else: p=buscar(a)
    if b in mapa: k=mapa[b]
    else: k=buscar(b)
    if dict[p]==a or p==0:  print(k-p+1)
    else: print(k-p)
    q-=1

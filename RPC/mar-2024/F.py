n,m=map(int,input().split())
people=[i for i in map(int, input().split())]

def solve():
    t=0
    menor=1000000000
    acum=0
    for i in range(n-1):
        acum+=people[i]
        acum-=m
        if acum<0:
            return i
        if acum<menor:
            menor=acum
            t=i
    acum+=people[n-1]-m
    if(acum<0): return n-1
    return t
   

if(people[0]>=n*m): print("impossible")
else: print(solve())
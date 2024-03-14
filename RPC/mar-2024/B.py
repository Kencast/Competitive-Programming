n=int(input())

def B(n):
    cont=0
    while(n>1):
        n/=2
        cont+=1
    return cont+1

print(B(n))
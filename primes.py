n=int(input())

mult=[9]
primes=[3]

for i in range(5, n, 2):
    p=0
    band=True
    while band or mult[p]==i:
        if primes[p]*primes[p]>i: break
        if(mult[p]==i):
            mult[p]+=primes[p]*2
            band=False
        p+=1
    if band==True: 
        primes.append(i)
        mult.append(i*i)

#for a in primes:print(a)


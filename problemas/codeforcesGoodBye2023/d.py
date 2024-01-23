t=int(input())

# https://codeforces.com/contest/1916/problem/D

while t:
    t-=1
    n=int(input())
    if n==1: 
        print(1)
        continue
    if(n==3):
        print(169)
        print(961)
        print(196)
        continue
    n=n//2-1
    exp=pow(10, n)
    print((13*exp)**2)
    print((31*exp)**2)
    print((14*exp)**2)
    a=exp*10
    b=3*a
    exp//=10
    while n:
        print((a+3*exp)**2)
        print((b+1*exp)**2)
        exp//=10
        n-=1

n=int(input())

def solve(cant, sum, num):
    if cant==1:
        print(num+str(sum))
    p=0
    if(n==cant): p=1
    else: p=0
    for i in range(p, 10):
        if sum-i>=0 and sum-i<=9*(cant-1):
            solve(cant-1, sum-i, num+str(i))

for i in range(1, 9*n):
    solve(n, i, "")
    print("---------")

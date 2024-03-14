import sympy

n, mod=map(int, input().split())
t=sympy.totient(mod)

def solve(b):
    if b==1: 
        return 1
    return pow(b, solve(b-1), t)+t

print(pow(n, solve(n-1), mod))
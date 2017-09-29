import time

def f(a, x):
    sum = 0
    for i in range(len(a)):
        sum += a[i]*pow(x, i)
    return sum

a = [1.0, 2.0, 3.0, 4.0, 5.0]
print(f(a, 1.0))

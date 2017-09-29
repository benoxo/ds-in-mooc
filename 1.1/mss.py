import sys
def mss(a):
    this_sum = 0
    total_sum = 0
    for i in a:
        this_sum += i
        if this_sum > total_sum:
            total_sum = this_sum
        elif this_sum < 0:
            this_sum = 0
    return total_sum

sys.stdin = open('in.txt', 'r')
n = sys.stdin.readline().split()
a = map(int, sys.stdin.readline().split())
print(mss(a))

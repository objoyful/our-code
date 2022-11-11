from math import sqrt

q = [1, 3, 10]
p = [2, 5, 13]

def find_distance(q, p):
    n = len(q)
    return sqrt(sum([(q[i] - p[i]) ** 2 for i in range(n)]))
import itertools

x = [1, 2, 3, 4]

for i in x:
    print(i)

print("=====")

n = itertools.cycle(x)
print(next(n))
print(next(n))
print(next(n))
print(next(n))

print("======")

y = iter(x)
for i in y:
    print(i)
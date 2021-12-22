import itertools

player_choice = itertools.cycle([1, 2])

for i in range(10):
    print(next(player_choice))
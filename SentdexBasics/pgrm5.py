game = [[0, 0, 0],
        [0, 0, 0],
        [0, 0, 0],]

game[0][1] = 99

print("   a  b  c")
count = 0
for count, row in enumerate(game):
    print(count, row)
    count += 1
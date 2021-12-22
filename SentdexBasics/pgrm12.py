game = [[1, 0, 2],
        [1, 1, 0],
        [2, 2, 1],]

cols = reversed(range(len(game)))
rows = range(len(game))

diags = []
for col, row in enumerate(reversed(range(len(game)))):
    diags.append(game[row][col])

print(diags)

diags = []
for ix in range(len(game)):
    diags.append(game[ix][ix])

# print(diags)

# if game[0][0] == game[1][1] == game[2][2]:
#     print("Winner!")

# if game[2][0] == game[1][1] == game[0][2]:
#     print("Winner!")


'''
for col in range(len(game)):
    check = []

    for row in game:
        # print(row[col])
        check.append(row[col])
    print(check)

    if check.count(check[0]) == len(check) and check[0] != 0:
        print("Winner!")
'''
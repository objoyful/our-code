game = [[2, 0, 1],
        [2, 0, 0],
        [2, 2, 0],]

'''
def win(current_game):
    for row in current_game:
        print(row)
        if row.count(row[0]) == len(row) and row[0] != 0:
            print('winner')

win(game)
'''


for col in range(len(game)):
    check = []

    for row in game:
        # print(row[col])
        check.append(row[col])
    print(check)

    if check.count(check[0]) == len(check) and check[0] != 0:
        print("Winner!")

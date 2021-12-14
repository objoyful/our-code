game = [[1, 0, 1],
        [0, 0, 0],
        [2, 2, 0],]

'''
horizontally
vertically
diagonally
'''

def win(current_game):
    for row in current_game:
        print(row)
        if row.count(row[0]) == len(row) and row[0] != 0:
            print('winner')

win(game)
# def addition(x, y):
#         return x + y

# z = addition("hey", " there")
# print(z)


game = [[0, 0, 0],
        [0, 0, 0],
        [0, 0, 0],]

def game_board(player = 0, row = 0, column = 0, just_display = False):
        print("   0  1  2")
        if not just_display:
                game[row][column] = player
        for count, row in enumerate(game):
                print(count, row)
                count += 1

game_board(just_display = True)
game_board(player = 1, row = 2, column = 1)
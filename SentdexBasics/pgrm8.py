# game = "I want to play a game"
# print(id(game))

# def game_board(player = 0, row = 0, column = 0, just_display = False):
#         global game
#         game = "A game"
#         print(id(game))
#         print(game)

# print(game)
# game_board()
# print(game)
# print(id(game))

game = [[0, 0, 0],
        [0, 0, 0],
        [0, 0, 0],]

def game_board(game_map, player = 0, row = 0, column = 0, just_display = False):
        print("   0  1  2")
        if not just_display:
                game_map[row][column] = player
        for count, row in enumerate(game_map):
                print(count, row)
                count += 1

        return game_map

game_board(just_display = True)
game_board(player = 1, row = 2, column = 1)
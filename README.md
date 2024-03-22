# BoardGame
Multiplayer game on an 8x8 table

# Class Position

The positions consist of rows (1–8) and columns (A–H). The position can be printed on the standard output. It can be changed by one field to the left, right, top, or bottom. It is possible to check if the position is in the same row or colon as another position.

# Class Player

The player can change his position by one square to the left, right, up or down. It is possible to get the name of the player, as well as his position.

# Class Table

The board consists of a list of players and remembers the current player's turn. It is possible to create a new player, as well as, to move the next player on the board. If the player on the move is in the position of another player, then the other player is deleted from the board. It is possible to draw a board on the standard output. Players are marked with the initial letters of their names, and empty positions with an arbitrary sign.

# Main

The program creates a board and asks the user to enter the number of players and create them. When the user enters the last player, the program moves one player at a time based on further input from user (0 for up, 1 for right, 2 for down, 3 for left). The program ends when only one player remains on the board.

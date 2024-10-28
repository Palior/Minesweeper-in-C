MINESWEEPER INSTRUCTIONS

The input for this program is a .txt file named "tablero.txt" containing spaces with mines represented by 1 and spaces without mines represented by 0. 
The grid has a fixed size of 8 rows by 8 columns, with no limit on the number of mines. The values are separated by spaces, as shown below:

0 0 1 0 0 1 0 0
0 0 0 0 0 1 0 0
1 0 0 0 0 0 0 0 
0 0 0 1 0 0 0 0
0 1 0 0 0 0 0 1
0 0 0 0 0 0 0 0
1 0 0 0 0 1 0 0 
0 0 0 1 0 0 0 0

You can edit this file as a text document to change the contents, transforming it into a Minesweeper grid, or create a new file with the same format and name, "tablero.txt".

When running the Minesweeper program, you will be presented with the following options:

To play in Player Mode, enter 1.
To play in Computer Mode, enter 2.
To exit the program, enter any other number.
PLAYER MODE:
The Minesweeper board will be displayed on the screen with coordinates on the top and left sides. The top coordinates represent columns, and the left coordinates represent rows, numbered from 1 to 8. The program will ask the user for the desired coordinates. If the coordinates are outside the grid's range, the program will prompt for them again. If the coordinates are within range, the Minesweeper board will update to reveal the chosen position. If the revealed position contains a mine, the game ends in defeat. The process continues until the user finds a mine or reveals all positions except those containing mines.

After exiting this mode, the program will offer the option to run again: entering 1 will exit the program, while any other number will continue execution.

COMPUTER MODE:
This function, which solves Minesweeper automatically, is not yet implemented. The only options available are to run the program again or exit.

EXITING THE PROGRAM:
Choosing this option stops the program from running.

# Games of DSA

This repository contains various games programmed in various languages such as C, C++, and Python using various concepts such as DFS, BFS, Memoization, stacks, queues, hashing, minimax, etc.

--- -
# How to Play:
- Clone the repository and follow the given instructions  
  **OR**
- Download the individual files:
- Also download the queue.hpp or stack.hpp header files as required.
- Follow the given instructions.

- Link to the [Main Repository](https://github.com/JaidevSK/Games-of-DSA)

# Game 1: [Tower of Hanoi](https://github.com/JaidevSK/Games-of-DSA/blob/main/TowerOfHanoi.c)
## Rules
- [Link to Wikipedia Page](https://en.wikipedia.org/wiki/Tower_of_Hanoi)

## Instructions
- There are n disks numbered such that disk n is at the lowest position.
- There are three rods numbered 0, 1 and 2:
    - 0 is the *FROM* rod
    - 1 is the *ADDITIONAL* rod
    - 2 is the *TO* rod
- First input the number of disks and then press enter.
- The steps to move the discs are then displayed.

## Major Concepts
- C
- Recursions

--- -
# Game 2: [Sudoku](https://github.com/JaidevSK/Games-of-DSA/blob/main/Sudoku.cpp)
## Rules
- [Link to Wikipedia Page](https://en.wikipedia.org/wiki/Sudoku)

## Instructions
- Input Values from the Left-Top Most cell to the Right-Bottom Most cell.
- Empty cell can be replaced by a 0.
- Click Enter.
- The Solved Board is displayed.

## Major Concepts
- C++
- Recursions
- Graphs
- Graph Traversal using DFS
- Stack


--- -
# Game 3: [Tic Tac Toe](https://github.com/JaidevSK/Games-of-DSA/blob/main/TicTacToe.py)
## Rules
- [Link to Wikipedia Page](https://en.wikipedia.org/wiki/Tic-tac-toe)

## Instructions
- The structure of the board is:
```
___________________
|     |     |     |
|  0  |  1  |  2  |
|_____|_____|_____|
|     |     |     |
|  3  |  4  |  5  |
|_____|_____|_____|
|     |     |     |
|  6  |  7  |  8  |
|_____|_____|_____|  
```
- The input for each step is the index from the above table for the place where we want to play the next move
- The response move is automatically generated, and the final result is displayed at the end of the game.

## Major Concepts
- Python
- Recursions and Backtracking
- Graphs
- Minimax Algorithm
- Board encoding (Bitwise operations)



--- -
# Game 4: [Game of Sim](https://github.com/JaidevSK/Games-of-DSA/blob/main/GameOfSim.c)
## Rules
- [Link to Wikipedia Page](https://en.wikipedia.org/wiki/Sim_(pencil_game))

## Instructions
- The 6 verices of the hexagon are represented as 0, 1, 2, 3, 4, 5
- The edges between the two vertices a, b are encoded in the board struct in the way as given in the following table:

| From/To | To/From | Index Position in Board Struct |
|---------|---------|--------------------------------|
| 0       | 1       | 0                              |
| 0       | 2       | 1                              |
| 0       | 3       | 2                              |
| 0       | 4       | 3                              |
| 0       | 5       | 4                              |
| 1       | 2       | 5                              |
| 1       | 3       | 6                              |
| 1       | 4       | 7                              |
| 1       | 5       | 8                              |
| 2       | 3       | 9                              |
| 2       | 4       | 10                             |
| 2       | 5       | 11                             |
| 3       | 4       | 12                             |
| 3       | 5       | 13                             |
| 4       | 5       | 14                             |

- If the particular position is coloured by player blue, the particular edge(index) location in the bard is 'B'; otherwise it is red 'R'
- Start the game by typing
    - R if we want to start first, as red palyer
    - B if we want to start second, as blue player
- Enter the index of the edge that we want to colour as given in above table.
- We lose as soon as we complete a proper triangle of our colour


## Major Concepts
- C
- Recursions and Backtracking
- Graphs
- Minimax Algorithm
- Board encoding (Bitwise operations)

--- -
# Game 5: [Puzzle 8](https://github.com/JaidevSK/Games-of-DSA/blob/main/Puzzle8.cpp)
## Rules
- [Link to Wikipedia Page](https://en.wikipedia.org/wiki/15_Puzzle)

## Instructions
- This game is the 3X3 version of the 15 Puzzle game.
- To play this, enter the Source Board from the left top most end to the right bottom most end.
- If the position is empty, enter 9.
- Similarly enter the Destination (Traget) Board.
- The solution steps represent the movement of the empty block.
    - R: Move the empty block to Right
    - L: Move the empty block to Left
    - U: Move the empty block to Up
    - D: Move the empty block to Down

## Major Concepts
- C++
- Recursions and Backtracking
- Graphs
- Graph Traversal using BFS
- Queue
- Memoization
- Board encoding (Bitwise operations)

--- -
# Game 6: [Up It Up](https://github.com/JaidevSK/Games-of-DSA/blob/main/UpItUp.cpp)
## Rules
- [Link to Youtube Video](https://www.youtube.com/watch?v=N_GbBjvU068)

## Instructions
- This game is represented by a 2D board such that the element: 
    - Empty = '0'
    - 'A' = '1'
    - 'v' = '2'
    - '^' = '3'
    - '<' = '4'
    - '>' = '5'
    - 'B' = '6'
- Here, 'A' is the top most face and 'B' is the bottom most face of the blocks. <, ^, v & > are the symbols that represent that if we tilt the block towards the arrow direction, we will get to the destination.
- Give the input board in the same form as Puzzle 8 following the above encoding scheme.
- Click enter and the solution is obtained.
- The solution steps represent the movement of the empty block.
    - R: Move the empty block to Right
    - L: Move the empty block to Left
    - U: Move the empty block to Up
    - D: Move the empty block to Down

## Major Concepts
- C++
- Recursions and Backtracking
- Graphs
- Graph Traversal using BFS
- Queue
- Hashing (unordered sets)
- Memoization
- Board encoding (Bitwise operations)


--- -
# Game 7: [Connect 4](https://github.com/JaidevSK/Games-of-DSA/blob/main/Connect4Game.cpp)
## Rules
- [Link to Wikipedia Page](https://en.wikipedia.org/wiki/Connect_Four)

## Instructions
- This game is the 4X5 version of the Connect Four Game.
- To play this, enter the colour Blue or Red:
    - Enter 'R' if you are the red player (staring first).
    - Enter 'B' if you are the blue player (staring second).
- Enter the column number where you would like to play the next move.
- The result is declared in case of no valid move or full board.

## Major Concepts
- C++
- Recursions and Backtracking
- Graphs
- Minimax
- Memoization
- Board encoding (Bitwise operations)

--- -
# Game 8: [Rubik's Cube](https://github.com/JaidevSK/Games-of-DSA/blob/main/RubiksCube.cpp)
## Rules
- [Link to Wikipedia Page](https://en.wikipedia.org/wiki/Rubik%27s_Cube)

## Instructions
- This game is the 2X2X2 version of Rubiks Cube
- Enter the colours of the cube in the 2D representation following the given table:

| Colour | Value |
|--------|-------|
| White  | 0     |
| Red    | 1     |
| Blue   | 2     |
| Orange | 3     |
| Green  | 4     |
| Yellow | 5     |

- The encoding of different faces is done such that the indices from ascending order are given to the faces {Top, Left, Front, Right, Rear, Bottom}
- The indexing for each face is done in clockwise manner starting from top left corner.
- For encoding, refer this figure:
    - Facewise Encoding Scheme Indices
    <img title="Facewise Encoding Scheme Indices" alt="Facewise Encoding Scheme Indices" src="/images/RubiksCube_encoding_scheme_facewise.png">
    
    - Pixelwise Encoding Scheme Indices for Each Face
    <img title="Pixelwise Encoding Scheme Indices for Each Face" alt="Pixelwise Encoding Scheme Indices for Each Face" src="/images/RubiksCube_encoding_scheme_pixelwise.png">
- The output moves are:
    - R : Clockwise 90 degrees on right
    - R2: Clockwise 180 degrees on right
    - R': Anti Clockwise 90 degrees on right
    - U : Clockwise 90 degrees on top
    - U2: Clockwise 180 degrees on top
    - U': Anti Clockwise 90 degrees on top
    - F : Clockwise 90 degrees on front
    - F2: Clockwise 180 degrees on front
    - F': Anti Clockwise 90 degrees on front


## Major Concepts
- C++
- Recursions and Backtracking
- Graphs
- Graph Traversal using BFS
- Queue
- Hashing (Unordered Sets)
- Memoization
- Board encoding (Bitwise operations)



# -*- coding: utf-8 -*-
"""
Created on Fri Dec  8 16:14:49 2023

@author: jaidev
"""

# A program to play tic-tac-toe with the computer.
import numpy as np

BOARD_SIZE = 3

def init_board(board):
    board.fill('.')

def print_board(board):
    print("______________________")
    for row in board:
        print("|      |      |      |")
        print("| ", end=" ")
        for cell in row:
            print(f"{cell:3} | ", end=" ")
        print("\n|______|______|______|")
        

def is_full(board):
    return '.' not in board.flatten()

def has_won(board, player):
    for row in board:
        if np.all(row == player):
            return True
    for col in board.T:
        if np.all(col == player):
            return True
    if np.all(np.diag(board) == player):
        return True
    if np.all(np.diag(np.fliplr(board)) == player):
        return True
    return False

def other_player(player):
    return 'O' if player == 'X' else 'X'

class Move:
    def __init__(self, row, col, score):
        self.row = row
        self.col = col
        self.score = score

def encode_move(move):
    b = 0
    b |= move.row
    b |= move.col << 2
    if move.score == -1:
        b |= 1 << 6
    elif move.score == 0:
        b |= 1 << 5
    elif move.score == 1:
        b |= 1 << 4
    return b

def decode_move(b):
    row = b & 0x3
    col = (b & 0xC) >> 2
    score = None
    if b & 0x10:
        score = 1
    elif b & 0x20:
        score = 0
    elif b & 0x40:
        score = -1
    return Move(row, col, score)

def ord(board):
    p = 1
    i = 0
    for row in board:
        for cell in row:
            if cell == 'X':
                d = 1
            elif cell == 'O':
                d = 2
            else:
                d = 0
            i += d * p
            p *= 3
    return i

def best_move(board, player):
    response = None
    candidate = None
    no_candidate = True

    o = ord(board)

    if computed_moves[o]:
        return decode_move(computed_moves[o])

    for row in range(BOARD_SIZE):
        for col in range(BOARD_SIZE):
            if board[row][col] == '.':
                board[row][col] = player
                if has_won(board, player):
                    board[row][col] = '.'
                    computed_moves[o] = encode_move(candidate := Move(row, col, 1))
                    return candidate
                board[row][col] = '.'

    for row in range(BOARD_SIZE):
        for col in range(BOARD_SIZE):
            if board[row][col] == '.':
                board[row][col] = player
                if is_full(board):
                    board[row][col] = '.'
                    computed_moves[o] = encode_move(candidate := Move(row, col, 0))
                    return candidate
                response = best_move(board, other_player(player))
                board[row][col] = '.'
                if response.score == -1:
                    computed_moves[o] = encode_move(candidate := Move(row, col, 1))
                    return candidate
                elif response.score == 0:
                    candidate = Move(row, col, 0)
                    no_candidate = False
                else:
                    if no_candidate:
                        candidate = Move(row, col, -1)
                        no_candidate = False
    computed_moves[o] = encode_move(candidate)
    return candidate

def print_key():
    i = 0
    for row in range(BOARD_SIZE):
        for col in range(BOARD_SIZE):
            print(f"{i:3}", end=" ")
            i += 1
        print()
    print()

board = np.empty((BOARD_SIZE, BOARD_SIZE), dtype=str)
computed_moves = np.zeros(43046721, dtype=np.uint8)

def main():
    move = 0
    row = 0
    col = 0
    response = None
    current = 'X'

    init_board(board)
    while True:
        print_board(board)
        if current == 'X':
            print_key()
            move = int(input("Enter your move: "))
            row = move // BOARD_SIZE
            col = move % BOARD_SIZE
            if board[row][col] != '.':
                print("Invalid Move\n")
                continue
            board[row][col] = current
        else:
            response = best_move(board, current)
            board[response.row][response.col] = current
        if has_won(board, current):
            print_board(board)
            print(f"Player {current} has won!")
            break
        elif is_full(board):
            print_board(board)
            print("Draw.")
            break
        current = other_player(current)

if __name__ == "__main__":
    main()

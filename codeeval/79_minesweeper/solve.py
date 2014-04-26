#!/usr/bin/python -tt

import sys

def count_neighbor_bombs(board, i, j):
    return len(filter(lambda c: c == '*',
        [ board[x][y] for x in range(i-1, i+2) for y in range(j-1, j+2)
            if x >= 0 and x < len(board)
            if y >= 0 and y < len(board[0]) ]))

def open_board(board):
    for i in range(0, len(board)):
        for j in range(0, len(board[0])):
            if board[i][j] != '*':
                board[i][j] = str(count_neighbor_bombs(board, i ,j))
    return board

def main():
    f = open(sys.argv[1], 'r')
    for l in f.readlines():
        args = l.strip().split(';')
        m, n = (int(i) for i in args[0].split(','))
        board = [ list(args[1][i*n:i*n + n]) for i in range(0,m) ]
        print ''.join(''.join(l) for l in open_board(board))
    f.close()

if __name__ == '__main__':
    main()

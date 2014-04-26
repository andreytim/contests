#!/usr/bin/python -tt 

import sys

def print_board(board):
    print '\n'.join(','.join(map(lambda x: str(x), s)) for s in board)

def min_path(board, n):
    for i in range(1, n):
        board[i][0] += board[i-1][0]
        board[0][i] += board[0][i-1]
    for i in range(1, n):
        for j in range(1, n):
            board[i][j] = board[i][j] + min(board[i-1][j], board[i][j-1])
    return board[n-1][n-1]

def main():
    f = open(sys.argv[1], 'r')
    l = f.readline()
    while l:
        n = int(l.strip())
        board = []
        for i in range(0, n):
            items = [ int(item) for item in f.readline().strip().split(',') if item != '']
            board += [ items ]
        print min_path(board, n)
        l = f.readline()
    f.close()

if __name__ == '__main__':
    main()

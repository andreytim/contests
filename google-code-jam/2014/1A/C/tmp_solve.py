#!/usr/bin/python

import sys
from collections import deque
from copy import copy, deepcopy

BOMB, EMPTY = '*', '.'

def count_bombs(board, points):
    return sum([ 1 for p in points if board[p[0]][p[1]] == BOMB ])

def get_neighbors(board, point, ntype = ''):
    res = [ (point[0] + i, point[1] + j) for i in range(-1,2) for j in range (-1,2)
            if point[0] + i > -1 and point[0] + i < len(board)
            if point[1] + j > -1 and point[1] + j < len(board[1]) ]
    return [ n for n in res if board[n[0]][n[1]] == ntype ] if ntype else res

def try_corner_click(board, M):
    queue = deque([ (len(board)-1, len(board[0])-1) ])
    total_revealed = 0
    visited = []
    #bcopy = deepcopy(board)
    while queue:
        point = queue.popleft()
        if not point in visited: 
            visited.append(point)
            total_revealed += 1
            neighbors = get_neighbors(board, point)
            #bcopy[point[0]][point[1]] = str(count_bombs(board, neighbors))
            if count_bombs(board, neighbors) == 0:
                queue += neighbors
    #print to_string(bcopy), total_revealed
    return total_revealed + M == len(board) * len(board[0])

cache = dict()
def check_possibility(bomb_point, bombs_left, bombs_total, board):
    board[bomb_point[0]][bomb_point[1]] = BOMB
    board_key = to_string(board)
    #print 'board: \n' + board_key
    if board_key in cache: return (cache[board_key], board)
    bombs_left -= 1
    if try_corner_click(board, bombs_total - bombs_left):
        if not bombs_left: return (True, board)
        else: 
            for n in get_neighbors(board, bomb_point, EMPTY):
                possible, board = check_possibility(n, bombs_left, bombs_total, deepcopy(board))
                if possible: return (True, board)
    cache[board_key] = False
    board[bomb_point[0]][bomb_point[1]] = EMPTY
    return (False, board)

def to_string(board):
    return '\n'.join(''.join(row) for row in board)

def solve_test_case(R, C, M):
    board = [[EMPTY]*C for i in range(0, R)]
    board[R-1][C-1] = 'c'
    if M == 0: return to_string(board)
    if R > 1 and C > 1 and R*C - M < 4: return 'Impossible' 
    possible, board = check_possibility((0,0), M, M, board) 
    return 'Impossible' if not possible else to_string(board)

def main():
    f = open(sys.argv[1], 'r')
    n = int(f.readline().strip())
    for i in range(1,n+1):
        R, C, M = (int(d) for d in f.readline().strip().split(' '))
        print 'Case #%d: %s' % (i, solve_test_case(R, C, M))

if __name__ == '__main__':
    main()

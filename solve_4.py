#!/bin/python3
''' https://adventofcode.com/2021
    solver of problem 4
    passes pylint
'''

import sys

IN_FILE="4_input.txt"
DBG=0

def main():
    ''' main program '''

    line_number = 0
    card_number = 0
    c_cols = 5      # each bingo card has 5 cols
    c_rows = 5      # each bingo card has 5 rows
    c_count = 100   # there's 100 cards, nasty hacky hard wired value
    #card = [ [0] * c_rows for i in range(c_count) ]
    card = [ [ [0] * c_cols for i in range(c_rows) ] for j in range(c_count)]
    card_row = 0   # counts from 0 to 4 repeatedly
    state = 0       # if 0, expecting bingo numbers, 1 is blank line, 2 to 6 are lines in bingo card

    with open(IN_FILE, "r") as fp_in:
        for raw_input_line in fp_in:
            input_line = raw_input_line.rstrip()
            line_number += 1

            #print("state %d line %d is %s" % (state, line_number, input_line, ))
            if state == 0:
                if input_line != '':
                    bingo_numbers = input_line.split(',')
                    state = 1
                else:
                    print('Error, line %d is unexpectedly blank at state %d' % (line_number, state, ))
                    sys.exit(1)

            elif state == 1:
                if input_line == '':
                    state = 2
                else:
                    print('Error, line %d is unexpectedly unblank "%s" at state %d' % (line_number, input_line, state, ))
                    sys.exit(1)

            elif state >= 2 and state <= 6:
                if input_line == '':
                    print('Error, line %d is unexpectedly blank at state %d' % (line_number, state, ))
                    sys.exit(1)
                else:
                    row_array = input_line.split(' ')
                    #print("card number %d, card_row %s" % (card_number, ';'.join(row_array)))
                    for i in range(c_cols):
                        value = row_array[i]
                        if value == '':
                            value = -1
                        #print("card number %d, card_row %d, card col %d, value %d" % (card_number, card_row, i, int(value), ))
                        card[card_number][card_row][i] = int(value)
                    card_row += 1

                # next card?
                if state < 6:
                    state += 1
                else: # on last line of the card, set state to waiting on blank line
                    state = 1
                    card_number += 1
                    card_row = 0


    print("total lines %d" % (line_number, ))
    print("cards %d" % (card_number, ))
    print("bingo_numbers = %s" % (', '.join(bingo_numbers)))


    for cn in range(c_count):
        print("card %d: " % (cn, ))
        for cr in range(c_rows):
            for cc in range(c_cols):
                print("%d " % (card[cn][cr][cc], ), end='')
            print('')
        print('')

################################################################################
main()

# end of solve_4.py

#!/bin/python3
''' https://adventofcode.com/2021
    solver of problem 2
    passes pylint
'''

IN_FILE="2_input.txt"
DBG=0

def main():
    ''' main program '''

    line_count = 0
    current_x = 0
    current_y = 0

    with open(IN_FILE, "r") as fp_in:
        for input_line in fp_in:
            #print("line %s" % (input_line, ), end='')
            (direction, distance) = input_line.strip().split(' ')
            #print('dir %s dist %s' % (direction, distance))

            if direction == "forward":
                current_x += int(distance)
            elif direction == "down":
                current_y += int(distance)
            elif direction == "up":
                current_y -= int(distance)

            line_count += 1


    print("total lines %d" % (line_count, ))
    print("x %d" % (current_x, ))
    print("y %d" % (current_y, ))
    print("x * y %d" % (current_x * current_y,))


main()

# end of solve_2.py

#!/usr/bin/python

import sys

def main():
    file = sys.argv[1]
    f = open(file)
    day_n = 0
    problem_sum = 0
    for i in f:
        i = i.rstrip('\n')
        if len(i.split('\t')) == 1:
            n = 0
            date = i
        else:
            date, problems = i.split('\t')
            if (len(problems) == 0):
                n = 0
            else:
                n = len(problems.split(','))
        day_n += 1
        problem_sum += n
        print date, n
    print '%d days solve %d probelms. average:%.2f' % (day_n, problem_sum, problem_sum*1.0/day_n)

if __name__ == '__main__':
    main()

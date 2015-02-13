#!/usr/bin/python
# -*- coding: utf-8 -*-

class Solution:
    # @param s, a string
    # @return a string
    def reverseWords(self, s):
        str_list = s.split()
        str_list.reverse()
        return ' '.join(str_list)

def main():
    s = Solution()
    str = '''   i'm		a test string'''
    rev_str = s.reverseWords(str)
    print str
    print rev_str

if __name__ == '__main__':
    main()

#!/usr/bin/python

import urllib2
from lxml import etree

def main():
    black = [
        'binary-tree-upside-down',
        'read-n-characters-given-read4',
        'read-n-characters-given-read4-ii-call-multiple-times',
        'longest-substring-with-at-most-two-distinct-characters',
        'one-edit-distance',
        'missing-ranges',
        'two-sum-ii-input-array-is-sorted',
        'two-sum-iii-data-structure-design',
    ]
    resp = urllib2.urlopen('https://oj.leetcode.com/problems/')
    html = resp.read()

    tree = etree.HTML(html)
    nodes = tree.xpath("id('problemList')/tbody/tr/td/a/@href")
    for p in nodes:
        str = p[10:-1]
        if str in black:
            continue

        print str

if __name__ == '__main__':
    main()

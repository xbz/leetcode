#!/usr/bin/python

import urllib2
from lxml import etree

def main():
    black = [
        'maximum-subarray-iii',
    ]
    resp = urllib2.urlopen('http://www.lintcode.com/en/daily/')
    html = resp.read()

    tree = etree.HTML(html)
    nodes = tree.xpath("id('problem-list')/div/a/@href")
    for p in nodes:
        str = p[9:]
        if str in black:
            continue

        print str

if __name__ == '__main__':
    main()

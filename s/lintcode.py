#!/usr/bin/python

import urllib2
from lxml import etree

def main():
    resp = urllib2.urlopen('http://www.lintcode.com/en/daily/')
    html = resp.read()

    tree = etree.HTML(html)
    nodes = tree.xpath("id('problem-list')/div/a/@href")
    for p in nodes:
        print p[9:]

if __name__ == '__main__':
    main()

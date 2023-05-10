#! /usr/bin/env python3
import urllib.request

def getPage(gatvedelem):
    tmp=urllib.request.urlopen(gatvedelem)
    tmp=tmp.read()
    tmp=tmp.decode("utf-8")
    return tmp
        


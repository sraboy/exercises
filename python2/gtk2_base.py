#!/usr/bin/env python

# coding: utf-8
import pygtk
import gtk

pygtk.require('2.0')

class Base:
    def __init__(self):
        self.window = gtk.Window(gtk.WINDOW_TOPLEVEL)
        self.window.show()
        
    def main(self):
        gtk.main()

print __name__
if __name__ == "__main__":
    base = Base()
    base.main()
    

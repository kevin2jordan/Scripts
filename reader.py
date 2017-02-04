#!/usr/bin/python2
import os,pyttsx
import time
import thread
f = open('rahul.txt','aw+')
x=pyttsx.init()
rate = x.getProperty('rate')
x.setProperty('rate',rate-50)
for line in f:
	x.say(line)
x.runAndWait()

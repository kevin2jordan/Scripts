#!/usr/bin/python2
import os,time
import thread,commands
i=1;
t=raw_input("enter the number of time in sec")
while i<=int(t):
	os.system("gnome-screenshot")
	time.sleep(1)
	i=i+1
exit()


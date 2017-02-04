import urllib2
from bs4 import BeautifulSoup
import re
import os
os.getcwd()
doc=open("english.txt")
doc=doc.read()
doc=doc.split("\n")
i=0
while i<len(doc):
    url="https://www.vocabulary.com/dictionary/"+doc[i]+""
    htmlfile=urllib2.urlopen(url)
    soup=BeautifulSoup(htmlfile,'lxml')
    soup1=soup.find(class_="short")
    soup1=soup1.get_text()
    os.system("tput setaf 3")
    print "######################################",doc[i],"#############################################"
    os.system("tput setaf 0")
    print "SHORT MEANING: ",soup1
    print "--------------------------------------------------------------------------"
    soup2=soup.find(class_="long")
    soup2=soup2.get_text()
    print "LONG MEANING: ",soup2
    print "--------------------------------------------------------------------------"
    soup3=soup.find(class_="instances")
    txt=soup3.get_text()
    txt1=txt.rstrip()
    print ' '.join(txt1.split())
    os.system("tput setaf 3")
    print "##############################################################################################"
    os.system("tput setaf 0")
    i+=1

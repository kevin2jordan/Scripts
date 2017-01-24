from bs4 import BeautifulSoup
import requests
import re
import urllib2
import os
import cookielib
import json
os.system("clear")

#####################################################################
def getfunc(url,header):
    return BeautifulSoup(urllib2.urlopen(urllib2.Request(url,headers=header)),'html.parser')
#####################################################################
image_type="img"
os.system("tput setaf 4")
print "\t\t#####################################################"
query = raw_input("\t\t\tEnter the type of image you want\t\t\n")
num_img = raw_input("\t\t\tEnter the number of image you want\t\t\n")
print type(num_img)
query= query.split()
query='+'.join(query)
########doing google search##########################################
url="https://www.google.co.in/search?q="+query+"&source=lnms&tbm=isch"

DIR="Myimages"
header={'User-Agent':"Mozilla/5.0 (Windows NT 6.1; WOW64) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/43.0.2357.134 Safari/537.36"
}
soup = getfunc(url,header)
#####################################################################
ActualImages=[]
for a in soup.find_all("div",{"class":"rg_meta"}):
    link , Type =json.loads(a.text)["ou"]  ,json.loads(a.text)["ity"]
    ActualImages.append((link,Type))

#print  "there are total" , len(ActualImages),"images"
####################################################################
if not os.path.exists(DIR):
            os.mkdir(DIR)
DIR = os.path.join(DIR, query.split()[0])

if not os.path.exists(DIR):
            os.mkdir(DIR)
######################################################################
for i , (img , Type) in enumerate( ActualImages):
    try:
        req = urllib2.Request(img, headers={'User-Agent' : header})
        raw_img = urllib2.urlopen(req).read()

        cntr = len([i for i in os.listdir(DIR) if image_type in i]) + 1
        print cntr,"downloded successfully"
	print type(cntr)
        if len(Type)==0:
            f = open(os.path.join(DIR , image_type + "_"+ str(cntr)+".jpg"), 'wb')
        else :
            f = open(os.path.join(DIR , image_type + "_"+ str(cntr)+"."+Type), 'wb')
        if str(cntr) == num_img:
		exit()

        f.write(raw_img)
        f.close()
    except Exception as e:
        print "could not load : "+img
        print e

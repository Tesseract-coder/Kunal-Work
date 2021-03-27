import cv2
import time
import numpy as np
import datetime
import smtplib
import urllib2
import cookielib
from getpass import getpass
import sys


username = raw_input("Enter Username: ")
passwd = raw_input("Enter password:")
message = raw_input("Enter Message: ")
number = raw_input("Enter Mobile number:")
message = "+".join(message.split(' '))

#Logging into the SMS Site
url = 'http://site24.way2sms.com/Login1.action?'
data = 'username='+username+'&password='+passwd+'&Submit=Sign+in'
 
#For Cookies:
cj = cookielib.CookieJar()
opener = urllib2.build_opener(urllib2.HTTPCookieProcessor(cj))
 
# Adding Header detail:
opener.addheaders = [('User-Agent','Mozilla/5.0 (X11; Linux x86_64) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/37.0.2062.120 Safari/537.36')]
 
try:
    usock = opener.open(url, data)
except IOError:
    print "Error while logging in."
    sys.exit(1)
 
 
jession_id = str(cj).split('~')[1].split(' ')[0]
send_sms_url = 'http://site24.way2sms.com/smstoss.action?'
send_sms_data = 'ssaction=ss&Token='+jession_id+'&mobile='+number+'&message='+message+'&msgLen=136'
opener.addheaders = [('Referer', 'http://site25.way2sms.com/sendSMS?Token='+jession_id)]


fromaddr = 'mysteriousguardofmagics@gmail.com'
toaddrs  = 'kadam.rahul8976@gmail.com'
msg = 'Someone has entered the room at:'
username = 'mysteriousguardofmagics@gmail.com'
password = 'howdoyouturnthison'
server = smtplib.SMTP('smtp.gmail.com:587')
server.starttls()
server.login(username,password)

def diffimg (a,b,c):
    t0=cv2.absdiff(a,b)
    t1=cv2.absdiff(b,c)

    t3=cv2.bitwise_and(t0,t1)
    return t3

cap = cv2.VideoCapture(0)

t= cap.read()[1]
tp=cap.read()[1]
tpp=cap.read()[1]

t=cv2.cvtColor(t,cv2.COLOR_BGR2GRAY)
tp=cv2.cvtColor(tp,cv2.COLOR_BGR2GRAY)
tpp=cv2.cvtColor(tpp,cv2.COLOR_BGR2GRAY)
x = 1
datetime = datetime.datetime.now()
while True:

    ret,ok = cap.read()
    cv2.imshow('livefeed',ok)
    img=diffimg(t,tp,tpp)
    cv2.imshow('motion detect',img)
    if np.mean(img) <= 1.0 :
        print('no motion')
    else :
        print('something is moving at')
        print datetime
        try:
            sms_sent_page = opener.open(send_sms_url,send_sms_data)
        except IOError:
            print "Error while sending message"

        cv2.imwrite(str(x)+'.jpg', ok)
        x += 1
        server.sendmail(fromaddr, toaddrs, msg)
    res,img=cap.read()
    t=tp
    tp=tpp
    tpp=cv2.cvtColor(img,cv2.COLOR_BGR2GRAY)



    


    key = cv2.waitKey(10)
    if key == 27:
        cv2.destroyAllWindows
        break



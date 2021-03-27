import cv2
import time
import numpy as np
import datetime


cap = cv2.VideoCapture(0)


def diffimg (a,b,c):          #defined function to find difference in images
    t0=cv2.absdiff(a,b)         
    t1=cv2.absdiff(b,c)

    t3=cv2.bitwise_and(t0,t1)
    return t3

def portion1 (b):               #takes first region of image
    a = b[0:320,0:240]
    return a

def portion2 (b):               #takes second region of image
    a = b[320:640,0:240]
    return a
    
def portion3 (b):               #takes third region of image
    a = b[0:320,240:480]
    return a    
def portion4 (b):               #takes fourth region of image
    a = b[320:640,240:480]
    return a

def mod(a):                     #modulus function
    a = a%2
    return a


while True:

    ret,ok = cap.read()                         #get frames
    cv2.line(ok,(320,0),(320,480),(255,0,0),5)  #draw referances
    cv2.line(ok,(0,240),(640,240),(255,0,0),5)
    cv2.imshow('livefeed',ok)                   #show frames

    kk = cv2.cvtColor(ok,cv2.COLOR_BGR2GRAY)
    

    p1 = portion1(kk)                          #get changes in region 1
    p2 = portion2(kk)                          #get changes in region 2
    p3 = portion3(kk)                          #get changes in region 3
    p4 = portion4(kk)                          #get changes in region 4

    
    if np.mean(p1) <= 100:
        print('car is in parking lot 1')
    else :
        print('car is not in parking lot 1')


    if np.mean(p2) <= 100:
        print('car is in parking lot 2')
    else :
        print('car is not in parking lot 2')

        
    if np.mean(p3) <= 100:
        print('car is in parking lot 3 ')
    else :
        print('car is not in parking lot 3')

        
    if np.mean(p4) <= 100:
        print('car is in parking lot 4 ')
    else :
        print('car is not in parking lot 4')
        
    time.sleep(1)

    key = cv2.waitKey(10)
    if key == 27:
        cv2.destroyAllWindows
        break
   














    

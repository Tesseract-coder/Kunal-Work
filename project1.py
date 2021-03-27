import cv2
import time
import numpy as np
import datetime

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
        cv2.imwrite(str(x)+'.jpg', ok)
        x += 1
    res,img=cap.read()
    t=tp
    tp=tpp
    tpp=cv2.cvtColor(img,cv2.COLOR_BGR2GRAY)



    


    key = cv2.waitKey(10)
    if key == 27:
        cv2.destroyAllWindows
        break



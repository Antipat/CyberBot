from PIL import Image
import cv2
import numpy as np
import math
from pylab import*
import serial
import time

r = serial.Serial('com3', 9600)

cap = cv2.VideoCapture(0)
ret, frame = cap.read()
fourcc = cv2.VideoWriter_fourcc(*'XVID')
out = cv2.VideoWriter('Woutput181.avi', fourcc, 20.0, (640,480))
template = cv2.imread("obrabM.jpg",0)
w, h = template.shape[::-1]
x,y = 0,0

dx = [100, 500]
dy = [50, 400]

sx = 400//2
sy = 350//2

command="0"
while True:    
    _, frame = cap.read ()
    #hsv = cv2.cvtColor(frame, cv2.COLOR_BGR2HSV)
    i= cv2.cvtColor(frame, cv2.COLOR_BGR2GRAY)
    
    lower_red = np.array([0,180,200])
    upper_red = np.array([255,225,225])
    #белый - 10,10,0  200,100,255.
    #зелёный - 10 10 0   150 200 150
    #серо-зелёный - 10 10 0  150 200 150

    #mask = cv2.inRange(hsv, lower_red, upper_red)
    #res = cv2.bitwise_and(frame, frame, mask = mask)
    res1 = cv2.matchTemplate(i,template,3)
    min_val, max_val, min_loc, max_loc = cv2.minMaxLoc(res1)
    top_left = max_loc
    bottom_right = (top_left[0] + w, top_left[1] + h)
    x = (top_left[0] + bottom_right[0])/2
    y = (top_left[1] + bottom_right[1])/2
    #for d1 in [5,210,410,635]:
        #if x>0+d1 and x<200+d1 and y>10 and y<500:
            #cv2.rectangle(frame, (d1,0),(210+d1,150) , (255, 0, 0), 3)
        #else:
            #cv2.rectangle(frame, (d1,0),(210+d1,150) , (0, 255, 0), 3)

        
    cv2.line(frame, (5,0), (5,500), (250,255,255), 2)
    cv2.line(frame, (210,0), (210,500), (250,255,255), 2)
    cv2.line(frame, (410,0), (410,500), (250,255,255), 2)
    cv2.line(frame, (635,0), (635,500), (250,255,255), 2)
    cv2.line(frame, (700,0), (0,0), (250,255,255), 2)
    cv2.line(frame, (700,150), (0,150), (250,255,255), 2)
    cv2.line(frame, (700,320), (0,320), (250,255,255), 2)
    cv2.line(frame, (700,477), (0,477), (250,255,255), 2)
    
    if y<500:
        cv2.rectangle(frame, top_left, bottom_right, (0, 255, 0), 3)
        cv2.putText(frame, f"{[x, y]}", (bottom_right[0]+10, bottom_right[1]+10), cv2.FONT_HERSHEY_SIMPLEX, 1, (255,255,0), 2)
    #out.write(res)
    
    out.write(frame)
    
    cv2.imshow('frame', frame)
    if (45<y<=170):
        if (99<x<=230):
            command = "1"    
        elif (230<x<=330) :
            command = "2"
        elif (x>330):
            command = "3"
    elif (170<y<=300):
        if (99<x<=230):
            command = "1"    
        elif (230<x<=330) :
            command = "0"
        elif (x>330):
            command = "3"
    elif (y>300):
        if (99<x<=230):
            command = "1"    
        elif (230<x<=330) :
            command = "4"
        elif (x>330):
            command = "3"
    
    r.write((command + '\n').encode('utf-8'))
    print(f"Отправлено: {command}")
    time.sleep(0.1)   
    
    #_, frame = cap.read ()
    #hsv = cv2.cvtColor(frame, cv2.COLOR_BGR2HSV)
    k = cv2.waitKey(5) & 0xFF
    if k == 27:
        break


cv2.destroyAllWindows()
cap.release()




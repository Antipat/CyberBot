import time, cyberpi, random,math

cyberpi.display.set_brush("green")
cyberpi.linechart.set_step(50)
cyberpi.display.clear()



def trigon(A, k):    
    #cyberpi.display.clear()
    n = 0
    
    for i in range(0, 360, 45):
        x = int(50+ A*math.sin(math.radians(i)))
        y = int(50+ A*math.cos(math.radians(i)))
        cyberpi.display.show_label("o", 32, x,y,n)
        n+=1
        
    
        
trigon(30, 10)    
    


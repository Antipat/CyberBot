import time, cyberpi, random,math

cyberpi.display.set_brush("green")
cyberpi.linechart.set_step(50)
cyberpi.display.clear()

n = 0

def trigon(A, k):
    cyberpi.linechart.set_step(50)
    cyberpi.display.clear()
    cyberpi.linechart.add(50)
    cyberpi.display.clear()
    
    cyberpi.linechart.set_step(0)
    for i in range(180):
        #x = math.sin(math.radians(i))
        y = 50+ A*math.sin(math.radians(k*i))
        cyberpi.linechart.add(y)
        
    cyberpi.linechart.set_step(0)
    for i in range(180):
        #x = math.sin(math.radians(i))
        y = 50+ -A*math.sin(math.radians(k*i))
        cyberpi.linechart.add(y)
        
trigon(20, 10)    
    


import time, cyberpi, random,math

cyberpi.display.set_brush("green")
cyberpi.linechart.set_step(50)
cyberpi.display.clear()

n = 0

def tabl():
    for i in range(1,3):
        for j in range(1,4):
            t = str(random.randint(0,100))
            cyberpi.table.add(i,j, t)
    
    
while True:
    tabl()
    time.sleep(1)
    


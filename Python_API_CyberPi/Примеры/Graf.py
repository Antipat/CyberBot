import time, cyberpi, random
cyberpi.display.set_brush("green")
cyberpi.linechart.set_step(10)
cyberpi.display.clear()
n =0
while True:
    time.sleep(1)
    d = random.randint(0,128)
    cyberpi.linechart.add(d)
    if n >=13:
        cyberpi.display.clear()
        n =0
    n+=1
    
    

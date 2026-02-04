import time, cyberpi, random
#cyberpi.led.on(255,0,0, "all")

bri = 0
while True:
    time.sleep(1)
    r = random.randint(0,255)
    g = random.randint(0,255)
    b = random.randint(0,255)
    cyberpi.led.on(r,g,b, "all")
    cyberpi.led.set_bri(bri)    
    bri = (bri +10)%100
    
    
    

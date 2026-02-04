import cyberpi, random
cyberpi.display.clear()
n = int(input("The number of times to roll 2 dice: "))
count_list = [0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0]
t = 0
sum_list = [2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12]
while t < n:
    dice_x = random.randint(1, 6)
    dice_y = random.randint(1, 6)
    print("(", dice_x, ",", dice_y, ")")
    result = dice_x + dice_y
    t += 1
    sum_index = sum_list.index(result)
    count_list[sum_index] += 1

cyberpi.barchart.add(round(count_list[0]/n * 200, 2))
cyberpi.display.set_brush(128, 0, 0)
cyberpi.display.set_brush(220, 20, 60)
cyberpi.barchart.add(round(count_list[1]/n * 200, 2))
cyberpi.display.set_brush(255, 0, 0)
cyberpi.barchart.add(round(count_list[2]/n * 200, 2))
cyberpi.display.set_brush(205, 92, 92)
cyberpi.barchart.add(round(count_list[3]/n * 200, 2))
cyberpi.display.set_brush(233, 150, 122)
cyberpi.barchart.add(round(count_list[4]/n * 200, 2))
cyberpi.display.set_brush(255, 69, 0)
cyberpi.barchart.add(round(count_list[5]/n * 200, 2))
cyberpi.display.set_brush(255, 165, 0)
cyberpi.barchart.add(round(count_list[6]/n * 200, 2))
cyberpi.display.set_brush(255, 215, 0)
cyberpi.barchart.add(round(count_list[7]/n * 200, 2))
cyberpi.display.set_brush(240, 230, 140)
cyberpi.barchart.add(round(count_list[8]/n * 200, 2))
cyberpi.display.set_brush(255, 255, 0)
cyberpi.barchart.add(round(count_list[9]/n * 200, 2))
cyberpi.display.set_brush(154, 205, 50)
cyberpi.barchart.add(round(count_list[10]/n * 200, 2))  

import time, cyberpi


while True:
    cyberpi.display.clear()
    if cyberpi.controller.is_press('up'):
        cyberpi.console.print("up")
        cyberpi.audio.play_drum('snare', 0.25)
    if cyberpi.controller.is_press('down'):
        cyberpi.console.print("down")
        cyberpi.audio.play_drum('bass-drum', 0.25)
    if cyberpi.controller.is_press('left'):
        cyberpi.console.print("left")
        cyberpi.audio.play_drum('open-hi-hat', 0.25)
    if cyberpi.controller.is_press('right'):
        cyberpi.console.print("right")
        cyberpi.audio.play_drum('closed-hi-hat', 0.25)

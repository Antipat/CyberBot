import cyberpi
import time

soundText = ("hello", "hi", "bye", "yeah", "wow", "laugh", "hum", "sad", "sigh", "angry")

cyberpi.console.print("hello")

for i in soundText:
    cyberpi.audio.play(i)
    time.sleep(1)




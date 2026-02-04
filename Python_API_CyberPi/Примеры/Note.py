import time, cyberpi
cyberpi.console.println('Press B to play music')
cyberpi.console.println('Press B to play music.')
while True:
    while not cyberpi.controller.is_press('b'):
        pass
    # You can right-click a block to view help information.
    # The block uses MIDI codes to indicate notes. The following MIDI codes are used in t
    #
    # Numbered musical notation/Note/MIDI code
    # 1 C4 60
    # 2 D4 62
    # 3 E4 64
    # 4 F4 65
    # 5 G4 67
    # 6 A4 69
    # 7 B4 71
    cyberpi.audio.play_music(60, 0.25)
    cyberpi.audio.play_music(60, 0.25)
    cyberpi.audio.play_music(67, 0.25)
    cyberpi.audio.play_music(67, 0.25)
    cyberpi.audio.play_music(69, 0.25)
    cyberpi.audio.play_music(69, 0.25)
    cyberpi.audio.play_music(67, 0.25)
    time.sleep(1)
    cyberpi.audio.play_music(65, 0.25)
    cyberpi.audio.play_music(65, 0.25)
    cyberpi.audio.play_music(64, 0.25)
    cyberpi.audio.play_music(64, 0.25)
    cyberpi.audio.play_music(62, 0.25)
    cyberpi.audio.play_music(62, 0.25)
    cyberpi.audio.play_music(60, 0.25)

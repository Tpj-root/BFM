import pygame
import sys

def play_sound(sound_file):
    """Function to play sound."""
    pygame.mixer.init()
    pygame.mixer.music.load(sound_file)
    pygame.mixer.music.play()
    while pygame.mixer.music.get_busy():  # Wait for the sound to finish
        pass

if __name__ == "__main__":
    if len(sys.argv) != 2:
        print("Usage: python play_sound.py <sound_file>")
        sys.exit(1)
    
    sound_file = sys.argv[1]
    play_sound(sound_file)


import serial
import subprocess
import time
import json

# Load sound files for different actions
sound_file_state_1 = "/home/sab/Documents/Tone/1.mp3"  # Sound for state 1
sound_file_state_2 = "/home/sab/Documents/Tone/2.mp3"  # Sound for state 2
sound_file_state_3 = "/home/sab/Documents/Tone/3.mp3"  # Sound for state 2
sound_file_state_4 = "/home/sab/Documents/Tone/4.mp3"  # Sound for state 2
sound_file_state_5 = "/home/sab/Documents/Tone/5.mp3"  # Sound for state 2
sound_file_state_6 = "/home/sab/Documents/Tone/6.mp3"  # Sound for state 2

# Configure the serial connection
COM_PORT = '/dev/ttyUSB0'  # Update for your specific serial port
BAUD_RATE = 9600

# Create a serial connection
ser = serial.Serial(COM_PORT, BAUD_RATE)
time.sleep(2)  # Wait for the serial connection to initialize

def play_sound(sound_file):
    """Function to play sound using a subprocess."""
    subprocess.Popen(['python3', 'play_sound.py', sound_file])

try:
    while True:
        # Read a line from the serial port
        if ser.in_waiting > 0:  # Check if there is data in the buffer
            line = ser.readline().decode('utf-8').strip()  # Read and decode the line
            
            try:
                # Parse the JSON-like data
                data = json.loads(line)
                for sensor, state in data.items():
                    if state == 1:  # Check if the button is activated
                        if sensor == "B1":
                            print(f"{sensor} detected action for state 1.")
                            play_sound(sound_file_state_1)  # Play the sound for state 1

                        elif sensor == "B2":
                            print(f"{sensor} detected action for state 2.")
                            play_sound(sound_file_state_2)  # Play the sound for state 2

                        elif sensor == "B3":
                            print(f"{sensor} detected action for state 3.")
                            play_sound(sound_file_state_3)  # Play the sound for state 2

                        elif sensor == "B4":
                            print(f"{sensor} detected action for state 4.")
                            play_sound(sound_file_state_4)  # Play the sound for state 2

                        elif sensor == "B5":
                            print(f"{sensor} detected action for state 5.")
                            play_sound(sound_file_state_5)  # Play the sound for state 2

                        elif sensor == "B6":
                            print(f"{sensor} detected action for state 6.")
                            play_sound(sound_file_state_6)  # Play the sound for state 2
            except json.JSONDecodeError:
                print("Received invalid data:", line)

except KeyboardInterrupt:
    print("Program terminated.")

finally:
    ser.close()  # Close the serial connection when done


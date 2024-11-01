import serial
import subprocess
import time

COM_PORT = '/dev/ttyUSB0'  # Update with your specific port
BAUD_RATE = 9600

# Create a serial connection
ser = serial.Serial(COM_PORT, BAUD_RATE)
time.sleep(2)  # Wait for the serial connection to initialize

try:
    while True:
        # Check if there is data in the buffer
        if ser.in_waiting > 0:
            # Read a line from the serial port and decode it, handling decoding errors
            line = ser.readline().decode('utf-8', errors='ignore').strip()
            
            # Check for the "Touched!" message
            if line == "Touched!":
                print("Touch detected! Executing command...")

                # Execute the command 'seq 1 10' and capture the output
                result = subprocess.run(['seq', '1', '10'], capture_output=True, text=True)

                # Print the output of the command
                print("Command output:")
                print(result.stdout)  # Print the standard output from the command
                if result.stderr:
                    print("Error:", result.stderr)  # Print any error that occurred

except KeyboardInterrupt:
    print("Program terminated.")

finally:
    ser.close()  # Close the serial connection when done


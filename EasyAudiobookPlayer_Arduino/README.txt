EasyAudiobookPlayer project Arduino modul programing. 

## Programming the Arduino Module  

### Requirements  
- A USB cable to connect the Arduino module to your computer.  
- Visual Studio Code with the PlatformIO add-on installed.  
- The EasyAudiobookPlayer Arduino project files from GitHub.  

---

### Steps to Upload the Program  
1. Download the Project  
   - Clone or download the EasyAudiobookPlayer Arduino project files from GitHub.  

2. Install Required Software  
   - Install [Visual Studio Code](https://code.visualstudio.com/).  
   - Open Visual Studio Code and install the PlatformIO add-on.  

3. Open the Project  
   - Open the `EasyAudiobookPlayer_Arduino` directory in Visual Studio Code.  

4. Configure PlatformIO  
     - Open the `platformio.ini` file in the project directory.  
   - Modify the configuration to match your Arduino module type and serial port:  
	"[env:nanoatmega328]
	platform = atmelavr
	board = nanoatmega328
	framework = arduino
	monitor_speed = 115200
	lib_deps = 	
		xoseperez/DebounceEvent@^2.0.5
		prosenb/EEPROMWearLevel@^2.1.0
		dfrobot/DFRobotDFPlayerMini@^1.0.6 “
 - Replace ` nanoatmega328` with the correct Arduino model (e.g., `pro16MHzatmega328`).  
 - Add this line: upload_port = your_serial_port if you know the serial port belongs to the Arduiono. Replace `your_serial_port` with the appropriate COM port (e.g., `COM3` on Windows).  


5. Modify the Source Code (Optional)  
   - If needed, edit the file `EasyAudiobookPlayer_Arduino\src\main.cpp` to customize the functionality.  

6. Upload the Program  
   - Connect the Arduino module to your computer via USB.  
   - In Visual Studio Code, click the PlatformIO: Upload button or use the shortcut to upload the program to the Arduino.  

---

### Program Overview  
The program is structured as follows:  

1. Initialization in `setup()`  
   - The MP3 player module is initialized.  
   - Button press functionality is configured.  

2. Looping in `loop()`  
   - Continuously monitors:  
     - Button presses:  
       - Toggles between play and pause modes.  
     - MP3 playback status:  
       - If an MP3 finishes, the program:  
         - Saves the current MP3 sequence number to the EEPROM.  
         - Ensures playback can resume from this sequence number upon restarting the device.  

---

### Notes  
- Ensure the Arduino module is compatible with the selected settings in the `platformio.ini` file.  
- The program uses the EEPROM to save and retrieve the MP3 sequence number, allowing it to resume playback seamlessly after a power cycle or reset.  

--- 

This README should guide you through the upload process and provide an understanding of the program's functionality. Let me know if you need further clarifications or enhancements!
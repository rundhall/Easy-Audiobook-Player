# Easy Audiobook Player

## Introduction
The **Easy Audiobook Player** is a simple, user-friendly device designed for individuals who face challenges using modern gadgets. Originally created as a Christmas gift for my 94-year-old grandmother, this device is tailored for users with visual or physical impairments, providing an accessible solution for audiobook playback.

---

## Features
- **Single Button Operation**: Simple start/stop functionality.
- **Advanced Controls**:
  - 5-second press: Skip to the next audiobook file.
  - 20-second press: Restart playback from the beginning.
- **Resume Playback**: Automatically resumes from the last played position.

---

## Components

| Component                                    | Quantity | Link                                                                 | Price  |
|---------------------------------------------|----------|----------------------------------------------------------------------|--------|
| DC 12V 24V 80W x 2 Audio Amplifier Board    | 1        | [Link](https://www.aliexpress.com/item/32823374190.html)             | $2.91  |
| Arduino Nano 16MHz ATMEGA328P               | 1        | [Link](https://www.aliexpress.com/item/1005006472755752.html)        | $3.32  |
| DFPlayer Mini MP3 Module                    | 1        | [Link](https://www.aliexpress.com/item/4000379417594.html)           | $1.63  |
| Game Push Button Switch                     | 1        | [Link](https://www.aliexpress.com/item/1005006347986280.htm)         | $0.50  |
| Wooden Enclosure Box (16x10x9.2 cm)         | 1        | [Link](https://www.aliexpress.com/item/1005005854034476.html)        | $4.94  |
| Toggle Switch SS22D07 2P2T                  | 1        | [Link](https://www.aliexpress.com/item/32822779479.html)             | $0.91  |
| USB 2.0 A Power Supply Extension Cable      | 1        | [Link](https://www.aliexpress.com/item/1005004980471643.html)        | $0.56  |
| DC-DC Voltage Regulator Module LM2596S      | 1        | [Link](https://www.aliexpress.com/item/1005001691110030.html)        | $0.72  |
| GHXAMP Full Range Speakers (4 ohm, 16W)     | 2        | [Link](https://www.aliexpress.com/item/1005007219657143.html)        | $7.31  |
| Mini Screw Terminal Blocks                  | 1        | [Link](https://www.aliexpress.com/item/1005005433827504.html)        | $0.72  |
| Micro SD Card (max. 32 GB)                  | 1        | [Link](https://www.aliexpress.com/item/1005001617961938.html)        | $2.57  |
| PCB                                         | 1        | Custom                                                               | ~$10.00 |

**Total Material Cost**: $36.09

---

## Assembly
### Hardware
1. **Connect Components**: Use a custom PCB or breadboard for wiring the Arduino Nano, DFPlayer Mini, and amplifier board.
2. **Enclosure**:
   - Drill holes for the speaker, button, and cable entry.
   - Mount all components securely in the wooden box.
3. **Power Supply**: Feed the USB power cable through the enclosure and connect to a 5V charger.

### Software
#### Preparing MP3 Files
1. Place your audiobook MP3 files into a `mp3_files` folder.
2. Use the provided Python script (`mp3_to_mp3chunks.bat`) to split files into 5-minute chunks.
3. Copy the output files to the `01` folder on a FAT32-formatted SD card.

#### Programming the Arduino
1. Install [PlatformIO](https://platformio.org/) in Visual Studio Code.
2. Clone the repository and open the `EasyAudiobookPlayer_Arduino` project.
3. Update the `platformio.ini` file to match your Arduino Nano configuration.
4. Upload the code to the Arduino Nano using PlatformIO.

---

## How It Works
- **Playback**: The Arduino controls the DFPlayer Mini to play audio files stored on the SD card.
- **Amplification**: The audio signal is amplified and played through the speakers.
- **Power Management**: A DC-DC converter steps up voltage for the amplifier, while the Arduino and DFPlayer operate on 5V.

---

## Usage Instructions
1. Press the button to start or stop playback.
2. Hold for 5 seconds to skip to the next file.
3. Hold for 20 seconds to reset playback.
4. Enjoy your audiobook!

---

## Conclusion
This Easy Audiobook Player is a thoughtful gift for anyone who values simplicity and accessibility. Whether for a loved one or as a DIY project, it’s a functional and meaningful creation.

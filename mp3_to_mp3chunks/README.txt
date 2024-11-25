# mp3_to_mp3chunks

This script processes all MP3 files in a given directory, splits them into smaller MP3 files with a maximum duration of 5 minutes each, and names them sequentially, starting from `0001.mp3`. The script is designed to work with the EasyAudiobookPlayer. The generated files should be copied to an SD card formatted as FAT32 in a folder named `01`.

For example:
```
F:/01/0001.mp3
```

## How to Use

1. **Install Python**
   - Download and install Python from [https://www.python.org/downloads/](https://www.python.org/downloads/).

2. **Prepare Directories**
   - Place all your MP3 files into a folder named `mp3_files`.

3. **Run the Script**
   - Execute the script by running the `mp3_to_mp3chunks.bat` file.

4. **Copy Generated Files**
   - After the script completes, copy the files from the `output_files` folder to the `01` folder on the SD card.

5. **Organize Processed Files**
   - Move all MP3 files from the `mp3_files` folder to the `done_mp3` folder to clean up for the next batch.

## Additional Notes

- Ensure that the SD card is formatted as FAT32 before copying the files.
- If the `done_mp3` folder does not exist, create it manually before running the script.
- The script processes all subdirectories within the `mp3_files` folder, ensuring no MP3 files are missed.
- If the `output_files` folder already contains files, the numbering will continue from the last file found in that folder.

### Example Directory Structure
Before running:
```
mp3_files/
   file1.mp3
   file2.mp3
output_files/
done_mp3/
```

After running:
```
mp3_files/
output_files/
   0001.mp3
   0002.mp3
   ...
done_mp3/
   file1.mp3
   file2.mp3
```

### Troubleshooting
- If the script fails to process a file, check that the input MP3 files are not corrupted and are in a supported format.
- Ensure Python and required libraries like `pydub` are properly installed. You can install `pydub` by running:
  ```
  pip install pydub
  ```
- Make sure `ffmpeg` or `libav` is installed on your system, as `pydub` depends on one of these for processing audio files.


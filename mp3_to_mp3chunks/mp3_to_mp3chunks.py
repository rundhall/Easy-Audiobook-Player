# -*- coding: utf-8 -*-
"""
Created on Sat Nov 23 15:22:47 2024

@author: rundhall
"""

import os
from pydub import AudioSegment

# Az eredeti és cél könyvtár beállítása
SOURCE_DIR = "mp3_files"  # Ide helyezd az eredeti MP3 fájlokat
OUTPUT_DIR = "output_files"  # Ide kerülnek a feldarabolt fájlok
DONE_DIR = "done_mp3"  # Ide kerülnek a feldarabolt fájlok
SEGMENT_DURATION_MS = 300 * 1000  # 10 másodperc szegmens időtartama

def get_next_file_counter(output_directory):
    existing_files = [f for f in os.listdir(output_directory) if f.endswith('.mp3')]
    if not existing_files:
        return 1
    
    max_number = max(int(os.path.splitext(f)[0]) for f in existing_files)
    return max_number + 1

def move_to_done_directory(done_directory, source_directory):
    if not os.path.exists(done_directory):
        os.makedirs(done_directory)
    
    for item in os.listdir(source_directory):
        source_path = os.path.join(source_directory, item)
        destination_path = os.path.join(done_directory, item)
        os.rename(source_path, destination_path)


def split_audio_files(source_dir, output_dir, done_dir, segment_duration_ms):
    """MP3 fájlok feldarabolása a megadott időtartamú szegmensekre."""
    if not os.path.exists(output_dir):
        os.makedirs(output_dir)

    for root, _, files in os.walk(source_dir):  # Walk through all subdirectories
        for filename in files:
            if filename.endswith(".mp3"):
                filepath = os.path.join(root, filename)
                try:
                    file_counter = get_next_file_counter(output_dir)
                    audio = AudioSegment.from_mp3(filepath)
        
                    for i in range(0, len(audio), segment_duration_ms):
                        segment = audio[i:i + segment_duration_ms]
                        output_filename = f"{file_counter:04}.mp3"
                        output_path = os.path.join(output_dir, output_filename)
                        segment.export(output_path, format="mp3")
                        print(f"File: {filename} Output: {output_filename}")
                        file_counter += 1
                except Exception as e:
                    print(f"Error processing file {filepath}: {e}")
        # Move the processed directory to the done directory
        #move_to_done_directory(done_dir, root)

if __name__ == "__main__":
    split_audio_files(SOURCE_DIR, OUTPUT_DIR, DONE_DIR, SEGMENT_DURATION_MS)

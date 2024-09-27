import os
import re
from datetime import datetime

def rename_video_files(directory):
    # Define the pattern to match files like VID_20240709_152727898.mp4
    pattern = re.compile(r"VID_(\d{8})_\d{9}\.mp4")
    
    # Iterate over all files in the directory
    for filename in os.listdir(directory):
        if pattern.match(filename):
            # Extract date from filename (assuming YYYYMMDD format)
            match = pattern.search(filename)
            if match:
                date_str = match.group(1)  # YYYYMMDD
                # Convert to datetime object
                date_obj = datetime.strptime(date_str, '%Y%m%d')
                # Format date as DD-MM-YYYY
                formatted_date = date_obj.strftime('%d-%m-%Y')
                
                # New filename with date at the beginning
                new_filename = f"{formatted_date}_{filename}"
                
                # Full path to the current and new file
                current_path = os.path.join(directory, filename)
                new_path = os.path.join(directory, new_filename)
                
                # Rename the file
                os.rename(current_path, new_path)
                print(f"Renamed: {filename} -> {new_filename}")

# Example usage
directory_path = r"C:\Users\princ\Downloads\preeti\partlater"
rename_video_files(directory_path)

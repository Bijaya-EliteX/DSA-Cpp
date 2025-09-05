from rembg import remove
from PIL import Image
import os

def remove_background(input_path, output_path):
    # Open the input image
    with open(input_path, "rb") as input_file:
        input_data = input_file.read()
    
    # Remove the background
    output_data = remove(input_data)
    
    # Save the output image
    with open(output_path, "wb") as output_file:
        output_file.write(output_data)

# Specify input and output paths
input_image_path = r"D:\Dzinefolio works\Sheetal colors\Cement board\input_image.png"  # Replace with your actual image file name
output_image_path = r"D:\Dzinefolio works\Sheetal colors\Cement board\output_image.png"  # Desired output path for the PNG

# Execute the background removal
remove_background(input_image_path, output_image_path)

# Optional: Display the original and processed images
original_image = Image.open(input_image_path)
removed_background_image = Image.open(output_image_path)

original_image.show(title="Original Image")
removed_background_image.show(title="Image with Removed Background")

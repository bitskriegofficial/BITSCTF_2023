#!/usr/bin/python
from PIL import Image

# Load the PNG image
img1 = Image.open('challenge2.png')
img2 = Image.open('blurred.png')
# Get the RGB values of all pixels
img1 = img1.convert('RGB')
img2 = img2.convert('RGB')
pixels1 = img1.load()
pixels2 = img2.load()
width1, height1 = img1.size
width2, height2 = img2.size
print(f"{width1} {width2}")
new_img = Image.new('RGB', (width1, height1))
a =30
new_pixels = new_img.load()
for y in range(height1):
    for x in range(width1):
        if y > height2*a -1:
        	r,g,b = pixels1[x,y]
        else:
        	if y%a == 0 and x%3 ==0:
        		r,g,b = pixels2[x/3,y/a]
        	else:
        		r,g,b = pixels1[x,y]
        new_pixels[x,y] =(r,g,b)
new_img.save('new_img2.png')

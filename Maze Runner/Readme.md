﻿'lostforever.jpg' is a very large image file, indicating binwalk (also question description mentions 'walking through the maze' as a hint towards binwalk.
extracting the files gives another large file which is an image that extracts to a couple of files one of which is a fake flag and another is an image of four coloured doors. extracting the coloured doors image leads to four zip files named in numbers which are char by char ascii values to the hex of the four colours of the doors.
Running exiftool on choose reveals a hex color value as the artist name.
converting the hex string to ascii leads to the correct zip file to proceed through the maze. 
Extracting that zip gives a file named 'Nash' which can be further extracted using binwalk to a couple of files one of them being a file named portal which is again very large in size (binwalk again)
Exiftools on portal indicate it being a jpg. Opening the portal reveals a door surrouned by 10 star signs. The star signs have alternate names which resemble the shape of their corresponding constellations. The set of files we got from extracting 'Nash' also gave us a readme which contains a clue to which star sign to follow through the maze. Cropping the picture of the portal according to the hint leads us to an image whose bottom right corner points to capricorn. 
Extracting goat.zip gives us a video (thought you might need some motivation). Binwalking this video takes us to a lot of images one of which is named 'Respect++' and holds our flag(the correct one)

On a side note - The maze is pretty interesting and if you found the flag walking the right path all the way you'll miss out on a couple of things (fun things or annoying things? ;] ). So it'll probably be fun getting lost through the maze laughing and crying along the way with all the dumb, funny, knowledgable or 'pleasurable' things. Although I must tell you, if you really choose to wander the maze not looking for the flag and just for exploration, you'll need a lot of time and patience to explore it all.

Made by - Hridya05

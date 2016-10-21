//krita animation renderer :P
//just needs some string formatting and a window :D
//nine
Posix.system ('avconv -i "img%04d.png" -r 24 -c:v libx264 -crf 20  -pix_fmt yuv420p img.mov');

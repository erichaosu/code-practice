from PIL import Image
import sys
import time
import threading
def smooth_img(img, w, h):
    new_img = Image.new('RGB', (w,h))
    pixels = new_img.load()
    
    #divid image into 2 piece
    #img1 = img.crop((0,0,w,h//2))
    #w1,h1 = img1.size
    #img2 = img.crop((0,h//2+2,w,h))
    """
    #w2,h2 = img2.size
    t1 = threading.Thread(target = smooth, args = (pixels, img, 0, w, 0, h//2))
    t1.start()
    t2 = threading.Thread(target = smooth, args = (pixels, img, 0, w, h//2, h))
    t2.start()
    """
    smooth(pixels, img, 0, w, 0, h)
    #smooth(pixels, img, 0, w, h//2, h)
    return new_img
def smooth(pixels, img, w1, w2, h1, h2):
    
    #all pixels at the edge will not count
    #column should >0 and < width-1
    #row should >0 and <height-1
    for col in range (w1, w2):
        if col > w1 and col < w2-1:
                for row in range (h1,h2):
                    if row > h1 and row < h2-1:
                            #first step: get surrounding pixels' RGB value
                            #3 pixels above 
                            p1Red,p1Green,p1Blue = img.getpixel((col, row-1))
                            p2Red,p2Green,p2Blue = img.getpixel((col-1, row-1))
                            p3Red,p3Green,p3Blue = img.getpixel((col+1, row-1))

                            #2 pixels on the left and right
                            p4Red,p4Green,p4Blue = img.getpixel((col-1,row))
                            p5Red,p5Green,p5Blue = img.getpixel((col+1,row))

                            #3 pixels below
                            p6Red,p6Green,p6Blue = img.getpixel((col,row+1))
                            p7Red,p7Green,p7Blue= img.getpixel((col-1,row+1))
                            p8Red,p8Green,p8Blue = img.getpixel((col+1,row+1))
                    
                            #average RGB value use // to get int
                            pavgRed = (p1Red + p2Red + p3Red + p4Red + p5Red + p6Red + p7Red + p8Red)//8
                            pavgBlue = (p1Blue + p2Blue + p3Blue + p4Blue + p5Blue + p6Blue + p7Blue + p8Blue)//8
                            pavgGreen = (p1Green + p2Green + p3Green + p4Green + p5Green + p6Green + p7Green + p8Green)//8

                            #set average RGB value to the pixels in the new img
                            pixels[col,row]  = ((pavgRed,pavgGreen,pavgBlue))
    return pixels
if __name__ == '__main__':    
    #open png file input from command line
    img = Image.open(sys.argv[1])
    #get image width and height
    w,h = img.size
    print ("image "+sys.argv[1]+"  size w= "+str(w)+" h= "+str(h) )
    start_time = time.time()

    #call smooth function to smooth each pixel's color with its neighbor color
    #pixel on first and last row, first and last column don't count
    img2 = smooth_img(img, w, h)
    end_time1 = time.time()
    print ("smooth take  {0:d} seconds".format (int(end_time1-start_time)))
    img2.save('C://Users/haosu/pyimg.png')
    end_time2 = time.time()
    print ("save image file take  {0:2.2f} seconds" .format((end_time2-end_time1)))
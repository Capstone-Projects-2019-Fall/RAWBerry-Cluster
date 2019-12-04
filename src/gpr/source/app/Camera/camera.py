#Module: Captures a number of RAW Unbayered images

from time import sleep
from picamera import picamera
import pydng


def capture_Frames(n, dest):	#capture n frames, name should be full path and filename to desired destination - should typically be .jpg

	i = 0 ##capture loop index
	freq = .1 ##frequency of captures
	width = 640
    length = 480

	##picamera parameters
	format = 'jpeg'
	bayer = true
	fr = 15
	##pydng params

    colour = True
    inputFilename = None
    shade = None
    dark = None
    bpp = 16
	

	with picamera.PiCamera() as camera:
			
		camera.resolution = (width, length)
		camera.framerate = fr ##for preview

		#warm up camera
		camera.start_preview
		sleep(5) ## 5 second preview window before capture begins

			#capture images
		while i < n: ##capture(output, format=None, use_video_port=False, resize=None, splitter_port=0, bayer=False **options)
			##'raw' - Deprecated option - use 'yuv' or 'rgb' directly
			##bayer parameter only works with jpeg encoder - produces RAW bayer data in image meta-data
			name = dest + '.jpeg'
			camera.capture( name % i, format, bayer)##capture frame
			sleep(freq)

		camera.stop_preview

		i = 0
		while i < n: ##after all images are captured, loop through all images and convert to dng format
			pydng.convert(name % i, width, length, colour, bpp, shade, dark)##convert frame to dng format


##executes module as script -- can still be imported
if __name__ == "__main__":
	import sys
	capture_Frames(sys.argv[1], sys.argv[2])
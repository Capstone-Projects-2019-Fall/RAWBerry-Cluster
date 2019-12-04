PYDNG V2.0
=========
Latest Release

Python based Adobe DNG RAW Converter. Tuned for use with the Raspberry Pi Camera. 
Convert raw bayer data from raw containing .jpgs from the Raspberry Pi Camera V2 ( SonyIMX219 ) into DNG files.
Requires: Python 2.7 and Numpy

![](https://github.com/schoolpost/pydng/blob/master/docs/demo.jpg?raw=true)

Instructions
------------
```
python setup.py build

python pydng.py <options> <inputFilename> 

Options:
 -w/--width  Frame width
 -l/--length Frame length

Examples:
  pyraw2dng.py -w 3280 -l 2464 color.jpg
```

TODO
------------

-Copy EXIF Data from .jpg to .dng

-Apply calibrated color matrix values 

-Map or remove Bad pixels

-Automated calibration script to let users generate dark/shade/pxl from input images


Credits
------------
Source referenced from:

Krontech | [chronos-utils](https://github.com/krontech/chronos-utils)

Andrew Baldwin | [MLVRawViewer](https://bitbucket.org/baldand/mlrawviewer)



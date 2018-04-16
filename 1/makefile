Gauss.jpg : 2DFT image_filters erase format Gauss.dat
	#

2DFT : 2DFT.cpp
	c++ 2DFT.cpp -o 2DFT

image_filters : image_filters.cpp
	c++ image_filters.cpp -o image_filters

Gray.jpg : erase_format Gray.dat
	python3 image2matrix.py "Sky.jpg" "Gray.dat"
	./erase_format "Gray.dat" "NFGray.dat"
	python3 matrix2image.py "NFGray.dat" "Gray.jpg"

Gray.dat : image2matrix.py matrix2image.py
	python3 image2matrix.py "Sky.jpg" "Gray.dat"

erase_format : erase_format.cpp
	rm -f a.out
	c++ erase_format.cpp -o erase_format

clean :
	rm -f *.dat Gray.jpg Gauss.jpg

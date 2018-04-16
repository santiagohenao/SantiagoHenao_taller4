import sys
import numpy as np
import os
import matplotlib.image as mpimg

img=mpimg.imread(sys.argv[1])

X=0.2126*img[:,:,0]+ 0.7152*img[:,:,1] + 0.0722*img[:,:,2]

np.savetxt(sys.argv[2],X.astype(int),fmt="%d")

def pre_write(filename,s):
    '''
    A very inefficient way, appends the string "s" to the beginning of a file of path "filename".
    '''
    with open(filename,'r') as original:
        with open('temp.txt','w') as provisional:
            provisional.write(s)
            provisional.write(original.read())
    os.rename('temp.txt',filename)

pre_write(sys.argv[2],"{} {}\n".format(X.shape[0],X.shape[1]))

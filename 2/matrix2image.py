import sys
import numpy as np
import matplotlib.pyplot as plt

'''
$ python3 mtrx2img.py path/to/data.dat outname

images are saved on grayscale, naturally.
'''

data=np.genfromtxt(sys.argv[1])

if len(data.shape)==2:
    plt.imsave(sys.argv[2],data,cmap="gray")

# SantiagoHenao_taller4
Homework 4 for my computatinal Methods Class, on semester 2018-01: Fourier transform and image analysis on C++

# 1: Softening

Gaussian softning of an image input.

The alpha of an .png image is completely ignored. All color RGB images are converted to grayscale images using luma coefficients of [Rec. 709](https://en.wikipedia.org/wiki/Rec._709).

Example image was published on Nasa's program [Astronomy Picture of the Day](https://apod.nasa.gov/apod/ap180403.html), and the credits and copyright are all to [Sergei Makurin](https://500px.com/makurin007).

## Process:

1. Color image are converted to .dat grayscale matrix by `image2matrix.py`.

 * Also `matrix2image.py` creates the grayscale image for preview.

3. `image_filters` reads the .dat grayscale data, calculates the Fourier Transform, apply a filter given by parameter, and returns a .dat grayscale matrix with the filtered image. In this case, the filter is "gaussian" and the filter parameter is "pixel_kernel"

# 2: Low-High pass Filter

_mutatis mutandis_ with the gaussian filter. A copy-paste of 1, and modify the parameters for the `image_filters` to filters "low" or "high" with umbral frequency parameter (double)


# 3: NFT

I've already made a Non-equidistant Fourier Transform, but on [my own way](https://github.com/santiagohenao/NFT). It works reasonably fine, and I made it without needing to interpolate anything. The mathematical ~~pseudoformal~~ idea that inspires me is [here](https://www.youtube.com/watch?v=spUNpyF58BY). 

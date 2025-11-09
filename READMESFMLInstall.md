# SFML SET-UP FOR LINUX

## Check the installed SFML version on your system
Using pkg-config : pkg-config --modversion sfml-all

## Install SFML dependencies (One Time Only)
``` bash
    sudo apt install \
    libx11-dev \
    libxcb1-dev \
    libxrandr-dev \
    libxinerama-dev \
    libxcursor-dev \
    libgl1-mesa-dev \
    libfreetype6-dev \
    libpng-dev \
    libjpeg-dev \
    libopenal-dev \
    libsndfile1-dev \
    libflac-dev \
    libvorbis-dev
```

## Download Desired Version
Go to https://github.com/SFML/SFML/releases and download the SFML version source code in tar.gz format.

## Extract, Build and Install
* tar -xvf SFML-3.0.X.tar.gz
* cd SFML-3.0
* cmake -S . -B build \  -DCMAKE_BUILD_TYPE=Release \ -DBUILD_SHARED_LIBS=ON \   -DSFML_BUILD_EXAMPLES=OFF
* cmake --build build 
* sudo make install
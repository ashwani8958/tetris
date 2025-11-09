# Tetris
A classic Tetris game implementation using SFML (Simple and Fast Multimedia Library)

## Requirements
- C++ compiler with C++11 support or higher
- SFML 3.0.0
- CMake (minimum version 3.0)

## Dependencies Installation

### Linux
SFML used : SFML 3.0.0 
Please refer to [READMESFMLInstall.md](READMESFMLInstall.md) for detailed SFML installation instructions.

### Windows
1. Download SFML 3.0.0 from the [official website](https://www.sfml-dev.org/download.php)
2. Extract the files to `extern/SFML-3.0.0/` in the project directory
3. Make sure to use the same version (debug/release) and architecture (32/64 bit) as your project

### macOS
```bash
brew install sfml
```

## Building the Project

1. Clone the repository:
```bash
git clone https://github.com/ashwani8958/tetris.git
cd tetris
```

2. Create a build directory:
```bash
mkdir build
cd build
```

3. Generate build files with CMake:
```bash
cmake ..
```

4. Build the project:
```bash
make
```

## Running the Game
After building, you can run the game from the build directory:
```bash
./tetris
```

## Controls
[Add game controls here]

## License
[Add license information here]

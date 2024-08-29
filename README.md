# Video to ASCII Art in C++

This project converts video frames into ASCII art using OpenCV and C++. The frames are processed in real-time, converting each pixel's intensity to a corresponding ASCII character.

## Prerequisites

Before you can build and run this project, you need to have the following software installed on your machine:

- CMake (for building the project)
- OpenCV (for handling video processing)
- A C++ compiler that supports C++11 or later

### Installing OpenCV

#### macOS (using Homebrew)

1. Open Terminal.
2. Install Homebrew if you haven't already:
    ```sh
    /bin/bash -c "$(curl -fsSL https://raw.githubusercontent.com/Homebrew/install/HEAD/install.sh)"
    ```
3. Install OpenCV using Homebrew:
    ```sh
    brew install opencv
    ```

#### Ubuntu/Debian (using apt)

1. Open Terminal.
2. Update your package list:
    ```sh
    sudo apt update
    ```
3. Install OpenCV:
    ```sh
    sudo apt install libopencv-dev
    ```

## Building the Project

1. Clone the repository to your local machine:
    ```sh
    git clone https://github.com/pym1900/mp3_2_ASCII.git
    cd video-to-ascii
    ```

2. Create a build directory and navigate into it:
    ```sh
    mkdir build
    cd build
    ```

3. Generate the Makefiles using CMake:
    ```sh
    cmake ..
    ```

4. Build the project using `make`:
    ```sh
    make
    ```

5. Run the executable:
    ```sh
    ./VideoToASCII
    ```

## How It Works

- **Frame Processing**: The program reads each frame from the video file, converts it to grayscale, resizes it, and maps the pixel intensities to corresponding ASCII characters.
  
- **ASCII Mapping**: The `pixelToASCII` function maps each pixel intensity to an ASCII character based on a predefined set of characters.

## Adjusting the Output

- You can change the video file path by modifying the `video_path` string in `main.cpp`.
- Adjust the `width` and `height` variables to change the resolution of the ASCII output.

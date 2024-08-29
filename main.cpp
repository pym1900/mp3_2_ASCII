#include <opencv2/opencv.hpp>
#include <chrono>
#include <iostream>
#include <thread>
#include <vector>
#include <string>

using namespace std;
using namespace cv;

string pixelToASCII(int pixel_intensity) {
    const vector<char> ASCII_CHARS = {' ', ' ', ' ', '.', '_', '-', '=', '+', '*', '!', '&', '#', '%', '$', '@'};
    return string(1, ASCII_CHARS[pixel_intensity * ASCII_CHARS.size() / 256]);
}

int main() {
    string video_path = "/Users/panyiming/Desktop/code/ji/ji.mp4";
    VideoCapture cap(video_path);

    double fps = cap.get(CAP_PROP_FPS);
    cout << fps << endl;

    int frame_duration_ms = static_cast<int>(1000 / fps);

    int width = 250;
    int height = 50;

    int frame_width = static_cast<int>(cap.get(CAP_PROP_FRAME_WIDTH));
    int frame_height = static_cast<int>(cap.get(CAP_PROP_FRAME_HEIGHT));
    cout << frame_width << " " << frame_height << endl;

    height = static_cast<int>((width * frame_height / frame_width) * 0.4194);

    Mat frame, gray_frame, resized_frame;

    while (true) {
        cap >> frame;
        if (frame.empty()) break;

        cvtColor(frame, gray_frame, COLOR_BGR2GRAY);
        resize(gray_frame, resized_frame, Size(width, height), 0, 0, INTER_LINEAR);

        string ascii_frame;
        for (int i = 0; i < height; ++i) {
            for (int j = 0; j < width; ++j) {
                ascii_frame += pixelToASCII(resized_frame.at<uchar>(i, j));
            }
            ascii_frame += "\n";
        }

        system("clear"); // to clear the console
        cout << ascii_frame;
        this_thread::sleep_for(chrono::milliseconds(frame_duration_ms));
    }

    return 0;
}

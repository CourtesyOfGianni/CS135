//Gianni Russell
//CSCI 135
//Prof. Tong Yi
//Lab 08 Part D

#include <iostream>
#include <cassert>
#include <cstdlib>
#include <fstream>

using namespace std;

const int MAX_H = 512;
const int MAX_W = 512;

// Reads a PGM file.
// Notice that: height and width are passed by reference!
void readImage(int image[MAX_H][MAX_W], int &height, int &width) {
    char c;
    int x;
    ifstream instr;
    instr.open("inImage.pgm");

    // read the header P2
    instr >> c;
    assert(c == 'P');
    instr >> c;
    assert(c == '2');

    // skip the comments (if any)
    while ((instr>>ws).peek() == '#') {
        instr.ignore(4096, '\n');
    }

    instr >> width;
    instr >> height;

    assert(width <= MAX_W);
    assert(height <= MAX_H);
    int max;
    instr >> max;
    assert(max == 255);

    for (int row = 0; row < height; row++)
        for (int col = 0; col < width; col++)
            instr >> image[row][col];
    instr.close();
    return;
}

// Writes a PGM file
// Need to provide the array data and the image dimensions
void writeImage(int image[MAX_H][MAX_W], int height, int width) {
    ofstream ostr;
    ostr.open("outImage.pgm");
    if (ostr.fail()) {
        cout << "Unable to write file\n";
        exit(1);
    };

    // print the header
    ostr << "P2" << endl;
    // width, height
    ostr << width << ' ';
    ostr << height << endl;
    ostr << 255 << endl;

    for (int row = 0; row < height; row++) {
        for (int col = 0; col < width; col++) {
            assert(image[row][col] < 256);
            assert(image[row][col] >= 0);
            ostr << image[row][col] << ' ';
        }
        ostr << endl; // Move to the next row after writing each row
    }
    ostr.close();
    return;
}

int main() {
    int img[MAX_H][MAX_W]; // Array for original image
    int h, w;  // Dimensions of image

    readImage(img, h, w); // h and w values were passed by reference and have the dimensions of the image

    int out[MAX_H][MAX_W];
    for(int row = 0; row < h; row++) {
        for(int col = 0; col < w; col++) {
            //print left and right side
            bool printVertical = (col == w/4 || col == 3*w/4) && (row > h/4 && row < 3*h/4);
            //print top and bottom sides
            bool printHorizontal = (row == h/4 || row == 3*h/4) && (col > w/4 && col < 3*w/4);

            if (printHorizontal || printVertical){
                out[row][col] = 255; // create 1 pixel frame
            }
            else {
                out[row][col] = img[row][col]; // Copy pixel from original image
            }
        }
    }

    writeImage(out, h, w);
    return 0;
}
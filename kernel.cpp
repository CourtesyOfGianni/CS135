#include <iostream>
#include <vector>
#include <algorithm>

// Assuming the image is in grayscale, so each pixel has one value (0-255).
using Image = std::vector<std::vector<int>>;

// Function to apply the Sobel horizontal edge detection operator
Image applyHorizontalEdgeDetection(const Image& input) {
    int rows = input.size();
    int cols = input[0].size();
    
    // Output image with the same dimensions as the input, initialized to 0
    Image output(rows, std::vector<int>(cols, 0));

    // Sobel operator for horizontal edges:
    // f(a,b,c,d,e,f,g,h,i) = (g + 2*h + i) - (a + 2*b + c)
    
    for (int i = 1; i < rows - 1; ++i) {
        for (int j = 1; j < cols - 1; ++j) {
            // Extract 3x3 window values
            int a = input[i-1][j-1];
            int b = input[i-1][j];
            int c = input[i-1][j+1];
            int d = input[i][j-1];
            int e = input[i][j]; // current pixel
            int f = input[i][j+1];
            int g = input[i+1][j-1];
            int h = input[i+1][j];
            int i_val = input[i+1][j+1];
            
            // Apply the Sobel formula
            int newValue = (g + 2 * h + i_val) - (a + 2 * b + c);

            // Clamp the value to 0-255 range
            newValue = std::clamp(newValue, 0, 255);

            // Assign the computed value to the output pixel
            output[i][j] = newValue;
        }
    }

    // Set the boundary pixels to black (0)
    for (int i = 0; i < rows; ++i) {
        output[i][0] = 0;
        output[i][cols - 1] = 0;
    }
    for (int j = 0; j < cols; ++j) {
        output[0][j] = 0;
        output[rows - 1][j] = 0;
    }

    return output;
}

void printImage(const Image& image) {
    for (const auto& row : image) {
        for (int pixel : row) {
            std::cout << pixel << " ";
        }
        std::cout << std::endl;
    }
}

int main() {
    // Example 5x5 input image for testing
    Image input = {
        {10, 10, 10, 10, 10},
        {10, 50, 50, 50, 10},
        {10, 50, 100, 50, 10},
        {10, 50, 50, 50, 10},
        {10, 10, 10, 10, 10}
    };

    Image output = applyHorizontalEdgeDetection(input);

    std::cout << "Output Image:\n";
    printImage(output);

    return 0;
}
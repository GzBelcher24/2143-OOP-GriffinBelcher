using namespace std;
#include "Rotate.h"
#include <iostream>
Rotate::Rotate(int degrees) : degrees_(degrees) {}

std::string Rotate::name() const {
    return "rotate(" + std::to_string(degrees_) + ")";
}

void Rotate::apply(Grid& pixels) {
    int height = static_cast<int>(pixels.size());
    if (height == 0) return;
    int width  = static_cast<int>(pixels[0].size());
    (void)width;  // used in the TODO branches — remove this line when implementing
    
    if (degrees_ == 0) {
        return;  // nothing to do
    }

    if (degrees_ == 180) {
        //flip Horizontally
          for (auto& row : pixels) {
           int width = row.size();
          for (int col = 0; col < width / 2; ++col) {
               std::swap(row[col], row[width - 1 - col]);
          }
       }
       //flip Vertically
      int height = pixels.size();
       for (int row = 0; row < height / 2; ++row) {
           std::swap(pixels[row], pixels[height - 1 - row]);
       }
    }

    if (degrees_ == 90) {
        // TODO: 90° clockwise — new dimensions are (width × height).
            Grid result(width, vector<Pixel>(height));  // note swapped dimensions

            for (int col = 0; col < width; ++col) {
                for (int row = 0; row < height; ++row) {
                    result[col][height - 1 - row] = pixels[row][col];
                }
            }
            pixels = result;
    }

    if (degrees_ == 270) {
      Grid result(width, vector<Pixel>(height));  // note swapped dimensions
        // rotate 90 degrees 3 times is the same as rotate 270 degrees once"
        for(int i = 0; i < 3; i++){
             for (int col = 0; col < width; ++col) {
                for (int row = 0; row < height; ++row) {
                    result[col][height - 1 - row] = pixels[row][col];
                }
            }
            for (int col = 0; col < width; ++col) {
                for (int row = 0; row < height; ++row) {
                    result[col][height - 1 - row] = pixels[row][col];
                }
            }
            pixels = result;
        }
    }else{
        cout<<"Invalid degree input"<<endl;
    }

}
#include "Grayscale.h"

std::string Grayscale::name() const {
    return "grayscale";
}

void Grayscale::apply(Grid& pixels) {
  // Outer loop: one pass per row (top to bottom)
    for (auto& row : pixels) {
        // Inner loop: one pixel per column (left to right)
        for (Pixel& p : row) {
      
            int red=p.r;
            int green=p.g; 
            int blue=p.b;
            int gray = (red + green + blue) / 3;
            p.r = gray;
            p.g = gray;
            p.b = gray;
        }
    }
}

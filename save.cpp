#include <cstdio>
#include <fstream>

const int row = 218;
const int column = 178;
float data[row][column];

void make_data() {
  float cx = column / 2;
  float cy = row / 2;
  float r = column / 3;
  for (int i = 0; i < row; i++) {
    for (int j = 0; j < column; j++) {
      float v = (r * r - (j - cx) * (j - cx) - (i - cy) * (i - cy)) / r / r;
      if (v < 0.0) v = 0;
      data[i][j] = v;
    }
  }
}

void save_data(const char *filename) {
  std::ofstream ofs(filename, std::ios::binary);
  ofs.write(reinterpret_cast<const char *>(data), row * column * sizeof(float));
}

int main() {
  make_data();
  save_data("data.dat");
}
#include <fstream>
#include <iostream>
#include <stdexcept>
#include <string>
#include <cstdint>
#include "../include/read_dataset.hpp"
#include <vector>


void loadMNIST(const std::string& filename) {
    std::cout << "Loading MNIST dataset from: " << filename <<std::endl;

    std::ifstream file(filename, std::ios::binary);
    if (!file.is_open())
        throw std::runtime_error("Cannot open file: " + filename);


    //read header in big-endian format
    int32_t magic = 0, num_images = 0, num_rows = 0, num_cols = 0;
    file.read((char*)&magic, 4);
    file.read((char*)&num_images, 4);
    file.read((char*)&num_rows, 4);
    file.read((char*)&num_cols, 4);

    //convert from big-endian to little-endian
    auto convert = [](int32_t x) {
        return ((x & 0xFF) << 24) |
               ((x & 0xFF00) << 8) |
               ((x & 0xFF0000) >> 8) |
               ((x >> 24) & 0xFF);
    };
    magic = convert(magic);
    num_images = convert(num_images);
    num_rows = convert(num_rows);
    num_cols = convert(num_cols);

    std::cout << "Magic: " << magic
              << " | Images: " << num_images
              << " | Rows: " << num_rows
              << " | Cols: " << num_cols << std::endl;
}

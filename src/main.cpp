#include <iostream>
#include <string>
#include "../include/read_dataset.hpp"
int main(int argc, char* argv[]) {

    if (argc < 2) {
            std::cerr << "Use: " << argv[0] << " <dataset_type>\n";
            return 1;
        }

        std::string dataset = argv[1];
        std::string path = argv[2];
        if (dataset == "mnist") {
            std::cout << "MNIST dataset...\n";
            loadMNIST(path);
        } else if (dataset == "sift") {
            std::cout << "SIFT dataset...\n";
            //loadSIFT();
        } else {
            std::cerr << "Unknown dataset: " << dataset << "\n";
            return 1;
        }

        return 0;
}
#include <string>

struct LSHParams {
    int seed = 1;
    int k = 4;
    int L = 5;
    double w = 4.0;
    int N = 1;
    double R = 2000;  
    std::string input_file;
    std::string query_file;
    std::string output_file;
    std::string distance_type;
    bool range_search = true;
};
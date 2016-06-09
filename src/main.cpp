#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <random>
#include <cstdlib>
#include "params.h"

int main(int argc, char** argv) {
    using namespace std;
    Params parameters{ Params::parse_parameters(argc, argv) };

    random_device rd;
    mt19937 mt(rd());
    uniform_real_distribution<double> unifr(0.0,1.0);
    
    vector<string> sample{};
    sample.reserve(parameters.m_sample_size);
    string input_read;
    int n{ 1 }; 
    std::ifstream input_file{ parameters.m_file_path };

    if (!input_file.is_open()) {
        cout << "Could not open file " << parameters.m_file_path << "!" << endl;
        return 1;
    }

    while ( getline(input_file, input_read) ) {
        if (n <= parameters.m_sample_size) {
            sample.push_back(input_read);
        } else  {
            int random_number{unifr(mt) * n};
            if (random_number < parameters.m_sample_size) {
                sample[random_number] = input_read;
            }
        }
        n++;
    }
    input_file.close();
    for (string line : sample) {
        std::cout << line << std::endl;
    }
    return 0; 
}

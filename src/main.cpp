#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <random>
#include <cstdlib>
#include "params.h"
#include "iohandler.h"

Iohandler* Iohandler::s_instance = nullptr;

int main(int argc, char** argv) {
    using namespace std;
    Params parameters{ Params::parse_parameters(argc, argv) };
    random_device rd;
    mt19937 mt(rd());
    uniform_real_distribution<double> unifr(0.0,1.0);
    
    vector<string> sample{};
    sample.reserve(parameters.m_sample_size);

    Iohandler *iohandler = Iohandler::instance(parameters);
    std::istream *input_file = iohandler->get_input_stream();
    int n{ 1 }; 
    string input_read;
    while ( getline(*input_file, input_read) ) {
        if (n <= parameters.m_sample_size) {
            sample.push_back(input_read);
        } else  {
            int random_number{static_cast<int>(unifr(mt) * n)};
            if (random_number < parameters.m_sample_size) {
                sample[random_number] = input_read;
            }
        }
        n++;
    }
    for (string line : sample) {
        std::cout << line << std::endl;
    }
    return 0; 
}

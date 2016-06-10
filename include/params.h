#ifndef PARAMS_H
#define PARAMS_H
#include <cstdlib>
#include <iostream>
#include <fstream>
class Params {
    public:
        const int m_sample_size;
        char * m_file_path;
        Params(int sample_size, char *file_path): m_sample_size(sample_size), m_file_path(file_path){};
        Params(int sample_size): m_sample_size(sample_size), m_file_path(nullptr) {};
        static Params parse_parameters(int argc, char **argv); 
};
#endif

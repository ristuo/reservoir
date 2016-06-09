#ifndef PARAMS_H
#define PARAMS_H
#include <cstdlib>
class Params {
    public:
        char const *m_file_path; 
        const int m_sample_size;
        Params(int sample_size, char *file_path): m_sample_size(sample_size), m_file_path(file_path){};
        static Params parse_parameters(int argc, char **argv); 
};
#endif

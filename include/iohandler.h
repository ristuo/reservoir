#ifndef IOHANDLER_H
#define IOHANDLER_H
#include <fstream>
#include <iostream>
#include "params.h"
#include <cstdlib>
class Iohandler {
    private:
        bool m_use_cin;
        std::ifstream *s_input_stream;
        static Iohandler *s_instance;
        Iohandler(char *file_path, bool use_cin): m_use_cin(use_cin) {
            if (!use_cin) {
                s_input_stream = new std::ifstream( file_path );
                if (!s_input_stream->is_open()) {
                    std::cout << "Could not open file " << file_path << std::endl;
                    exit(1);
                }
            }
        };
    public:
        std::istream *get_input_stream();
        static Iohandler *instance(Params &parameters) {
            if (!s_instance) {
                if (parameters.m_file_path) {
                    s_instance = new Iohandler(parameters.m_file_path, false);
                } else {
                    s_instance = new Iohandler(nullptr, true);
                }
            }    
            return s_instance;
        };
        ~Iohandler() {
            if (s_input_stream) {
                s_input_stream->close();
                delete s_input_stream;
            }
            delete s_instance;
        }
};
#endif

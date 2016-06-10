#include "iohandler.h"
#include <fstream>
std::istream* Iohandler::get_input_stream() {
    if (m_use_cin) { 
        return &std::cin;
    }
    return s_input_stream;
}

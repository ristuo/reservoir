#include "params.h"
#include <stdlib.h>
#include <stdio.h>
#include <iostream>

Params Params::parse_parameters(int argc, char **argv) {
    if (argc < 3) {
        std::cout << "USAGE " << argv[0] << " [sample size] [file path]" << std::endl;
        exit(1);
    }

    int sample_size{ atoi(argv[1]) };
    if (!sample_size) {
        std::cout << "First parameter should be an integer for sample size!" << std::endl; 
        exit(1);
    }
    return Params(sample_size, argv[2]);
}

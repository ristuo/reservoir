# reservoir
Reservoir sampling implementation to replace the inefficient GNU shuf that is, to pick uniformly at random n lines from a file.

##Compiling
```sh 
mkdir build
cd build
cmake ..
make
```
##Usage
First parameter is integer for how many lines to pick, seconds is path to input file. Program will output to stdout.

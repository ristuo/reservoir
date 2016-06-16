# reservoir
Reservoir sampling implementation to replace the inefficient GNU shuf that is, to pick uniformly at random n lines from a file. Contra random poster at stackoverflow shuf is actually pretty fast, on 7 million records shuf runs in 35 seconds, this implementation in 30 or so. On different files it seems that this is 15 % faster than shuf.

##Compiling
```sh 
mkdir build
cd build
cmake ..
make
```
##Usage
First parameter is integer for how many lines to pick, seconds is path to input file. Program will output to stdout.
USAGE reservoir N [FILE PATH]
where N is the number of lines to pick.

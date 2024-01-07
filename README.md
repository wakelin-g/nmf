This repository describes how to perform non-negative matrix factoriation (NMF) in C++ using the mlpack libraries.

## Installation and Setup
Install the relevant C++ libraries (mlpack, argparse) using homebrew by running the `setup.sh` script
```
./setup.sh
```
This script will also (temporarily) set your env variables so that the g++ compiler has access to these libraries installed through homebrew. For this to be applied permanently, add the following lines to your `.zshrc` or `.bashrc` file.
```
export CPATH=/opt/homebrew/include
export LIBRARY_PATH=/opt/homebrew/lib
```
You can compile the NMF program by running `Make` in the same directory as the source files.

## Usage
To compile the NMF program, `cd` into the `src` directory and run `Make`
```
> cd src
> make
g++-13 -O3 -std=c++17 -o nmf nmf.cpp -larmadillo -fopenmp
> ls
Makefile  nmf  nmf.cpp
```
The `nmf` executable can be run on a provided input file
```
./nmf ../data/norm-wt-m1-non.csv
```
This produces the output matrices $H$ and $W$ in csv format in whichever directory that the binary was executed from
```
> ls
H.csv  Makefile  nmf  nmf.cpp  W.csv
```
Alternatively, you can specify where you want to save the $H$ and $W$ matrices using the `-o`/`--output` option
```
> rm H.csv W.csv
> mkdir results
> ./nmf ../data/norm-wt-m1-non.csv -o results
> ls
results  Makefile  nmf  nmf.cpp
> ls results
H.csv  W.csv
```
If desired, the name of the input can be prepended to the filenames of the output matrices using the `-p`/`--prepend-input` flag
```
> rm results/*
> ./nmf ../data/norm-wt-m1-non.csv -o results -p
> ls results
norm-wt-m1-non_H.csv  norm-wt-m1-non_W.csv
```
Finally, the rank of the factorization (equivalent to `n_comps` in sklearn) can be optionally specified using the `-r`/`--rank` option. By default, this is set to 7.

This repository describes how to perform non-negative matrix factoriation (NMF) in C++ using the mlpack libraries.
## Background 
Nonnegative matrix factorization (NMF) aims to find a low-rank approximation of a non-negative matrix $X$

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

## Running the Program
NMF can be run on an input file `input.csv` as
```
./nmf input.csv
```

The $W$ and $H$ matrices will be saved in their own csv files
```
> ls
W.csv
H.csv
```

#!/bin/bash

req=("gcc@13" "mlpack" "argparse")
echo "Installing dependencies..."
for r in ${req[@]}; do
    brew list ${r} &>/dev/null || brew install ${r}
    echo "package: ${r} installed"
done

export CPATH=/opt/homebrew/include
export LIBRARY_PATH=/opt/homebrew/lib
printf "\nCPATH and LIBRARY_PATH env variables set to allow compilation using homebrew packages for this session only. To make this permanent, add \n\nexport CPATH=/opt/homebrew/include\nexport LIBRARY_PATH=/opt/homebrew/lib\n\nto your .zshrc/.bashrc\n"

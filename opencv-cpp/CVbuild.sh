#!/bin/sh

if [ ! -n "$2" ]
then
  echo "Usage: Arg#1: .c filename, Arg#2: output name"
  exit $E_BADARGS
fi  

	    echo "compiling $1"
	    gcc -ggdb `pkg-config --cflags opencv` -o $2 $1 `pkg-config --libs opencv`;

#	for C++ files, do this.
#	for i in *.cpp; do
#	    echo "compiling $i"
#	    g++ -ggdb `pkg-config --cflags opencv` -o `basename $i .cpp` $i `pkg-config --libs opencv`;
#	done

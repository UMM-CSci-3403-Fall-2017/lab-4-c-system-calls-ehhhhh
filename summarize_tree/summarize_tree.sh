#!/usr/bin/bash

#store the command line argument
TARGET=$1

#call find and pipe it to word count, then set NUM_X to the result of that
NUM_DIRS=$(find "$TARGET"/ -type d | wc -l )
NUM_REGULAR=$(find "$TARGET"/ -type f | wc -l )

#print the results to standard output
echo "There were $NUM_DIRS directories."
echo "There were $NUM_REGULAR regular files."

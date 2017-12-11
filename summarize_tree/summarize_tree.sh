#!/usr/bin/bash

TARGET=$1

NUM_DIRS=$(find "$TARGET"/ -type d | wc -l )
NUM_REGULAR=$(find "$TARGET"/ -type f | wc -l )

echo "Number of directories: $NUM_DIRS"
echo "Number of files: $NUM_REGULAR"

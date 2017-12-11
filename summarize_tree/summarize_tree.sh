#!/usr/bin/bash

TARGET=$1

NUM_DIRS=$(find "$TARGET"/ -type d | wc -l )
NUM_REGULAR=$(find "$TARGET"/ -type f | wc -l )

echo "There were $NUM_DIRS directories."
echo "There were $NUM_REGULAR regular files."

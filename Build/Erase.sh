#!/bin/bash

start=$(date +%s)

make ERASE_ALL

end=$(date +%s)
execution_time=$((end - start))

echo "Total flashing time: $execution_time seconds"

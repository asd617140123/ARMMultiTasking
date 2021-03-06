#!/bin/bash
set -e

for platform in "arm" "thumb" "aarch64"; do
  for opt_level in "0" "3" "s"; do
    for sanitizers in "ON" "OFF"; do
      for lto in "ON" "OFF"; do
        # LTO isn't enabled at O0
        if [[ "${opt_level}_${lto}" != "0_ON" ]]; then
          rm -f CMakeCache.txt
          cmake . -DBUILD_PLATFORM=${platform} -DOPT_LEVEL=${opt_level} -DSANITIZERS=${sanitizers} -DLTO=${lto}
          make -j"$(nproc)" make_demos
          lit demos/ -a
          make clean
        fi
      done
    done
  done
done

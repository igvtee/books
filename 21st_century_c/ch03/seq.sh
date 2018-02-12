#!/bin/sh

for i in `seq 1 1000`; do
  echo output for run $i >> run_outputs
  ./run_program >> run_outputs
done

#!/bin/sh
for file in *.c;
do
  cp $file ${file}.bkup
done

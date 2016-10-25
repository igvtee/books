#!/bin/sh
# $0 objname < in > out
objname=${1:-objname}
od -An -v -tx1 -w12 | sed -e '1i\
const unsigned char '$objname'[] = {
s/\([0-9a-f][0-9a-f]\) */0x\1, /g
$s/, $//
$a\
};'

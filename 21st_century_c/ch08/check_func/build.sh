#!/bin/sh

touch NEWS README AUTHORS ChangeLog
autoreconf -iv
./configure
make

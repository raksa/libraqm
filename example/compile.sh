#!/bin/sh
clang test.c -o test \
-I/usr/local/opt/freetype/include/freetype2 \
-I../src \
-L../src/.libs -lraqm \
-lfreetype
#!/bin/sh
name=test
local_lib=../src/.libs

clang -o $name \
-I/usr/local/opt/freetype/include/freetype2 \
-I../src \
-L../src/.libs -lraqm \
-lfreetype \
$name.c

install_name_tool -change "/usr/local/lib/libraqm.0.dylib" "@executable_path/$local_lib/libraqm.0.dylib" test
#!/bin/sh

valgrind --leak-check=full --track-origins=yes --show-reachable=yes --suppressions=suppressions.txt --gen-suppressions=yes Debug/sdl_tutorial

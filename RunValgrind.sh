#!/bin/sh

valgrind --leak-check=full --track-origins=yes Debug/sdl_tutorial

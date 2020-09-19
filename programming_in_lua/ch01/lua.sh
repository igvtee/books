#!/bin/sh

lua -e "print(math.sin(12))"
LUA_INIT=@hello.lua lua -e "print(\"LUA_INIT\")"

#!/bin/sh
find . -regex '.*\.\(cpp\|hpp\|h\|cc\|cxx\)' -exec clang-format -style=file -i --verbose {} \;
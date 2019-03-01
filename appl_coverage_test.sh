#!/bin/bash
./.obj/test_appl/gnu-debug-exe/test_appl $*
lcov -t appl -o .obj/test_appl/gnu-debug-exe/lcov.info -c -d .obj/test_appl/gnu-debug-exe/ 2>/dev/null 1>/dev/null
genhtml -o .obj/lcov .obj/test_appl/gnu-debug-exe/lcov.info 2>/dev/null 1>/dev/null

#!/bin/bash
./.obj/test_appl/gnu-debug-exe/test_appl
# gcov .obj/test_appl/gnu-debug-exe/**/*.o .obj/test_appl/gnu-debug-exe/*.o
lcov -t appl -o .obj/test_appl/gnu-debug-exe/lcov.info -c -d .obj/test_appl/gnu-debug-exe/
genhtml -o .obj/lcov .obj/test_appl/gnu-debug-exe/lcov.info

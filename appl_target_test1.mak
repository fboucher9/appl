# See LICENSE for license details

#
#
#

ifndef appl_target_test1.mak-included
appl_target_test1.mak-included := 1

include $(APPL_SRC)appl_target_base.mak

target-list += test_appl

# test_appl-name = test

# test_appl-type = exe

test_appl-exports = appl.exports

test_appl-deps = \
    appl_test.c \
    appl_hash_test.c \
    appl_pool_test.c \
    appl_thread_cache_test.c \
    appl_module_test.c \
    appl_timer_test.c \
    appl_binary_heap_test.c \
    $(appl_base-deps)

# List of libraries required to link test application
test_appl-libs = pthread dl rt winsock2

APPL_LIBRARY-winsock2-mingw-lflags = -lws2_32

endif # ifndef appl_target_test1.mak-included

# end-of-file: appl_target_test1.mak

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
    hash/appl_hash_test.cpp \
    pool/appl_pool_test.cpp \
    thread/appl_thread_cache_test.c \
    module/appl_module_test.c \
    binary_heap/appl_binary_heap_test.c \
    options/appl_options_test.cpp \
    xlib/appl_xlib_test.cpp \
    appl_test_prompt.c \
    mutex/appl_mutex_test.cpp \
    clock/appl_clock_test.cpp \
    clock/appl_clock_main.cpp \
    random/appl_random_test.cpp \
    event/appl_event_test.cpp \
    backtrace/appl_backtrace_test.cpp \
    env/appl_env_test.cpp \
    env/appl_env_main.cpp \
    heap/appl_heap_test.cpp \
    appl_coverage_test.cpp \
    object/appl_object_test.cpp \
    allocator/appl_allocator_test.cpp \
    debug/appl_debug_test.cpp \
    context/appl_context_test.cpp \
    file/appl_file_test.cpp \
    log/appl_log_test.cpp \
    library/appl_library_test.cpp \
    timer/appl_timer_test.cpp \
    appl_crc_test.cpp \
    chunk/appl_chunk_test.cpp \
    appl_node_test.cpp \
    dict/appl_dict_test.cpp \
    queue/appl_queue_test.cpp \
    thread/appl_thread_test.cpp \
    string/appl_string_test.cpp \
    property/appl_property_test.cpp \
    socket/appl_socket_test.cpp \
    socket/appl_netdevice_test.cpp \
    socket/appl_netdevice_main.cpp \
    buf/appl_buf_test.cpp \
    url/appl_url_test.cpp \
    url/appl_percent_main.c \
    url/appl_percent_test.cpp \
    socket/appl_address_main.cpp \
    socket/appl_download_main.cpp \
    $(appl_base-deps)

# List of libraries required to link test application
test_appl-libs = pthread dl rt winsock2

APPL_LIBRARY-winsock2-mingw-lflags = -lws2_32

endif # ifndef appl_target_test1.mak-included

# end-of-file: appl_target_test1.mak

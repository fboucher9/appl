# See LICENSE for license details

target-list += test_appl

test_appl-cfgs = $(APPL_TOOLCHAIN)

test_appl-deps = \
    appl_test.c \
    appl.cpp \
    appl_address_handle.cpp \
    appl_address_node.cpp \
    appl_address_property.cpp \
    appl_address_service.cpp \
    appl_address_std_node.cpp \
    appl_buf.cpp \
    appl_clock.cpp \
    appl_clock_handle.cpp \
    appl_clock_service.cpp \
    appl_clock_std.cpp \
    appl_clock_w32.cpp \
    appl_context.cpp \
    appl_context_handle.cpp \
    appl_context_std.cpp \
    appl_debug.cpp \
    appl_debug_handle.cpp \
    appl_debug_std.cpp \
    appl_debug_w32.cpp \
    appl_env.cpp \
    appl_env_handle.cpp \
    appl_env_service.cpp \
    appl_event_handle.cpp \
    appl_event_mgr.cpp \
    appl_event_node.cpp \
    appl_event_service.cpp \
    appl_event_std_mgr.cpp \
    appl_event_std_node.cpp \
    appl_file_handle.cpp \
    appl_file_mgr.cpp \
    appl_file_node.cpp \
    appl_file_service.cpp \
    appl_file_std_mgr.cpp \
    appl_file_std_node.cpp \
    appl_heap.cpp \
    appl_heap_dbg.cpp \
    appl_heap_handle.cpp \
    appl_heap_service.cpp \
    appl_heap_std.cpp \
    appl_list.cpp \
    appl_mutex_handle.cpp \
    appl_mutex_mgr.cpp \
    appl_mutex_node.cpp \
    appl_mutex_service.cpp \
    appl_mutex_std_mgr.cpp \
    appl_mutex_std_node.cpp \
    appl_node.cpp \
    appl_node_iterator.cpp \
    appl_object.cpp \
    appl_object_handle.cpp \
    appl_options.cpp \
    appl_options_std.cpp \
    appl_poll_handle.cpp \
    appl_poll_mgr.cpp \
    appl_poll_node.cpp \
    appl_poll_service.cpp \
    appl_property.cpp \
    appl_property_handle.cpp \
    appl_property_service.cpp \
    appl_socket_descriptor.cpp \
    appl_socket_handle.cpp \
    appl_socket_mgr.cpp \
    appl_socket_node.cpp \
    appl_socket_service.cpp \
    appl_socket_std_mgr.cpp \
    appl_socket_std_node.cpp \
    appl_string.cpp \
    appl_string_handle.cpp \
    appl_string_service.cpp \
    appl_thread_handle.cpp \
    appl_thread_mgr.cpp \
    appl_thread_node.cpp \
    appl_thread_property.cpp \
    appl_thread_service.cpp \
    appl_thread_std_mgr.cpp \
    appl_thread_std_node.cpp \
    appl_thread_w32_mgr.cpp \
    appl_thread_w32_node.cpp

# List of libraries required to link test application
test_appl-libs = pthread rt winsock2

APPL_LIBRARY-winsock2-mingw-lflags = -lws2_32


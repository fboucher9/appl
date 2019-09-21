# See LICENSE for license details

#
#   Module: appl_target_base.mak
#
#   Description:
#       Definitions common to multiple targets.
#

ifndef appl_target_base.mak-included
appl_target_base.mak-included := 1

# socket/appl_poll_handle.cpp
# socket/appl_poll_mgr.cpp
# socket/appl_poll_node.cpp
# socket/appl_poll_service.cpp

appl_base-deps := \
    appl.cpp \
    appl_status.cpp \
    appl_tree.cpp \
    binary_heap/appl_binary_heap.cpp \
    socket/appl_address_handle.cpp \
    socket/appl_address_node.cpp \
    socket/appl_address_property.cpp \
    socket/appl_address_service.cpp \
    socket/appl_address_std_node.cpp \
    allocator/appl_allocator.cpp \
    allocator/appl_allocator_handle.cpp \
    allocator/appl_allocator_service.cpp \
    allocator/appl_allocator_std.cpp \
    allocator/appl_placement.cpp \
    backtrace/appl_backtrace_handle.cpp \
    backtrace/appl_backtrace_service.cpp \
    backtrace/appl_backtrace.cpp \
    backtrace/appl_backtrace_std.cpp \
    backtrace/appl_backtrace_impl.cpp \
    buf/appl_buf.cpp \
    buf/appl_buf0.cpp \
    buf/appl_buf_filter.cpp \
    buf/appl_buf_iterator.cpp \
    buf/appl_mem.cpp \
    buf/appl_str.cpp \
    buf/appl_bits_handle.cpp \
    buf/appl_bits_service.cpp \
    buf/appl_bits.cpp \
    buf/appl_bits_base.cpp \
    buf/appl_bits_std.cpp \
    buf/appl_str_bits.cpp \
    buf/appl_bytes_descriptor.cpp \
    buf/appl_bytes_handle.cpp \
    buf/appl_bytes_service.cpp \
    callstack/appl_callstack_handle.cpp \
    callstack/appl_callstack_service.cpp \
    chunk/appl_chunk_handle.cpp \
    chunk/appl_chunk_service.cpp \
    chunk/appl_chunk_std.cpp \
    chunk/appl_chunk.cpp \
    clock/appl_clock.cpp \
    clock/appl_clock_handle.cpp \
    clock/appl_clock_service.cpp \
    clock/appl_clock_std.cpp \
    clock/appl_clock_w32.cpp \
    clock/appl_clock_impl.cpp \
    context/appl_context.cpp \
    context/appl_context_handle.cpp \
    context/appl_context_service.cpp \
    context/appl_context_std.cpp \
    appl_coverage.cpp \
    appl_crc16.cpp \
    appl_crc32.cpp \
    debug/appl_debug.cpp \
    debug/appl_debug_handle.cpp \
    debug/appl_debug_std.cpp \
    debug/appl_debug_w32.cpp \
    debug/appl_debug_impl.cpp \
    dict/appl_dict_handle.cpp \
    dict/appl_dict_service.cpp \
    dict/appl_dict.cpp \
    dict/appl_dict_std.cpp \
    socket/appl_download_handle.cpp \
    socket/appl_download_service.cpp \
    socket/appl_download_mgr.cpp \
    socket/appl_download_node.cpp \
    socket/appl_http_decoder.cpp \
    env/appl_env.cpp \
    env/appl_env_handle.cpp \
    env/appl_env_service.cpp \
    env/appl_env_std.cpp \
    env/appl_env_w32.cpp \
    event/appl_event_handle.cpp \
    event/appl_event_mgr.cpp \
    event/appl_event_node.cpp \
    event/appl_event_service.cpp \
    event/appl_event_std_mgr.cpp \
    event/appl_event_std_node.cpp \
    event/appl_event_impl.cpp \
    file/appl_file_descriptor.cpp \
    file/appl_file_handle.cpp \
    file/appl_file_mgr.cpp \
    file/appl_file_node.cpp \
    file/appl_file_service.cpp \
    file/appl_file_std_mgr.cpp \
    file/appl_file_std_node.cpp \
    hash/appl_hash_handle.cpp \
    hash/appl_hash_service.cpp \
    hash/appl_hash.cpp \
    heap/appl_heap.cpp \
    heap/appl_heap_dbg.cpp \
    heap/appl_heap_handle.cpp \
    heap/appl_heap_service.cpp \
    heap/appl_heap_std.cpp \
    heap/appl_heap_impl.cpp \
    heap/appl_heap_primary.cpp \
    library/appl_library_handle.cpp \
    library/appl_library_service.cpp \
    library/appl_library_mgr.cpp \
    library/appl_library_node.cpp \
    library/appl_library_w32_mgr.cpp \
    library/appl_library_w32_node.cpp \
    library/appl_library_std_mgr.cpp \
    library/appl_library_std_node.cpp \
    appl_list.cpp \
    log/appl_log_handle.cpp \
    log/appl_log_service.cpp \
    log/appl_log.cpp \
    log/appl_log_std.cpp \
    log/appl_log_impl.cpp \
    log/appl_log_client.cpp \
    main/appl_main.cpp \
    main/appl_main_service.cpp \
    module/appl_module_handle.cpp \
    module/appl_module_service.cpp \
    module/appl_module.cpp \
    module/appl_packet_handle.cpp \
    module/appl_packet_service.cpp \
    module/appl_packet.cpp \
    mutex/appl_mutex_handle.cpp \
    mutex/appl_mutex_mgr.cpp \
    mutex/appl_mutex_node.cpp \
    mutex/appl_mutex_service.cpp \
    mutex/appl_mutex_std_mgr.cpp \
    mutex/appl_mutex_std_node.cpp \
    mutex/appl_mutex_impl.cpp \
    socket/appl_netdevice_handle.cpp \
    socket/appl_netdevice_service.cpp \
    socket/appl_netdevice_mgr.cpp \
    socket/appl_netdevice_std.cpp \
    socket/appl_netdevice_w32.cpp \
    appl_node.cpp \
    appl_node_iterator.cpp \
    object/appl_object.cpp \
    object/appl_object_handle.cpp \
    object/appl_object_service.cpp \
    appl_once.cpp \
    options/appl_options.cpp \
    options/appl_options_std.cpp \
    options/appl_options_handle.cpp \
    options/appl_options_service.cpp \
    appl_refcount.cpp \
    appl_refcount_handle.cpp \
    appl_refcount_service.cpp \
    pool/appl_pool.cpp \
    pool/appl_pool_std.cpp \
    pool/appl_pool_mgr.cpp \
    pool/appl_pool_handle.cpp \
    pool/appl_pool_service.cpp \
    property/appl_property.cpp \
    property/appl_property_handle.cpp \
    property/appl_property_service.cpp \
    property/appl_property_std.cpp \
    queue/appl_queue.cpp \
    queue/appl_queue_handle.cpp \
    queue/appl_queue_impl.cpp \
    queue/appl_queue_service.cpp \
    queue/appl_queue_std.cpp \
    random/appl_random_handle.cpp \
    random/appl_random_service.cpp \
    random/appl_random_mgr.cpp \
    random/appl_random.cpp \
    random/appl_random_std_mgr.cpp \
    random/appl_random_w32_mgr.cpp \
    random/appl_random_pseudo.cpp \
    random/appl_random_std_crypto.cpp \
    random/appl_random_w32_crypto.cpp \
    socket/appl_socket_descriptor.cpp \
    socket/appl_socket_handle.cpp \
    socket/appl_socket_mgr.cpp \
    socket/appl_socket_node.cpp \
    socket/appl_socket_service.cpp \
    socket/appl_socket_std_mgr.cpp \
    socket/appl_socket_std_node.cpp \
    socket/appl_socket_w32_mgr.cpp \
    socket/appl_socket_w32_node.cpp \
    string/appl_string.cpp \
    string/appl_string_handle.cpp \
    string/appl_string_service.cpp \
    thread/appl_thread_impl.cpp \
    thread/appl_thread_cache.cpp \
    thread/appl_thread_handle.cpp \
    thread/appl_thread_descriptor.cpp \
    thread/appl_thread_descriptor_impl.cpp \
    thread/appl_thread_mgr.cpp \
    thread/appl_thread_node.cpp \
    thread/appl_thread_property.cpp \
    thread/appl_thread_service.cpp \
    thread/appl_thread_std_mgr.cpp \
    thread/appl_thread_std_node.cpp \
    timer/appl_timer_handle.cpp \
    timer/appl_timer_service.cpp \
    timer/appl_timer_mgr.cpp \
    timer/appl_timer_group.cpp \
    timer/appl_timer_node.cpp \
    timer/appl_timer_std_mgr.cpp \
    timer/appl_timer_std_group.cpp \
    timer/appl_timer_std_node.cpp \
    url/appl_url_handle.cpp \
    url/appl_url_service.cpp \
    url/appl_url.cpp \
    url/appl_url_std.cpp \
    url/appl_percent.cpp \
    appl_validate.cpp \
    xlib/appl_xlib.cpp \
    xlib/appl_xlib_std.cpp \
    xlib/appl_xlib_handle.cpp \
    xlib/appl_xlib_service.cpp

endif # ifndef appl_target_base.mak-included

# end-of-file: appl_target_base.mak

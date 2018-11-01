# See LICENSE for license details

#
#   Module: appl_target_base.mak
#
#   Description:
#       Definitions common to multiple targets.
#

ifndef appl_target_base.mak-included
appl_target_base.mak-included := 1

appl_base-deps := \
    appl.cpp \
    appl_tree.cpp \
    appl_address_handle.cpp \
    appl_address_node.cpp \
    appl_address_property.cpp \
    appl_address_service.cpp \
    appl_address_std_node.cpp \
    appl_allocator.cpp \
    appl_allocator_handle.cpp \
    appl_allocator_service.cpp \
    appl_buf.cpp \
    appl_buf0.cpp \
    appl_chunk.cpp \
    appl_clock.cpp \
    appl_clock_handle.cpp \
    appl_clock_service.cpp \
    appl_clock_std.cpp \
    appl_clock_w32.cpp \
    appl_context.cpp \
    appl_context_handle.cpp \
    appl_context_service.cpp \
    appl_context_std.cpp \
    appl_crc16.cpp \
    appl_debug.cpp \
    appl_debug_handle.cpp \
    appl_debug_std.cpp \
    appl_debug_w32.cpp \
    appl_env.cpp \
    appl_env_handle.cpp \
    appl_env_service.cpp \
    appl_env_std.cpp \
    appl_env_w32.cpp \
    appl_event_handle.cpp \
    appl_event_mgr.cpp \
    appl_event_node.cpp \
    appl_event_service.cpp \
    appl_event_std_mgr.cpp \
    appl_event_std_node.cpp \
    appl_event_impl.cpp \
    appl_file_handle.cpp \
    appl_file_mgr.cpp \
    appl_file_node.cpp \
    appl_file_service.cpp \
    appl_file_std_mgr.cpp \
    appl_file_std_node.cpp \
    appl_hash_handle.cpp \
    appl_heap.cpp \
    appl_heap_dbg.cpp \
    appl_heap_handle.cpp \
    appl_heap_service.cpp \
    appl_heap_std.cpp \
    appl_heap_impl.cpp \
    appl_library_handle.cpp \
    appl_library_service.cpp \
    appl_library_mgr.cpp \
    appl_library_node.cpp \
    appl_library_w32_mgr.cpp \
    appl_library_w32_node.cpp \
    appl_library_std_mgr.cpp \
    appl_library_std_node.cpp \
    appl_list.cpp \
    appl_log_handle.cpp \
    appl_log_service.cpp \
    appl_log.cpp \
    appl_log_std.cpp \
    appl_log_impl.cpp \
    appl_module_handle.cpp \
    appl_module_service.cpp \
    appl_module.cpp \
    appl_mutex_handle.cpp \
    appl_mutex_mgr.cpp \
    appl_mutex_node.cpp \
    appl_mutex_service.cpp \
    appl_mutex_std_mgr.cpp \
    appl_mutex_std_node.cpp \
    appl_mutex_impl.cpp \
    appl_node.cpp \
    appl_node_iterator.cpp \
    appl_object.cpp \
    appl_object_handle.cpp \
    appl_object_service.cpp \
    appl_options.cpp \
    appl_options_std.cpp \
    appl_options_handle.cpp \
    appl_options_service.cpp \
    appl_poll_handle.cpp \
    appl_poll_mgr.cpp \
    appl_poll_node.cpp \
    appl_poll_service.cpp \
    appl_pool.cpp \
    appl_pool_std.cpp \
    appl_pool_mgr.cpp \
    appl_pool_handle.cpp \
    appl_pool_service.cpp \
    appl_property.cpp \
    appl_property_handle.cpp \
    appl_property_service.cpp \
    appl_property_std.cpp \
    appl_queue.cpp \
    appl_queue_handle.cpp \
    appl_queue_impl.cpp \
    appl_queue_service.cpp \
    appl_queue_std.cpp \
    appl_random_handle.cpp \
    appl_random_service.cpp \
    appl_random_mgr.cpp \
    appl_random.cpp \
    appl_random_std_mgr.cpp \
    appl_random_w32_mgr.cpp \
    appl_random_pseudo.cpp \
    appl_random_std_crypto.cpp \
    appl_random_w32_crypto.cpp \
    appl_refcount.cpp \
    appl_refcount_handle.cpp \
    appl_socket_descriptor.cpp \
    appl_socket_handle.cpp \
    appl_socket_mgr.cpp \
    appl_socket_node.cpp \
    appl_socket_service.cpp \
    appl_socket_std_mgr.cpp \
    appl_socket_std_node.cpp \
    appl_socket_w32_mgr.cpp \
    appl_socket_w32_node.cpp \
    appl_string.cpp \
    appl_string_handle.cpp \
    appl_string_service.cpp \
    appl_thread_impl.cpp \
    appl_thread_cache.cpp \
    appl_thread_handle.cpp \
    appl_thread_mgr.cpp \
    appl_thread_node.cpp \
    appl_thread_property.cpp \
    appl_thread_service.cpp \
    appl_thread_std_mgr.cpp \
    appl_thread_std_node.cpp

endif # ifndef appl_target_base.mak-included

# end-of-file: appl_target_base.mak

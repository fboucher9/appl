/* See LICENSE for license details */

/*

*/

#if defined APPL_OS_WINDOWS

#include <windows.h>

#include <appl_status.h>

#include <appl_predefines.h>

#include <appl_types.h>

#include <appl_object.h>

#include <dir/appl_dir_mgr.h>

#include <dir/appl_dir_w32_mgr.h>

#include <buf/appl_buf.h>

#include <buf/appl_buf0.h>

#include <appl_mem.h>

#include <appl_str.h>

#include <dir/appl_dir_descriptor.h>

#include <appl_heap_handle.h>

#include <misc/appl_unused.h>

//
//
//
appl_dir_w32_mgr::appl_dir_w32_mgr(
    struct appl_context * const
        p_context) :
    appl_dir_mgr(
        p_context)
{
}

//
//
//
appl_dir_w32_mgr::~appl_dir_w32_mgr()
{
}

//
//
//
enum appl_status
    appl_dir_w32_mgr::f_init(void)
{
    return
        appl_status_ok;

} // f_init()

//
//
//
appl_size_t
    appl_dir_w32_mgr::v_cleanup(void)
{
    return
        sizeof(
            class appl_dir_w32_mgr);

} // v_cleanup()

//
//
//
enum appl_status
    appl_dir_w32_mgr::v_enumerate(
        struct appl_dir_descriptor const * const
            p_descriptor)
{
    enum appl_status
        e_status;

    unsigned long int const
        i_name_len =
        appl_buf_len(
            p_descriptor->o_name.o_min.pc_uchar,
            p_descriptor->o_name.o_max.pc_uchar);

    union appl_buf_ptr
        o_name0_ptr;

    e_status =
        appl_heap_alloc(
            m_context,
            i_name_len + 3u,
            &(
                o_name0_ptr.p_void));

    if (
        appl_status_ok
        == e_status)
    {
        appl_str_copy(
            o_name0_ptr.p_uchar,
            o_name0_ptr.p_uchar + i_name_len,
            p_descriptor->o_name.o_min.pc_uchar,
            p_descriptor->o_name.o_max.pc_uchar);

        o_name0_ptr.p_uchar[i_name_len] =
            '\\';

        o_name0_ptr.p_uchar[i_name_len + 1u] =
            '*';

        o_name0_ptr.p_uchar[i_name_len + 2u] =
            '\000';

        WIN32_FIND_DATA
            o_find_file_data;

        appl_mem_zero(
            &(
                o_find_file_data),
            sizeof(
                o_find_file_data));

        HANDLE
            h_find_file_result;

        h_find_file_result =
            FindFirstFileA(
                o_name0_ptr.pc_char,
                &(
                    o_find_file_data));

        if (
            INVALID_HANDLE_VALUE
            != h_find_file_result)
        {
            bool
                b_more_files;

            b_more_files =
                true;

            while (
                b_more_files)
            {
                struct appl_dir_item
                    o_dir_item;

                o_dir_item.o_name.o_min.p_char =
                    o_find_file_data.cFileName;

                o_dir_item.o_name.o_max.pc_uchar =
                    o_dir_item.o_name.o_min.pc_uchar
                    + appl_buf0_len(
                        o_dir_item.o_name.o_min.pc_uchar);

                (*(p_descriptor->p_callback))(
                    p_descriptor->p_void,
                    &(
                        o_dir_item));

                if (
                    FindNextFileA(
                        h_find_file_result,
                        &(
                            o_find_file_data)))
                {
                }
                else
                {
                    b_more_files =
                        false;
                }
            }

            FindClose(
                h_find_file_result);
        }
        else
        {
            e_status =
                appl_status_fail;
        }

        appl_heap_free(
            m_context,
            i_name_len + 3u,
            o_name0_ptr.p_void);
    }
    else
    {
        e_status =
            appl_status_fail;
    }

    return
        e_status;

} // v_enumerate()

#endif /* #if defined APPL_OS_WINDOWS */

/* end-of-file: appl_dir_w32_mgr.cpp */

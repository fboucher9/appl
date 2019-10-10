/* See LICENSE for license details */

/*

*/

#if defined APPL_OS_LINUX

#include <appl_status.h>

#include <appl_predefines.h>

#include <appl_types.h>

#include <object/appl_object.h>

#include <dir/appl_dir_mgr.h>

#include <dir/appl_dir_std_mgr.h>

#include <buf/appl_buf.h>

#include <dir/appl_dir_descriptor.h>

#include <buf/appl_buf0.h>

#include <sys/types.h>

#include <dirent.h>

#include <errno.h>

#if defined APPL_DEBUG

#include <debug/appl_debug_handle.h>

#endif /* #if defined APPL_DEBUG */

#include <misc/appl_unused.h>

//
//
//
appl_dir_std_mgr::appl_dir_std_mgr(
    struct appl_context * const
        p_context) :
    appl_dir_mgr(
        p_context)
{
}

//
//
//
appl_dir_std_mgr::~appl_dir_std_mgr()
{
}

//
//
//
enum appl_status
    appl_dir_std_mgr::f_init(void)
{
    return
        appl_status_ok;

} // f_init()

//
//
//
appl_size_t
    appl_dir_std_mgr::v_cleanup(void)
{
    return
        sizeof(class appl_dir_std_mgr);

} // v_cleanup()

//
//
//
enum appl_status
    appl_dir_std_mgr::v_enumerate(
        struct appl_dir_descriptor const * const
            p_descriptor)
{
    enum appl_status
        e_status;

    struct appl_buf0 *
        p_buf0;

    e_status =
        appl_buf0_create(
            m_context,
            p_descriptor->o_name.o_min.pc_uchar,
            p_descriptor->o_name.o_max.pc_uchar,
            &(
                p_buf0));

    if (
        appl_status_ok
        == e_status)
    {
        appl_buf_ptr
            o_name0;

        o_name0.pc_uchar =
            appl_buf0_get(
                p_buf0);

        DIR *
            p_dir_std;

        p_dir_std =
            opendir(
                o_name0.pc_char);

        if (
            p_dir_std)
        {
            struct dirent *
                p_dir_entry;

            p_dir_entry =
                readdir(
                    p_dir_std);

            while (
                (
                    appl_status_ok
                    == e_status)
                && p_dir_entry)
            {
#if defined APPL_DEBUG
                if (0)
                {
                    appl_debug_print0(
                        m_context,
                        "readdir [");

                    appl_debug_print0(
                        m_context,
                        p_dir_entry->d_name);

                    appl_debug_print0(
                        m_context,
                        "]\n");
                }
#endif /* #if defined APPL_DEBUG */

                struct appl_dir_item
                    o_dir_item;

                o_dir_item.o_name.o_min.pc_char =
                    p_dir_entry->d_name;

                o_dir_item.o_name.o_max.pc_uchar =
                    o_dir_item.o_name.o_min.pc_uchar
                    + appl_buf0_len(
                        o_dir_item.o_name.o_min.pc_uchar);

                e_status =
                    (*(p_descriptor->p_callback))(
                        p_descriptor->p_void,
                        &(
                            o_dir_item));

                if (
                    appl_status_ok
                    == e_status)
                {
                    p_dir_entry =
                        readdir(
                            p_dir_std);
                }
            }

            closedir(
                p_dir_std);
        }
        else
        {
#if defined APPL_DEBUG
            appl_debug_print0(
                m_context,
                "opendir fail ");

            appl_debug_print_number(
                m_context,
                errno,
                0,
                0);

            appl_debug_print0(
                m_context,
                "\n");
#endif /* #if defined APPL_DEBUG */
        }

        appl_buf0_destroy(
            p_buf0);
    }

    return
        e_status;

} // v_enumerate()

#endif /* #if defined APPL_OS_LINUX */

/* end-of-file: appl_dir_std_mgr.cpp */

/* See LICENSE for license details */

/*

*/

#include <appl_status.h>

#include <appl_types.h>

#include <appl_object.h>

#include <dict/appl_dict.h>

#include <appl_list.h>

#include <dict/appl_dict_std.h>

#include <appl_unused.h>

/*

*/
struct appl_dict_std_node
{
    struct appl_list
        o_list;

    /* -- */

    unsigned char *
        p_name_min;

    unsigned char *
        p_name_max;

    /* -- */

    void *
        p_value;

    void *
        pv_padding[1u];

}; /* struct appl_dict_std_node */

//
//
//
appl_dict_std::appl_dict_std() :
    appl_dict(),
    m_hash()
{
}

//
//
//
appl_dict_std::~appl_dict_std()
{
}

//
//
//
enum appl_status
    appl_dict_std::f_init(void)
{
    return
        appl_status_fail;

} // f_init()

//
//
//
enum appl_status
    appl_dict_std::v_cleanup(void)
{
    return
        appl_status_ok;

} // v_cleanup()

//
//
//
enum appl_status
    appl_dict_std::v_set(
        unsigned char const * const
            p_name_min,
        unsigned char const * const
            p_name_max,
        void * const
            p_value)
{
    appl_unused(
        p_name_min,
        p_name_max,
        p_value);

    return
        appl_status_fail;

} // v_set()

//
//
//
enum appl_status
    appl_dict_std::v_get(
        unsigned char const * const
            p_name_min,
        unsigned char const * const
            p_name_max,
        void * * const
            r_value)
{
    appl_unused(
        p_name_min,
        p_name_max,
        r_value);

    return
        appl_status_fail;

} // v_get()

/* end-of-file: appl_dict_std.cpp */

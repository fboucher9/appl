/* See LICENSE for license details */

/*

*/

#include "appl_status.h"

#include "appl_types.h"

#include "appl_object.h"

#include "appl_list.h"

#include "appl_node.h"

/* Assert compiler */
#if ! defined __cplusplus
#error use c++ compiler
#endif /* #if ! defined __cplusplus */

//
//
//
struct appl_list *
    appl_node::get_list(void)
{
    return
        &(
            o_list);

} // get_list()

//
//
//
class appl_node *
    appl_node::get_node(
        struct appl_list * const
            p_list)
{
    return
        reinterpret_cast<class appl_node *>(
            reinterpret_cast<appl_ptrdiff_t>(
                p_list)
            - reinterpret_cast<appl_ptrdiff_t>(
                &(
                    static_cast<class appl_node *>(0)->o_list)));

} // get_node()

//
//
//
class appl_node *
    appl_node::get_next(void)
{
    return
        appl_node::get_node(
            o_list.o_next.p_node);

} // get_next()

//
//
//
class appl_node *
    appl_node::get_prev(void)
{
    return
        appl_node::get_node(
            o_list.o_prev.p_node);

} // get_prev()

//
//
//
void
    appl_node::join(
        class appl_node * const
            p_node_left,
        class appl_node * const
            p_node_right)
{
    appl_list_join(
        &(
            p_node_left->o_list),
        &(
            p_node_right->o_list));
}

//
//
//
appl_node::appl_node() :
    appl_object(),
    o_list()
{
    appl_list_init(
        &(
            o_list));

}

//
//
//
appl_node::~appl_node()
{
    appl_list_join(
        &(
            o_list),
        &(
            o_list));
}

/* end-of-file: appl_node.cpp */

/* See LICENSE for license details */

/*

*/

#include <appl_status.h>

#include <appl_types.h>

#include <object/appl_object.h>

#include <allocator/appl_allocator.h>

#include <heap/appl_heap.h>

//
//
//
appl_heap::appl_heap(
    struct appl_context * const
        p_context) :
    appl_allocator(
        p_context)
{
}

//
//
//
appl_heap::~appl_heap()
{
}

/* end-of-file: appl_heap.cpp */

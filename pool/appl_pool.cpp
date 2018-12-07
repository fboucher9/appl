
#include <appl_status.h>

#include <appl_types.h>

#include <appl_object.h>

#include <allocator/appl_allocator.h>

#include <pool/appl_pool.h>

#include <appl_unused.h>

//
//
//
appl_pool::appl_pool(
    struct appl_context * const
        p_context) :
    appl_allocator(
        p_context)
{
}

//
//
//
appl_pool::~appl_pool()
{
}

/* end-of-file: appl_pool.cpp */

/* See LICENSE for license details */

/*

*/

/* Reverse include guard */
enum guard_appl_pool_h
{
    inc_appl_pool_h =
        /* Header file dependencies */
        inc_appl_allocator_h
};

/* Assert compiler */
#include <misc/appl_assert_cplusplus.h>

//
//  Class: appl_pool
//
//  Description:
//      Allocate fixed-size structures from system memory.
//
//  Comments:
//      -   No array, allocate single instances.
//      -   No realloc, may not change size of instances.
//
struct appl_pool : public appl_allocator
{
    public:

        appl_pool(
            struct appl_context * const
                p_context);

        virtual
        ~appl_pool();

    protected:

    private:

        appl_pool(
            struct appl_pool const & r);

        struct appl_pool &
            operator =(
                struct appl_pool const & r);

}; // struct appl_pool

/* end-of-file: appl_pool.h */

/* See LICENSE for license details */

/*

*/

/* Reverse include guard */
#if defined INC_APPL_POOL_H
#error include appl_pool.h once
#endif /* #if defined INC_APPL_POOL_H */

#define INC_APPL_POOL_H

/* Header file dependencies */
#if ! defined INC_APPL_OBJECT_H
#error include appl_object.h before
#endif /* #if ! defined INC_APPL_OBJECT_H */

struct appl_pool;

/* Assert compiler */
#if ! defined __cplusplus
#error use c++ compiler
#endif /* #if ! defined __cplusplus */

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
struct appl_pool : public appl_object
{
    public:

        virtual
        enum appl_status
            v_alloc(
                void * * const
                    r_buf);

        template <typename T_instance>
        enum appl_status
            alloc_object(
                T_instance * * const
                    r_object)
        {
            return
                v_alloc(
                    reinterpret_cast<void * *>(
                        r_object));

        } // alloc_object()

        virtual
        enum appl_status
            v_free(
                void * const
                    p_buf);

        template <typename T_instance>
        enum appl_status
            free_object(
                T_instance * const
                    p_object)
        {
            return
                v_free(
                    static_cast<void *>(
                        p_object));

        } // free_object()

    protected:

        appl_pool();

        virtual
        ~appl_pool();

    private:

        appl_pool(
            class appl_pool const & r);

        class appl_pool &
            operator =(
                class appl_pool const & r);

}; // class appl_pool

/* end-of-file: appl_pool.h */

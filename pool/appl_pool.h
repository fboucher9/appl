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

/* Predefine */
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
struct appl_pool : public appl_allocator
{
    public:

        template <typename T_instance>
        enum appl_status
            alloc_struct(
                T_instance * * const
                    r_object)
        {
            enum appl_status
                e_status;

            union object_ptr
            {
                void *
                    p_placement;

                T_instance *
                    p_instance;

            } o_object_ptr;

            e_status =
                v_alloc(
                    0,
                    &(
                        o_object_ptr.p_placement));

            if (
                appl_status_ok
                == e_status)
            {
                *(
                    r_object) =
                    o_object_ptr.p_instance;
            }

            return
                e_status;

        } // alloc_struct()

    protected:

        appl_pool();

        virtual
        ~appl_pool();

    private:

        appl_pool(
            struct appl_pool const & r);

        struct appl_pool &
            operator =(
                struct appl_pool const & r);

}; // struct appl_pool

/* end-of-file: appl_pool.h */

/* See LICENSE for license details */

/*

*/

class appl_refcount_service
{
    public:

        static
        struct appl_object *
        s_parent(
            struct appl_refcount * const
                p_refcount);

        static
        struct appl_object const *
        s_const_parent(
            struct appl_refcount const * const
                p_refcount);

        static
        enum appl_status
        s_acquire(
            struct appl_refcount * const
                p_refcount);

        static
        enum appl_status
        s_release(
            struct appl_refcount * const
                p_refcount);

}; // class appl_refcount_service

/* end-of-file: appl_refcount_service.h */

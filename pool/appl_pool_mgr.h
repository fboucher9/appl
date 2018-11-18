/* See LICENSE for license details */

/*

*/

/* Reverse include guard */
enum guard_appl_pool_mgr_h
{
    inc_appl_pool_mgr_h =
        /* Header file dependencies */
        inc_appl_object_h
};

struct appl_pool;

/* Assert compiler */
#if ! defined __cplusplus
#error use c++ compiler
#endif /* #if ! defined __cplusplus */

class appl_pool_mgr;

//
//
//
class appl_pool_mgr : public appl_object
{
    public:

        static
        enum appl_status
            s_create(
                struct appl_allocator * const
                    p_allocator,
                class appl_pool_mgr * * const
                    r_instance);

        virtual
        enum appl_status
            v_create_node(
                appl_size_t const
                    i_buf_len,
                struct appl_pool * * const
                    r_pool_node);

        appl_pool_mgr();

        virtual
        ~appl_pool_mgr();

    protected:

    private:

        appl_pool_mgr(
            class appl_pool_mgr const & r);

        class appl_pool_mgr &
            operator =(
                class appl_pool_mgr const & r);

}; // class appl_pool_mgr

/* end-of-file: appl_pool_mgr.h */

/* See LICENSE for license details */

/*

*/

/* Reverse include guard */
#if defined INC_APPL_POOL_MGR_H
#error include appl_pool_mgr.h once
#endif /* #if defined INC_APPL_POOL_MGR_H */

#define INC_APPL_POOL_MGR_H

/* Header file dependencies */
#if ! defined INC_APPL_OBJECT_H
#error include appl_object.h before
#endif /* #if ! defined INC_APPL_OBJECT_H */

struct appl_pool;

/* Assert compiler */
#if ! defined __cplusplus
#error use c++ compiler
#endif /* #if ! defined __cplusplus */

class appl_pool_mgr;

//
//
//
class appl_pool_mgr : public appl_heap_object
{
    friend struct appl_heap;
    public:

        static
        enum appl_status
            s_create(
                struct appl_heap * const
                    p_heap,
                class appl_pool_mgr * * const
                    r_instance);

        virtual
        enum appl_status
            v_create_node(
                appl_size_t const
                    i_buf_len,
                struct appl_pool * * const
                    r_pool_node);

    protected:

        appl_pool_mgr();

        virtual
        ~appl_pool_mgr();

    private:

        appl_pool_mgr(
            class appl_pool_mgr const & r);

        class appl_pool_mgr &
            operator =(
                class appl_pool_mgr const & r);

}; // class appl_pool_mgr

/* end-of-file: appl_pool_mgr.h */

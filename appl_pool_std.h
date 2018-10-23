/* See LICENSE for license details */

/*

*/

/* Reverse include guard */
#if defined INC_APPL_POOL_STD_H
#error include appl_pool_std.h once
#endif /* #if defined INC_APPL_POOL_STD_H */

/* Header file dependencies */
#if ! defined INC_APPL_POOL_H
#error include appl_pool.h before
#endif /* #if ! defined INC_APPL_POOL_H */

/* Header file dependencies */
#if ! defined INC_APPL_LIST_H
#error include appl_list.h before
#endif /* #if ! defined INC_APPL_LIST_H */

/* Header file dependencies */
#if ! defined INC_APPL_MUTEX_IMPL_H
#error include appl_mutex_impl.h before
#endif /* #if ! defined INC_APPL_MUTEX_IMPL_H */

/* Assert compiler */
#if ! defined __cplusplus
#error use c++ compiler
#endif /* #if ! defined __cplusplus */

/* Predefine */
struct appl_pool_std_descriptor;

//
//
//
class appl_pool_std : public appl_pool
{
    friend struct appl_heap;
    public:

        static
        enum appl_status
            s_create(
                struct appl_heap * const
                    p_heap,
                appl_size_t const
                    i_buf_len,
                class appl_pool_std * * const
                    r_instance);

    protected:

        appl_pool_std();

        virtual
        ~appl_pool_std();

    private:

        // list of available items
        struct appl_list
            m_available_items;

        // lock
        class appl_mutex_impl
            m_lock;

        // size in bytes of each item
        appl_size_t
            m_buf_len;

        // count of available items
        appl_size_t
            m_available_count;

        appl_pool_std(
            class appl_pool_std const & r);

        class appl_pool_std &
            operator =(
                class appl_pool_std const & r);

        enum appl_status
            f_init(
                struct appl_pool_std_descriptor const * const
                    p_descriptor);

        virtual
        enum appl_status
            v_cleanup(void);

        virtual
        enum appl_status
            v_alloc(
                void * * const
                    r_buf);

        virtual
        enum appl_status
            v_free(
                void * const
                    p_buf);

}; // class appl_pool_std

/* end-of-file: appl_pool_std.h */

/* See LICENSE for license details */

/*

*/

/* Reverse include guard */
enum guard_appl_mutex_node_h
{
    inc_appl_mutex_node_h = 1
        /* Header file dependency */
        + inc_appl_object_h
};

/* Predefine */
struct appl_mutex;

/* Assert compiler */
#if ! defined __cplusplus
#error use c++ compiler
#endif /* #if ! defined __cplusplus */

//
//
//
struct appl_mutex : public appl_object
{
    public:

        virtual
        enum appl_status
            v_lock(void);

        virtual
        enum appl_status
            v_unlock(void);

        virtual
        enum appl_status
            v_sync(
                enum appl_status (*
                    p_sync_callback)(
                    void * const
                        p_sync_context),
                void * const
                    p_sync_context);

    protected:

        appl_mutex(
            struct appl_context * const
                p_context);

        virtual
        ~appl_mutex();

    private:

        appl_mutex(
            struct appl_mutex const & r);

        struct appl_mutex &
            operator =(
                struct appl_mutex const & r);

}; // struct appl_mutex

/* end-of-file: appl_mutex_node.h */

/* See LICENSE for license details */

/*

*/

/* Reverse include guard */
enum guard_appl_log_client_h
{
    inc_appl_log_client_h = 1
        + inc_appl_node_h
};

/*

*/
struct appl_log_client_descriptor
{
    void (* p_callback)(
        void * const
            p_callback_context,
        struct appl_log_record const * const
            p_log_record);

    void *
        p_callback_context;

}; /* struct appl_log_client_descriptor */

/* Assert compiler */
#if ! defined __cplusplus
#error use c++ compiler
#endif /* #if ! defined __cplusplus */

//
//
//
struct appl_log_client : public appl_node
{
    public:

        static
        enum appl_status
            s_create(
                struct appl_context * const
                    p_context,
                struct appl_log_client_descriptor const * const
                    p_descriptor,
                struct appl_log_client * * const
                    r_client);

        static
        enum appl_status
            s_destroy(
                struct appl_log_client * const
                    p_client);

        appl_log_client(
            struct appl_context * const
                p_context);

        virtual
        ~appl_log_client();

        enum appl_status
            f_init(
                struct appl_log_client_descriptor const * const
                    p_descriptor);

        virtual
        appl_size_t
            v_cleanup(void);

        virtual
        void
            v_dispatch(
                struct appl_log_record const * const
                    p_log_record) const;

    protected:

    private:

        struct appl_log_client_descriptor
            m_descriptor;

        appl_log_client(
            struct appl_log_client const & r);

        struct appl_log_client &
            operator =(
                struct appl_log_client const & r);

}; // struct appl_log_client

/* end-of-file: appl_log_client.h */
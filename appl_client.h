/* See LICENSE for license details */

/*

*/

#if defined(INC_APPL_CLIENT_H)
#error include appl_client.h once
#endif /* #if defined(INC_APPL_CLIENT_H) */

#define INC_APPL_CLIENT_H

struct appl_context_descriptor;

#if !defined(__cplusplus)
#error use c++ compiler
#endif /* #if !defined(__cplusplus) */

class appl_client;

class appl_heap;

class appl_options;

struct appl_client_descriptor
{
    class appl_heap *
        p_heap;

}; /* struct appl_client_descriptor */

//
//
//
class appl_client : public appl_object
{
    public:

        static
        enum appl_status
            create_instance(
                struct appl_client_descriptor const * const
                    p_client_descriptor,
                class appl_client * * const
                    r_client);

        virtual
        enum appl_status
            destroy(void);

        class appl_heap *
            m_heap;

        class appl_options *
            m_options;

    protected:

        appl_client();

        virtual
        ~appl_client();

        virtual
        enum appl_status
            init(
                void const * const
                    p_descriptor);

        virtual
        enum appl_status
            cleanup(void);

    private:

        appl_client(
            class appl_client const & r);

        class appl_client &
            operator =(
                class appl_client const & r);

        static
        void
            placement_new(
                void * const
                    p_placement);

}; // class appl_client


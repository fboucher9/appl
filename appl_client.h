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

//
//
//
class appl_client : public appl_object
{
    public:

        static
        enum appl_status
            create_instance(
                struct appl_context_descriptor const * const
                    p_client_descriptor,
                class appl_client * * const
                    r_client);

    protected:

        appl_client();

        virtual
        ~appl_client();

        enum appl_status
            init(
                struct appl_context_descriptor const * const
                    p_client_descriptor);

        enum appl_status
            cleanup(void);

    private:

        appl_client(
            class appl_client const & r);

        class appl_client &
            operator =(
                class appl_client const & r);

}; // class appl_client


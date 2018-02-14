/* See LICENSE for license details */

/*

*/

#if defined(INC_APPL_CONTEXT_STD_H)
#error include appl_context_std.h once
#endif /* #if defined(INC_APPL_CONTEXT_STD_H) */

#define INC_APPL_CONTEXT_STD_H

struct appl_context_descriptor;

#if !defined(__cplusplus)
#error use c++ compiler
#endif /* #if !defined(__cplusplus) */

class appl_context;

class appl_context_std;

//
//
//
class appl_context_std : public appl_context
{
    public:

        static
        enum appl_status
            create_instance(
                class appl_context_descriptor const * const
                    p_context_descriptor,
                class appl_context * * const
                    r_context);

    protected:

        appl_context_std();

        virtual
        ~appl_context_std();

        virtual
        enum appl_status
            init(
                void const * const
                    p_descriptor);

        virtual
        enum appl_status
            cleanup(void);

        virtual
        enum appl_status
            destroy(void);

    private:

        appl_context_std(
            class appl_context_std const & r);

        class appl_context_std &
            operator =(
                class appl_context_std const & r);

        static
        void
            placement_new(
                void * const
                    p_placement);

        enum appl_status
            init_debug(void);

        void
            cleanup_debug(void);

        enum appl_status
            init_options(
                struct appl_context_descriptor const * const
                    p_context_descriptor);

        void
            cleanup_options(void);

        enum appl_status
            init_thread_mgr(void);

        void
            cleanup_thread_mgr(void);

}; // class appl_context_std

/* end-of-file: appl_context_std.h */
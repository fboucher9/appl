/* See LICENSE for license details */

/*

*/

#if defined(INC_APPL_CONTEXT_H)
#error include appl_context.h once
#endif /* #if defined(INC_APPL_CONTEXT_H) */

#define INC_APPL_CONTEXT_H

struct appl_context_handle;

#if !defined(__cplusplus)
#error use c++ compiler
#endif /* #if !defined(__cplusplus) */

class appl_context;

class appl_heap;

class appl_debug;

class appl_options;

class appl_thread_mgr;

//
//
//
class appl_context : public appl_object
{
    public:

        class appl_heap *
            m_heap;

        class appl_debug *
            m_debug;

        class appl_options *
            m_options;

        class appl_thread_mgr *
            m_thread_mgr;

        static
        class appl_context *
        convert_handle(
            struct appl_context_handle * const
                p_context_handle);

        struct appl_context_handle *
            get_handle(void);

    protected:

        appl_context();

        virtual
        ~appl_context();

    private:

        appl_context(
            class appl_context const & r);

        class appl_context &
            operator =(
                class appl_context const & r);

}; // class appl_context

/* end-of-file: appl_context.h */

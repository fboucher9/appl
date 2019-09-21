/* See LICENSE for license details */

/*

Module: appl_refcount.h

Description:

    Base class for objects that have a reference counter.

Example:

    The following sample code shows how to implement an object
    that is derived from a appl_refcount.

    The implementation must have a reference counter member and
    must correctly handle destroy when last reference is
    destroyed.

    The implementation must have a locking mechanism to protect
    the reference counter from multiple threads.

    class appl_resource : public appl_refcount
    {
        private:

            int
                m_refcount;

            virtual
            enum appl_status
                v_cleanup(void)
            {
                bool b_destroy;
                m_mutex->v_lock();
                b_destroy = (0 == --m_refcount)
                m_mutex->v_unlock();
                if (b_destroy)
                {
                    f_cleanup();
                    return
                        appl_status_ok;
                }
                else
                {
                    return
                        appl_status_fail;
                }
            }

            virtual
            enum appl_status
                v_add(void)
            {
                m_mutex->v_lock();
                m_refcount ++;
                m_mutex->v_unlock();
            }
    };

*/

/* Reverse include guard */
enum guard_appl_refcount_h
{
    inc_appl_refcount_h = 1
        /* Header file dependency */
        + inc_appl_object_h
        + inc_appl_types_h
};

/* Predefine */
struct appl_mutex;

/* Predefine */
struct appl_refcount;

/* Assert compiler */
#include <appl_assert_cplusplus.h>

//
//
//
struct appl_refcount : public appl_object
{
    public:

        appl_refcount(
            struct appl_context * const
                p_context);

        virtual
        ~appl_refcount();

        enum appl_status
            f_init(void);

        virtual
        appl_size_t
            v_cleanup(void);

        virtual
        enum appl_status
            v_acquire(void);

        virtual
        enum appl_status
            v_release(void);

    protected:

        // --

        struct appl_mutex *
            m_mutex;

        signed long int
            m_refcount;

#define PADDING (APPL_SIZEOF_PTR + APPL_SIZEOF_LONG)
#include <appl_padding.h>

        // --

    private:

        appl_refcount(
            struct appl_refcount const & r);

        struct appl_refcount &
            operator =(
                struct appl_refcount const & r);

}; // struct appl_refcount

/* end-of-file: appl_refcount.h */

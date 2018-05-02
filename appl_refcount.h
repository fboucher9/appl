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

    class appl_resource : public appl_refcount
    {
        private:

            int
                m_refcount;

            virtual
            enum appl_status
                v_cleanup(void)
            {
                if (0 == --m_refcount)
                {
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
                m_refcount ++;
            }
    };

*/

/* Reverse include guard */
#if defined INC_APPL_REFCOUNT_H
#error include appl_refcount.h once
#endif /* #if defined INC_APPL_REFCOUNT_H */

#define INC_APPL_REFCOUNT_H

/* Header file dependency */
#if defined INC_APPL_OBJECT_H
#error include appl_object.h before appl_refcount.h
#endif /* #if defined INC_APPL_OBJECT_H */

/* Predefine */
struct appl_refcount;

/* Assert compiler */
#if ! defined __cplusplus
#error use c++ compiler
#endif /* #if ! defined __cplusplus */

//
//
//
struct appl_refcount : public appl_object
{
    public:

        virtual
        enum appl_status
            v_add(void);

    protected:

        appl_refcount();

        virtual
        ~appl_refcount();

    private:

        appl_refcount(
            struct appl_refcount const & r);

        struct appl_refcount &
            operator =(
                struct appl_refcount const & r);

}; // struct appl_refcount

/* end-of-file: appl_refcount.h */

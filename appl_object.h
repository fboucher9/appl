/* See LICENSE for license details */

/*

*/

#if defined(INC_APPL_OBJECT_H)
#error include appl_object.h once
#endif /* #if defined(INC_APPL_OBJECT_H) */

#define INC_APPL_OBJECT_H

#if !defined(__cplusplus)
#error use c++ compiler
#endif /* #if !defined(__cplusplus) */

//
//
//
class appl_object
{
    public:

        virtual
        enum appl_status
            destroy(
                class appl_client * const
                    p_client);

    protected:

        appl_object();

        virtual
        ~appl_object();

    private:

        appl_object(
            class appl_object const & r);

        class appl_object &
            operator =(
                class appl_object const & r);

}; // class appl_object

/* end-of-file: appl_object.h */

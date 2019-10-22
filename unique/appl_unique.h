/* See LICENSE for license details */

/*

*/

/* Reverse include guard */
enum guard_appl_unique_h
{
    inc_appl_unique_h = 1
        /* Header file dependencies */
        | inc_appl_object_h
        /* ... */

}; /* enum guard_appl_unique_h */

/*

*/
struct appl_unique_descriptor
{
    unsigned long int
        i_value;

#define PADDING (APPL_SIZEOF_LONG)
#include <misc/appl_padding.h>

}; /* struct appl_unique_descriptor */

#include <misc/appl_assert_cplusplus.h>

//
//
//
struct appl_unique : public appl_object
{
    public:

        appl_unique(
            struct appl_context * const
                p_context);

        virtual
        ~appl_unique();

        enum appl_status
            f_init(
                struct appl_unique_descriptor const * const
                    p_descriptor);

        virtual
        appl_size_t
            v_cleanup(void);

        unsigned long int
            f_get(void) const;

    protected:

    private:

        unsigned long int
            m_value;

#define PADDING (APPL_SIZEOF_LONG)
#include <misc/appl_padding.h>

        appl_unique(
            struct appl_unique const & r);

        struct appl_unique &
            operator =(
                struct appl_unique const & r);

}; // struct appl_unique

/* end-of-file: appl_unique.h */

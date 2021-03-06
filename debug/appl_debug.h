/* See LICENSE for license details */

/*

*/

/* Assert configuration */
#include <misc/appl_assert_debug.h>

/* Included. */
#define INC_APPL_DEBUG_H

/* Reverse include guard */
enum guard_appl_debug_h
{
    inc_appl_debug_h =
        /* Header file dependencies */
        inc_appl_object_h
};

/* Assert compiler */
#include <misc/appl_assert_cplusplus.h>

class appl_debug;

//
//
//
class appl_debug : public appl_object
{
    public:

        appl_debug(
            struct appl_context * const
                p_context);

        virtual
        ~appl_debug();

        virtual
        enum appl_status
            v_break(void);

        virtual
        enum appl_status
            v_print(
                unsigned char const * const
                    p_msg_min,
                unsigned char const * const
                    p_msg_max);

    protected:

    private:

        appl_debug(
            class appl_debug const & r);

        class appl_debug &
            operator =(
                class appl_debug const & r);

}; // class appl_debug

/* end-of-file: appl_debug.h */

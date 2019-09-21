/* See LICENSE for license details */

/*

*/

/* Included. */
#define INC_APPL_MUTEX_MGR_H

/* Reverse include guard */
enum guard_appl_mutex_mgr_h
{
    inc_appl_mutex_mgr_h =
        /* Header file dependency */
        inc_appl_object_h
};

struct appl_mutex_descriptor;

struct appl_mutex;

/* Assert compiler */
#include <appl_assert_cplusplus.h>

class appl_mutex_mgr;

//
//
//
class appl_mutex_mgr : public appl_object
{
    public:

        appl_mutex_mgr(
            struct appl_context * const
                p_context);

        virtual
        ~appl_mutex_mgr();

        virtual
        enum appl_status
            v_create_node(
                struct appl_mutex_descriptor const * const
                    p_mutex_descriptor,
                struct appl_mutex * * const
                    r_mutex);

        virtual
        enum appl_status
            v_destroy_node(
                struct appl_mutex * const
                    p_mutex);

    protected:

    private:

        appl_mutex_mgr(
            class appl_mutex_mgr const & r);

        class appl_mutex_mgr &
            operator =(
                class appl_mutex_mgr const & r);

}; // class appl_mutex_mgr

/* end-of-file: appl_mutex_mgr.h */

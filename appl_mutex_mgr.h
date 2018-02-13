/* See LICENSE for license details */

/*

*/

/* Reverse include guard */
#if defined INC_APPL_MUTEX_MGR_H
#error include appl_mutex_mgr.h
#endif /* #if defined INC_APPL_MUTEX_MGR_H */

#define INC_APPL_MUTEX_MGR_H

/* Header file dependency */
#if ! defined INC_APPL_OBJECT_H
#error include appl_object.h before
#endif /* #if ! defined INC_APPL_OBJECT_H */

struct appl_mutex_descriptor;

/* Assert compiler */
#if ! defined __cplusplus
#error use c++ compiler
#endif /* #if ! defined __cplusplus */

class appl_mutex_node;

class appl_mutex_mgr;

//
//
//
class appl_mutex_mgr : public appl_object
{
    public:

        virtual
        enum appl_status
            v_create(
                struct appl_mutex_descriptor const * const
                    p_mutex_descriptor,
                class appl_mutex_node * * const
                    r_mutex_node);

    protected:

        appl_mutex_mgr();

        virtual
        ~appl_mutex_mgr();

    private:

        appl_mutex_mgr(
            class appl_mutex_mgr const & r);

        class appl_mutex_mgr &
            operator =(
                class appl_mutex_mgr const & r);

}; // class appl_mutex_mgr

/* end-of-file: appl_mutex_mgr.h */

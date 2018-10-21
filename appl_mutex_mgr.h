/* See LICENSE for license details */

/*

*/

/* Reverse include guard */
#if defined INC_APPL_MUTEX_MGR_H
#error include appl_mutex_mgr.h
#endif /* #if defined INC_APPL_MUTEX_MGR_H */

#define INC_APPL_MUTEX_MGR_H

/* Header file dependency */
#if ! defined INC_APPL_HEAP_OBJECT_H
#error include appl_heap_object.h before
#endif /* #if ! defined INC_APPL_HEAP_OBJECT_H */

struct appl_mutex_descriptor;

struct appl_mutex;

/* Assert compiler */
#if ! defined __cplusplus
#error use c++ compiler
#endif /* #if ! defined __cplusplus */

class appl_mutex_mgr;

//
//
//
class appl_mutex_mgr : public appl_heap_object
{
    public:

        virtual
        enum appl_status
            v_create(
                struct appl_mutex_descriptor const * const
                    p_mutex_descriptor,
                struct appl_mutex * * const
                    r_mutex);

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

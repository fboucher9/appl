/* See LICENSE for license details */

/*

*/

/* Reverse include guard */
#if defined INC_APPL_LIBRARY_MGR_H
#error include appl_library_mgr.h once
#endif /* #if defined INC_APPL_LIBRARY_MGR_H */

#define INC_APPL_LIBRARY_MGR_H

/* Header file dependency */
#if ! defined INC_APPL_OBJECT_H
#error include appl_object.h before appl_library_mgr.h
#endif /* #if ! defined INC_APPL_OBJECT_H */

struct appl_library_descriptor;

struct appl_library;

/* Assert compiler */
#if ! defined __cplusplus
#error use c++ compiler
#endif /* #if ! defined __cplusplus */

class appl_library_mgr;

//
//
//
class appl_library_mgr : public appl_object
{
    public:

        virtual
        enum appl_status
            v_create_node(
                struct appl_library_descriptor const * const
                    p_library_descriptor,
                struct appl_library * * const
                    r_library);

    protected:

        appl_library_mgr();

        virtual
        ~appl_library_mgr();

    private:

        appl_library_mgr(
            class appl_library_mgr const & r);

        class appl_library_mgr &
            operator =(
                class appl_library_mgr const & r);

}; // class appl_library_mgr

/* end-of-file: appl_library_mgr.h */

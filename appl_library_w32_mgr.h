/* See LICENSE for license details */

/*

*/

/* Reverse include guard */
#if defined INC_APPL_LIBRARY_W32_MGR_H
#error include appl_library_w32_mgr.h once
#endif /* #if defined INC_APPL_LIBRARY_W32_MGR_H */

#define INC_APPL_LIBRARY_W32_MGR_H

/* Header file dependency */
#if ! defined INC_APPL_LIBRARY_MGR_H
#error include appl_library_mgr.h before appl_library_w32_mgr.h
#endif /* #if ! defined INC_APPL_LIBRARY_MGR_H */

struct appl_context;

struct appl_library_mgr;

struct appl_library_descriptor;

/* Assert compiler */
#if ! defined __cplusplus
#error use c++ compiler
#endif /* #if ! defined __cplusplus */

class appl_library_w32_mgr;

//
//
//
class appl_library_w32_mgr : public appl_library_mgr
{
    public:

        //
        //
        //
        static
        enum appl_status
            s_create(
                struct appl_allocator * const
                    p_allocator,
                struct appl_library_mgr * * const
                    r_library_mgr);

        //
        //
        //
        appl_library_w32_mgr();

        //
        //
        //
        virtual
        ~appl_library_w32_mgr();

    protected:

    private:

        appl_library_w32_mgr(
            class appl_library_w32_mgr const & r);

        class appl_library_w32_mgr &
            operator =(
                class appl_library_w32_mgr const & r);

        //
        //
        //
        virtual
        enum appl_status
            v_create_node(
                struct appl_library_descriptor const * const
                    p_library_descriptor,
                struct appl_library * * const
                    r_library);

}; // class appl_library_w32_mgr

/* end-of-file: appl_library_w32_mgr.h */

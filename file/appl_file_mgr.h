/* See LICENSE for license details */

/*

*/

/* Reverse include guard */
enum guard_appl_file_mgr_h
{
    inc_appl_file_mgr_h =
        /* Header file dependencies */
        inc_appl_object_h
};

struct appl_file_descriptor;

struct appl_file;

#if !defined(__cplusplus)
#error use c++ compiler
#endif /* #if !defined(__cplusplus) */

class appl_file_mgr;

//
//
//
class appl_file_mgr : public appl_object
{
    public:

        virtual
        enum appl_status
            v_create_node(
                struct appl_file_descriptor const * const
                    p_file_descriptor,
                struct appl_file * * const
                    r_file_node);

    protected:

        appl_file_mgr();

        virtual
        ~appl_file_mgr();

    private:

        appl_file_mgr(
            class appl_file_mgr const & r);

        class appl_file_mgr &
            operator =(
                class appl_file_mgr const & r);

}; // class appl_file_mgr

/* end-of-file: appl_file_mgr.h */

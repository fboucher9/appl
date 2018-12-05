/* See LICENSE for license details */

/*

*/

/* Reverse include guard */
enum guard_appl_library_w32_mgr_h
{
    inc_appl_library_w32_mgr_h =
        /* Header file dependency */
        inc_appl_library_mgr_h
};

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

        static
        enum appl_status
            s_destroy(
                struct appl_allocator * const
                    p_allocator,
                struct appl_library_mgr * const
                    p_library_mgr);

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

        virtual
        appl_size_t
            v_cleanup(void);

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

        virtual
        enum appl_status
            v_destroy_node(
                struct appl_library * const
                    p_library);

}; // class appl_library_w32_mgr

/* end-of-file: appl_library_w32_mgr.h */

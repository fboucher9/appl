/* See LICENSE for license details */

/*

*/

/* Reverse include guard */
#if defined INC_APPL_RANDOM_W32_MGR_H
#error include appl_random_w32_mgr.h once
#endif /* #if defined INC_APPL_RANDOM_W32_MGR_H */

#define INC_APPL_RANDOM_W32_MGR_H

/* Header file dependency */
#if ! defined INC_APPL_RANDOM_MGR_H
#error include appl_random_mgr.h before appl_random_w32_mgr.h
#endif /* #if ! defined INC_APPL_RANDOM_MGR_H */

struct appl_allocator;

/* Assert compiler */
#if ! defined __cplusplus
#error use c++ compiler
#endif /* #if ! defined __cplusplus */

class appl_random_w32_mgr;

//
//
//
class appl_random_w32_mgr : public appl_random_mgr
{
    public:

        static
        enum appl_status
        s_create(
            struct appl_allocator * const
                p_allocator,
            class appl_random_mgr * * const
                r_random_mgr);

        appl_random_w32_mgr();

        virtual
        ~appl_random_w32_mgr();

        enum appl_status
            f_init(void);

    protected:

    private:

        appl_random_w32_mgr(
            class appl_random_w32_mgr const & r);

        class appl_random_w32_mgr &
            operator =(
                class appl_random_w32_mgr const & r);

        virtual
        enum appl_status
        v_create_node(
            struct appl_random_descriptor const * const
                p_descriptor,
            struct appl_random * * const
                r_node);

}; // class appl_random_w32_mgr

/* end-of-file: appl_random_w32_mgr.h */

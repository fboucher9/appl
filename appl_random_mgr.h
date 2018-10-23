/* See LICENSE for license details */

/*

*/

/* Reverse include guard */
#if defined INC_APPL_RANDOM_MGR_H
#error include appl_random_mgr.h once
#endif /* #if defined INC_APPL_RANDOM_MGR_H */

#define INC_APPL_RANDOM_MGR_H

/* Header file dependency */
#if ! defined INC_APPL_OBJECT_H
#error include appl_object.h before appl_random_mgr.h
#endif /* #if ! defined INC_APPL_OBJECT_H */

struct appl_random;

struct appl_random_descriptor;

/* Assert compiler */
#if ! defined __cplusplus
#error use c++ compiler
#endif /* #if defined __cplusplus */

class appl_random_mgr;

//
//
//
class appl_random_mgr : public appl_object
{
    public:

        virtual
        enum appl_status
        v_create_node(
            struct appl_random_descriptor const * const
                p_descriptor,
            struct appl_random * * const
                r_node);

    protected:

        appl_random_mgr();

        virtual
        ~appl_random_mgr();

    private:

        appl_random_mgr(
            class appl_random_mgr const & r);

        class appl_random_mgr &
            operator =(
                class appl_random_mgr const & r);

}; // class appl_random_mgr

/* end-of-file: appl_random_mgr.h */

/* See LICENSE for license details */

/*

*/

#if defined INC_APPL_REFCOUNT_H
#error include appl_refcount.h once
#endif /* #if defined INC_APPL_REFCOUNT_H */

#define INC_APPL_REFCOUNT_H

struct appl_refcount;

/* Assert compiler */
#if ! defined __cplusplus
#error use c++ compiler
#endif /* #if ! defined __cplusplus */

//
//
//
struct appl_refcount : public appl_object
{
    public:

        virtual
        enum appl_status
            v_add(void);

    protected:

        appl_refcount();

        virtual
        ~appl_refcount();

    private:

        appl_refcount(
            struct appl_refcount const & r);

        struct appl_refcount &
            operator =(
                struct appl_refcount const & r);

}; // struct appl_refcount

/* end-of-file: appl_refcount.h */

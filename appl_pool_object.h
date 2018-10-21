/* See LICENSE for license details */

/* Reverse include guard */
#if defined INC_APPL_POOL_OBJECT_H
#error include appl_pool_object.h once
#endif /* #if defined INC_APPL_POOL_OBJECT_H */

#define INC_APPL_POOL_OBJECT_H

/* Header file dependency */
#if ! defined INC_APPL_OBJECT_H
#error include appl_object.h before
#endif /* #if ! defined INC_APPL_OBJECT_H */

/* Predefine */
struct appl_pool;

struct appl_pool_object_descriptor
{
    struct appl_pool *
        p_pool;

}; /* struct appl_pool_object_descriptor */

/* Assert compiler */
#if ! defined __cplusplus
#error use C++ compiler
#endif /* #if ! defined __cplusplus */

// Predefine
class appl_pool_object;

//
//  Class: appl_pool_object
//
//  Description:
//      Base class for objects that are allocated by a pool.
//
class appl_pool_object : public appl_object
{
    public:

        virtual
        enum appl_status
            v_destroy(void);

        struct appl_pool *
            get_pool(void) const;

    protected:

        appl_pool_object();

        virtual
        ~appl_pool_object();

        enum appl_status
            f_init(
                struct appl_pool_object_descriptor const * const
                    p_pool_object_descriptor);

    private:

        // --

        struct appl_pool *
            m_pool;

        void *
            z_padding[1u];

        // --

        appl_pool_object(
            class appl_pool_object const & r);

        class appl_pool_object &
            operator =(
                class appl_pool_object const & r);

}; // class appl_pool_object

/* end-of-file: appl_pool_object.h */

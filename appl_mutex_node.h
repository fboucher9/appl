/* See LICENSE for license details */

/*

*/

/* Reverse include guard */
#if defined INC_APPL_MUTEX_NODE_H
#error include appl_mutex_node.h once
#endif /* #if defined INC_APPL_MUTEX_NODE_H */

#define INC_APPL_MUTEX_NODE_H

/* Header file dependency */
#if ! defined INC_APPL_HEAP_OBJECT_H
#error include appl_heap_object.h before
#endif /* #if ! defined INC_APPL_HEAP_OBJECT_H */

struct appl_mutex;

/* Assert compiler */
#if ! defined __cplusplus
#error use c++ compiler
#endif /* #if ! defined __cplusplus */

//
//
//
struct appl_mutex : public appl_heap_object
{
    public:

        virtual
        enum appl_status
            v_lock(void);

        virtual
        enum appl_status
            v_unlock(void);

    protected:

        appl_mutex();

        virtual
        ~appl_mutex();

    private:

        appl_mutex(
            struct appl_mutex const & r);

        struct appl_mutex &
            operator =(
                struct appl_mutex const & r);

}; // struct appl_mutex

/* end-of-file: appl_mutex_node.h */

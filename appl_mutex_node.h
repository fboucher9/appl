/* See LICENSE for license details */

/*

*/

/* Reverse include guard */
#if defined INC_APPL_MUTEX_NODE_H
#error include appl_mutex_node.h once
#endif /* #if defined INC_APPL_MUTEX_NODE_H */

#define INC_APPL_MUTEX_NODE_H

/* Header file dependency */
#if ! defined INC_APPL_OBJECT_H
#error include appl_object.h before
#endif /* #if ! defined INC_APPL_OBJECT_H */

struct appl_mutex_handle;

/* Assert compiler */
#if ! defined __cplusplus
#error use c++ compiler
#endif /* #if ! defined __cplusplus */

class appl_mutex_node;

//
//
//
class appl_mutex_node : public appl_object
{
    public:

        virtual
        enum appl_status
            v_lock(void);

        virtual
        enum appl_status
            v_unlock(void);

        static
        class appl_mutex_node *
        convert_handle(
            struct appl_mutex_handle * const
                p_mutex_handle);

    protected:

        appl_mutex_node();

        virtual
        ~appl_mutex_node();

    private:

        appl_mutex_node(
            class appl_mutex_node const & r);

        class appl_mutex_node &
            operator =(
                class appl_mutex_node const & r);

}; // class appl_mutex_node

/* end-of-file: appl_mutex_node.h */

/* See LICENSE for license details */

/*

*/

/* Reverse include guard */
#if defined INC_APPL_LIBRARY_NODE_H
#error include appl_library_node.h once
#endif /* #if defined INC_APPL_LIBRARY_NODE_H */

#define INC_APPL_LIBRARY_NODE_H

/* Header file dependency */
#if ! defined INC_APPL_OBJECT_H
#error include appl_object.h before appl_library_node.h
#endif /* #if ! defined INC_APPL_OBJECT_H */

struct appl_library;

/* Assert compiler */
#if ! defined __cplusplus
#error use c++ compiler
#endif /* #if ! defined __cplusplus */

//
//
//
struct appl_library : public appl_heap_object
{
    public:

        virtual
        enum appl_status
            v_query(
                unsigned char const * const
                    p_symbol_name_min,
                unsigned char const * const
                    p_symbol_name_max,
                void * * const
                    r_symbol) const;

    protected:

        appl_library();

        virtual
        ~appl_library();

    private:

        appl_library(
            struct appl_library const & r);

        struct appl_library &
            operator =(
                struct appl_library const & r);

}; // struct appl_library

/* end-of-file: appl_library_node.h */

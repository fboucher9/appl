/* See LICENSE for license details */

/*

*/

/* Reverse include guard */
#if defined INC_APPL_LIBRARY_W32_NODE_H
#error include appl_library_w32_node.h once
#endif /* #if defined INC_APPL_LIBRARY_W32_NODE_H */

#define INC_APPL_LIBRARY_W32_NODE_H

/* Header file dependency */
#if ! defined INC_APPL_LIBRARY_NODE_H
#error include appl_library_node.h before appl_library_w32_node.h
#endif /* #if ! defined INC_APPL_LIBRARY_NODE_H */

struct appl_heap;

struct appl_library_descriptor;

struct appl_library;

/* Assert compiler */
#if ! defined __cplusplus
#error use c++ compiler
#endif /* #if ! defined __cplusplus */

class appl_library_w32_node;

//
//
//
class appl_library_w32_node : public appl_library
{
    // friend struct appl_heap;

    public:

        //
        //
        //
        static
        enum appl_status
            s_create(
                struct appl_heap * const
                    p_heap,
                struct appl_library_descriptor const * const
                    p_library_descriptor,
                struct appl_library * * const
                    r_library);

        //
        //
        //
        appl_library_w32_node();

        //
        //
        //
        virtual
        ~appl_library_w32_node();

        //
        //
        //
        enum appl_status
            f_init(
                struct appl_library_descriptor const * const
                    p_library_descriptor);

    protected:

    private:

        HMODULE
            m_library_handle;

        appl_library_w32_node(
            class appl_library_w32_node const & r);

        class appl_library_w32_node &
            operator =(
                class appl_library_w32_node const & r);

        virtual
        enum appl_status
            v_query(
                unsigned char const * const
                    p_symbol_name_min,
                unsigned char const * const
                    p_symbol_name_max,
                void * * const
                    r_symbol) const;

}; // class appl_library_w32_node

/* end-of-file: appl_library_w32_node.h */

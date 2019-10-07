/* See LICENSE for license details */

/*

*/

/* Included. */
#define INC_APPL_HASH_H

/* Reverse include guard */
enum guard_appl_hash_h
{
    inc_appl_hash_h =
        /* Header file dependencies */
        inc_appl_status_h
        + inc_appl_types_h
        + inc_appl_object_h
        + inc_appl_list_h
        + inc_appl_hash_handle_h
};

/*

*/
struct appl_hash_table
{
    struct appl_list
        o_list;

}; /* struct appl_hash_table */

//
//  Class: appl_hash
//
//  Description:
//      Instance of appl_hash object.
//
struct appl_hash : public appl_object
{
    public:

        enum appl_status
            f_init(
                struct appl_hash_descriptor const * const
                    p_descriptor);

        void
            f_insert(
                void const * const
                    p_key,
                unsigned long int const
                    i_key_len,
                struct appl_list * const
                    p_list);

        bool
            f_lookup(
                void const * const
                    p_key,
                unsigned long int const
                    i_key_len,
                struct appl_list * * const
                    r_list);

        void
            f_iterate(
                void (
                    * p_callback)(
                    void * const
                        p_context,
                    struct appl_list * const
                        p_list),
                void * const
                    p_context);

        appl_hash(
            struct appl_context * const
                p_context);

        virtual
        ~appl_hash();

    protected:

    private:

        // --

        struct appl_hash_descriptor
            m_descriptor;

        // --

        struct appl_hash_table *
            m_table;

#define PADDING (APPL_SIZEOF_PTR)
#include <misc/appl_padding.h>

        // --

        virtual
        appl_size_t
            v_cleanup(void);

        appl_hash(
            struct appl_hash const & r);

        struct appl_hash &
            operator =(
                struct appl_hash const & r);

}; // struct appl_hash


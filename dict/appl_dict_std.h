/* See LICENSE for license details */

/*

Notes:

    -   Hash table of nodes
    -   Nodes contain a name and a value

*/

/* Included. */
#define INC_APPL_DICT_STD_H

/* Reverse include guard */
enum guard_appl_dict_std_h
{
    inc_appl_dict_std_h =
        /* Header file dependencies */
        inc_appl_dict_h
        + inc_appl_list_h
};

//
//
//
class appl_dict_std : public appl_dict
{
    public:

        static
        enum appl_status
            s_create(
                struct appl_allocator * const
                    p_allocator,
                class appl_dict_std * * const
                    r_instance);

        static
        enum appl_status
            s_destroy(
                struct appl_allocator * const
                    p_allocator,
                struct appl_dict * const
                    p_instance);

        appl_dict_std(
            struct appl_context * const
                p_context);

        virtual
        ~appl_dict_std();

        enum appl_status
            f_init(void);

    protected:

    private:

        // --

        struct appl_hash *
            m_hash;

        void *
            pv_padding[1u];

        // --

        appl_dict_std(
            class appl_dict_std const & r);

        class appl_dict_std &
            operator =(
                class appl_dict_std const & r);

        virtual
        appl_size_t
            v_cleanup(void);

        virtual
        enum appl_status
            v_set(
                unsigned char const * const
                    p_name_min,
                unsigned char const * const
                    p_name_max,
                void * const
                    p_value);

        virtual
        enum appl_status
            v_get(
                unsigned char const * const
                    p_name_min,
                unsigned char const * const
                    p_name_max,
                void * * const
                    r_value);

        static
        int
            s_compare(
                void * const
                    p_context,
                void const * const
                    p_key,
                unsigned long int const
                    i_key_len,
                struct appl_list * const
                    p_node);

        static
        unsigned long int
            s_index(
                void * const
                    p_context,
                void const * const
                    p_key,
                unsigned long int const
                    i_key_len);

        enum appl_status
            f_alloc_node(
                unsigned char const * const
                    p_name_min,
                unsigned char const * const
                    p_name_max,
                void * const
                    p_value,
                struct appl_dict_std_node * * const
                    r_node);

}; // class appl_dict_std

/* end-of-file: appl_dict_std.h */

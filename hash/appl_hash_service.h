/* See LICENSE for license details */

struct appl_context;

struct appl_hash_descriptor;

struct appl_hash;

struct appl_list;

//
//
//
class appl_hash_service
{
    public:

        static
        enum appl_status
        s_create(
            struct appl_context * const
                p_context,
            struct appl_hash_descriptor const * const
                p_descriptor,
            struct appl_hash * * const
                r_instance);

        static
        struct appl_object *
        s_parent(
            struct appl_hash * const
                p_hash);

        static
        void
        s_insert(
            struct appl_hash * const
                p_hash,
            void const * const
                p_key,
            unsigned long int const
                i_key_len,
            struct appl_list * const
                p_list);

        static
        bool
        s_lookup(
            struct appl_hash * const
                p_hash,
            void const * const
                p_key,
            unsigned long int const
                i_key_len,
            struct appl_list * * const
                r_list);

        static
        void
        s_iterate(
            struct appl_hash * const
                p_hash,
            void (
                * p_callback)(
                void * const
                    p_context,
                struct appl_list * const
                    p_list),
            void * const
                p_context);

}; // class appl_hash_service

/* end-of-file: appl_hash_service.h */

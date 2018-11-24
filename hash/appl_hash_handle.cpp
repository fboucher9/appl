/* See LICENSE for license details */

/*

*/

#include <appl_status.h>

#include <appl_types.h>

#include <appl_hash_handle.h>

#include <appl_object.h>

#include <appl_list.h>

#include <appl_convert.h>

#include <allocator/appl_allocator.h>

#include <context/appl_context.h>

#include <heap/appl_heap.h>

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
                    p_descriptor)
        {
            enum appl_status
                e_status;

            e_status =
                m_context->m_heap->alloc_structure_array(
                    p_descriptor->i_max_index,
                    &(
                        m_table));

            if (
                appl_status_ok
                == e_status)
            {
                m_descriptor =
                    *(
                        p_descriptor);

                {
                    unsigned long int
                        i_index;

                    i_index =
                        0ul;

                    while (
                        i_index < m_descriptor.i_max_index)
                    {
                        struct appl_hash_table * const
                            p_hash_table =
                            m_table + i_index;

                        appl_list_init(
                            &(
                                p_hash_table->o_list));

                        i_index ++;
                    }
                }

                if (
                    appl_status_ok
                    != e_status)
                {
                    m_context->m_heap->free_structure_array(
                        p_descriptor->i_max_index,
                        m_table);
                }
            }

            return
                e_status;

        } // f_init()

        void
            f_insert(
                void const * const
                    p_key,
                unsigned long int const
                    i_key_len,
                struct appl_list * const
                    p_list)
        {
            appl_size_t const
                i_index =
                (
                    (*m_descriptor.p_index)(
                        m_descriptor.p_context,
                        p_key,
                        i_key_len)
                    % m_descriptor.i_max_index);

            struct appl_hash_table * const
                p_hash_table =
                m_table + i_index;

            appl_list_join(
                p_list,
                &(
                    p_hash_table->o_list));

        } // f_insert()

        struct appl_list *
            f_lookup(
                void const * const
                    p_key,
                unsigned long int const
                    i_key_len)
        {
            struct appl_list *
                p_list;

            p_list =
                0;

            appl_size_t const
                i_index =
                (
                    (*m_descriptor.p_index)(
                        m_descriptor.p_context,
                        p_key,
                        i_key_len)
                    % m_descriptor.i_max_index);

            struct appl_hash_table const * const
                p_hash_table =
                m_table + i_index;

            struct appl_list *
                p_iterator;

            p_iterator =
                p_hash_table->o_list.o_next.p_node;

            while (
                (
                    !(
                        p_list))
                && (
                    p_iterator
                    != &(p_hash_table->o_list)))
            {
                int const
                    i_compare_result =
                    (*m_descriptor.p_compare)(
                        m_descriptor.p_context,
                        p_key,
                        i_key_len,
                        p_iterator);

                if (
                    0
                    == i_compare_result)
                {
                    p_list =
                        p_iterator;
                }
                else
                {
                    p_iterator =
                        p_iterator->o_next.p_node;
                }
            }

            return
                p_list;

        } // f_lookup()

        void
            f_iterate(
                void (
                    * p_callback)(
                    void * const
                        p_context,
                    struct appl_list * const
                        p_list),
                void * const
                    p_context)
        {
            appl_size_t
                i_index;

            i_index =
                0u;

            while (
                i_index < m_descriptor.i_max_index)
            {
                struct appl_hash_table const * const
                    p_hash_table =
                    m_table + i_index;

                struct appl_list *
                    p_iterator;

                p_iterator =
                    p_hash_table->o_list.o_next.p_node;

                while (
                    p_iterator
                    != &(
                        p_hash_table->o_list))
                {
                    struct appl_list * const
                        p_next_iterator =
                        p_iterator->o_next.p_node;

                    (*p_callback)(
                        p_context,
                        p_iterator);

                    p_iterator =
                        p_next_iterator;

                }

                i_index ++;
            }

        } // f_iterate()

        appl_hash() :
            appl_object(),
            m_descriptor(),
            m_table()
        {
        }

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
#include <appl_padding.h>

        // --

        virtual
        enum appl_status
            v_cleanup(void)
        {
            enum appl_status
                e_status;

            m_context->m_heap->free_structure_array(
                m_descriptor.i_max_index,
                m_table);

            e_status =
                appl_status_ok;

            return
                e_status;

        } // v_cleanup()

        appl_hash(
            struct appl_hash const & r);

        struct appl_hash &
            operator =(
                struct appl_hash const & r);

}; // struct appl_hash

appl_hash::~appl_hash()
{
}

//
//
//
class appl_hash_service
{
    public:

        static
        enum appl_status
        s_create(
            struct appl_allocator * const
                p_allocator,
            struct appl_hash_descriptor const * const
                p_descriptor,
            struct appl_hash * * const
                r_instance)
        {
            return
                p_allocator->alloc_object(
                    p_descriptor,
                    r_instance);
        }

        static
        struct appl_object *
        s_parent(
            struct appl_hash * const
                p_hash)
        {
            return
                p_hash;
        }

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
                p_list)
        {
            p_hash->f_insert(
                p_key,
                i_key_len,
                p_list);
        }

        static
        struct appl_list *
        s_lookup(
            struct appl_hash * const
                p_hash,
            void const * const
                p_key,
            unsigned long int const
                i_key_len)
        {
            return
                p_hash->f_lookup(
                    p_key,
                    i_key_len);
        }

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
                p_context)
        {
            p_hash->f_iterate(
                p_callback,
                p_context);
        }

}; // class appl_hash_service

/*

*/
enum appl_status
appl_hash_create(
    struct appl_context * const
        p_context,
    struct appl_hash_descriptor const * const
        p_descriptor,
    struct appl_hash * * const
        r_instance)
{
    return
        appl_hash_service::s_create(
            p_context->m_allocator,
            p_descriptor,
            r_instance);

} /* appl_hash_create() */

/*

*/
struct appl_object *
appl_hash_parent(
    struct appl_hash * const
        p_hash)
{
    return
        appl_hash_service::s_parent(
            p_hash);

} /* appl_hash_destroy() */

/*

*/
void
appl_hash_insert(
    struct appl_hash * const
        p_hash,
    void const * const
        p_key,
    unsigned long int const
        i_key_len,
    struct appl_list * const
        p_list)
{
    appl_hash_service::s_insert(
        p_hash,
        p_key,
        i_key_len,
        p_list);

} /* appl_hash_insert() */

/*

*/
struct appl_list *
appl_hash_lookup(
    struct appl_hash * const
        p_hash,
    void const * const
        p_key,
    unsigned long int const
        i_key_len)
{
    return
        appl_hash_service::s_lookup(
            p_hash,
            p_key,
            i_key_len);

} /* appl_hash_lookup() */

/*

*/
void
appl_hash_iterate(
    struct appl_hash * const
        p_hash,
    void (
        * p_callback)(
        void * const
            p_context,
        struct appl_list * const
            p_list),
    void * const
        p_context)
{
    appl_hash_service::s_iterate(
        p_hash,
        p_callback,
        p_context);

} /* appl_hash_iterate() */

/* end-of-file: appl_hash_handle.cpp */

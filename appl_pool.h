/* See LICENSE for license details */

/*

*/

/* Reverse include guard */
#if defined INC_APPL_POOL_H
#error include appl_pool.h once
#endif /* #if defined INC_APPL_POOL_H */

#define INC_APPL_POOL_H

/* Header file dependencies */
#if ! defined INC_APPL_OBJECT_H
#error include appl_object.h before
#endif /* #if ! defined INC_APPL_OBJECT_H */

struct appl_pool;

/* Assert compiler */
#if ! defined __cplusplus
#error use c++ compiler
#endif /* #if ! defined __cplusplus */

//
//  Class: appl_pool
//
//  Description:
//      Allocate fixed-size structures from system memory.
//
//  Comments:
//      -   No array, allocate single instances.
//      -   No realloc, may not change size of instances.
//
struct appl_pool : public appl_heap_object
{
    public:

        virtual
        enum appl_status
            v_alloc(
                void * * const
                    r_buf);

        template <typename T_instance>
        enum appl_status
            alloc_struct(
                T_instance * * const
                    r_object)
        {
            return
                v_alloc(
                    reinterpret_cast<void * *>(
                        r_object));

        } // alloc_struct()

        template <typename T_instance>
        enum appl_status
            alloc_object(
                T_instance * * const
                    r_object)
        {
            enum appl_status
                e_status;

            union object_ptr
            {
                void *
                    p_placement;

                struct appl_pool_object *
                    p_object;

                T_instance *
                    p_instance;

            } o_object_ptr;

            e_status =
                v_alloc(
                    &(
                        o_object_ptr.p_placement));

            if (
                appl_status_ok
                == e_status)
            {
                T_instance::s_new(
                    o_object_ptr.p_placement);

                o_object_ptr.p_object->set_context(
                    m_context);

                o_object_ptr.p_object->m_pool =
                    this;

                e_status =
                    o_object_ptr.p_instance->f_init();

                if (
                    appl_status_ok
                    == e_status)
                {
                    *(
                        r_object) =
                        o_object_ptr.p_instance;
                }

                if (
                    appl_status_ok
                    != e_status)
                {
                    v_free(
                        o_object_ptr.p_placement);
                }
            }

            return
                e_status;

        } // alloc_object()

        template <typename T_instance, typename T_descriptor>
        enum appl_status
            alloc_object(
                T_descriptor const * const
                    p_descriptor,
                T_instance * * const
                    r_object)
        {
            enum appl_status
                e_status;

            union object_ptr
            {
                void *
                    p_placement;

                struct appl_pool_object *
                    p_object;

                T_instance *
                    p_instance;

            } o_object_ptr;

            e_status =
                v_alloc(
                    &(
                        o_object_ptr.p_placement));

            if (
                appl_status_ok
                == e_status)
            {
                T_instance::s_new(
                    o_object_ptr.p_placement);

                o_object_ptr.p_object->set_context(
                    m_context);

                o_object_ptr.p_object->set_pool(
                    this);

                e_status =
                    o_object_ptr.p_instance->f_init(
                        p_descriptor);

                if (
                    appl_status_ok
                    == e_status)
                {
                    *(
                        r_object) =
                        o_object_ptr.p_instance;
                }

                if (
                    appl_status_ok
                    != e_status)
                {
                    v_free(
                        o_object_ptr.p_placement);
                }
            }

            return
                e_status;

        } // alloc_object()

        virtual
        enum appl_status
            v_free(
                void * const
                    p_buf);

    protected:

        appl_pool();

        virtual
        ~appl_pool();

    private:

        appl_pool(
            struct appl_pool const & r);

        struct appl_pool &
            operator =(
                struct appl_pool const & r);

}; // struct appl_pool

/* end-of-file: appl_pool.h */

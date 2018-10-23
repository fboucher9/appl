/* See LICENSE for license details */

/* Reverse include guard */
#if defined INC_APPL_HEAP_OBJECT_H
#error include appl_heap_object.h once
#endif /* #if defined INC_APPL_HEAP_OBJECT_H */

#define INC_APPL_HEAP_OBJECT_H

/* Header file dependencies */
#if ! defined INC_APPL_OBJECT_H
#error include appl_object.h before
#endif /* #if ! defined INC_APPL_OBJECT_H */

/* Predefine */

/* Assert compiler */
#if ! defined __cplusplus
#error use c++ compiler
#endif /* #if ! defined __cplusplus */

/* Predefine */
class appl_heap_object;

//
//
//
class appl_heap_object : public appl_object
{
    public:

        virtual
        enum appl_status
            v_destroy(void);

        appl_size_t
            get_placement_length(void) const;

        void
            set_placement_length(
                appl_size_t const
                    i_placement_length);

    protected:

        appl_heap_object();

        virtual
        ~appl_heap_object();

    private:

        // --

        appl_size_t
            m_placement_length;

        appl_size_t
            z_padding[1u];

        // --

        appl_heap_object(
            class appl_heap_object const & r);

        class appl_heap_object &
            operator =(
                class appl_heap_object const & r);

}; // class appl_heap_object

/* end-of-file: appl_heap_object.h */

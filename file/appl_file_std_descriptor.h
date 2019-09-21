/* See LICENSE for license details */

/*

*/

/* Reverse include guard */
enum guard_appl_file_std_descriptor_h
{
    inc_appl_file_std_descriptor_h = 1
        + inc_appl_status_h
        + inc_appl_types_h
        + inc_appl_object_h
        + inc_appl_file_descriptor_h
};

/* Assert compiler */
#include <appl_assert_cplusplus.h>

//
//
//
struct appl_file_descriptor : public appl_object
{
    public:

        appl_file_descriptor(
            struct appl_context * const
                p_context);

        virtual
        ~appl_file_descriptor();

        enum appl_status
            f_init(void);

        virtual
        appl_size_t
            v_cleanup(void);

        unsigned char const *
            p_name_min;

        unsigned char const *
            p_name_max;

        /* -- */

        enum appl_file_type
            e_type;

        enum appl_file_mode
            e_mode;

#define PADDING (APPL_SIZEOF_INT*2)
#include <appl_padding.h>

    protected:

    private:

        appl_file_descriptor(
            struct appl_file_descriptor const & r);

        struct appl_file_descriptor &
            operator =(
                struct appl_file_descriptor const & r);

}; // struct appl_file_descriptor


/* See LICENSE for license details */

/*

*/

/* Reverse include guard */
enum guard_appl_packet_h
{
    inc_appl_packet_h = 1
        /* Header file dependencies */
        + inc_appl_object_h
};

/* Predefine */
struct appl_context;

/* Predefine */
struct appl_module;

/* Assert compiler */
#if ! defined __cplusplus
#error use c++ compiler
#endif /* #if ! defined __cplusplus */

//
//
//
struct appl_packet : public appl_object
{
    public:

        appl_packet(
            struct appl_context * const
                p_context);

        virtual
        ~appl_packet();

        enum appl_status
            f_init(void);

        virtual
        appl_size_t
            v_cleanup(void);

        struct appl_module *
            p_module;

        unsigned char *
            p_buf_min;

        /* -- */

        unsigned char *
            p_buf_max;

        unsigned long int
            e_type;

#define PADDING (APPL_SIZEOF_PTR + APPL_SIZEOF_LONG)
#include <appl_padding.h>

        /* -- */

        /* timestamps ... */

        /* extensions? */

    protected:

    private:

        appl_packet(
            struct appl_packet const & r);

        struct appl_packet &
            operator =(
                struct appl_packet const & r);

}; // struct appl_packet

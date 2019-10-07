/* See LICENSE for license details */

/*

*/

enum guard_appl_convert_h
{
    inc_appl_convert_h =
        /* Header file dependencies */
        1
};

#include <misc/appl_assert_cplusplus.h>

//
//
//
class appl_convert
{
    public:

        template <typename T>
        static
        inline
        unsigned char
        to_uchar(
            T const
                i_value)
        {
            return
                (
                    i_value & 0xFFu);
        } // to_char()

        template <typename T>
        static
        inline
        unsigned short int
        to_ushort(
            T const
                i_value)
        {
            return
                (
                    i_value & 0xFFFFu);
        } // to_short()

        template <typename T>
        static
        inline
        unsigned int
        to_uint(
            T const
                i_value)
        {
            return
                (
                    i_value & (~0u));
        } // to_int()

        template <typename T>
        static
        inline
        unsigned long int
        to_ulong(
            T const
                i_value)
        {
            return
                (
                    i_value & (~0ul));
        } // to_long()

        template <typename T>
        static
        inline
        signed char
        to_char(
            T const
                i_value)
        {
            return
                static_cast<signed char>(
                    i_value);

        } // to_char()

        template <typename T>
        static
        inline
        signed short int
        to_short(
            T const
                i_value)
        {
            return
                static_cast<signed short int>(
                    i_value);
        } // to_short()

        template <typename T>
        static
        inline
        signed int
        to_int(
            T const
                i_value)
        {
            return
                static_cast<signed int>(
                    i_value);
        } // to_int()

        template <typename T>
        static
        inline
        signed long int
        to_long(
            T const
                i_value)
        {
            return
                static_cast<signed long int>(
                    i_value);
        } // to_long()

        static
        inline
        signed char
        to_signed(
            unsigned char const
                i_value)
        {
            union to_signed_char
            {
                unsigned char
                    i_unsigned;

                signed char
                    i_signed;

            } o_storage;

            o_storage.i_unsigned =
                i_value;

            return
                o_storage.i_signed;

        } // to_signed()

        static
        inline
        signed short int
        to_signed(
            unsigned short int const
                i_value)
        {
            union to_signed_short
            {
                unsigned short int
                    i_unsigned;

                signed short int
                    i_signed;

            } o_storage;

            o_storage.i_unsigned =
                i_value;

            return
                o_storage.i_signed;

        } // to_signed()

        static
        inline
        signed int
        to_signed(
            unsigned int const
                i_value)
        {
            union to_signed_int
            {
                unsigned int
                    i_unsigned;

                signed int
                    i_signed;

            } o_storage;

            o_storage.i_unsigned =
                i_value;

            return
                o_storage.i_signed;

        } // to_signed()

        static
        inline
        signed long int
        to_signed(
            unsigned long int const
                i_value)
        {
            union to_signed_long
            {
                unsigned long int
                    i_unsigned;

                signed long int
                    i_signed;

            } o_storage;

            o_storage.i_unsigned =
                i_value;

            return
                o_storage.i_signed;

        } // to_signed()

#if defined INC_APPL_TYPES_H
        static
        inline
        appl_sll_t
        to_signed(
            appl_ull_t const
                i_value)
        {
            union to_signed_ll
            {
                appl_ull_t
                    i_unsigned;

                appl_sll_t
                    i_signed;

            } o_storage;

            o_storage.i_unsigned =
                i_value;

            return
                o_storage.i_signed;

        } // to_signed()
#endif /* #if defined INC_APPL_TYPES_H */

        static
        inline
        unsigned char
        to_unsigned(
            signed char const
                i_value)
        {
            union to_unsigned_char
            {
                signed char
                    i_signed;

                unsigned char
                    i_unsigned;

            } o_storage;

            o_storage.i_signed =
                i_value;

            return
                o_storage.i_unsigned;

        } // to_unsigned()

        static
        inline
        unsigned short int
        to_unsigned(
            signed short int const
                i_value)
        {
            union to_unsigned_short
            {
                signed short int
                    i_signed;

                unsigned short int
                    i_unsigned;

            } o_storage;

            o_storage.i_signed =
                i_value;

            return
                o_storage.i_unsigned;

        } // to_unsigned()

        static
        inline
        unsigned int
        to_unsigned(
            signed int const
                i_value)
        {
            union to_unsigned_int
            {
                signed int
                    i_signed;

                unsigned int
                    i_unsigned;

            } o_storage;

            o_storage.i_signed =
                i_value;

            return
                o_storage.i_unsigned;

        } // to_unsigned()

        static
        inline
        unsigned long int
        to_unsigned(
            signed long int const
                i_value)
        {
            union to_unsigned_long
            {
                signed long int
                    i_signed;

                unsigned long int
                    i_unsigned;

            } o_storage;

            o_storage.i_signed =
                i_value;

            return
                o_storage.i_unsigned;

        } // to_unsigned()

#if defined INC_APPL_TYPES_H
        static
        inline
        appl_ull_t
        to_unsigned(
            appl_sll_t const
                i_value)
        {
            union to_unsigned_ll
            {
                appl_sll_t
                    i_signed;

                appl_ull_t
                    i_unsigned;

            } o_storage;

            o_storage.i_signed =
                i_value;

            return
                o_storage.i_unsigned;

        } // to_unsigned()
#endif /* #if defined INC_APPL_TYPES_H */

        //
        //
        //
        static
        inline
        unsigned char const *
        to_uchar_ptr(
            char const * const
                p_buffer0)
        {
            union char_ptr
            {
                char const *
                    pc_char;

                unsigned char const *
                    pc_uchar;

            } o_storage;

            o_storage.pc_char =
                p_buffer0;

            return
                o_storage.pc_uchar;

        } // to_uchar_ptr()

        //
        //
        //
        static
        inline
        char const *
        to_char_ptr(
            unsigned char const * const
                p_buffer)
        {
            union char_ptr
            {
                unsigned char const *
                    pc_uchar;

                char const *
                    pc_char;

            } o_storage;

            o_storage.pc_uchar =
                p_buffer;

            return
                o_storage.pc_char;

        } // to_char_ptr()

        //
        //
        //
        static
        inline
        char *
        to_char_ptr(
            unsigned char * const
                p_buffer)
        {
            union char_ptr
            {
                unsigned char *
                    p_uchar;

                char *
                    p_char;

            } o_storage;

            o_storage.p_uchar =
                p_buffer;

            return
                o_storage.p_char;

        } // to_char_ptr()

        //
        //
        //
        static
        inline
        unsigned char * *
        to_uchar_ptr_table(
            char * * const
                argv)
        {
            union uchar_ptr_table
            {
                char * *
                    p_char_table;

                unsigned char * *
                    p_uchar_table;

            } o_storage;

            o_storage.p_char_table =
                argv;

            return
                o_storage.p_uchar_table;

        } // to_uchar_ptr_table()

        //
        //
        //
        static
        inline
        unsigned char const * const *
        to_uchar_ptr_table(
            char const * const * const
                argv)
        {
            union uchar_ptr_table
            {
                char const * const *
                    p_char_table;

                unsigned char const * const *
                    p_uchar_table;

            } o_storage;

            o_storage.p_char_table =
                argv;

            return
                o_storage.p_uchar_table;

        } // to_uchar_ptr_table()

}; // appl_convert

/* end-of-file: appl_convert.h */

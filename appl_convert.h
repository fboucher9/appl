/* See LICENSE for license details */

/*

*/

#if defined INC_APPL_CONVERT_H
#error include appl_convert.h once
#endif /* #if defined INC_APPL_CONVERT_H */

#define INC_APPL_CONVERT_H

#if ! defined __cplusplus
#error use c++ compiler
#endif /* #if ! defined __cplusplus */

//
//
//
static
inline
unsigned char const *
appl_convert(
    char const * const
        p_buffer0)
{
    return
        static_cast<unsigned char const *>(
            static_cast<void const *>(
                p_buffer0));

} // appl_convert()

//
//
//
static
inline
char const *
appl_convert(
    unsigned char const * const
        p_buffer)
{
    return
        static_cast<char const *>(
            static_cast<void const *>(
                p_buffer));

} // appl_convert()

//
//
//
static
inline
char *
appl_convert(
    unsigned char * const
        p_buffer)
{
    return
        static_cast<char *>(
            static_cast<void *>(
                p_buffer));

} // appl_convert()

//
//
//
static
inline
unsigned char * *
appl_convert(
    char * * const
        argv)
{
    return
        reinterpret_cast<unsigned char * * const>(
            argv);

} // appl_convert()

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
                static_cast<unsigned char>(
                    i_value);
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
                static_cast<unsigned short int>(
                    i_value);
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
                static_cast<unsigned int>(
                    i_value);
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
                static_cast<unsigned long int>(
                    i_value);
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
            return
                static_cast<signed char>(
                    i_value);
        } // to_signed()

        static
        inline
        signed short int
        to_signed(
            unsigned short int const
                i_value)
        {
            return
                static_cast<signed short int>(
                    i_value);
        } // to_signed()

        static
        inline
        signed int
        to_signed(
            unsigned int const
                i_value)
        {
            return
                static_cast<signed int>(
                    i_value);
        } // to_signed()

        static
        inline
        signed long int
        to_signed(
            unsigned long int const
                i_value)
        {
            return
                static_cast<signed long int>(
                    i_value);
        } // to_signed()

#if defined INC_APPL_TYPES_H
        static
        inline
        appl_sll_t
        to_signed(
            appl_ull_t const
                i_value)
        {
            return
                static_cast<appl_sll_t>(
                    i_value);
        } // to_signed()
#endif /* #if defined INC_APPL_TYPES_H */

        static
        inline
        unsigned char
        to_unsigned(
            signed char const
                i_value)
        {
            return
                static_cast<unsigned char>(
                    i_value);
        } // to_unsigned()

        static
        inline
        unsigned short int
        to_unsigned(
            signed short int const
                i_value)
        {
            return
                static_cast<unsigned short int>(
                    i_value);
        } // to_unsigned()

        static
        inline
        unsigned int
        to_unsigned(
            signed int const
                i_value)
        {
            return
                static_cast<unsigned int>(
                    i_value);
        } // to_unsigned()

        static
        inline
        unsigned long int
        to_unsigned(
            signed long int const
                i_value)
        {
            return
                static_cast<unsigned long int>(
                    i_value);
        } // to_unsigned()

#if defined INC_APPL_TYPES_H
        static
        inline
        appl_ull_t
        to_unsigned(
            appl_sll_t const
                i_value)
        {
            return
                static_cast<appl_ull_t>(
                    i_value);
        } // to_unsigned()
#endif /* #if defined INC_APPL_TYPES_H */

}; // appl_convert

/* end-of-file: appl_convert.h */

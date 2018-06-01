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
static
inline
unsigned short int
appl_store_to_uchar(
    unsigned long int const
        u_value)
{
    return
        static_cast<unsigned char>(
            u_value);

} // appl_store()

//
//
//
static
inline
unsigned short int
appl_store_to_ushort(
    unsigned long int const
        u_value)
{
    return
        static_cast<unsigned short int>(
            u_value);

} // appl_store()

//
//
//
static
inline
unsigned int
appl_store_to_uint(
    unsigned long int const
        u_value)
{
    return
        static_cast<unsigned int>(
            u_value);

} // appl_store()

//
//
//
#if defined INC_APPL_TYPES_H
static
inline
unsigned long int
appl_store_to_ulong(
    appl_ull_t const
        u_value)
{
    return
        static_cast<unsigned long int>(
            u_value);

} // appl_store()
#endif /* #if defined INC_APPL_TYPES_H */

//
//
//
static
inline
unsigned long int
appl_sign_convert_to_unsigned(
    signed long int const
        i_value)
{
    return
        static_cast<unsigned long int>(
            i_value);
} // appl_sign_convert_l()

//
//
//
static
inline
signed long int
appl_sign_convert_to_signed(
    unsigned long int const
        u_value)
{
    return
        static_cast<signed long int>(
            u_value);
} // appl_sign_convert_u()

/* end-of-file: appl_convert.h */

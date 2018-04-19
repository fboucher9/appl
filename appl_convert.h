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
}

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

}

/* end-of-file: appl_convert.h */

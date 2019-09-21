/* See LICENSE for license details */

/*

*/

#include <appl_status.h>

#include <buf/appl_bytes_descriptor.h>

#include <appl_unused.h>

//
//
//
class appl_bytes_descriptor_service
{
    public:

        static
        void
            s_init(
                struct appl_bytes_descriptor * const
                    p_descriptor);

    private:

        static
        enum appl_status
            s_consume(
                void * const
                    p_void,
                unsigned char * const
                    r_value);

        static
        enum appl_status
            s_produce(
                void * const
                    p_void,
                unsigned char const
                    i_value);

}; // class appl_bytes_descriptor_service

//
//
//
void
    appl_bytes_descriptor_service::s_init(
        struct appl_bytes_descriptor * const
            p_descriptor)
{
    p_descriptor->p_consume =
        &(
            appl_bytes_descriptor_service::s_consume);

    p_descriptor->p_produce =
        &(
            appl_bytes_descriptor_service::s_produce);

    p_descriptor->p_void =
        0;

} // s_init()

//
//
//
enum appl_status
    appl_bytes_descriptor_service::s_consume(
        void * const
            p_void,
        unsigned char * const
            r_value)
{
    appl_unused(
        p_void,
        r_value);

    return
        appl_raise_not_implemented();

} // s_consume()

//
//
//
enum appl_status
    appl_bytes_descriptor_service::s_produce(
        void * const
            p_void,
        unsigned char const
            i_value)
{
    appl_unused(
        p_void,
        i_value);

    return
        appl_raise_not_implemented();

} // s_produce()

//
//
//
void
    appl_bytes_descriptor_init(
        struct appl_bytes_descriptor * const
            p_descriptor)
{
    appl_bytes_descriptor_service::s_init(
        p_descriptor);

} // appl_bytes_descriptor_init()

/* end-of-file: appl_bytes_descriptor.cpp */

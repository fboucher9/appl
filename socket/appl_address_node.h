/* See LICENSE for license details */

/*

Module: appl_address_node.h

Description:

    Base interface for address objects.

*/

/* Reverse include guard */
enum guard_appl_address_node_h
{
    inc_appl_address_node_h = 1
        /* Header file dependency */
        + inc_appl_object_h
};

/* Predefine */
struct appl_address;

/* Assert compiler */
#if ! defined __cplusplus
#error use c++ compiler
#endif /* #if ! defined __cplusplus */

//
//  Class: appl_address
//
//  Description:
//      Base interface for address objects.
//
struct appl_address : public appl_object
{
    public:

        appl_address(
            struct appl_context * const
                p_context);

        virtual
        ~appl_address();

        virtual
        enum appl_status
            v_get_name_len(
                unsigned long int * const
                    r_name_len) const;

        virtual
        enum appl_status
            v_get_name(
                unsigned char * const
                    p_name_min,
                unsigned char * const
                    p_name_max,
                unsigned char * * const
                    r_name_cur) const;

        virtual
        enum appl_status
            v_get_port(
                unsigned short int * const
                    r_port) const;

        virtual
        enum appl_status
            v_get_family(
                int * const
                    r_family) const;

        virtual
        enum appl_status
            v_get_index(
                unsigned int * const
                    r_index) const;

    protected:

    private:

        appl_address(
            struct appl_address const & r);

        struct appl_address &
            operator =(
                struct appl_address const & r);

}; // struct appl_address

/* end-of-file: appl_address_node.h */

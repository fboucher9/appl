/* See LICENSE for license details */

/*

*/

/* Included. */
#define INC_APPL_DICT_H

/* Reverse include guard */
enum guard_appl_dict_h
{
    inc_appl_dict_h =
        /* Header file dependencies */
        inc_appl_status_h
        + inc_appl_object_h
};

//
//
//
struct appl_dict : public appl_object
{
    public:

        virtual
        enum appl_status
            v_set(
                unsigned char const * const
                    p_name_min,
                unsigned char const * const
                    p_name_max,
                void * const
                    p_value);

        virtual
        enum appl_status
            v_get(
                unsigned char const * const
                    p_name_min,
                unsigned char const * const
                    p_name_max,
                void * * const
                    r_value);

    protected:

        appl_dict();

        virtual
        ~appl_dict();

    private:

        appl_dict(
            struct appl_dict const & r);

        struct appl_dict &
            operator =(
                struct appl_dict const & r);

}; // struct appl_dict

/* end-of-file: appl_dict.h */

/* See LICENSE for license details */

/*

*/

/* Reverse include guard */
enum guard_appl_netdevice_mgr_h
{
    inc_appl_netdevice_mgr_h = 1
        /* Header file dependencies */
        + inc_appl_object_h

}; /* enum guard_appl_netdevice_mgr_h */

/* Included. */

/* Predefine */
struct appl_context;

/* Predefine */
struct appl_netdevice_descriptor;

//
//
//
class appl_netdevice_mgr : public appl_object
{
    public:

        appl_netdevice_mgr(
            struct appl_context * const
                p_context);

        virtual
        ~appl_netdevice_mgr();

        enum appl_status
            f_init(void);

        virtual
        appl_size_t
            v_cleanup(void);

        virtual
        enum appl_status
            v_enumerate(
                struct appl_netdevice_descriptor const * const
                    p_netdevice_filter,
                void (* p_callback)(
                    void * const
                        p_callback_context,
                    struct appl_netdevice_descriptor const * const
                        p_netdevice_descriptor),
                void * p_callback_context);

    protected:

    private:

        appl_netdevice_mgr(
            class appl_netdevice_mgr const & r);

        class appl_netdevice_mgr &
            operator =(
                class appl_netdevice_mgr const & r);

}; // class appl_netdevice_mgr

/* See LICENSE for license details */

/*

*/

/* Reverse include guard */
enum guard_appl_refcount_impl_h
{
    inc_appl_refcount_impl_h =
    inc_appl_refcount_h
};

//
//
//
class appl_refcount_impl
{
    public:

        appl_refcount_impl();

        ~appl_refcount_impl();

        enum appl_status
            f_init(void);

        enum appl_status
            f_cleanup(void);

    protected:

        struct appl_mutex *
            m_mutex;

        void *
            pv_padding[1u];

        // --

        signed long int
            m_count;

        unsigned long int
            ul_padding[1u];

    private:

        appl_refcount_impl(
            class appl_refcount_impl const & r);

        class appl_refcount_impl &
            operator =(
                class appl_refcount_impl const & r);

}; // class appl_refcount_impl

/* end-of-file: appl_refcount_impl.h */

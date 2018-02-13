
class appl_mutex_std_mgr;

//
//
//
class appl_mutex_std_mgr : public appl_mutex_mgr
{
    public:

        static
        enum appl_status
            create_instance(
                class appl_context * const
                    p_context,
                class appl_mutex_mgr * * const
                    r_mutex_mgr);

    protected:

        appl_mutex_std_mgr();

        virtual
        ~appl_mutex_std_mgr();

    private:

        appl_mutex_std_mgr(
            class appl_mutex_std_mgr const & r);

        class appl_mutex_std_mgr &
            operator =(
                class appl_mutex_std_mgr const & r);

}; // class appl_mutex_std_mgr

/* end-of-file: appl_mutex_std_mgr.h */

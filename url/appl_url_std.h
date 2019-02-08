
//
//
//
class appl_url_std : public appl_url
{
    public:

        appl_url_std(
            struct appl_context * const
                p_context);

        virtual
        ~appl_url_std();

    protected:

    private:

        appl_url_std(
            class appl_url_std const & r);

        class appl_url_std &
            operator =(
                class appl_url_std const & r);

}; // class appl_url_std


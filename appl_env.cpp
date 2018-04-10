/* See LICENSE for license details */

{
    public:

        virtual
        enum appl_status
            v_get(
                unsigned char const * const
                    p_name_min,
                unsigned char const * const
                    p_name_max,
                struct appl_string_handle * * const
                    r_string_handle);

        virtual
        enum appl_status
            s_set(
                unsigned char const * const
                    p_name_min,
                unsigned char const * const
                    p_name_max,
                unsigned char const * const
                    p_value_min,
                unsigned char const * const
                    p_value_max);

    protected:

        appl_env();

        virtual
        ~appl_env();

    private:

        appl_env(
            class appl_env const & r);

        class appl_env &
            operator =(
                class appl_env const & r);

}; // class appl_env

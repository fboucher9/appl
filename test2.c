
#include <appl.h>

static
enum appl_status
test2(
    struct appl_context * const
        p_context,
    struct appl_options const * const
        p_options)
{
    (void)(p_context);
    (void)(p_options);
    return appl_status_fail;
}

int main(
    int argc,
    char * * argv)
{
    appl_main_std(
        (unsigned char const * const *)(argv),
        (unsigned char const * const *)(argv+argc),
        &(test2));
}

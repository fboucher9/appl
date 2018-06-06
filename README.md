# appl

application library

## modules

*appl_context* - appl library handle and base object used to call all
functions.

*appl_heap* - allocate and free system memory.

*appl_debug* - break to debugger and print debugging messages.

*appl_clock* - read of precision timer and sleep operations.

*appl_file* - file input and output.

*appl_thread* - start and stop of asynchronous tasks.

*appl_mutex* - mutex synchronization object.

*appl_event* - event or conditional synchronization object.

*appl_random* - random number generation.

*appl_list* - linked list.

*appl_socket* - network input and output.

*appl_address* - network address and port information.

*appl_env* - access to process environment block.

*appl_options* - query of program arguments.

*appl_main* - program entry point.

## example

```
#include <appl.h>
enum appl_status appl_main(struct appl_context * p_context)
{
#if defined APPL_DEBUG
    appl_debug_print0(
        (unsigned char const *)(
            "appl_main..."));
#endif /* #if defined APPL_DEBUG */
    return appl_status_ok;
}
```

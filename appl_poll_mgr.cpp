
//
//
//
void
    appl_poll_mgr::thread_handler(void)
{
    // create a pollfd table

    p_mutex_node->lock();

    // count number of elements
    struct appl_iterator
        o_iterator;

    appl_iterator_init(
        &(
            o_iterator),
        &(
            m_nodes));

    unsigned int
        i_poll_table_count;

    i_poll_table_count =
        0u;

    while (
        appl_iterator_next(
            &(
                o_iterator)))
    {
        class appl_poll_node * const
            p_poll_node =
            reinterpret_cast<class appl_poll_node *>(
                o_iterator.p_cur + 1);

        if (
            p_poll_node->m_avail)
        {
            i_poll_table_count ++;
        }
    }

    // allocate an array
    p_heap =
        m_context->m_heap;

    struct appl_buf
        o_poll_table_allocation;

    e_status =
        p_heap->alloc_memory(
            &(
                o_poll_table_allocation),
            static_cast<unsigned long int>(
                sizeof(
                    struct pollfd)
                * i_poll_table_count));

    if (
        appl_status_ok
        == e_status)
    {
        // fill array(s)
        appl_iterator_init(
            &(
                o_iterator),
            &(
                m_nodes));

        unsigned int
            i_index;

        i_index =
            0u;

        while (
            appl_iterator_next(
                &(
                    o_iterator)))
        {
            class appl_poll_node * const
                p_poll_node =
                reinterpret_cast<class appl_poll_node *>(
                    o_iterator.p_cur + 1);

            if (
                p_poll_node->m_avail)
            {
                p_poll_node->m_used =
                    true;

                p_poll_table[i_index] =
                    p_poll_node->m_fd;
            }
        }
    }

    p_mutex_node->unlock();

    i_poll_result =
        poll(
            p_poll_table,
            i_poll_table_count);

    // dispatch callbacks...

    p_mutex_node->lock();

    // release the nodes

    p_mutex_node->unlock();

} // thread_handler()

void *
    appl_poll_mgr::thread_entry(
        void * const
            p_thread_context)
{
    class appl_poll_mgr *
        p_poll_mgr;

    p_poll_mgr =
        static_cast<class appl_poll_mgr *>(
            p_thread_context);

    p_poll_mgr->thread_handler();

    return
        static_cast<void *>(
            0);

} // thread_entry()

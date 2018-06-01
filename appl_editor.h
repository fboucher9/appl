/* See LICENSE for license details */

/*

*/

struct appl_editor_iterator
{
    struct appl_editor *
        p_editor;

    struct appl_editor_node *
        p_node;

    unsigned char
        i_offset;

};

struct appl_editor_node
{
    struct appl_list
        o_list;

    /* -- */

    unsigned char
        i_start_offset;

    unsigned char
        i_end_offset;

    unsigned char
        i_data_length;

    unsigned char
        uc_padding[5u];

    /* -- */

    unsigned char
        a_data[32u];

};

struct appl_editor
{
    struct appl_list
        o_nodes;

    /* -- */

    unsigned long int
        i_node_count;

    unsigned long int
        i_total_count;

    /* -- */

    unsigned long int
        i_total_unused;

    unsigned long int
        ul_padding[1u];

};

static
enum appl_status
pop_head(
    struct appl_editor * const
        p_editor,
    struct appl_editor_node * const
        p_node,
    unsigned char * const
        r_value)
{
    enum appl_status
        e_status;

    if (
        p_node->i_data_length)
    {
        *(
            r_value) =
            p_node->a_data[p_node->i_start_offset];

        p_node->i_data_length --;

        p_node->i_start_offset ++;

        if (32u <= p_node->i_start_offset)
        {
            p_node->i_start_offset = 0u;
        }

        e_status =
            appl_status_ok;
    }
    else
    {
        e_status =
            appl_status_fail;
    }

    return
        e_status;

}

static
enum appl_status
pop_tail(
    struct appl_editor * const
        p_editor,
    struct appl_editor_node * const
        p_node,
    unsigned char * const
        r_value)
{
    enum appl_status
        e_status;

    if (
        p_node->i_data_length)
    {
        if (p_node->i_end_offset)
        {
            p_node->i_end_offset --;
        }
        else
        {
            p_node->i_end_offset = 32u - 1u;
        }

        *(
            r_value) =
            p_node->a_data[p_node->i_end_offset];

        p_node->i_data_length --;

        e_status =
            appl_status_ok;
    }
    else
    {
        e_status =
            appl_status_fail;
    }

    return
        e_status;

}

static
enum appl_status
push_head(
    struct appl_editor * const
        p_editor,
    struct appl_editor_node * const
        p_node,
    unsigned char const
        c_value)
{
    enum appl_status
        e_status;

    if (
        32u > p_node->i_data_length)
    {
        if (p_node->i_start_offset)
        {
            p_node->i_start_offset --;
        }
        else
        {
            p_node->i_start_offset = 32u - 1u;
        }

        p_node->a_data[p_node->i_start_offset] =
            c_value;

        p_node->i_data_length ++;

        e_status =
            appl_status_ok;
    }
    else
    {
        e_status =
            appl_status_fail;
    }

    return
        e_status;

}

static
enum appl_status
push_tail(
    struct appl_editor * const
        p_editor,
    struct appl_editor_node * const
        p_node,
    unsigned char const
        c_value)
{
    enum appl_status
        e_status;

    if (
        32u > p_node->i_data_length)
    {
        p_node->a_data[p_node->i_end_offset] =
            c_value;

        p_node->i_data_length ++;

        p_node->i_end_offset ++;

        if (32u <= p_node->i_end_offset)
        {
            p_node->i_end_offset = 0u;
        }

        e_status =
            appl_status_ok;
    }
    else
    {
        e_status =
            appl_status_fail;
    }

}

static
enum appl_status
insert_prev(
    struct appl_editor * const
        p_editor,
    struct appl_editor_node * const
        p_node,
    unsigned char const
        c_value)
{
    enum appl_status
        e_status;

    struct appl_editor_node *
        p_prev_node;

    p_prev_node =
        (struct appl_editor_node *)(
            p_node->o_list.p_prev);

    if (
        &(p_prev_node->o_list) != &(p_editor->o_nodes))
    {
        e_status =
            push_tail(
                p_editor,
                p_prev_node,
                c_value);

        if (
            appl_status_ok
            != e_status)
        {
            e_status =
                create_prev(
                    p_editor,
                    p_node,
                    c_value);
        }
    }
    else
    {
        e_status =
            create_prev(
                p_editor,
                p_node,
                c_value);
    }

    return
        e_status;

}

static
enum appl_status
insert_next(
    struct appl_editor * const
        p_editor,
    struct appl_editor_node * const
        p_node,
    unsigned char const
        c_value)
{
}

static
enum appl_status
insert_head(
    struct appl_editor * const
        p_editor,
    struct appl_editor_node * const
        p_node,
    unsigned char const
        c_value)
{
    enum appl_status
        e_status;

    e_status =
        push_head(
            p_editor,
            p_node,
            c_value);

    if (
        appl_status_ok
        != e_status)
    {
        e_status =
            insert_prev(
                p_editor,
                p_node,
                c_value);
    }

    return
        e_status;

}

static
enum appl_status
insert_tail(
    struct appl_editor * const
        p_editor,
    struct appl_editor_node * const
        p_node,
    unsigned char const
        c_value)
{
}

static
enum appl_status
shift_prev(
    struct appl_editor * const
        p_editor,
    struct appl_editor_node * const
        p_node,
    unsigned char const
        i_shift_count)
{
    enum appl_status
        e_status;

    unsigned char
        i_shift_iterator;

    i_shift_iterator =
        i_shift_count;

    e_status =
        appl_status_ok;

    while (
        (
            appl_status_ok
            == e_status)
        && (
            0 != i_shift_iterator))
    {
        unsigned char
            c_value;

        e_status =
            pop_head(
                p_editor,
                p_node,
                &(
                    c_value));

        if (
            appl_status_ok
            == e_status)
        {
            e_status =
                insert_prev(
                    p_editor,
                    p_node,
                    c_value);

            if (
                appl_status_ok
                == e_status)
            {
                i_shift_iterator --;
            }
        }
    }

    return
        e_status;

}

static
enum appl_status
shift_next(
    struct appl_editor * const
        p_editor,
    struct appl_editor_node * const
        p_node,
    unsigned char const
        i_shift_count)
{
}

static
enum appl_status
insert_at(
    struct appl_editor * const
        p_editor,
    struct appl_editor_node * const
        p_node,
    unsigned char const
        c_value,
    unsigned char const
        i_offset)
{
    enum appl_status
        e_status;

    if (
        (i_offset * 2) < p_node->i_data_length)
    {
        e_status =
            shift_prev(
                p_editor,
                p_node,
                i_offset);

        if (
            appl_status_ok
            == e_status)
        {
            e_status =
                insert_head(
                    p_editor,
                    p_node,
                    c_value);
        }
    }
    else
    {
        e_status =
            shift_next(
                p_editor,
                p_node,
                p_node->i_data_length - i_offset);

        if (
            appl_status_ok
            == e_status)
        {
            e_status =
                insert_tail(
                    p_editor,
                    p_node,
                    c_value);
        }
    }

    return
        e_status;

}

static
enum appl_status
delete_at(
    struct appl_editor * const
        p_editor,
    struct appl_editor_node * const
        p_node,
    unsigned char const
        i_offset)
{
}

enum appl_status
appl_editor_create(
    struct appl_context * const
        p_context,
    struct appl_editor * * const
        r_editor);

enum appl_status
appl_editor_destroy(
    struct appl_editor * const
        p_editor);

enum appl_status
appl_editor_iterator_init(
    struct appl_editor * const
        p_editor,
    struct appl_editor_iterator * const
        p_iterator);

enum appl_status
appl_editor_iterator_cleanup(
    struct appl_editor_iterator * const
        p_iterator);

enum appl_status
appl_editor_iterator_set_offset(
    struct appl_editor_iterator * const
        p_iterator,
    unsigned long int const
        i_offset);

enum appl_status
appl_editor_iterator_get_offset(
    struct appl_editor_iterator * const
        p_iterator,
    unsigned long int * const
        r_offset);

enum appl_status
appl_editor_iterator_delete(
    struct appl_editor_iterator * const
        p_iterator);

enum appl_status
appl_editor_iterator_insert(
    struct appl_editor_iterator * const
        p_iterator,
    unsigned char const
        c_value);

enum appl_status
appl_editor_iterator_read(
    struct appl_editor_iterator * const
        p_iterator,
    unsigned char * const
        r_value);

enum appl_status
appl_editor_iterator_right(
    struct appl_editor_iterator * const
        p_iterator);

enum appl_status
appl_editor_iterator_left(
    struct appl_editor_iterator * const
        p_iterator);

/* end-of-file: appl_editor.h */

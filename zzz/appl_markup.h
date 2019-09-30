
#if 0

tag : value
tracks {
    track {
        type = value
        width = value
        height = value
    track }
    track {
    track }
tracks }

unsigned char tag_id : 4u;
unsigned char tag_len : 4u;
unsigned char extra_id[]; /* 7-bit encoding */
unsigned char extra_len[]; /* 7-bit encoding */
unsigned char data[];

enum id_special
{
    id_0 = 0,
    id_14 = 14,
    id_15 = extra_id
};

enum value_special
{
    special_0 = null
    special_1 = len1
    special_2 = len2
    special_3 = len3
    ...
    special_8 = len8
    special_9 = false
    special_10 = true
    special_12 = number
    special_13 = begin
    special_14 = end
    special_15 = extra_len
};

struct extended_number
{
    unsigned char more_bytes : 1;
    unsigned char value : 7;
};

extended_marker[]
extended_id[]
extended_value[]
extended_len[]
payload[]
types:
    label
    number
    binary
    begin
    end

amf-style

    marker-label1-8, label[]

    marker-number1-8, number[]

    marker-binary1-8, len[], binary[]

    marker-begin1-8, label[]

    marker-end1-8, label[]

    marker-false

    marker-true

struct marker
{
    unsigned char type : 4u;
        label,
        number,
        binary,
        begin,
        end,
        false,
        true
    unsigned char len : 4u;
        0-8
};

config.version : 1
track.begin :
track.end :
track.index : 0
    track.type : video
    track.avcc : [ ... ]
    track.port : 6030
track.index : 1

program: begin
    track: begin
        type:
        number x
        avcc:
        binary []
    track: end
program: end

begin media
    label type
        number video
    label track
        number index
    label pts
        number value
    label dts
        number value
    label data
        binary buffer
end media

tag-len tag
value-len value

#endif

/*

object

    begin, name, value, name, value, end

array

    value, value, value

    name, value, value, value

*/

enum appl_markup_type
{
    appl_markup_type_name = 1,

    appl_markup_type_value = 2,

    appl_markup_type_begin = 3,

    appl_markup_type_end = 4

}; /* enumm appl_markup_type */

struct appl_markup_element
{
    enum appl_markup_type
        e_type;

    unsigned int
        ui_padding[3u];

    /* -- */

    struct appl_buf
        o_data;

    /* -- */

    unsigned char
        uc_reserved[8u];

};

struct appl_markup_decoder;

struct appl_markup_decoder_descriptor
{
    enum appl_status
        (* p_notify)(
            void * const
                p_void,
            struct appl_markup_element const * const
                p_element);

    void *
        p_void;

};

enum appl_status
appl_markup_decoder_create(
    struct appl_context * const
        p_context,
    struct appl_markup_decoder_descriptor const * const
        p_descriptor,
    struct appl_markup_decoder * * const
        r_instance);

enum appl_status
appl_markup_decoder_destroy(
    struct appl_markup_decoder * const
        p_instance);

enum appl_status
appl_markup_decoder_write(
    struct appl_markup_decoder * const
        p_instance,
    unsigned char const
        c_data);

struct appl_markup_encoder;

struct appl_markup_encoder_descriptor
{
    enum appl_status
        (* p_produce)(
            void * const
                p_void,
            unsigned char const
                c_data);

    void *
        p_void;

};

enum appl_status
appl_markup_encoder_create(
    struct appl_context * const
        p_context,
    struct appl_markup_encoder_descriptor const * const
        p_descriptor,
    struct appl_markup_encoder * * const
        r_instance);

enum appl_status
appl_markup_encoder_destroy(
    struct appl_markup_encoder * const
        p_instance);

enum appl_status
appl_markup_encoder_write(
    struct appl_markup_encoder * const
        p_instance,
    struct appl_markup_element const * const
        p_element);

#if 0

label or value

format short medium or long

struct appl_marker_element
{
    unsigned char
        b_type : 1;

    unsigned char
        e_format : 2;

    unsigned char
        i_data : 5;

};

enum appl_status
appl_markup_convert_to_binary(
    unsigned long int const
        i_value,
    struct appl_buf * const
        p_buffer);

enum appl_status
appl_markup_convert_to_integer(
    struct appl_buf const * const
        p_buffer,
    unsigned long int * const
        r_value);

enum appl_status
    appl_markup_encoder_write_label(
        struct appl_markup_encoder * const
            p_instance,
        struct appl_buf const * const
            p_binary);

enum appl_status
    appl_markup_encoder_write_value(
        struct appl_markup_encoder * const
            p_instance,
        struct appl_buf const * const
            p_binary);

typedef
enum appl_status
(appl_markup_decoder_notify_label)(
    void * const
        p_notify_context,
    struct appl_buf const * const
        p_binary);

typedef
enum appl_status
(appl_markup_decoder_notify_value)(
    void * const
        p_notify_context,
    struct appl_buf const * const
        p_binary);

struct appl_markup_element
{
    unsigned char b_type;
    unsigned char uc_padding[7u];
    /* -- */
    struct appl_buf o_buf;
};

enum appl_status
    appl_markup_decoder_read(
        struct appl_markup_decoder * const
            p_instance,
        struct appl_markup_element * const
            p_element);

#endif

/*

Markup File Format

1234 :
"1234" :
[1 2 3 4] :
1234
"1234"
[1 2 3 4]

*/



/*

AMF style markup

marker
    null
    true
    false
    number
    binary
    begin-object
    end-object
    begin-array
    end-array

struct appl_markup_special
{
    unsigned char marker : 4;
    unsigned char count : 4;
};

struct appl_markup_number
{
    unsigned char marker;
    unsigned char number[];
};

struct appl_markup_binary
{
    unsigned char marker;
    unsigned char length[];
    unsigned char payload[];
};

*/

#if 0
{
    "class" "ns_config_list"
    "version" 1234
    "configs"
    [
        {
            "index" 0
            "service" "server"
            "protocol" "rtsp"
            "port" 1234
            "tracks"
            [
                {
                    "type" "video"
                    "index" 0
                    "port" 1234
                    "headers"
                    [
                        "sps"
                        "pps"
                        "pps"
                        "pps"
                    ]
                }
                {
                    "type" "audio"
                    "index" 0
                    "port" 1234
                    "headers"
                    [
                        "asc"
                    ]
                }
                {
                    "type" "audio"
                    "index" 1
                }
            ]
        }
        {
            "index" 1
            "service" "client"
            "protocol" "rtmp"
            "tracks"
            [
                {
                }
                {
                }
            ]
        }
    ]
}
#endif


enum appl_markup_special
{
    /* Boolean false */
    appl_markup_special_false = 0,

    /* Boolean true */
    appl_markup_special_true = 1,

    /* Null value */
    appl_markup_special_null = 2,

    /* Begin a list of label and value pairs */
    appl_markup_special_begin_object = 3,

    /* End a list of label and value pairs */
    appl_markup_special_end_object = 4,

    /* Begin a list of values */
    appl_markup_special_begin_array = 5,

    /* End a list of values */
    appl_markup_special_end_array = 6,

    /* 1 byte of extra data */
    appl_markup_special_direct_1 = 7,

    /* 2 bytes of extra data */
    appl_markup_special_direct_2 = 8,

    /* 4 bytes of extra data */
    appl_markup_special_direct_4 = 9,

    /* 1 byte of data length */
    appl_markup_special_indirect_1 = 10,

    /* 2 bytes of data length */
    appl_markup_special_indirect_2 = 11,

    /* 4 bytes of data length */
    appl_markup_special_indirect_4 = 12

};

struct appl_markup_element
{
    unsigned char
        i_marker;

    struct appl_buf
        o_data;

};

struct appl_markup_decoder_descriptor
{
    enum appl_status
        (* p_consume)(
            void * const
                p_consume_void,
            unsigned char * const
                r_value);

    void *
        p_consume_void;

    /* -- */

    enum appl_status
        (* p_notify)(
            void * const
                p_notify_void,
            struct appl_markup_element const * const
                p_element);

    void *
        p_notify_void;

};

enum appl_status
    appl_markup_decoder_parse_object(
        struct appl_markup_decoder * const
            p_instance);

enum appl_status
    appl_markup_decoder_parse_array(
        struct appl_markup_decoder * const
            p_instance);

enum appl_status
    appl_markup_decoder_parse_label(
        struct appl_markup_decoder * const
            p_instance);

enum appl_status
    appl_markup_decoder_parse_value(
        struct appl_markup_decoder * const
            p_instance);

enum appl_status
    appl_markup_decoder_parse_member(
        struct appl_markup_decoder * const
            p_instance);

enum appl_status
    appl_markup_decoder_parse_element(
        struct appl_markup_decoder * const
            p_instance);


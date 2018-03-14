/* See LICENSE for license details */

/*

*/

struct appl_pci_handle;

struct appl_pci_descriptor
{
    unsigned short int
        i_segment_number;

    unsigned short int
        i_bus_number;

    unsigned short int
        i_device_number;

    unsigned short int
        i_function_number;

}; /* struct appl_pci_descriptor */

#define APPL_PCI_SCANINFO_FLAG_VENDOR_ID \
    0x00000001ul

#define APPL_PCI_SCANINFO_FLAG_DEVICE_ID \
    0x00000002ul

#define APPL_PCI_SCANINFO_FLAG_SUBSYS_VENDOR_ID \
    0x00000004ul

#define APPL_PCI_SCANINFO_FLAG_SUBSYS_DEVICE_ID \
    0x00000008ul

struct appl_pci_scaninfo
{
    struct appl_pci_handle *
        p_pci_handle;

    unsigned long int
        i_flags;

    unsigned short int
        i_vendor_id;

    unsigned short int
        i_device_id;

    unsigned short int
        i_subsys_vendor_id;

    unsigned short int
        i_subsys_device_id;

    unsigned char
        i_header_type;

    unsigned char
        i_class;

    unsigned char
        i_subclass;

    unsigned char
        i_interface;

    unsigned char
        i_revision;

}; /* struct appl_pci_scaninfo */

struct appl_pci_barinfo
{
    appl_ull_t
        i_address;

    appl_ull_t
        i_length;

    unsigned char
        i_index;

    unsigned char
        i_type;

    unsigned char
        i_prefetchable;

}; /* struct appl_pci_barinfo */



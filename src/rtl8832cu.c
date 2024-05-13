#include <linux/module.h>
#include <linux/pci.h>
#include <linux/usb.h>
#include "rtl8832cu.h"

// PCI device IDs
static const struct pci_device_id rtl8832cu_pci_ids[] = {
    { PCI_DEVICE(PCI_VENDOR_ID_REALTEK, PCI_DEVICE_ID_REALTEK_RTL8832CU) },
    { /* Add additional PCI device IDs if necessary */ },
    { }
};

// USB device IDs
static const struct usb_device_id rtl8832cu_usb_ids[] = {
    { USB_DEVICE(USB_VENDOR_ID_REALTEK, USB_DEVICE_ID_REALTEK_RTL8832CU) },
    { /* Add additional USB device IDs if necessary */ },
    { }
};

MODULE_DEVICE_TABLE(pci, rtl8832cu_pci_ids);
MODULE_DEVICE_TABLE(usb, rtl8832cu_usb_ids);

// PCI driver structure
static struct pci_driver rtl8832cu_pci_driver = {
    .name = "rtl8832cu_pci",
    .id_table = rtl8832cu_pci_ids,
    .probe = rtl8832cu_pci_probe,
    .remove = rtl8832cu_pci_remove,
};

// USB driver structure
static struct usb_driver rtl8832cu_usb_driver = {
    .name = "rtl8832cu_usb",
    .id_table = rtl8832cu_usb_ids,
    .probe = rtl8832cu_usb_probe,
    .disconnect = rtl8832cu_usb_disconnect,
};

// Module initialization function
static int __init rtl8832cu_module_init(void) {
    int err;

    err = pci_register_driver(&rtl8832cu_pci_driver);
    if (err)
        return err;

    err = usb_register(&rtl8832cu_usb_driver);
    if (err)
        pci_unregister_driver(&rtl8832cu_pci_driver);

    return err;
}

// Module cleanup function
static void __exit rtl8832cu_module_exit(void) {
    usb_deregister(&rtl8832cu_usb_driver);
    pci_unregister_driver(&rtl8832cu_pci_driver);
}

module_init(rtl8832cu_module_init);
module_exit(rtl8832cu_module_exit);

MODULE_LICENSE("GPL");
MODULE_AUTHOR("pabloe924");
MODULE_DESCRIPTION("RTL8832CU Wireless LAN Driver");
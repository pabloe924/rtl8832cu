#ifndef RTL8832CU_H
#define RTL8832CU_H

// Include necessary header files
#include <linux/types.h>
#include <linux/device.h>
#include <linux/usb.h> // For USB support
#include <linux/pci.h> // For PCI support

// Define device-specific constants
#define RTL8832CU_VENDOR_ID     0x10EC

#ifdef CONFIG_USB_RTL8832CU
// USB-specific constants
#define RTL8832CU_DEVICE_ID_USB     0x0883
#define RTL8832CU_NUM_ENDPOINTS     4

// USB-specific structure
struct rtl8832cu_priv {
    struct usb_interface *intf;
    struct usb_device *dev;
    struct urb *urb;

    // Add other USB-specific data members as needed
};

#define rtl8832cu_usb_probe(...)
#define rtl8832cu_usb_disconnect(...)
#define rtl8832cu_usb_configure(...)
#define rtl8832cu_usb_endpoint_config(...)

#else // CONFIG_PCI_RTL8832CU

// PCI-specific constants
#define RTL8832CU_DEVICE_ID_PCI     ... (define PCI device ID)

// PCI-specific structure (may differ from USB)
struct rtl8832cu_priv {
    struct pci_dev *pdev;

    // other PCI-specific data members
};

#define rtl8832cu_pci_probe(...)
#define rtl8832cu_pci_remove(...)
#define rtl8832cu_pci_configure(...)
#define rtl8832cu_pci_interrupt(...) // Optional, for PCI-specific interrupt handling

#endif // CONFIG_PCI_RTL8832CU

// Function prototypes common to PCI and USB (if any)

// Interrupt handler prototype (optional, can be here or in a separate file)
void rtl8832cu_interrupt(struct urb *urb);

#endif // RTL8832CU_H

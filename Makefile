obj-m += rtl8832cu.o
rtl8832cu-y := src/rtl8832cu.o src/rtl8832cu_pci.o src/rtl8832cu_usb.o

KERNEL_DIR := /lib/modules/$(shell uname -r)/build
PWD := $(shell pwd)

all:
    $(MAKE) -C $(KERNEL_DIR) M=$(PWD) modules

clean:
    $(MAKE) -C $(KERNEL_DIR) M=$(PWD) clean
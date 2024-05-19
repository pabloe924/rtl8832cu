obj-m += rtl8832cu.o
rtl8832cu-y := src/rtl8832cu.o src/rtl8832cu_pci.o src/rtl8832cu_usb.o

KERNEL_DIR := /lib/modules/$(shell uname -r)/build
PWD := $(shell pwd)

all:
	make -C /lib/modules/$(shell uname -r)/build M=$(PWD) modules

clean:
	make -C /lib/modules/$(shell uname -r)/build M=$(PWD) clean
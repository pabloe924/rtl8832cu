obj-m += rtl8832cu.o
rtl8832cu-objs := rtl8832cu.o rtl8832cu_pci.o rtl8832cu_usb.o

EXTRA_CFLAGS := -I$(PWD)/../include

all:
	make -C /lib/modules/$(shell uname -r)/build M=$(PWD) modules

clean:
	make -C /lib/modules/$(shell uname -r)/build M=$(PWD) clean

rtl8832cu.o: rtl8832cu.c ../include/rtl8832cu.h
rtl8832cu_pci.o: rtl8832cu_pci.c ../include/rtl8832cu.h
rtl8832cu_usb.o: rtl8832cu_usb.c ../include/rtl8832cu.h
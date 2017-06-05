#
#  Configure:
#  source /opt/yocto/poky/2.2/environment-setup-core2-32-poky-linux
#
#  Compile:
#  KERNELDIR=/opt/yocto/poky-morty-16.0.0/build/tmp/work/genericx86-poky-linux/linux-yocto/4.8.3+gitAUTOINC+83110d94ed_1adf9d3633-r0/linux-genericx86-standard-build make
#
#

ifeq ($(KERNELRELEASE),)

# Assume the source tree is where the running kernel was built
# You should set KERNELDIR in the environment if it's elsewhere
	KERNELDIR ?= /lib/modules/$(shell uname -r)/build
# The current directory is passed to sub-makes as argument
	PWD := $(shell pwd)

modules:
	$(MAKE) -C $(KERNELDIR) M=$(PWD) modules
	cp altera_driver.ko /opt/tftp

modules_install:
	$(MAKE) -C $(KERNELDIR) M=$(PWD) modules_install

clean:
	rm -rf *.o *~ core .depend .*.cmd *.ko *.mod.c .tmp_versions modules.order Module.symvers

.PHONY: modules modules_install clean

else
# called from kernel build system: just declare what our modules are
	obj-m := altera_driver.o 
endif

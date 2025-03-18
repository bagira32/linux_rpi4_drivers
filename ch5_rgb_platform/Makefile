obj-m := ledRGB_rpi4_platform.o

KERNEL_DIR ?= /home/bagira/git/linux

all:
	make -C $(KERNEL_DIR) \
		ARCH=arm64 CROSS_COMPILE=aarch64-linux-gnu-\
		M=$(PWD) modules

clean:
	make -C $(KERNEL_DIR) \
		ARCH=arm64 CROSS_COMPILE=aarch64-linux-gnu- \
		M=$(PWD) clean

deploy:
	scp *.ko bagira@192.168.1.42:/home/bagira

CC = aarch64-linux-gnu-gcc
all: ioctl_test

app : ioctl_test.c
	$(CC) -o $@ $^
clean :
	rm ioctl_test
deploy : ioctl_test
	cp $^ /tmp

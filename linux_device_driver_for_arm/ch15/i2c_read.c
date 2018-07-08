#include <stdio.h>
#include <linux/types.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/ioctl.h>
#include <linux/i2c.h>
#include <linux/i2c-dev.h>

int main(int argc, char *argv[])
{
	unsigned int fd;
	unsigned short mem_addr;
	unsigned short size;
	unsigned short idx;
#define BUFF_SIZE 32
	char buf[BUFF_SIZE];
	char cswap;
	ssize_t ret;
	union {
		unsigned short addr;
		char bytes[2];
	} tmp;

	if (argc < 3) {
		printf("Use:\n%s /dev/i2c-x mem_addr size\n", argv[0]);
		return 0;
	}
	sscanf(argv[2], "%hu", &mem_addr);
	sscanf(argv[3], "%hu", &size);

	if (size > BUFF_SIZE)
		size = BUFF_SIZE;

	fd = open(argv[1], O_RDWR);
	if (!fd) {
		printf("Error on opening the device file\n");
		return 0;
	}

	ioctl(fd, I2C_SLAVE, 0x50);	/* EEPROM address */
	ioctl(fd, I2C_TIMEOUT, 1);
	ioctl(fd, I2C_RETRIES, 1);

	for (idx = 0; idx < size; ++idx, ++mem_addr) {
		tmp.addr = mem_addr;
		cswap = tmp.bytes[0];
		tmp.bytes[0] = tmp.bytes[1];
		tmp.bytes[1] = cswap;
		ret = write(fd, &tmp.addr, 2);
		if (ret != 2) {
			printf("write error: %zd\n", ret);
			break;
		}
		ret = read(fd, &buf[idx], 1);
		if (ret != 1) {
			printf("read error: %zd\n", ret);
			break;
		}
	}
	buf[size] = 0;
	close(fd);
	printf("Read %d char: %s\n", size, buf);

	return 0;
}

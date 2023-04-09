#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <elf.h>

/**
 * _magic_print - prints magic info.
 * @p: char pointer.
 * Return: nothing.
 */
void _magic_print(char *p)
{
	int byt;

	printf("  Magic:  ");

	for (byt = 0; byt < 16; byt++)
		printf(" %02x", p[byt]);

	printf("\n");

}

/**
 * _data_print - prints data
 * @p: char pointer.
 * Return: nothing.
 */
void _data_print(char *p)
{
	char dat = p[5];

	printf("  Data:                              2's complement");
	if (dat == 1)
		printf(", little endian\n");

	if (dat == 2)
		printf(", big endian\n");
}

/**
 * _ver_print - prints version
 * @p: char pointer.
 * Return: no return.
 */
void _ver_print(char *p)
{
	int ver = p[6];

	printf("  Version:                           %d", ver);

	if (ver == EV_CURRENT)
		printf(" (current)");

	printf("\n");
}

/**
 * _osabi_print - prints OS/ABI
 * @p: char pointer.
 * Return: no return.
 */
void _osabi_print(char *p)
{
	char os_abi = p[7];

	printf("  OS/ABI:                            ");
	if (os_abi == 0)
		printf("UNIX - System V\n");
	else if (os_abi == 2)
		printf("UNIX - NetBSD\n");
	else if (os_abi == 6)
		printf("UNIX - Solaris\n");
	else
		printf("<unknown: %x>\n", os_abi);

	printf("  ABI Version:                       %d\n", p[8]);
}

/**
 * _type_print - prints type
 * @p: char pointer.
 * Return: nothing.
 */
void _type_print(char *p)
{
	char type;

	if (p[5] == 1)
		type = p[16];
	else
		type = p[17];

	printf("  Type:                              ");
	if (type == 0)
		printf("NONE (No file type)\n");
	else if (type == 1)
		printf("REL (Relocatable file)\n");
	else if (type == 2)
		printf("EXEC (Executable file)\n");
	else if (type == 3)
		printf("DYN (Shared object file)\n");
	else if (type == 4)
		printf("CORE (Core file)\n");
	else
		printf("<unknown: %x>\n", type);
}

/**
 * _address_print - prints memory address
 * @p: char pointer.
 * Return: nothing.
 */
void _address_print(char *p)
{
	int start, j;
	char syst;

	printf("  Entry point address:               0x");

	syst = p[4] + '0';
	if (syst == '1')
	{
		start = 26;
		printf("80");
		for (j = start; j >= 22; j--)
		{
			if (p[j] > 0)
				printf("%x", p[j]);
			else if (p[j] < 0)
				printf("%x", 256 + p[j]);
		}
		if (p[7] == 6)
			printf("00");
	}

	if (syst == '2')
	{
		start = 26;
		for (j = start; j > 23; j--)
		{
			if (p[j] >= 0)
				printf("%02x", p[j]);

			else if (p[j] < 0)
				printf("%02x", 256 + p[j]);

		}
	}
	printf("\n");
}


/**
 * _syst_check - check the version system.
 * @p: char pointer.
 * Return: nothing.
 */
void _syst_check(char *p)
{
	char syst = p[4] + '0';

	if (syst == '0')
		exit(98);

	printf("ELF Header:\n");
	_magic_print(p);

	if (syst == '1')
		printf("  Class:                             ELF32\n");

	if (syst == '2')
		printf("  Class:                             ELF64\n");

	_data_print(p);
	_ver_print(p);
	_osabi_print(p);
	_type_print(p);
	_address_print(p);
}

/**
 * _elf_check - check if it is an elf file.
 * @p: char pointer.
 * Return: 1 if it's elf file, elso 0.
 */
int _elf_check(char *p)
{
	int add = (int)p[0];
	char E = p[1];
	char L = p[2];
	char F = p[3];

	if (add == 127 && E == 'E' && L == 'L' && F == 'F')
		return (1);

	return (0);
}

/**
 * _close_fd - Closes an ELF file. If fails, exit 98
 * @fd: file descriptor of the ELF file.
 */
void _close_fd(int fd)
{
	if (close(fd) == -1)
	{
		dprintf(STDERR_FILENO,
			"Error: Can't close fd %d\n", fd);
		exit(98);
	}
}

/**
 * main - Entry  point.
 * @argc: number of CL arguments.
 * @argv: array of CL arguments.
 * Return: Always 0.
 */
int main(int argc, char *argv[])
{
	int fd, r_ret;
	char p[27];

	if (argc != 2)
	{
		dprintf(STDERR_FILENO, "Usage: elf_header elf_filename\n");
		exit(98);
	}

	fd = open(argv[1], O_RDONLY);

	if (fd < 0)
	{
		dprintf(STDERR_FILENO, "Err: file can not be open\n");
		exit(98);
	}

	lseek(fd, 0, SEEK_SET);
	r_ret = read(fd, p, 27);

	if (r_ret == -1)
	{
		dprintf(STDERR_FILENO, "Err: The file can not be read\n");
		exit(98);
	}

	if (!_elf_check(p))
	{
		dprintf(STDERR_FILENO, "Err: It is not an ELF\n");
		exit(98);
	}

	_syst_check(p);

	_close_fd(fd);

	return (0);
}


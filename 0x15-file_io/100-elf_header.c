#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <elf.h>

/**
 * _check_elf - Checks if a file is an ELF file.
 * @p: A pointer to e_ident of ELF header data structure.
 */
void _check_elf(unsigned char *p)
{
	int j = 0;

	for ( ; j < 4; j++)
	{
		if (p[j] != 127 && p[j] != 'E' && p[j] != 'L' && p[j] != 'F')
		{
			dprintf(STDERR_FILENO, "Error: Not an ELF file\n");
			exit(98);
		}
	}
}

/**
 *_print_magic - Prints the ELF header magic number.
 * @p: A pointer to e_ident of ELF header data structure.
 */
void _print_magic(unsigned char *p)
{
	int j = 0;

	printf("  Magic:   ");

	for (; j < EI_NIDENT; j++)
	{
		printf("%02x", p[j]);

		if (j == EI_NIDENT - 1)
			printf("\n");
		else
			printf(" ");
	}
}

/**
 * _print_class - Prints the ELF header class.
 * @p: A pointer to e_ident of ELF header data structure.
 */
void _print_class(unsigned char *p)
{
	printf("  Class:                             ");

	switch (p[EI_CLASS])
	{
	case ELFCLASSNONE:
		printf("none\n");
		break;
	case ELFCLASS32:
		printf("ELF32\n");
		break;
	case ELFCLASS64:
		printf("ELF64\n");
		break;
	default:
		printf("<unknown: %x>\n", p[EI_CLASS]);
	}
}

/**
 * _print_data - Prints the ELF header data.
 * @p: A pointer to e_ident of ELF header data structure.
 */
void _print_data(unsigned char *p)
{
	printf("  Data:                              ");

	switch (p[EI_DATA])
	{
	case ELFDATANONE:
		printf("none\n");
		break;
	case ELFDATA2LSB:
		printf("2's complement, little endian\n");
		break;
	case ELFDATA2MSB:
		printf("2's complement, big endian\n");
		break;
	default:
		printf("<unknown: %x>\n", p[EI_CLASS]);
	}
}

/**
 * _print_ver - Prints the ELF header type.
 * @p: A pointer to e_ident of ELF header data strucutre.
 */
void _print_ver(unsigned char *p)
{
	printf("  Version:                           %d",
	       p[EI_VERSION]);

	switch (p[EI_VERSION])
	{
	case EV_CURRENT:
		printf(" (current)\n");
		break;
	default:
		printf("\n");
		break;
	}
}

/**
 * _print_osabi - Prints the ELF header OS/ABI.
 * @p: A pointer to e_ident of ELF header data structure.
 */
void _print_osabi(unsigned char *p)
{
	printf("  OS/ABI:                            ");

	switch (p[EI_OSABI])
	{
	case ELFOSABI_NONE:
		printf("UNIX - System V\n");
		break;
	case ELFOSABI_HPUX:
		printf("UNIX - HP-UX\n");
		break;
	case ELFOSABI_NETBSD:
		printf("UNIX - NetBSD\n");
		break;
	case ELFOSABI_LINUX:
		printf("UNIX - Linux\n");
		break;
	case ELFOSABI_SOLARIS:
		printf("UNIX - Solaris\n");
		break;
	case ELFOSABI_IRIX:
		printf("UNIX - IRIX\n");
		break;
	case ELFOSABI_FREEBSD:
		printf("UNIX - FreeBSD\n");
		break;
	case ELFOSABI_TRU64:
		printf("UNIX - TRU64\n");
		break;
	case ELFOSABI_ARM:
		printf("ARM\n");
		break;
	case ELFOSABI_STANDALONE:
		printf("Standalone App\n");
		break;
	default:
		printf("<unknown: %x>\n", p[EI_OSABI]);
	}

	printf("  ABI Version:                       %d\n",
	       p[EI_ABIVERSION]);
}

/**
 * _print_type - Prints the type of an ELF header.
 * @type: The e_type of ELF header data structure.
 * @p: A pointer to e_ident of ELF header data structure.
 */
void _print_type(unsigned int type, unsigned char *p)
{
	if (p[EI_DATA] == ELFDATA2MSB)
		type >>= 8;

	printf("  Type:                              ");

	switch (type)
	{
	case ET_NONE:
		printf("NONE (None)\n");
		break;
	case ET_REL:
		printf("REL (Relocatable file)\n");
		break;
	case ET_EXEC:
		printf("EXEC (Executable file)\n");
		break;
	case ET_DYN:
		printf("DYN (Shared object file)\n");
		break;
	case ET_CORE:
		printf("CORE (Core file)\n");
		break;
	default:
		printf("<unknown: %x>\n", type);
	}
}

/**
 * _print_address - Prints the ELF header entry point.
 * @add: The e_entry of ELF header data structure.
 * @p: A pointer to e_ident of ELF header data structure.
 */
void _print_address(unsigned long int add, unsigned char *p)
{
	printf("  Entry point address:               ");

	if (p[EI_DATA] == ELFDATA2MSB)
	{
		add = ((add << 8) & 0xFF00FF00) |
			  ((add >> 8) & 0xFF00FF);
		add = (add << 16) | (add >> 16);
	}

	if (p[EI_CLASS] == ELFCLASS32)
		printf("%#x\n", (unsigned int) add);

	else
		printf("%#lx\n", add);
}

/**
 * _exit_status - Prints an error message and exit the program.
 * @str: The name the ELF file.
 */
void _exit_status(char *str)
{
	dprintf(STDERR_FILENO, "Error: Can't read/close file %s\n", str);
	exit(98);
}

/**
 * main - Displays specified information on ELF header to STDOUT.
 * @argc: The number of CL arguments.
 * @argv: A string array of CL arguments.
 * Return: 0 on success. Exit with code 98 if fails.
 */
int main(int argc, char *argv[])
{
	Elf64_Ehdr *elfh;
	int fd, r_count, len;

	if (argc != 2)
		_exit_status(argv[1]);

	len = sizeof(Elf64_Ehdr);
	elfh = malloc(len);
	if (elfh == NULL)
		_exit_status(argv[1]);

	fd = open(argv[1], O_RDONLY);
	if (fd == -1)
	{
		free(elfh);
		_exit_status(argv[1]);
	}

	r_count = read(fd, elfh, len);
	if (r_count == -1)
	{
		free(elfh);
		close(fd);
		_exit_status(argv[1]);
	}

	_check_elf(elfh->e_ident);
	printf("ELF Header:\n");
	_print_magic(elfh->e_ident);
	_print_class(elfh->e_ident);
	_print_data(elfh->e_ident);
	_print_ver(elfh->e_ident);
	_print_osabi(elfh->e_ident);
	_print_type(elfh->e_type, elfh->e_ident);
	_print_address(elfh->e_entry, elfh->e_ident);

	free(elfh);
	close(fd);
	return (0);
}

#include <elf.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include "main.h"
/*
 * e_ident[] - IDENTIFICATION INDEXES
 *
 * Description: These indexes contain the initial
 * bytes that uniquely identify
 * the file as an ELF object file. They
 * provide machine-independent
 * formation about the file's format and structure.
*/

/**
 * check_if_elf - Checks if a file is an ELF
 * file by verifying its magic numbers.
 *
 * @e_ident: A pointer to an array of bytes
 * specifying how to interpret the file.
 *
 * Return: Nothing.
*/
void check_if_elf(unsigned char *e_ident)
{
	int in = 0;

	while (in < 4)
	{
		if (e_ident[in] != 127 &&
		    e_ident[in] != 'E' &&
		    e_ident[in] != 'L' &&
		    e_ident[in] != 'F') /*0x7F is 127 in ASCII*/
		{
			dprintf(STDERR_FILENO, "Error: Not an ELF file\n");
			exit(98);
		}

		in++;
	}
}

/**
 * print_magic - Displays the ELF file's unique identifier bytes.
 *
 * @e_ident: Pointer to the file's identification
 * bytes, used to verify ELF format.
 *
 * Return: None
 */
void print_magic(unsigned char *e_ident)
{
	int i = 0;

	printf("  Magic    ");

	while (i < EI_NIDENT)
	{
		printf("%02x", e_ident[i]);

		if (i == EI_NIDENT - 1)
			printf("\n");
		else
			printf(" ");

		i++;
	}
}
/**
 * print_class - Displays whether the ELF file is 32-bit or 64-bit.
 *
 * @e_ident: Pointer to the ELF header's identification bytes.
 *
 * Return: None
 */
void print_class(unsigned char *e_ident)
{
	printf("  Class:                             ");

	switch (e_ident[EI_CLASS]) /*EI_CLASS - File class*/
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
			printf("<unknown: %x>\n", e_ident[EI_CLASS]);
	}
}
/**
 * print_data - Displays the ELF file's endianness (byte order).
 * This indicates how multi-byte data is stored in memory.
 *
 * @e_ident: Pointer to the ELF header's identification bytes.
 *
 * Return: None
 */
void print_data(unsigned char *e_ident)
{
	printf("  Data:                              ");

	switch (e_ident[EI_DATA]) /*EI_DATA - Data encoding*/
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
			printf("<unknown: %x>\n", e_ident[EI_DATA]);
	}
}
/**
 * print_version - Displays the ELF specification version used by the file.
 *
 * @e_ident: Pointer to the ELF header's identification bytes.
 *
 * Return: None
 */
void print_version(unsigned char *e_ident)
{
	printf("  Version:                           ");

	if (e_ident[EI_VERSION] == EV_CURRENT)
		printf("%d (current)\n", e_ident[EI_VERSION]);
	else
		printf("%i\n", e_ident[EI_VERSION]);
}
/**
 * print_osabi - prints the OS/ABI of the ELF file
 *
 * @e_ident: a pointer to an array of bytes specifies
 *           how to interpret the file
 * Return: nothing
*/
void print_osabi(unsigned char *e_ident)
{
	printf("  OS/ABI:                            ");

	switch (e_ident[EI_OSABI])
	{
		case ELFOSABI_SYSV:
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
		case ELFOSABI_AIX:
			printf("UNIX - AIX\n");
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
			printf("<unknown: %x>\n", e_ident[EI_OSABI]);
	}
}
/**
 * print_abi - Displays the ABI version, which
 * influences the file's system compatibility.
 *
 * @e_ident: Pointer to the ELF header's identification bytes.
 *
 * Return: None
 */
void print_abi(unsigned char *e_ident)
{
	printf("  ABI Version:                       %d\n",
		e_ident[EI_ABIVERSION]);
}
/**
 * print_type -  Displays the ELF file's classification.
 *
 * @e_type: The object file type.
 * @e_ident: Pointer to the ELF header's identification bytes.
 *
 * Return: None
 */
void print_type(unsigned int e_type, unsigned char *e_ident)
{
	if (e_ident[EI_DATA] == ELFDATA2MSB)
		e_type >>= 8;

	printf("  Type:                              ");

	switch (e_type)
	{
		case ET_NONE:
			printf("NONE (Unknown type)\n");
			break;
		case ET_REL:
			printf("REL (Relocatable file)\n");
			break;
		case ET_EXEC:
			printf("EXEC (Exexutable file)\n");
			break;
		case ET_DYN:
			printf("DYN (Shared object file)\n");
			break;
		case ET_CORE:
			printf("CORE (Core file)\n");
			break;
		default:
			printf("<unknown: %x\n", e_type);
	}
}
/**
 * print_entry - Displays the memory address where
 * the ELF file's execution begins.
 *
 * @e_entry: The virtual memory address of the
 * program's starting point.
 * @e_ident: Pointer to the ELF header's identification bytes.
 *
 * Return: None
 */
void print_entry(unsigned long int e_entry, unsigned char *e_ident)
{
	printf("  Entry point address:               ");

	if (e_ident[EI_DATA] == ELFDATA2MSB)
	{
		e_entry = ((e_entry << 8) & 0xFF00FF00) |
			  ((e_entry >> 8) & 0xFF00FF);
		e_entry = (e_entry << 16) | (e_entry >> 16);
	}

	if (e_ident[EI_CLASS] == ELFCLASS32)
		printf("%#x\n", (unsigned int)e_entry);
	else
		printf("%#lx\n", e_entry);
}
/**
 * close_file - Releases the file descriptor associated with the ELF file.
 *
 * @elf_file: The file descriptor for the ELF file.
 *
 * Return: None
 */
void close_file(int elf_file)
{
	if (close(elf_file) == -1)
	{
		dprintf(STDERR_FILENO,
			"Error: Can't close fd %d\n", elf_file);
		exit(98);
	}
}

/**
 * main - This is main
 *
 * Description: elf_header_parser file
 *
 * @argc: argument one
 * @argv: argument two
 *
 * Return: Always 0 (success)
*/
int main(int __attribute__((__unused__)) argc, char *argv[])
{
	Elf64_Ehdr *elf;
	int elf_file, read_file;

	elf_file = open(argv[1], O_RDONLY);
	if (elf_file == -1)
	{
		dprintf(STDERR_FILENO, "Error: Can't read file %s\n", argv[1]);
		exit(98);
	}

	elf = malloc(sizeof(Elf64_Ehdr));
	if (elf == NULL)
	{
		close_file(elf_file);
		free(elf);
		dprintf(STDERR_FILENO, "Error: Can't read file %s\n", argv[1]);
		exit(98);
	}

	read_file = read(elf_file, elf, sizeof(Elf64_Ehdr));
	if (read_file == -1)
	{
		free(elf);
		close_file(elf_file);
		dprintf(STDERR_FILENO, "Error: `%s`: No such file\n", argv[1]);
		exit(98);
	}
	check_if_elf(elf->e_ident);
	printf("ELF Header:\n");
	print_magic(elf->e_ident);
	print_class(elf->e_ident);
	print_data(elf->e_ident);
	print_version(elf->e_ident);
	print_osabi(elf->e_ident);
	print_abi(elf->e_ident);
	print_type(elf->e_type, elf->e_ident);
	print_entry(elf->e_entry, elf->e_ident);
	free(elf);
	close_file(elf_file);
	return (0);
}

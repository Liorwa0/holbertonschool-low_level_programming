#include <elf.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>

void print_magic(unsigned char *e_ident);
void print_class(unsigned char *e_ident);
void print_data(unsigned char *e_ident);
void print_version(unsigned char *e_ident);
void print_osabi(unsigned char *e_ident);
void print_abi(unsigned char *e_ident);
void print_type(unsigned int e_type, unsigned char *e_ident);
void print_entry(unsigned long int e_entry, unsigned char *e_ident);

/**
 * print_header_info - calls print functions
 * @h: header pointer
 */
void print_header_info(Elf64_Ehdr *h)
{
	printf("ELF Header:\n");
	print_magic(h->e_ident);
	print_class(h->e_ident);
	print_data(h->e_ident);
	print_version(h->e_ident);
	print_osabi(h->e_ident);
	print_abi(h->e_ident);
	print_type(h->e_type, h->e_ident);
	print_entry(h->e_entry, h->e_ident);
}

/**
 * main - main function
 * @argc: arg count
 * @argv: arg vector
 * Return: 0
 */
int main(int argc, char *argv[])
{
	int fd;
	Elf64_Ehdr *h;

	if (argc != 2)
	{
		dprintf(STDERR_FILENO, "Usage: elf_header elf_filename\n");
		exit(98);
	}
	fd = open(argv[1], O_RDONLY);
	if (fd < 0)
	{
		dprintf(STDERR_FILENO, "Error: Can't open file\n");
		exit(98);
	}
	h = malloc(sizeof(Elf64_Ehdr));
	if (!h)
	{
		close(fd);
		exit(98);
	}
	if (read(fd, h, sizeof(Elf64_Ehdr)) < 1)
	{
		free(h);
		close(fd);
		dprintf(STDERR_FILENO, "Error: Can't read\n");
		exit(98);
	}
	if (h->e_ident[EI_MAG0] != ELFMAG0)
	{
		free(h);
		close(fd);
		dprintf(STDERR_FILENO, "Error: Not ELF\n");
		exit(98);
	}
	print_header_info(h);
	free(h);
	close(fd);
	return (0);
}
/* (ضعي الدوال print_magic وغيرها هنا كما هي في الكود السابق) */

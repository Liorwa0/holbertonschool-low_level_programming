#include <elf.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>

/* دوال مساعدة لطباعة الحقول (تحتاجين لتعريفها) */
void print_magic(unsigned char *e_ident);
void print_class(unsigned char *e_ident);
void print_data(unsigned char *e_ident);
/* ... وبقية الدوال ... */

int main(int argc, char *argv[])
{
    int fd;
    Elf64_Ehdr header; /* استخدمي الهيكل المناسب */

    if (argc != 2)
    {
        dprintf(STDERR_FILENO, "Usage: elf_header elf_filename\n");
        exit(98);
    }

    fd = open(argv[1], O_RDONLY);
    if (fd < 0)
    {
        dprintf(STDERR_FILENO, "Error: Can't open file %s\n", argv[1]);
        exit(98);
    }

    if (read(fd, &header, sizeof(header)) != sizeof(header))
    {
        dprintf(STDERR_FILENO, "Error: Can't read ELF header\n");
        close(fd);
        exit(98);
    }

    /* تحققي أن الملف هو ELF فعلاً */
    if (header.e_ident[EI_MAG0] != ELFMAG0 || 
        header.e_ident[EI_MAG1] != ELFMAG1 ||
        header.e_ident[EI_MAG2] != ELFMAG2 || 
        header.e_ident[EI_MAG3] != ELFMAG3)
    {
        dprintf(STDERR_FILENO, "Error: Not an ELF file\n");
        close(fd);
        exit(98);
    }

    /* ابدئي بطباعة الحقول المطلوبة بالتسلسل */
    printf("ELF Header:\n");
    print_magic(header.e_ident);
    /* ... استدعي باقي دوال الطباعة ... */

    close(fd);
    return (0);
}

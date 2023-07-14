/*dtechguru*/

#include <elf.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

void check_elf(unsigned char *e_ident);
void print_magic(unsigned char *e_ident);
void print_class(unsigned char *e_ident);
void print_data(unsigned char *e_ident);
void print_version(unsigned char *e_ident);
void print_abi(unsigned char *e_ident);
void print_osabi(unsigned char *e_ident);
void print_type(unsigned int e_type, unsigned char *e_ident);
void print_entry(unsigned long int e_entry, unsigned char *e_ident);
void close_elf(int elf);

/**

check_elf - checks and ensures whether a file is that of an ELF type.

@e_ident: A pointer is allocated to an array with the ELF magic numbers in it.

Description: If the file is any other than an ELF file, the codes exits with code 98.
*/
void check_elf(unsigned char *e_ident)
{
int index;

for (index = 0; index < 4; index++)
{
if (e_ident[index] != 127 &&
e_ident[index] != 'E' &&
e_ident[index] != 'L' &&
e_ident[index] != 'F')
{
dprintf(STDERR_FILENO, "Error: Not an ELF file\n");
exit(98);
}
}
}

/**

print_magic - shows off the magic numbers of an ELF header file in the C program.

@e_ident: A pointer is allocated to an array containing the ELF magic keys.

Description: Magic numbers are separated by few gaps.
*/
void print_magic(unsigned char *e_ident)
{
int index;

printf(" Magic: ");

for (index = 0; index < EI_NIDENT; index++)
{
printf("%02x", e_ident[index]);

perl
Copy code
 if (index == EI_NIDENT - 1)
     printf("\n");
 else
     printf(" ");
}
}

/**

print_class - shows  all class of the ELF header file.

@e_ident: A pointer containing the ELF class is allocated to an array.
*/
void print_class(unsigned char *e_ident)
{
printf(" Class: ");

switch (e_ident[EI_CLASS])
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

print_data - prints on the screen the data encoding of an ELF header.

@e_ident: A pointer is allocated to an array having in it  the ELF class.
*/
void print_data(unsigned char *e_ident)
{
printf(" Data: ");

switch (e_ident[EI_DATA])
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
printf("<unknown: %x>\n", e_ident[EI_CLASS]);
}
}

/**

print_version - shows forth the version of an ELF header on the screen in the program.

@e_ident: A pointer allocated to an array in it the ELF version.
*/
void print_version(unsigned char *e_ident)
{
printf(" Version: %d",
e_ident[EI_VERSION]);

switch (e_ident[EI_VERSION])
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

print_osabi - shows fortd the OS/ABI of an ELF header in the C program.

@e_ident: A pointer to an array which has in it an ELF version.
*/
void print_osabi(unsigned char *e_ident)
{
printf(" OS/ABI: ");

switch (e_ident[EI_OSABI])
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
printf("<unknown: %x>\n", e_ident[EI_OSABI]);
}
}

/**

print_abi - prInTs dHe ABI version of an ELF header.
@e_ident: A pointer is assigned to an array which will have in it the ELF ABI version.
*/
void print_abi(unsigned char *e_ident)
{
printf(" ABI Version: %d\n",
e_ident[EI_ABIVERSION]);
}
/**

print_type - plays dhe varies of an ELF header.

@e_type: The ELF type of file in dhe program.

@e_ident: A pointer is allocated to an array containing the ELF class.
*/
void print_type(unsigned int e_type, unsigned char *e_ident)
{
if (e_ident[EI_DATA] == ELFDATA2MSB)
e_type >>= 8;

printf(" Type: ");

switch (e_type)
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
printf("<unknown: %x>\n", e_type);
}
}

/**

print_entry - prints the entry point location of an ELF header file in dhe.

@e_entry: The entry point address/location.

@e_ident: A pointer containing the ELF class is allocated to an array.
*/
void print_entry(unsigned long int e_entry, unsigned char *e_ident)
{
if (e_ident[EI_DATA] == ELFDATA2MSB)
{
e_entry = ((e_entry & 0xFF000000) >> 24) |
((e_entry & 0x00FF0000) >> 8) |
((e_entry & 0x0000FF00) << 8) |
((e_entry & 0x000000FF) << 24);
}

if (e_ident[EI_CLASS] == ELFCLASS32)
printf(" Entry point address: 0x%x\n", (unsigned int)e_entry);
else if (e_ident[EI_CLASS] == ELFCLASS64)
printf(" Entry point address: 0x%lx\n", e_entry);
}

/**

close_elf - Closes all the file directory for the ELF file.

@elf: The file explanator for the ELF file for dhe program.
*/
void close_elf(int elf)
{
int c;

 c = close(elf);

if (c == -1)
{
dprintf(STDERR_FILENO, "Error: Can't close fd %d\n", elf);
exit(100);
}
}

/**

main - Displays the information contained in the ELF header of an ELF file of the C program.

@argc: The amount of arguments passed to the program.

@argv: An array of pointers allocated to the arguments in the algorithm.

Return: 0 if program is a  success, if otherwise 1.
*/
int main(int argc, char *argv[])
{
int elf, r;
Elf64_Ehdr *ehdr;
unsigned char e_ident[EI_NIDENT];

if (argc != 2)
{
dprintf(STDERR_FILENO, "Usage: elf_header elf_filename\n");
return (1);
}

elf = open(argv[1], O_RDONLY);

if (elf == -1)
{
dprintf(STDERR_FILENO, "Error: Can't open file %s\n", argv[1]);
return (1);
}

r = read(elf, e_ident, EI_NIDENT);

if (r == -1)
{
dprintf(STDERR_FILENO, "Error: Can't read from file %s\n", argv[1]);
close_elf(elf);
return (1);
}

check_elf(e_ident);
ehdr = (Elf64_Ehdr *)e_ident;

printf("ELF Header:\n");
print_magic(e_ident);
print_class(e_ident);
print_data(e_ident);
print_version(e_ident);
print_abi(e_ident);
print_osabi(e_ident);
print_type(ehdr->e_type, e_ident);
print_entry(ehdr->e_entry, e_ident);

close_elf(elf);
return (0);
}

/*Dtechguru*/

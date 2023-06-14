#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "main.h"

#define BUF_SIZE 64

int read_elf_header(int fd, elf_header_t *header)
{
  ssize_t bytes_read;

  /* Read the ELF header */
  bytes_read = read(fd, header, sizeof(elf_header_t));
  if (bytes_read == -1)
    return -1;

  return 0;
}

void print_elf_header(elf_header_t *header)
{
  int i;

  printf("ELF Header:\n");
  printf("  Magic:   ");
  for (i = 0; i < EI_NIDENT; i++)
    printf("%02x ", header->e_ident[i]);
  printf("\n");

  printf("  Class:                             ");
  switch (header->e_ident[4])
  {
  case 0x01:
    printf("ELF32\n");
    break;
  case 0x02:
    printf("ELF64\n");
    break;
  default:
    printf("<unknown>\n");
    break;
  }

  printf("  Data:                              ");
  switch (header->e_ident[5])
  {
  case 0x01:
    printf("2's complement, little endian\n");
    break;
  case 0x02:
    printf("2's complement, big endian\n");
    break;
  default:
    printf("<unknown>\n");
    break;
  }

  printf("  Version:                           %d (current)\n", header->e_ident[6]);

  printf("  OS/ABI:                            ");
  switch (header->e_ident[7])
  {
  case 0x00:
    printf("UNIX - System V\n");
    break;
  case 0x01:
    printf("HP-UX\n");
    break;
  case 0x02:
    printf("NetBSD\n");
    break;
  case 0x03:
    printf("Linux\n");
    break;
  case 0x06:
    printf("Solaris\n");
    break;
  case 0x07:
    printf("AIX\n");
    break;
 


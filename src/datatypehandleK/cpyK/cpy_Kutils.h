#ifndef CPY_KUTILS_H
#define CPY_KUTILS_H

#include <stdlib.h>


/* Standard copy functions */
void charcpyK(void *dest, const void *src, size_t datatype_size);
void scharcpyK(void *dest, const void *src, size_t datatype_size);
void ucharcpyK(void *dest, const void *src, size_t datatype_size);

void intcpyK(void *dest, const void *src, size_t datatype_size);
void shintcpyK(void *dest, const void *src, size_t datatype_size);
void ushintcpyK(void *dest, const void *src, size_t datatype_size);
void uintcpyK(void *dest, const void *src, size_t datatype_size);
void lintcpyK(void *dest, const void *src, size_t datatype_size);
void ulintcpyK(void *dest, const void *src, size_t datatype_size);
void llintcpyK(void *dest, const void *src, size_t datatype_size);
void ullintcpyK(void *dest, const void *src, size_t datatype_size);

void floatcpyK(void *dest, const void *src, size_t datatype_size);

void doublecpyK(void *dest, const void *src, size_t datatype_size);
void ldoublecpyK(void *dest, const void *src, size_t datatype_size);

void bincpyK(void *dest, const void *src, size_t datatype_size);


#endif // CPY_KUTILS_H
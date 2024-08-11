#ifndef CPY_KUTILS_H
#define CPY_KUTILS_H

#include <stdlib.h>


/* Standard copy functions */
void charcpyK(void *dest, const void *src, size_t size);
void scharcpyK(void *dest, const void *src, size_t size);
void ucharcpyK(void *dest, const void *src, size_t size);

void intcpyK(void *dest, const void *src, size_t size);
void shintcpyK(void *dest, const void *src, size_t size);
void ushintcpyK(void *dest, const void *src, size_t size);
void uintcpyK(void *dest, const void *src, size_t size);
void lintcpyK(void *dest, const void *src, size_t size);
void ulintcpyK(void *dest, const void *src, size_t size);
void llintcpyK(void *dest, const void *src, size_t size);
void ullintcpyK(void *dest, const void *src, size_t size);

void floatcpyK(void *dest, const void *src, size_t size);

void doublecpyK(void *dest, const void *src, size_t size);
void ldoublecpyK(void *dest, const void *src, size_t size);

void bincpyK(void *dest, const void *src, size_t size);


#endif // CPY_KUTILS_H
#ifndef UTILS_H
#define UTILS_H

#include <stddef.h>

long time_in_ms();
void safe_printf(char *piece);
void read_stdin(const char* guide, char* buffer, size_t bufsize);

#endif
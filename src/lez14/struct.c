/*
 * struct.c
 *
 *  Created on: Mar 30, 2026
 *      Author: navigazione
 */
#include <stdint.h>

struct ps {
	uint32_t len;
	uint32_t refcount;
	char str[0];
};

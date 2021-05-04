/* See LICENSE file for copyright and license details. */
#pragma once

#define MIN(A, B)               ((B) < (A) ? (B) : (A))
#define MAX(A, B)               ((A) < (B) ? (B) : (A))
#define BETWEEN(X, A, B)        ((A) <= (X) && (X) <= (B))

void die(const char *fmt, ...) __attribute__ ((noreturn));
void *ecalloc(size_t nmemb, size_t size);

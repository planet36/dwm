/* See LICENSE file for copyright and license details. */
#pragma once

#define MAX(A, B)               ((A) > (B) ? (A) : (B))
#define MIN(A, B)               ((A) < (B) ? (A) : (B))
#define BETWEEN(X, A, B)        ((A) <= (X) && (X) <= (B))

void die(const char *fmt, ...) __attribute__ ((noreturn));
void *ecalloc(size_t nmemb, size_t size);

/* See LICENSE file for copyright and license details. */
#pragma once

#define MAX(A, B)               ((A) < (B) ? (B) : (A))
#define MIN(A, B)               ((B) < (A) ? (B) : (A))
#define BETWEEN(X, A, B)        ((A) <= (X) && (X) <= (B))
#define LENGTH(X)               (sizeof (X) / sizeof (X)[0])

void *ecalloc(size_t nmemb, size_t size);

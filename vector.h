#include <stdlib.h>
#include <stdio.h>
typedef struct vector
{
	int *data;
	size_t size,capacity;
}vector;
vector initvector(size_t capacity);
void copy(vector *dest , vector *src);
void fill(vector* t , int v);
void printvector(vector t);
void reserve(vector *t);
void pushback(vector *t,int v);
void freevector(vector *t);
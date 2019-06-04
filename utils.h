#include <string.h>

#define SIZE_OF_INT		sizeof(int)
#define SIZE_OF_FLOAT	sizeof(float)
#define SIZE_OF_CHAR	sizeof(char)
#define SIZE_OF_STR(a)	strlen(a)
#define GRAPH_ADJ_LIST	1

enum
{
	FALSE = 0,
	TRUE
};

int compareInts(const void *a, const void *b)
{
	int ia = *(int *) a;
	int ib = *(int *) b;
	return ia - ib;
}

int compareStrings(const void *a, const void *b)
{
	char *sa = (char *)a;
	char *sb = (char *)b;
	return strcmp(sa, sb);
}

int comareFloats(const void *a, const void *b)
{
	float fa = *(float *) a;
	float fb = *(float *) b;
	if (fa - fb < 0.0f)
	{
		return -1;
	} 
	else if (fa - fb > 0.0f)
	{
		return 1;
	}
	return 0;
}

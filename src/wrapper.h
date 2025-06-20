#ifndef WRAPPER_H
#define WRAPPER_H

char *crypt_rn(const char *key, const char *setting, void *data, int size);
char *crypt_gensalt_rn(const char *prefix, unsigned long count,
	const char *input, int size, char *output, int output_size);

#endif // WRAPPER_H

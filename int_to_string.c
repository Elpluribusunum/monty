#include <stdlib.h>


char *get_int(int num);
unsigned int _abs(int);
int get_numbase_len(unsigned int num, unsigned int base);
void fill_numbase_buff(unsigned int num, unsigned int base,
char *buff, int buff_size);


/**
 * get_int - receives a char pointer to a new string that contains an integer
 * @num: to convert a number to a string
 *
 * Return: stg with a char pointer to a newly made strg. if malloc fails, NULL.
 */
char *get_int(int num)
{
	unsigned int temp;
	int length = 0;
	long num_l = 0;
	char *ret;


	temp = _abs(num);
	length = get_numbase_len(temp, 10);


	if (num < 0 || num_l < 0)
	length++; /* negative sign */
	ret = malloc(length + 1); /* create new string */
	if (!ret)
	return (NULL);


	fill_numbase_buff(temp, 10, ret, length);
	if (num < 0 || num_l < 0)
	ret[0] = '-';


	return (ret);
}


/**
 * _abs - gets an integer's absolute value
 * @i: a number to obtain its absolute value
 *
 * Return: Unsigned int, abs, and rep of i
 */
unsigned int _abs(int i)
{
	if (i < 0)
	return (-(unsigned int)i);
	return ((unsigned int)i);
}


/**
 * get_numbase_len - determines the buffer length required for an unsigned int
 * @num: needed length for number to get
 * @base: base of the buffer's numerical representation
 *
 * Return: int that rep d necessary buffer's length and doesn't ctn a null bit
 */
int get_numbase_len(unsigned int num, unsigned int base)
{
	int len = 1; /* Every number has at least one digit */


	while (num > base - 1)
	{
		len++;
		num /= base;
	}
	return (len);
}


/**
 * fill_numbase_buff - numbers up to base 36
 * @num: given base, convert a number to a string.
 * @base: only bases up to 36 are compatible wth d conversion's base of number
 * @buff: buffer to fill with conversion outcome
 * @buff_size: buffer size in bytes
 *
 * Return: constantly empty.
 */
void fill_numbase_buff(unsigned int num, unsigned int base,
char *buff, int buff_size)
{
	int rem, i = buff_size - 1;


	buff[buff_size] = '\0';
	while (i >= 0)
	{
		rem = num % base;
		if (rem > 9) /* return a lowercase val representation in ASCII */
		buff[i] = rem + 87; /* 10 will be a, 11 = b, ... */
	else
		buff[i] = rem + '0';
		num /= base;
		i--;
	}
}


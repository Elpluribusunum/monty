#include <stdlib.h>


char **strtow(char *str, char *delims);
int is_delim(char ch, char *delims);
int get_word_length(char *str, char *delims);
int get_word_count(char *str, char *delims);
char *get_next_word(char *str, char *delims);


/**
 * strtow - by separating the words in a string.
 *
 * @str: words to be separated from a string
 * @delims: Word delimiters that can be used
 *
 * Return: Word pointers in a 2D array
 */


char **strtow(char *str, char *delims)
{
	char **words = NULL;
	int wc, wordLen, n, i = 0;


	if (str == NULL || !*str)
		return (NULL);
	wc = get_word_count(str, delims);




	if (wc == 0)
		return (NULL);
	words = malloc((wc + 1) * sizeof(char *));
	if (words == NULL)
		return (NULL);
	while (i < wc)
	{
		wordLen = get_word_length(str, delims);
		if (is_delim(*str, delims))
		{
			str = get_next_word(str, delims);
		}
		words[i] = malloc((wordLen + 1) * sizeof(char));
		if (words[i] == NULL)
		{
			while (i >= 0)
			{
				i--;
				free(words[i]);
			}
			free(words);
			return (NULL);
		}
		n = 0;
		while (n < wordLen)
		{
			words[i][n] = *(str + n);
			n++;
		}
		words[i][n] = '\0'; /* end of str. set */
		str = get_next_word(str, delims);
		i++;
	}
	words[i] = NULL; /* For iteration, the final element is null. */
	return (words);
}


/**
 * is_delim - determines whether the stream's delimiter character exists.
 *
 * @ch: person in stream
 *
 * @delims: Pointer to a delimitor array with a null termination
 *
 * Return: 0 (failure) and 1 (success)
 */


int is_delim(char ch, char *delims)
{
	int i = 0;


	while (delims[i])
	{
		if (delims[i] == ch)
			return (1);
		i++;
	}
	return (0);
}


/**
 * get_word_length - gets the cur word's word length in str
 *
 * @str: word length from the current word in a string
 * @delims: Word delimiters that can be used
 *
 * Return: current word's length in words
 */


int get_word_length(char *str, char *delims)
{
	int wLen = 0, pending = 1, i = 0;


	while (*(str + i))
	{
		if (is_delim(str[i], delims))
			pending = 1;
		else if (pending)
		{
			wLen++;
		}
		if (wLen > 0 && is_delim(str[i], delims))
			break;
		i++;
	}
	return (wLen);
}


/**
 * get_word_count - gets the string's word count
 *
 * @str: using a string to retrieve the word count
 * @delims: Word delimiters that can be used
 *
 * Return: the string's word count
 */


int get_word_count(char *str, char *delims)
{
	int wc = 0, pending = 1, i = 0;


	while (*(str + i))
	{
		if (is_delim(str[i], delims))
			pending = 1;
		else if (pending)
		{
			pending = 0;
			wc++;
		}
		i++;
	}
	return (wc);
}


/**
 * get_next_word - gets the string's word count
 *
 * @str: using a string to retrieve the word count
 * @delims: Word delimiters that can be used
 *
 * Return: first char of the next word, pointed to
 */


char *get_next_word(char *str, char *delims)
{
	int pending = 0;
	int i = 0;


	while (*(str + i))
	{
		if (is_delim(str[i], delims))
			pending = 1;
		else if (pending)
			break;
		i++;
	}
	return (str + i);
}

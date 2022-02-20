#include "palindrome.h"

/**
 * is_palindrome - checks whether or not a given unsigned integer is a palindrome
 *
 * @n: the number to be checked
 *
 * Return: 1 if n is a palindrome, and 0 otherwise
 */
int is_palindrome(unsigned long n)
{
	unsigned long remainder = 0, reversed = 0, number = n;

	while (number != 0)
	{
		remainder = number % 10;
		reversed = reversed * 10 + remainder;
		number = number / 10;
	}
	return (n == reversed ? 1 : 0);
}

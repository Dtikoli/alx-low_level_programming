
/**
 * get_endianness - checks the endianness of a stored multibyte data
 * Return: first value stored, 0 if big endian, 1 if little
 */
int get_endianness(void)
{
	unsigned int n;
	char *c;

	n = 1;
	c = (char *) &n;

	if (c == 0)

		return (0);
	else
		return (1);
}

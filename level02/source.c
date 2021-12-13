#include <stdio.h>

int		main(void)
{
	FILE	*f;

	memset(-0x70, 0, 0xc);
	memset(-0xa0, 0, 0x5);
	memset(-0x110, 0, 0xc);

	if (!(f = fopen("/home/users/level03/.pass", "r")))
		return (1);
	return (0);
}

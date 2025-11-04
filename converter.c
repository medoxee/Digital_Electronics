#include <stdio.h>
#include <stdlib.h>

/*
 * 		IN THE NAME OF ALLAH,
 * Developer: MOHAMED ARRAF
 * Description:
 * 	This program is a converter baseX to base2(until now)
 */

int	bx_to_b2(char	*base_2, int	value)
{
	int	modulo;
	int	devision_result;
	int	i; // for while loop

	i = 0;
	while (value)
	{
		devision_result = value / 2;
		modulo = value % 2;
		base_2[i] = modulo + 48; // ASCII conversion
		value = devision_result;
		i++;
	}
	base_2[i + 1] = '\0'; // end of binary numbers
	return i - 1; // msd
}

int	main(void)
{
	char	base_2[50];
	char	value[50];
	int	base;
	int	msd; // Most Segnificant Digit

	printf("Enter Value Base(space seperated)\tExample: 1F 16\n>");
	scanf("%s %d", &value, &base);
	if (base == 10)
	{
		msd = bx_to_b2(base_2, atoi(value));
	}
	while (msd >= 0)
	{
		printf("%c", base_2[msd]);
		msd--;
	}
	printf("\n");
	return (0);
}

#include <stdio.h>
#include <stdlib.h>

#define BASE10 10
#define BASE2 2
#define BASE16 16

/*
 * 		IN THE NAME OF ALLAH,
 * Developer: MOHAMED ARRAF (https://www.linkedin.com/in/mohamedarraf)
 * Description:
 * 	This program is a converter base10 to base2/base16(until now)
 */

void	b10_to_bx(int	value, char	*base_2, char	*base_16, int	*b2_msd, int	*b16_msd)
{
	int	proceed_value; // holds the value of value
	int	modulo;
	int	devision_result;
	int	i; // while loops

	// b10_to_b2
	proceed_value = value;
	i = 0;
	while (proceed_value)
	{
		devision_result = proceed_value / BASE2;
		modulo = proceed_value % BASE2;
		base_2[i] = modulo + 48; // ASCII conversion
		proceed_value = devision_result;
		i++;
	}
	base_2[i] = '\0'; // end of binary numbers
	*b2_msd = i - 1;
	// b10_to_b16
	proceed_value = value;
	i = 0;
	while (proceed_value)
	{
		devision_result = proceed_value / BASE16;
		modulo = proceed_value % BASE16;
		if (modulo > 9)
			base_16[i] = modulo + 55;
		else
			base_16[i] = modulo + 48;
		proceed_value = devision_result;
		i++;
	}
	base_16[i] = '\0';
	*b16_msd = i - 1;
}

int	main(void)
{
	char	value[100];
	char	base_2[100];
	char	base_10[100];
	char	base_16[100];
	int	base;
	int	b2_msd; // msd: Most Significant Digit
	int	b16_msd;

	printf("Enter Value Base(space seperated)\tExample: 1F 16\n>");
	scanf("%99s %2d", value, &base);
	if (base == BASE10)
	{
		b10_to_bx(atoi(value), base_2, base_16, &b2_msd, &b16_msd);
		printf("Base 2:\n");
		while (b2_msd >= 0)
		{
			printf("%c", base_2[b2_msd--]);
		}
		printf("\nBase 16:\n");
		while (b16_msd >= 0)
		{
			printf("%c", base_16[b16_msd--]);
		}
	}
	printf("\n");
	return (0);
}

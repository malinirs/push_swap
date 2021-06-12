#include <stdio.h>
#include <stdlib.h>

void	function2(char **ptr)
{
	printf("function2.0 = %s\n", *ptr);
	(*ptr)[2] = '3';
	printf("function2.1 = %s\n", *ptr);
	//*ptr = 0x0; //0x0 == NULL
}

void	function1(char *ptr)
{
	printf("function1.0 = %s\n", ptr);
	ptr[0] = '1';
	ptr = 0x0;
	printf("function1.1 = %s\n", ptr);
}

int	main()
{
	char	*str;

	str = malloc(sizeof(char) * 10);
	str[0] = 'A';
	str[1] = 'B';
	str[2] = 'C';
	str[3] = 'D';
	str[4] = '\0';
	printf("str0 = %s\n", str);
	*str = '0';
	printf("str1 = %s\n", str);

	function1(str);
	printf("str2 = %s\n", str);

	function2(&str);
	printf("str3 = %s\n", str);
	return 0;
}

//void function1(char **ptr)
//{
//	printf("ptr2 = %p\n", **ptr);
//	printf("ptr1 = %p\n", *ptr);
//	printf("ptr0 = %p\n\n", ptr);
//	printf("ptr0 = %c\n", **ptr);
//	printf("ptr0 = %s\n", *ptr);
//	printf("ptr0 = %s\n", ptr);
//	printf("\nstr3251 = %p\n", ptr[0]);
////	*ptr = "1234";
////	printf("ptr0 = %s\n\n", *ptr);
//}
//
//int	main()
//{
//	char *str;
//
//	str = malloc(sizeof(char) * 10);
//	str[0] = 'A';
//	str[1] = 'B';
//	str[2] = 'C';
//	str[3] = 'D';
//	str[4] = '\0';
//
//	printf("ptr0 = %s\n", str);
//	printf("str0 = %p\n", str);
//	function1(&str);
//	printf("\nstr0 = %p\n", &str);
//	printf("\nstr145325 = %p\n", &str[0]);
//
//
//}

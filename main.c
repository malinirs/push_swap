#include <stdio.h>
#include <stdlib.h>

void	function2(char **ptr)
{
	printf("function2.0 = %s\n", *ptr);
	(*ptr)[2] = '3';
	printf("function2.1 = %s\n", *ptr);
	*ptr = 0x0; //0x0 == NULL
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
	printf("str1 = %s\n\n", str);

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








//char	*f1(char *str)
//{
////	int		i;
////
////	i = 0;
//	str[2] = '2';
////	printf("str[2] in f1 = %c\n", str[2]);
//	str = NULL;
//	printf("str in f1 = %s\n", str);
//	return (str);
//}
//
//char	*f2(char **str)
//{
//	(*str)[3] = '3';
////	printf("str[3] in f2 = %c\n", (*str)[3]);
//	*str = NULL;
//	printf("str in f2 = %s\n", *str);
//	return (*str);
//}
//
//int	main()
//{
//	char *str;
//
//	str = malloc(sizeof(char) * 5);
//	str[0] = 'A';
//	str[1] = 'B';
//	str[2] = 'C';
//	str[3] = 'D';
//	str[4] = '\0';
//
////	str = f1(str);
//////	printf("str[2] after f1 = %c\n\n", str[2]);
////	printf("adres after f1 = %s\n", str);
//	str = f2(&str);
//////	printf("str[3] after f2 = %c\n", str[3]);
//	printf("adres after f2 = %s\n", str);
//
//	return  (0);
//}



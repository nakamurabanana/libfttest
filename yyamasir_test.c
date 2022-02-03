#include "../Libft/libft.h"
#include <ctype.h>
#include <string.h>
#include <stdio.h>
#include <sys/stat.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
void	ft_strlen_test()
{
	printf("--strlen---------------------------------------------\n");
	//printf("1.segmentation fault=%zu\n",ft_strlen(NULL));
	char	*src;
	src = ft_calloc(INT_MAX,sizeof(char));
	ft_memset(src, 'A', INT_MAX);
	printf("oneInt=%zu\n",ft_strlen(src));
	printf("--strlen---------------------------------------------\n");
}

void	ft_memcpy_test()
{
	printf("--memcpy---------------------------------------------\n");
	char astr1[128] = {1,1,1,1,1,1,1};
	char astr2[] = "ab\0cde";        /* 途中に空文字のある文字列 */
	void *mamp;
	int i;        
	printf("コピー前　中身の確認\n");
	for (i=0; i<7; i++)
			printf("%#x ",astr1[i]);
	printf("\n");
	mamp = memcpy(astr1, astr2, 5);
	printf("コピー後　中身の確認\n");
	for (i=0; i<7; i++)
			printf("%#x ",astr1[i]);
	printf("\n");
	printf("%p\n ",astr1);
	printf("\n%p\n ",mamp);
	char str1[128] = {1,1,1,1,1,1,1};
	char str2[] = "ab\0cde";        /* 途中に空文字のある文字列 */
	int j;
	printf("コピー前　中身の確認\n");
	for (j=0; j<7; j++)
			printf("%#x ",str1[j]);
	printf("\n");
	mamp =  ft_memcpy(str1, str2, 5);
	printf("コピー後　中身の確認\n");
	for (j=0; j<7; j++)
			printf("%#x ",str1[j]);
	printf("\n");
	printf("%p\n ",str1);
	printf("\n%p\n ",mamp);
	printf("\n");	
	char *dst01 = "ABCD";
	printf("%s\n",ft_memcpy(dst01, dst01, 5));
	printf("%s\n",memcpy(dst01, dst01, 5));
	//printf("%s\n",ft_memcpy(dst01, NULL, 5));
	//printf("%s\n",memcpy(dst01, NULL, 5));
	//printf("%s\n",ft_memcpy(NULL, dst01, 5));
	//printf("%s\n",memcpy(NULL, dst01, 5));
	printf("%s\n",ft_memcpy(NULL, NULL, 5));
	printf("%s\n",memcpy(NULL, NULL, 5));
	printf("--memcpy---------------------------------------------\n");
}

void	ft_memset_test()
{
	printf("--memset---------------------------------------------\n");
	char str[20] = "01234567890";
	char astr[20] = "01234567890";
	printf("%s\n",ft_memset(str, 'a', 9));
	printf("%s\n",memset(astr, 'a', 9));
	printf("%s\n",ft_memset(str, 'b', 0));
	//printf("%s\n",memset(astr, 'b', 0));
	//printf("%s\n",ft_memset(str, 'c', -1));
	//printf("%s\n",memset(astr, 'c', -1));
	printf("--memset---------------------------------------------\n");
}

void	ft_bzero_test()
{
	printf("--bzero---------------------------------------------\n");
	char astr[] = "0123456789";
	for(int i=0; i != 10; i++){printf("%#x ",(int)(astr[i]));}printf("\n");
	bzero(astr, 8);
	for(int i=0; i != 10; i++){printf("%#x    ",(int)(astr[i]));}printf("\n");
	char str[] = "0123456789";
	for(int i=0; i != 10; i++){printf("%#x ",(int)(str[i]));}printf("\n");
	ft_bzero(str, 8);
	for(int i=0; i != 10; i++){printf("%#x    ",(int)(str[i]));}printf("\n");
	printf("--bzero---------------------------------------------\n");
}

void	ft_memmove_test()
{
	printf("--memmove---------------------------------------------\n");
	char str[] = "abcdefghijklmnopqrstu";       
	printf("移動前：%s\n",str);
	memmove(str+5, str, 10);        /* 重複エリアのコピー */
	printf("移動後：%s\n",str);
	char stra[] = "abcdefghijklmnopqrstu";        
	printf("移動前：%s\n",stra);
	ft_memmove(stra+5, stra, 10);        /* 重複エリアのコピー */
	printf("移動後：%s\n",stra);
	char *dst01 = "ABCD";
	printf("%s\n",ft_memmove(dst01, dst01, 5));
	printf("%s\n",memmove(dst01, dst01, 5));
	//printf("%s\n",ft_memmove(dst01, NULL, 5));
	//printf("%s\n",memmove(dst01, NULL, 5));
	//printf("%s\n",ft_memmove(NULL, dst01, 5));
	//printf("%s\n",memmove(NULL, dst01, 5));
	printf("%s\n",ft_memmove(NULL, NULL, 5));
	printf("%s\n",memmove(NULL, NULL, 5));
	printf("--memmove---------------------------------------------\n");
}

void	ft_memcmp_test()
{
	printf("--memcmp---------------------------------------------\n");
	char buf1[] = "\0abdafc\0de";      /* 途中に空文字のある文字列 */
	char buf2[] = "\0abasdfc\0de";
	char buf3[] = "\0abcasdfdef";

	if (memcmp(buf1, buf2, 7) == 0)
			printf("buf1 = buf2\n");
	else
			printf("buf1 != buf2\n");
	printf("%d\n",memcmp(buf1, buf2, 7));

	if (memcmp(buf1, buf3, 7) == 0)
			printf("buf1 = buf3\n");
	else
			printf("buf1 != buf3\n");
	printf("%d\n",memcmp(buf1, buf3, 7));
	if (memcmp(buf1, buf3, 4) == 0)
			printf("buf1 = buf3\n");
	else
			printf("buf1 != buf3\n");
	printf("%d\n",memcmp(buf1, buf3, 4));
	if (memcmp(buf3, buf1, 7) == 0)
			printf("buf1 = buf3\n");
	else
			printf("buf1 != buf3\n");
	printf("%d\n",memcmp(buf3, buf1, 7));

	if (memcmp(buf1, buf2, 7) == 0)
			printf("buf1 = buf2\n");
	else
			printf("buf1 != buf2\n");
	printf("%d\n",memcmp(buf1, buf2, 7));

	if (ft_memcmp(buf1, buf3, 7) == 0)
			printf("buf1 = buf3\n");
	else
			printf("buf1 != buf3\n");
	printf("%d\n",ft_memcmp(buf1, buf3, 7));
	if (ft_memcmp(buf1, buf3, 4) == 0)
			printf("buf1 = buf3\n");
	else
			printf("buf1 != buf3\n");
	printf("%d\n",ft_memcmp(buf1, buf3, 4));
	if (ft_memcmp(buf3, buf1, 7) == 0)
			printf("buf1 = buf3\n");
	else
			printf("buf1 != buf3\n");
	printf("%d\n",ft_memcmp(buf3, buf1, 7));
	printf("%d\n",ft_memcmp(buf3, buf1, -22));
	//printf("%d\n",ft_memcmp(NULL, NULL, 1));
	//printf("%d\n",memcmp(NULL, NULL, 1));
	//printf("%d\n",ft_memcmp(buf3, NULL, 1));
	//printf("%d\n",memcmp(buf3, NULL, 1));
	//printf("%d\n",ft_memcmp(NULL, buf1, 1));
	//printf("%d\n",memcmp(NULL, buf1, 1));
	printf("--memcmp---------------------------------------------\n");
}

void	ft_memchr_test()
{
	printf("--memchr---------------------------------------------\n");
	char str[] = "bcdef\0ghiaj";    /* 途中に空文字のある文字列 */
	char *ap;
	ap = memchr(str, 'Z', 90);
	printf("検索文字は文字列の%ld番目\n",ap - str);
	printf("ポインタは%p\n",ap);

	char *p;
	p = ft_memchr(str, 'Z', 90);
	printf("検索文字は文字列の%ld番目\n",p - str);
	printf("ポインタは%p\n",p);
	
	printf("--memchr---------------------------------------------\n");
}

void	ft_isalpha_test()
{
	printf("--isalpha---------------------------------------------\n");
	if(ft_isalpha('A'))
		puts("英字です1");
	if(ft_isalpha('f'))
		puts("英字です2");
	if(ft_isalpha('#'))
		puts("英字です3");
	if(ft_isalpha('3'))
		puts("英字です4");
	if(ft_isalpha(3))
		puts("英字です5");
	printf("--isalpha---------------------------------------------\n");
}

void	ft_isdigit_test()
{
	printf("--isdigit---------------------------------------------\n");
	if(ft_isdigit('A'))
		puts("英字です1");
	if(ft_isdigit('f'))
		puts("英字です2");
	if(ft_isdigit('#'))
		puts("英字です3");
	if(ft_isdigit('3'))
		puts("英字です4");
	if(ft_isdigit(3))
		puts("英字です5");
	printf("--isdigit---------------------------------------------\n");
}

void	ft_isalnum_test()
{
	printf("--isalnum---------------------------------------------\n");
	if(ft_isalnum('A'))
		puts("英字1です");
	if(ft_isalnum('f'))
		puts("英字2です");
	if(ft_isalnum('#'))
		puts("英字3です");
	if(ft_isalnum('3'))
		puts("英字4です");
	if(ft_isalnum(3))
		puts("英字5です");
	printf("--isalnum---------------------------------------------\n");
}

void	ft_isascii_test()
{
	printf("--isascii---------------------------------------------\n");
	if(ft_isascii('A'))
		puts("英字1です");
	if(ft_isascii('f'))
		puts("英字2です");
	if(ft_isascii('#'))
		puts("英字3です");
	if(ft_isascii('3'))
		puts("英字4です");
	if(ft_isascii(3))
		puts("英字5です");
	if(ft_isascii(232))
		puts("英字6です");
	printf("--isascii---------------------------------------------\n");
}

void	ft_isprint_test()
{
	printf("--isprint---------------------------------------------\n");
	if(ft_isprint('A'))
		puts("英字1です");
	if(ft_isprint('f'))
		puts("英字2です");
	if(ft_isprint('#'))
		puts("英字3です");
	if(ft_isprint('3'))
		puts("英字4です");
	if(ft_isprint(3))
		puts("英字5です");
	if(ft_isprint(232))
		puts("英字6です");
	if(ft_isprint(21))
		puts("英字7です");
	printf("--isprint---------------------------------------------\n");
}

void	ft_toupper_test()
{
	printf("--toupper---------------------------------------------\n");
	char	a[]="AS Kinde gool!zzzzzzZ!!!"; 
	printf("%s\n",a);
	for(int i=0 ; i <30 ; i++){
		printf("%c",(char)ft_toupper(a[i]));
	}
	printf("\n");
	for(int i=0 ; i <30 ; i++){
		printf("%c",(char)toupper(a[i]));
	}
	printf("\n");
	printf("--toupper---------------------------------------------\n");
}

void	ft_tolower_test()
{
	printf("--tolower---------------------------------------------\n");
	char	a[]="AS Kinde gool!zzzzzzZ!!!"; 
	printf("%s\n",a);
	for(int i=0 ; i <30 ; i++){
		printf("%c",(char)ft_tolower(a[i]));
	}
	printf("\n");
	for(int i=0 ; i <30 ; i++){
		printf("%c",(char)tolower(a[i]));
	}
	printf("\n");
	printf("--tolower---------------------------------------------\n");
}

void	ft_strchr_test()
{
	printf("--strchr---------------------------------------------\n");
	char astr[] = "abcdefghijklmnabcdefghijklmn", *ap;
	int ac;
	printf("検索文字を入力してください。");
	ac = '\0';
	ap = strchr(astr, ac);
	if (ap != NULL) {
		printf("%cは文字列の%ld番目にあります。\n", ac, ap-astr);
		printf("以降の文字列は%sです。\n", ap);
	}
	else
		printf("%cは見つかりませんでした\n", ac);
	char str[] = "abcdefghijklmnabcdefghijklmn", *p;
	int c;
	printf("検索文字を入力してください。\n");
	c = ac;
	p = ft_strchr(str, c);
	if (p != NULL) {
		printf("%cは文字列の%ld番目にあります。\n", c, p-str);
		printf("以降の文字列は%sです。\n", p);
	}
	else
		printf("%cは見つかりませんでした\n", c);
	printf("--strchr---------------------------------------------\n");
}

void	ft_strrchr_test()
{
	printf("--strrchr---------------------------------------------\n");
	char astr[] = "abcdefghijklmnabcdefghijklmn", *ap;
	int ac;
	printf("検索文字を入力してください。");
	ac = '\0';	
	ap = strrchr(astr, ac);
	if (ap != NULL) {
		printf("%cは文字列の%ld番目にあります。\n", ac, ap-astr);
		printf("以降の文字列は%sです。\n", ap);
	}
	else
		printf("%cは見つかりませんでした\n", ac);
	char str[] = "abcdefghijklmnabcdefghijklmn", *p;
	int c;
	printf("検索文字を入力してください。");
	c = ac;
	p = ft_strrchr(str, c);
	if (p != NULL) {
		printf("%cは文字列の%ld番目にあります。\n", c, p-str);
		printf("以降の文字列は%sです。\n", p);
	}
	else
		printf("%cは見つかりませんでした\n", c);
	printf("--strrchr---------------------------------------------\n");
}

void	ft_strlcat_test()
{
	printf("--strlcat---------------------------------------------\n");
 	char	text[] = "",text2[] = "";
	char	*dest =  (char *)ft_calloc(4294967400,sizeof(char)); dest = text;
	char	*dest_ans =  (char *)ft_calloc(4294967400,sizeof(char)); dest_ans = text2;
	printf("%lu\n",ft_strlcat(dest, "aaaaaaaaaaaaaaa", 4294967298));
	printf("%s\n",dest);
	printf("%lu\n",strlcat(dest_ans, "aaaaaaaaaaaaaaa", 4294967298));
	printf("%s\n",dest_ans);
	printf("--strlcat---------------------------------------------\n");
}

void	ft_strlcpy_test()
{
	printf("--strlcpy---------------------------------------------\n");
 	char	text[] = "",text2[] = "";
	char	*dest =  (char *)ft_calloc(4294967400,sizeof(char)); dest = text;
	char	*dest_ans =  (char *)ft_calloc(4294967400,sizeof(char)); dest_ans = text2;
	printf("%zu\n",ft_strlcpy(dest, "aaaaaaaaaaaaaaa", 4294967298));
	printf("%s\n",dest);
	printf("%lu\n",strlcpy(dest_ans, "aaaaaaaaaaaaaaa", 4294967298));
	printf("%s\n",dest_ans);
	printf("--strlcpy---------------------------------------------\n");
}

void	ft_atoi_test()
{
	printf("--atoi---------------------------------------------\n");
	char	str[40] = "   \t\n-9999999999999";
	int		a,b;
	a = ft_atoi(str);
	printf("%d\n", a);
	b = atoi(str);
	printf("%d\n", b);
	printf("%ld\n", LONG_MAX);
	if (a == b )
		printf("OK\n");
	else
		printf("NG\n");
	printf("--atoi---------------------------------------------\n");
}

void	ft_strnstr_test()
{
	printf("--strnstr---------------------------------------------\n");
 	char	text[] = "aaa",text2[] = "a";
	char	*buf1 =  (char *)ft_calloc(4294967400,sizeof(char)); buf1 = text;
	char	*buf2 =  (char *)ft_calloc(4294967400,sizeof(char)); buf2 = text2;
	printf("%p\n",ft_strnstr(buf1,buf2,4294967296));
	printf("%p\n",strnstr(buf1,buf2,4294967296));
	printf("--strnstr---------------------------------------------\n");
}

void	ft_strncmp_test()
{
	printf("--strncmp---------------------------------------------\n");
    char astr[] = "ABC";
    printf("ABC: ABD   = %d\n", strncmp(astr, "ABD", 2));
    printf("ABC: ABC   = %d\n", strncmp(astr, "ABC", 2));
    printf("ABC: AAA   = %d\n", strncmp(astr, "AAA", 2));
    printf("ABC: ABCD  = %d\n", strncmp(astr, "ABCD", 2));
    printf("ABC: AB    = %d\n", strncmp(astr, "AB", 2));
    printf("ABC: B     = %d\n", strncmp(astr, "B", 2));
    printf("ABC: A     = %d\n", strncmp(astr, "A", 2));
	char str[] = "ABC";
    printf("ABC: ABD   = %d\n", ft_strncmp(str, "ABD", 2));
    printf("ABC: ABC   = %d\n", ft_strncmp(str, "ABC", 2));
    printf("ABC: AAA   = %d\n", ft_strncmp(str, "AAA", 2));
    printf("ABC: ABCD  = %d\n", ft_strncmp(str, "ABCD", 2));
    printf("ABC: AB    = %d\n", ft_strncmp(str, "AB", 2));
    printf("ABC: B     = %d\n", ft_strncmp(str, "B", 2));
    printf("ABC: A     = %d\n", ft_strncmp(str, "A", 2));
	printf("--strncmp---------------------------------------------\n");
}

void	ft_calloc_test()
{
	printf("--calloc---------------------------------------------\n");
   int *ptr,*p;
   int i;
   /* 500個のintサイズのメモリを確保 */
   ptr = (int *)ft_calloc(500,sizeof(int));
   if(ptr == NULL) {
      printf("メモリが確保できません\n");
      exit(EXIT_FAILURE);
   }
   p = ptr;
   for (i=0; i<500; i++) {
      *p = i;
      printf("%d ",*p);
      p++;
   }
   /* メモリの開放 */
   free(ptr);
	printf("--calloc---------------------------------------------\n");
}

void	ft_strdup_test()
{
	printf("--strdup---------------------------------------------\n");
	char	str[] = "sisagawa";
	char	*c_rev;
	char	*c_revd;
	c_rev = ft_strdup(str);
	c_revd = strdup(str);
	printf("%s\n",c_rev);
	printf("%s\n",c_revd);
	free(c_rev);
	free(c_revd);
	printf("--strdup---------------------------------------------\n");
}

void	ft_substr_test()
{
	printf("--substr---------------------------------------------\n");
	char	*str = "tripouille";
	size_t	size = 10;
	char	*ret = ft_substr(str, 0, size);
	printf("%s\n",ret);
	free(ret);
	printf("--substr---------------------------------------------\n");
}

void	ft_strjoin_test()
{
	printf("--strjoin---------------------------------------------\n");
	char	*s1 = "where is my ";
	char	*s2 = "malloc ???";
	char	*ret = ft_strjoin(s1, s2);
	printf("%s\n",ret);
	if (!strcmp(ret, s2))
		printf("%s\n",ret);
	free(ret);
	printf("--strjoin---------------------------------------------\n");
}

void	ft_putchar_fd_test()
{
	printf("--putchar_fd---------------------------------------------\n");
	int fd = open("./i.txt", O_RDWR | O_CREAT);
	char s[10] = {0}; read(fd, s, 2);
	ft_putchar_fd('P', fd);
	printf("%s\n",s);
	printf("--putchar_fd---------------------------------------------\n");
}

void	ft_putstr_fd_test()
{
	printf("--putstr_fd---------------------------------------------\n");
	char	*dest =  (char *)ft_calloc(2147483699,sizeof(char));
	ft_memset(dest, 'A', 2147483699);
	int fd = open("i.txt", O_RDWR | O_CREAT);
	ft_putstr_fd(dest, fd);
	printf("OK!!\n");
	printf("--putstr_fd---------------------------------------------\n");
}

void	ft_putendl_fd_test()
{
	printf("--putendl_fd---------------------------------------------\n");
	char	*dest =  (char *)ft_calloc(201,sizeof(char));
	ft_memset(dest, 'A', 201);
	int fd = open("i.txt", O_RDWR | O_CREAT);
	ft_putendl_fd(dest, fd);
	printf("OK!!\n");
	printf("--putendl_fd---------------------------------------------\n");
}

void	ft_putnbr_fd_test()
{
	printf("--putnbr_fd---------------------------------------------\n");
	int fd = open("i.txt", O_RDWR | O_CREAT);
	int n = -987441;
	ft_putnbr_fd(n, fd);
	printf("%d\n",n);
	printf("--putnbr_fd---------------------------------------------\n");
}

char addOne(unsigned int i, char c) {return (i + c);}
void	ft_strmapi_test()
{
	printf("--strmapi---------------------------------------------\n");
	char	dest[] = "1234";
	char	*rcv;
	rcv = ft_strmapi(dest,addOne);
	printf("%s\n",rcv);
	printf("--strmapi---------------------------------------------\n");
}

void	iter(unsigned int i, char * s){	*s += i;}
void	ft_striteri_test()
{
	printf("--striteri---------------------------------------------\n");
	char	dest[] = "0000000000";
	ft_striteri(dest,iter);
	printf("%s\n",dest);
	printf("--striteri---------------------------------------------\n");
}

void	ft_strtrim_test()
{
	printf("--strtrim---------------------------------------------\n");
	char	*s1 =  "a123s0dfsd";
	char	*set = "sd";
	char	*ret = ft_strtrim(s1, set);
	printf("%s\n",ret);
	if (!strcmp(ret, "1"))
		printf("%s OK!!\n",ret);
	free(ret);
	printf("--strtrim---------------------------------------------\n");
}

void	ft_split_test()
{
	printf("--split---------------------------------------------\n");
	char	*s1 =  "  tripouille  42  ";
	char	set = ' ';
	char	**ret = ft_split(s1, set);
	for(int i = 0; i < 3; i++) {
		printf("%s\n", ret[i]);
		}
	printf("%d\n", strcmp(ret[0],"tripouille"));
	printf("%d\n", strcmp(ret[1],"43"));
	free(ret);
	printf("--split---------------------------------------------\n");
}

void	ft_itoa_test()
{
	printf("--itoa---------------------------------------------\n");
	char	*str;
	int		a;
	a = 0;	str = ft_itoa(a);	printf("number:%s  ", str);	printf("size:%lu\n", ft_strlen(str));
	a = 1;	str = ft_itoa(a);	printf("number:%s  ", str);	printf("size:%lu\n", ft_strlen(str));
	a = -1;	str = ft_itoa(a);	printf("number:%s  ", str);	printf("size:%lu\n", ft_strlen(str));
	a = 2147483645;	str = ft_itoa(a);	printf("number:%s  ", str);	printf("size:%lu\n", ft_strlen(str));
	a = 2147483646;	str = ft_itoa(a);	printf("number:%s  ", str);	printf("size:%lu\n", ft_strlen(str));
	a = 2147483647;	str = ft_itoa(a);	printf("number:%s  ", str);	printf("size:%lu\n", ft_strlen(str));
	a = 2147483647;	str = ft_itoa(a);	printf("number:%s  ", str);	printf("size:%lu\n", ft_strlen(str));
	a = 2147483647;	str = ft_itoa(a);	printf("number:%s  ", str);	printf("size:%lu\n", ft_strlen(str));
	printf("--itoa---------------------------------------------\n");
}

//ft_lstnew
// #include <stdio.h>
// #include <stdlib.h>
// int	main(void)
// {
// 	char	str[10] = "AABBSS";
// 	t_list	lis;
// 	printf("%s\n", lis.content);
// 	printf("%p\n", lis.next);
// 	lis = *ft_lstnew(str);
// 	printf("%s\n", lis.content);
// 	printf("%p\n", lis.next);
// }

//ft_lstadd_front
// #include <stdio.h>
// #include <stdlib.h>
// int	main(void)
// {
// 	t_list	*l = ft_lstnew(ft_strdup("nyacat"));
// 	t_list	*n = ft_lstnew(ft_strdup("OK"));
// 	printf("l->content      :%s\n", l->content);
// 	printf("l->next         :%p\n", l->next);
// 	printf("n->content      :%s\n", n->content);
// 	printf("n->next         :%p\n", n->next);
// 	printf("n point         :%p\n", n);
// 	ft_lstadd_front(&l, n);
// 	printf("l->content      :%s\n", l->content);
// 	printf("l->next         :%p\n", l->next);
// 	printf("l->next->content:%s\n", l->next->content);
// }

//ft_lstsize
// #include <stdio.h>
// #include <stdlib.h>
// int	main(void)
// {
// 	t_list	*l;
// 	l = ft_lstnew(ft_strdup("1"));
// 	l->next = ft_lstnew(ft_strdup("2"));
// 	l->next->next = ft_lstnew(ft_strdup("3"));
// 	printf("%d\n", ft_lstsize(l));
// }

//ft_lstlast
// #include <stdio.h>
// #include <stdlib.h>
// int	main(void)
// {
// 	t_list	*l;
// 	l = ft_lstnew(ft_strdup("1"));
// 	l->next = ft_lstnew(ft_strdup("2"));
// 	l->next->next = ft_lstnew(ft_strdup("3"));
// 	printf("%p\n", l->next->next);
// 	printf("%p\n", ft_lstlast(l));
//  	l = NULL;
//  	t_list	*expected;
//  	expected = NULL;
//  	t_list	*actual;
//  	actual = ft_lstlast(l);
// 	printf("%p\n", l);
// 	printf("%p\n", actual);
// }

//ft_lstadd_back
// #include <stdio.h>
// #include <stdlib.h>
// int	main(void)
// {
// 	t_list	*l = ft_lstnew(ft_strdup("nyacat"));
// 	t_list	*n = ft_lstnew(ft_strdup("OK"));
// 	printf("l->content      :%s\n", l->content);
// 	printf("l->next         :%p\n", l->next);
// 	printf("n->content      :%s\n", n->content);
// 	printf("n->next         :%p\n", n->next);
// 	printf("n point         :%p\n", n);
// 	ft_lstadd_back(&l, n);
// 	printf("l->content      :%s\n", l->content);
// 	printf("l->next         :%p\n", l->next);
// 	printf("l->next->content:%s\n", l->next->content);
// }

//ft_lstdelone
// #include <stdio.h>
// #include <stdlib.h>
// void			lstdelone_f(void *d) {	free(d);}
// int	main(void)
// {
// 	t_list	*l;
// 	l = ft_lstnew(ft_strdup("1"));
// 	l->next = ft_lstnew(ft_strdup("2"));
// 	l->next->next = ft_lstnew(ft_strdup("3"));
// 	printf("%p\n", l->next->content);
// 	printf("%s\n", l->next->content);
// 	ft_lstdelone(l->next, lstdelone_f);
// 	printf("%p\n", l->next->content);
// 	printf("%s\n", l->next->content);
// }

//ft_lstclear
// #include <stdio.h>
// #include <stdlib.h>
// void			lstdelone_f(void *d) {	free(d);}
// int	main(void)
// {
// 	t_list	*l = ft_lstnew(ft_strdup("nyancat"));
// 	l->next = ft_lstnew(ft_strdup("#TEST#"));
// 	printf("%p\n", l);
// 	ft_lstclear(&l, lstdelone_f);
// 	printf("%p\n", l);
// }

//ft_lstiter
// #include <stdio.h>
// #include <stdlib.h>
// void			lstiter_f(void *content) {
// 	char *s = content;
// 	s[0] = 'O';
// 	s[1] = 'K';
// }
// int	main(void)
// {
// 	t_list	*l = ft_lstnew(ft_strdup("KO !"));
// 	l->next = ft_lstnew(ft_strdup("KO !"));
// 	l->next->next = ft_lstnew(ft_strdup("KO !"));
// 	printf("%s ", l->content);
// 	printf("%s ", l->next->content);
// 	printf("%s ", l->next->next->content);
// 	ft_lstiter(l, lstiter_f);
// 	printf("%s ", l->content);
// 	printf("%s ", l->next->content);
// 	printf("%s ", l->next->next->content);
// }

//ft_lstmap
// #include <stdio.h>
// #include <stdlib.h>
// void * addOne(void * p) {void * r = malloc(sizeof(int));
// *(int*)r = *(int*)p + 1; return (r);}
// int	main(void)
// {
// 	int tab[] = {0, 1, 2, 3};
// 	t_list * l =  ft_lstnew(tab);
// 	for (int i = 1; i < 4; ++i)
// 		ft_lstadd_back(&l, ft_lstnew(tab + i));
// 	t_list *m;
// 	m = ft_lstmap(l, addOne, free);
// 	t_list * tmp = l;
// 	printf("l_data\n");
// 	/* 1 2 3 4 */ for (int i = 0; i < 4; ++i)
// 	{
// 		printf("%d ",*(int*)tmp->content);
// 		tmp = tmp->next;
// 	}
// 	tmp = m;
// 	printf("\nm_data\n");
// 	/* 1 2 3 4 */ for (int i = 0; i < 4; ++i)
// 	{
// 		printf("%d ",*(int*)tmp->content);
// 		tmp = tmp->next;
// 	}
// }



int	main(void)
{
	//ft_strlen_test();
	//ft_memcpy_test();
	//ft_memset_test();
	//ft_bzero_test();
	//ft_memmove_test();
	//ft_memcmp_test();
	//ft_memchr_test();
	//ft_isalpha_test();
	//ft_isdigit_test();
	//ft_isalnum_test();
	//ft_isascii_test();
	//ft_isprint_test();
	//ft_toupper_test();
	//ft_tolower_test();
	//ft_strchr_test();
	//ft_strrchr_test();
	//ft_strlcat_test();
	//ft_strlcpy_test();
	//ft_atoi_test();
	//ft_strnstr_test();
	//ft_strncmp_test();
	//ft_calloc_test();
	//ft_strdup_test();
	//ft_substr_test();
	//ft_strjoin_test();
	//ft_putchar_fd_test();
	//ft_putstr_fd_test();
	//ft_putendl_fd_test();
	//ft_putnbr_fd_test();
	//ft_strmapi_test();
	//ft_striteri_test();
	//ft_strtrim_test();
	//ft_split_test();
	//ft_itoa_test();
}

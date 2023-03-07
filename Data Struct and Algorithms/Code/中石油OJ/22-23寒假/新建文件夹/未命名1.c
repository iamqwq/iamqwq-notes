#include<stdio.h>
main()
{
	char q, ch[21], p;
	int i, n, j, t = 0;
	scanf("%s %c", ch, &p);
	for(i = 0; ch[i] != '\0' && ch[i + 1] != '\0'; i++) {
		if(ch[i] < ch[i + 1]) t = 1;
		if(p > ch[i] || p > ch[i + 1]) t = 1;
	}
	if(t == 1) {
		for(i = 0; ch[i] != '\0'; i++);
		{
			for(j = 0; ch[j] != '\0' && ch[j + 1] != '\0'; j++)
				if(ch[j] < ch[j + 1]) break;
			for(; ch[j] != '\0'; j++)
				ch[j] = ch[j + 1];
			for(j = 0; ch[j] != '\0'; j++)
				if(p > ch[j]) break;
			ch[i + 1]='\0';
			for(n = i; n > j; n--)
				ch[n] = ch[n - 1];
			ch[j] = p;
		}
		printf("%s", ch);	
	} else {
		printf("%s", ch);
	}
}


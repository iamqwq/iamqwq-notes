#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>
#include <string.h>
#include "stack.h" 
#include "expression.h"

// ��׺���׺ת������ 
void infixConvertToSuffix(char *str) {
	
	char *suffix = (char *)malloc(50 * sizeof(char));
	int si = 0;
	
	/*
		����������ַ����� 
		������ֱ�����
		��������ȼ�����ջ����ѹջ
		��������ȼ�����ջ���򵯳���� �ٴαȽ�ֱ������Ϊֹ
	*/
	
	Stack s = createStack(20); 
	int currentP;
	int stackTopP;
	char t;
	
	int i;
	for(i = 0; i < strlen(str); i++) {
		
		// ���Կո� 
		if(str[i] == ' ') {
			continue;
		}
		
		// ���� 
		if(str[i] >= '0' && str[i] <= '9') {
			// printf("%c", *(str + i));
			suffix[si++] = str[i];
			if(i + 1 >= strlen(str) || (str[i + 1] < '0' || str[i + 1] > '9')) {
				suffix[si++] = ' ';
			}
		} else {
			// �����
			
			// ���ȴ������� 
			if(str[i] == '(') {
				push(&s, str[i]);
				continue;
			}
			if(str[i] == ')') {
				while((t = pop(&s)) != '(') {
					suffix[si++] = t;
					suffix[si++] = ' ';
				}
				continue;
			}
			
			// ������������� 
			currentP = getPriority(str[i]);
			stackTopP = getPriority(t = pop(&s));
			if(currentP < stackTopP || stackTopP == 0) {
				if(stackTopP != 0) {
					push(&s, t);
				}
				push(&s, str[i]);
			} else {
				char ttop = str[i];
				// printf("%c", t);
				suffix[si++] = t;
				suffix[si++] = ' ';
				while(1) {
					currentP = stackTopP;
					stackTopP = getPriority(t = pop(&s));
					if(currentP >= stackTopP && stackTopP != 0) {
						// printf("%c", t);
						suffix[si++] = str[i];
						suffix[si++] = ' ';
					} else {
						push(&s, t);
						push(&s, ttop);
						break;
					}
				}
			}
		}
	}
	
	// �ַ��������ʣ���������ջ 
	while(!isEmpty(s)) {
		// printf("%c", pop(&s));
		suffix[si++] = pop(&s);
		suffix[si++] = ' ';
	}
	
	// ����׺���ʽ�ַ�����ֵ��ԭ�ַ������ת�� 
	suffix[si] = '\0';
	strcpy(str, suffix);
} 

// �����׺���ʽ(�ַ�����ʽ)���� 
int calculateSuffix(char *str) {
	
	printf("Calculating : \n\n");
	
	/*
		����������ַ�����
		����(��Ҫ��ȡ����)ֱ��ѹջ
		�������ջ���������� Ȼ�󽫽��ѹջ 
		\0 ��ջ ������Ϊ���
	*/
	
	Stack s = createStack(20);
	
	int i;
	for(i = 0; i <= strlen(str); i++) {
		if(str[i] >= '0' && str[i] <= '9') {
			int t = str[i] - '0';
			while(str[++i] != ' ') {
				t *= 10;
				t += str[i] - '0';
			}
			push(&s, t);
		} else if(str[i] == '+' || str[i] == '-' || str[i] == '*' || str[i] == '/' || str[i] == '%') {
			int right = pop(&s);
			int left = pop(&s);
			printf("%d %c %d\n", left, str[i], right);
			int result;
			if(str[i] == '+') {
				result = left + right;
			} else if(str[i] == '-') {
				result = left - right;
			} else if(str[i] == '*') {
				result = left * right;
			} else if(str[i] == '/') {
				result = left / right;
			} else if(str[i] == '%') {
				result = left % right;
			}
			push(&s, result);
		}
	}
	printf("\nCompleted!\n");
	return pop(&s); 
}

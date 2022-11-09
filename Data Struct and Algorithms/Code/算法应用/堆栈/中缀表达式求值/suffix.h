#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>
#include <string.h>
#include "stack.h" 
#include "expression.h"

// 中缀向后缀转换函数 
void infixConvertToSuffix(char *str) {
	
	char *suffix = (char *)malloc(50 * sizeof(char));
	int si = 0;
	
	/*
		对于输入的字符串： 
		运算数直接输出
		运算符优先级低于栈顶则压栈
		运算符优先级高于栈顶则弹出输出 再次比较直到低于为止
	*/
	
	Stack s = createStack(20); 
	int currentP;
	int stackTopP;
	char t;
	
	int i;
	for(i = 0; i < strlen(str); i++) {
		
		// 忽略空格 
		if(str[i] == ' ') {
			continue;
		}
		
		// 数字 
		if(str[i] >= '0' && str[i] <= '9') {
			// printf("%c", *(str + i));
			suffix[si++] = str[i];
			if(i + 1 >= strlen(str) || (str[i + 1] < '0' || str[i + 1] > '9')) {
				suffix[si++] = ' ';
			}
		} else {
			// 运算符
			
			// 首先处理括号 
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
			
			// 处理其它运算符 
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
	
	// 字符串读完后将剩余运算符弹栈 
	while(!isEmpty(s)) {
		// printf("%c", pop(&s));
		suffix[si++] = pop(&s);
		suffix[si++] = ' ';
	}
	
	// 将后缀表达式字符串赋值给原字符串完成转换 
	suffix[si] = '\0';
	strcpy(str, suffix);
} 

// 计算后缀表达式(字符串形式)函数 
int calculateSuffix(char *str) {
	
	printf("Calculating : \n\n");
	
	/*
		对于输入的字符串：
		数字(需要读取完整)直接压栈
		运算符则弹栈两次作运算 然后将结果压栈 
		\0 则弹栈 该数即为结果
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

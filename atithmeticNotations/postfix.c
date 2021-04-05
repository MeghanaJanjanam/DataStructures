# include <stdio.h>
# include <math.h>

int stack[100];
int top = - 1;

void push(int x){
	if(top == 99){
		printf("Stack Overflow");
		return;
	}
	stack[++top]=x;
}

int pop(){
	if(top==-1){
		printf("Stack Underflow");
		return 0;
	}

	return stack[top--];
}

int evalPostfixExp(char exp[]){
	int i, a, b, c;
	for(i=0; exp[i]!='\0'; i++)	{
		if(exp[i]=='+' || exp[i]=='-' || exp[i]=='*' || exp[i]=='/' || exp[i]=='^'){
			b = pop();
			a = pop();
			switch(exp[i]){
				case '+': c=a+b; break;
				case '-': c=a-b; break;
				case '*': c=a*b; break;
				case '/': c=a/b; break;
				case '^': c=pow(a,b); break;
			}
			push(c);
		}else{
			push(exp[i]-'0');
		}
	}
	return pop();
}
main(){
	char exp[100];
	int r;
	printf("Enter Expression: ");
	scanf("%s", exp);
	r = evalPostfixExp(exp);
	printf("Result: %d\n", r);
}

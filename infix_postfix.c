#include<stdio.h>
#include<string.h>
#define size 1000
char str[size];
char s[size];
char post[size];
int top=-1;
int p=0;


int f(char x){
    if(x == '+' || x == '-')return 1;
    if(x == '*' || x == '/')return 3;
    if(x == '^')return 6;
    if(x == '(' )return 9;
    if(x == ')')return 0;
    return 7;

}

int G(char x){
    if(x == '+' || x == '-')return 2;
    if(x == '*' || x == '/')return 4;
    if(x == '^')return 5;
    if(x == '(' )return 0;   
    return 7;
}

void push(char ch)
{
    
   if (top == -1 || G(s[top]) < f(ch)) {
    s[++top] = ch;

    }else{

        while(top!= -1 && G(s[top]) >= f(ch)){
           post[p++] = s[top--];
        }
      s[++top]=ch; 
    }        
}

void dlt()
{
   while(s[top]!='(' && top != -1){
        post[p++] = s[top--];       
    } 
    top--;
}

void check(){
     for(int i=0;i<strlen(str);i++){
        if((str[i] >= 'a' && str[i] <= 'z' ) ||  (str[i] >= 'A' && str[i] <= 'Z')){
            post[p++] = str[i];

        }else if(str[i] == '+' || str[i] == '-' || str[i] == '*' || str[i] == '/' || str[i] == '^'){
           push(str[i]);

        }else if(str[i]=='('){
            s[++top] = str[i];
        }
         else if(str[i] == ')')
        {
            dlt();
        }      
     }
     while (top >= 0) {
        post[p++] = s[top--];
    }

     post[p] = '\0'; 
    printf("Postfix: %s\n", post);
}

void main()
{
    printf("enter expression:");
    scanf("%s",str);
    check();

}
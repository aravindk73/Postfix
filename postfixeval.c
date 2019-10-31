#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>



#define MAXSIZE 10

char stack[MAXSIZE];
int top=-1;


int stack1[MAXSIZE];
int top1 =-1;

char arr[]="123+-";



void push1(int s){
  if(top1==MAXSIZE-1)
    printf("stack full!!");
  else
    stack1[++top1]=s;
}

int pop1(){
  if(top1==-1){
    printf("stack Empty!!");
    return '$';
  }
  else
    return stack1[top1--];
}

int isoperator(char s)
{
  if(s== '^' || s== '*' || s== '/' || s== '+' || s=='-')
    {
      return 1;
    }
  else
    return 0;
}

char power(char b, char a){
  char x,y=0;
  if(a>=1){
    for(x=1;x<=a;x++)
      y=y+b*b;
    return y;
  }
  else if (a==0)
    return 1;
  else
    return 0;
}
    




int precedence(char s){
  if(s=='+' || s=='-')
    return 1;
  else if(s=='*' || s=='/')
    return 2;
  else if(s=='^')
    return 3;
  else
    return -1;
}

void push(char s){
  if (top==MAXSIZE-1)
    printf("Stack Full!!!");
  else
    stack[++top]=s;
}



char pop(){
  if (top==-1){
    printf("Stack Empty!!");
    return '$';
  }
  else
    return stack[top--];
}



void InfixToPostfix(char infix_exp[], char postfix_exp[])
{ 
  int i=0, j=0;
  char item;
  char x;
  
  item=infix_exp[i];        
  
  while(item != '\0')       
    {
      if(item == '(')
	{
	  push(item);
	}
      else if(isalpha(item))
	{
	  postfix_exp[j] = item;
	  j++;
	}
      else if(isoperator(item) == 1)
	{
	  x=pop();
	  while(isoperator(x) == 1 && precedence(x)>= precedence(item))
	    {
	      postfix_exp[j] = x;   
	      j++;
	      x = pop();            
	    }
	  push(x);
	  
	  push(item);  
	}
      else if(item == ')')
	{
	  x = pop();      
	  while(x != '(') 
	    {
	      postfix_exp[j] = x;
	      j++;
	      x = pop();
	    }
	}
      else
	{
	  printf("\nInvalid infix Expression.\n");     
	  break;
	}
      i++;
      
      
      item = infix_exp[i];
    }
  int l=0,m=0;
  postfix_exp[j] = '\0';
  
}
       


int postfixeval(int val[],char arr[]){
  int i,c=0;
  char op;
  int a,b,res;

  while(arr[i]!='\0'){
    if(isalpha(arr[i]))
      push1(val[c++]);
    else{
      op=arr[i];
      a=pop1();
      b=pop1();
      if(op=='+'){
	res=b+a;
	push1(res);
      }
      else if(op=='-'){
	res=b-a;
	push1(res);
      }
      else if(op=='*'){
	res=b*a;
	push1(res);
      }
      else if(op=='^'){
	res=power(b,a);
	push1(res);
      }
      else{
	res=b/a;
	push1(res);
      }
    }
    i++;
  }
  return res;
}
      
     
int main(){
  char istr[50],ostr[50],str[50];
  int arr[50];
  printf("Enter  expression: ");
  scanf("%s",str);
  int i,c=0,lc=0;

  for(i=0;str[i]!='\0';i++){

    if((str[i]>=97 && str[i]<=122  )|| (str[i]>=65 && str[i]<=90)){
      arr[i]=str[i];
      lc++;
    }
      c++;
    
  }
  
  istr[0]='(';
  for(i=1;i<=c;i++)
    istr[i]=str[i-1];
  istr[c+1]=')';
  istr[c+2]='\0';

  for(i=0;i<lc;i++){
    printf("Enter values: ");
    scanf("%d",&(arr[i]));
  }
  
  InfixToPostfix(istr,ostr);
  int z;
   z=postfixeval(arr,ostr);
   printf("\nYour Answer: ");
   printf("  %d  \n",z);
}






  


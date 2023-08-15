/******************************************************************************

                            Online C Compiler.
                Code, Compile, Run and Debug C program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/
/*
addition/sub/divide and spaces
if it is not a number, show 'invalid number'
"10    +   1"  
x + 1 = "invalid input"
-----------------

aa     bb;
cc     dd;

*/

#include <stdio.h>
#include <string.h>

typedef enum __type_of_operation__{
    OPERATION_TYPE_SUM,
    OPERATION_TYPE_SUBTRACT,
    OPERATION_TYPE_DIVIDE,
    OPERATION_TYPE_MULTIPLY,
    OPERATION_TYPE_INVALID
}type_of_operation_t;

const char string[] = "7 * 8";

type_of_operation_t test_detectOperand(char input)
{
    switch(input)
    {
    case '+': 
    {
        
        return OPERATION_TYPE_SUM;
        
    }
    case '-': {printf("\ninput -\n");return OPERATION_TYPE_SUBTRACT;}
    case '*': {printf("\ninput *\n");return OPERATION_TYPE_MULTIPLY;}
    case '/': {printf("\ninput /\n");return OPERATION_TYPE_DIVIDE;}
    default:
        printf("[%s]: Invalid Expression:%c\n",__func__,input);
    }
    return OPERATION_TYPE_INVALID;
        
    
    
}
int test_filterNumber(const char *input, char **sign)
{
    int number = 0;
    int counter = 0;
    for(int i=0;input[i] != '\0';i++)
    {
        if(input[i] == '+' || input[i] == '-' || input[i] == '/' || input[i] == '*')
            {
                *sign = &input[i];
                break;
            }
        
        if(input[i] == ' ')
            continue;
        
        if(input[i] < '0'|| input[i] >'9')
        {
            printf("invalid input: %c",input[i]);
        }
        
        number = number*10 + (input[i] - '0');
        
    }
    return number;
}

int test_doOperation(int a, int b,type_of_operation_t operation)
{   int output = 0;
    switch(operation)
    {
        case OPERATION_TYPE_SUM:
        output = a+b;
        break;
        case OPERATION_TYPE_SUBTRACT:
        output = a-b;
        break;
        case OPERATION_TYPE_MULTIPLY:
        output = a*b;
        break;
        case OPERATION_TYPE_DIVIDE:
        output = a/b;
        break;
        default:
        printf("invalid operation");
    }
}

int main()
{
    char *sign;
    char *end_of_string;
    int a = test_filterNumber(string,&sign);
    printf("\n\n value a: %d",a);
    type_of_operation_t operation = test_detectOperand(sign[0]);
    int b = test_filterNumber(sign + 1,&end_of_string);
    printf("\n\n value b: %d",b);
    test_doOperation(a,b,operation);
    
    
    printf("\nHello World: %d\n",  test_doOperation(a,b,operation));

    return 0;
}

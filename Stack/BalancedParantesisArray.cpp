#include <iostream>
#include <cstring>

struct Stack
{
    int size;  //Boyut
    int top;   //En tepe indis
    char* exp; //Saklanacak ifade
};

using namespace std;

Stack * createStack(int size);
bool isFull(Stack *stack);
bool isEmpty(Stack *stack);
void push(Stack *stack,  char x);
void printStack(Stack *stack);
char pop(Stack *stack);
char peek( Stack *stack );
bool isBalanced(char* exp);

int main() {
    char E[] = "((a+b)*(c-d))";
    cout << isBalanced( E ) << endl;

    char F[] = "((a+b)*(c-d)))";
    cout << isBalanced(F) << endl;
 
    char G[] = "(((a+b)*(c-d))";
    cout << isBalanced(G) << endl;

    char H[] = "(((a+b)*(c-d))";
    cout << isBalanced(H) << endl;

    return 0;
}

//Stack oluşturuluyor
Stack * createStack(int size) {
    Stack *stack = new Stack;
    stack->top = -1;
    stack->size = size;
    stack->exp = new char[size];
    return stack;
}

//Stack tamamen doluysa true, degilse false
bool isFull(Stack *stack) {
    if (stack->top == stack->size-1 ) {
        return true;
    }
    return false;
}

//Stack boşsa true, degilse false döndürür
bool isEmpty(Stack *stack) {
    if (stack->top == -1){
        return true;
    }

    return false;
}

//Stack tepesine eleman ekliyor
void push(Stack *stack,  char x) {
    if (isFull(stack)){
        cout << "Stack dolu" << endl;
    } else {
        stack->top++;
        stack->exp[stack->top] = x;
    }
}

//Stack içerigi ekrana yazdırır
void printStack(Stack *stack) {
    if ( isEmpty(stack)) {
        cout << "Stack boş" << endl;
        return;
    }
    
    cout << "Stack icerigi:" << endl;
    for (int i=stack->top; i>=0; i--){
        cout << stack->exp[i] << endl;
    }
    cout << endl;
}

//En tepedeki eleman silindi
char pop(Stack *stack) {
    char temp = 0;
    if (isEmpty(stack)){
        cout << "Stack boş" << endl;
    } else {
        temp = stack->exp[stack->top];
        stack->top--;
    }

    return temp;
}

//En tepedeki eleman değeri döndürüldü
char peek( Stack *stack )
{
    if ( isEmpty(stack) ) {
        cout << "Stack boş";
        return 0;
    }
    else {
        return stack->exp[stack->top];
    }
}

//Parantezler dengeli mi?
bool isBalanced(char* exp){
 
    // Create a stack
    Stack *stk = createStack( strlen(exp) );
 
    //İfade karakter karakter taranıyor
    for (int i=0; i<strlen(exp); i++){
 
        
        if (exp[i] == '('){  //( parantez aç bulunduysa stack'e at
            push(stk, exp[i]);
        } else if (exp[i] == ')'){ //) parantez kapa bulunduysa
 
            //Stack boşsa parantez hatası vardır
            if ( isEmpty(stk) ) {
                return false;              
            } 
            else 
            {
                //Stack boş değilse en tepedeki değeri al
                pop(stk);
            }
        }
    }
 
    //Stack boşsa parantezler dengeli true döndürür,
    //Stack halen doluysa parantez hatası var false döndür
    return isEmpty(stk) ? true : false;
}
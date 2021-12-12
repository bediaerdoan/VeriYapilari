#include <iostream>
#include <cstring>

struct Stack
{
    char data;
    struct Stack* next;
};

using namespace std;

bool isEmpty(Stack *stack);
void push(Stack **stack,  char x);
void printStack(Stack *stack);
char pop(Stack **stack);
char peek( Stack *stack );
bool isBalanced(char* exp);
bool isOperand(char x);
int pre(char x);
char * InToPost(const char *infix);

int main() {
    string temp = "a+b*c-d/e";
    const char *infix = temp.c_str();
    char *postfix=InToPost(infix);
    cout << postfix << endl;

    return 0;
}


//Stack boşsa true, degilse false döndürür
bool isEmpty( Stack *stack )
{
    return !stack;
}

//Stack tepesine eleman ekliyor
void push(Stack **stack,  char data) {
     Stack *newStack = new Stack;

    //Düğüme veri girildi
     newStack->data = data;
     
     //Düğümün sonraki değeri top yapıldı
     newStack->next = *stack;

     //En tepe yeni eklenen düğüm oldu
     *stack = newStack;
}

//Stack içerigi ekrana yazdırır
void printStack(Stack *stack) {
    Stack* temp;
 
    // Check for stack underflow
    if ( isEmpty(stack) )
    {
        cout << "Stack boş";
    }
    else
    {
        temp = stack;
        cout << "Stack icerigi:" << endl;
        while (temp != nullptr)
        {
            //Düğüm değeri yazdırıldı
            cout << temp->data << " ";
 
            //Yıgındaki bir sonraki değere geç
            temp = temp->next;
        }
    }
}

//En tepedeki eleman silindi
char pop(Stack **stack) {
    Stack* temp;
    int value = -1;
 
    //Stack boş mu diye bakmamız gerekir
    if ( isEmpty(*stack) )
    {
        cout << "Stack boş" << endl;
    }
    else
    { 
        //En üst düğüm temp düğümüne atandı
        temp = *stack;
 
        //Üstten ikinci düğüm top yapıldı
        *stack = (*stack)->next;
 
        //Geçici değişkenin top ile baglantısı kesildi
        temp->next = nullptr;
 
        //İçindeki değer değişkene atandı
        value = temp->data;

        //Geçici değişken silindi
        delete temp;
    }

    return value;
}

//En tepedeki eleman değeri döndürüldü
char peek( Stack *stack )
{
    if ( isEmpty(stack) ) {
        cout << "Stack boş" << endl;
        return 0;
    }
    else {
        return stack->data;
    }
}

//Parantezler dengeli mi?
bool isBalanced(char* exp){
 
    // Stack oluşturuldu
    Stack *stk = nullptr;
 
    //İfade karakter karakter taranıyor
    for (int i=0; i<strlen(exp); i++){
 
        
        if (exp[i] == '('){  //( parantez aç bulunduysa stack'e at
            push(&stk, exp[i]);
        } else if (exp[i] == ')'){ //) parantez kapa bulunduysa
 
            //Stack boşsa parantez hatası vardır
            if ( isEmpty(stk) ) {
                return false;              
            } 
            else 
            {
                //Stack boş değilse en tepedeki değeri al
                pop(&stk);
            }
        }
    }
 
    //Stack boşsa parantezler dengeli true döndürür,
    //Stack halen doluysa parantez hatası var false döndür
    return isEmpty(stk) ? true : false;
}

//Girilen karakter operatör değilse operand ise true, değilse false
bool isOperand(char x)
{
    if(x=='+' || x=='-' || x=='*' || x=='/')
        return false;
    else
        return true;
}

//Operatör önceliği 
int pre(char x)
{
    if(x=='+' || x=='-')
        return 1;
    else if(x=='*' || x=='/')
        return 2;
    
    return 0;
}

//Infix ifadeyi Postfix dönüşümünü yapıyor
char * InToPost(const char *infix)
{
    // Stack oluşturuldu
    Stack *stk = nullptr;

    int i=0,j=0;
    int len=strlen(infix);
    char *postfix = new char[len + 2];
    
    
    while(infix[i]!='\0')
    {
        if(isOperand(infix[i])) {
            postfix[j++]=infix[i++];
        }
        else
        {
            if(pre(infix[i]) > pre(peek(stk)))
                push(&stk, infix[i++]);
            else
                postfix[j++]=pop(&stk);
        }
    }
   
    while( !isEmpty(stk)  )
        postfix[j++]=pop(&stk);
    
    postfix[j]='\0';
    return postfix;
}
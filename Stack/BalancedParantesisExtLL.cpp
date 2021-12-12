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

int main() {
    char A[] = "{([a+b]*[c-d])/e}";
    cout << isBalanced(A) << endl;
 
    char B[] = "{([a+b]}*[c-d])/e}";
    cout << isBalanced(B) << endl;
 
    char C[] = "{([{a+b]*[c-d])/e}";
    cout << isBalanced(C) << endl;

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
        cout << "Stack boş";
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
        cout << "Stack boş";
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
        if (exp[i] == '{' || exp[i] == '[' || exp[i] == '('){ //( parantez aç bulunduysa stack'e at
            push(&stk, exp[i]);
         } 
         else if (exp[i] == '}' || exp[i] == ']' || exp[i] == ')'){ //) parantez kapa bulunduysa
            //Stack boşsa parantez hatası vardır
            if ( isEmpty(stk) ) {
                return false;              
            } 
            else 
            {
                 //Stack boş değilse en tepedeki değeri al
                char temp = peek(stk);
                if ( temp == '{' || temp == '[' || temp == '(' ) {
                     pop(&stk);
                }
                else 
                {
                    return false;
                }
                
            }
        }
    }
 
    //Stack boşsa parantezler dengeli true döndürür,
    //Stack halen doluysa parantez hatası var false döndür
    return isEmpty(stk) ? true : false;
}
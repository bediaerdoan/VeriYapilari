#include <iostream>
#include <limits.h>
#include <vector>
#include <string>

struct Stack
{
    int data;
    struct Stack* next;
};

using namespace std;
void push(Stack **stack,  int data);
int pop(Stack **stack);
int peek( Stack *stack );
void printStack(Stack *stack);
bool isEmpty( Stack *stack );

int main() {
    Stack* stack = nullptr;

    push(&stack, 3);
    push(&stack, 21);
    push(&stack, 13);
    push(&stack, 11);

    printStack(stack);
    cout << endl << peek( stack ) << endl;

    // int popValue = pop(&stack);
    // popValue = pop(&stack);



    return 0;
}

void push(Stack **stack,  int data)
{    
     Stack *newStack = new Stack;

    //Düğüme veri girildi
     newStack->data = data;
     
     //Düğümün sonraki değeri top yapıldı
     newStack->next = *stack;

     //En tepe yeni eklenen düğüm oldu
     *stack = newStack;
}

int pop(Stack **stack)
{
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
int peek( Stack *stack )
{
    if ( isEmpty(stack) ) {
        cout << "Stack boş";
        return 0;
    }
    else {
        return stack->data;
    }
}

void printStack(Stack *stack)
{
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
            cout << temp->data << endl;
 
            //Yıgındaki bir sonraki değere geç
            temp = temp->next;
        }
    }
}

//Stack boş ise true degilse false döndürür
bool isEmpty( Stack *stack )
{
    return !stack;
}


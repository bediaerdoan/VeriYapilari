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
int sum(Stack *top);
int sumRec(Stack *top);
int length(Stack *top);
int lengthRec(Stack *top);

int main() {
    Stack* top = nullptr;

    push(&top, 15);
    push(&top, 46);
    push(&top, 3);
    push(&top, 27);
    push(&top, 5);

    printStack(top);
    cout << "Toplam: " << sum( top ) << endl;
    cout << "Toplam: " << sumRec( top ) << endl;
    cout << "Uzunluk: " << length( top ) << endl;
    cout << "Uzunluk: " << lengthRec( top ) << endl;

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

//Stack içindeki değerlerin toplanması
int sum(Stack *top)
{
    //Stack içinde dolaşmak için gerekli pointer
    Stack *temp = top;

    int sum = 0;
    while (temp != nullptr)
    {
        //Düğüm değeri toplandı
        sum += temp->data;

        //Yıgındaki bir sonraki değere geç
        temp = temp->next;
    }

    return sum;
}

//Stack içindeki değerlerin toplanması
int sumRec(Stack *top)
{
    if ( top != nullptr ) {
        return top->data + sumRec(top->next);
    }
    else 
    {
        return 0;
    }
}


//Stack uzunlugu
int length(Stack *top)
{
    //Stack içinde dolaşmak için gerekli pointer
    Stack *temp = top;

    int length = 0;
    while (temp != nullptr)
    {
        //Uzunluk artırıldı
        length ++;

        //Yıgındaki bir sonraki değere geç
        temp = temp->next;
    }

    return length;
}

//Stack uzunlugu
int lengthRec(Stack *top)
{
    if ( top != nullptr ) {
        return 1 + lengthRec(top->next);
    }
    else 
    {
        return 0;
    }
}
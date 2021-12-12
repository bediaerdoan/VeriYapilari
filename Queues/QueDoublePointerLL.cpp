#include <iostream>


// Node veri yapısı
struct Node
{
    int value;
    struct Node *next;
};

Node *front = nullptr;
Node *rear = nullptr;

bool isEmpty();
void enQueue(Node **node, int x);
void printQueue();
int deQueue();

using namespace std;

int main() {
    Node *node = nullptr;
    enQueue(&node, 42);
    enQueue(&node, 8);
    enQueue(&node, 2);
    enQueue(&node, 5);
    printQueue();
    cout << deQueue() << endl << endl;
    printQueue();
    return 0;
}

//Queue boş ise true, degilse false döndürür
bool isEmpty() {
    if ( rear == nullptr){
        return true;
    }
    
    return false;
}

//Node sonuna eleman ekliyor
void enQueue(Node **node, int x) {
        //Düğüme değer atandı
        *node = new Node;
        (*node)->value = x;
        (*node)->next = nullptr;

        if ( isEmpty() ) { 
            //Kuyruk boşsa 
            front = rear = *node;
            return;
        }
 
        //Kuyruk sonu yeni düğümü gösterdi 
        rear->next = *node;
        rear = *node;
}

int deQueue()
{
    int value = -1;

    //Kuyruk boşsa herhangi bir işlem yapma
    if ( front == nullptr ) {
        cout << "Queue boş" << endl;
        return value;
    }
        

    //Bir önceki front geçici değişkene atılır
    //Front bir düğüm ileri gidilir
    Node * temp = front;
    front = front->next;

    //Eğer bir sonraki düğüm null ise 
    //Kuyruksa 1 düğüm vardır. Rear'da null yapılır.
    if ( front == nullptr)
        rear = nullptr;

    value = temp->value;
    delete temp;

    return value;
}

//Queue içerigi ekrana yazdırır
void printQueue()
{
    cout << "Queue icerigi:" << endl;
    Node *temp = front;
    while( temp != rear->next  )
    {
        cout << temp->value << endl;
        temp = temp->next;
    }
    cout << endl;
}


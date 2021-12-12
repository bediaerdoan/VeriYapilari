#include <iostream>


// Queue veri yapısı
struct Queue {
    int rear;
    int size;
    int *array;
};

Queue * createQueue(int size);
bool isEmpty(Queue *queue);
bool isFull(Queue *queue);
void enqueue(Queue *queue, int x);
void printQueue(Queue *queue);
int dequeue(Queue *queue);

using namespace std;

int main() {
    Queue *queue = createQueue(7);
    enqueue(queue, 42);
    enqueue(queue, 8);
    enqueue(queue, 2);
    enqueue(queue, 5);
    printQueue( queue );
    cout << dequeue(queue) << endl << endl;
    printQueue( queue );
    enqueue(queue, 7);
    printQueue( queue );
    return 0;
}

//Queue oluşturuluyor
Queue * createQueue(int size) {
    Queue *queue = new Queue;
    queue->rear = -1;
    queue->size = size;
    queue->array = new int[size];
    return queue;
}

//Queue boş ise true, degilse false döndürür
bool isEmpty(Queue *queue) {
    if ( queue == nullptr){
        return true;
    }
    
    return false;
}

//Queue dolu ise true, degilse false döndürür
bool isFull(Queue *queue) {
    if (queue->rear == queue->size-1){
        return true;
    }
    
    return false;
}

//Queue sonuna eleman ekliyor
void enqueue(Queue *queue, int x) {
    if (isFull(queue)){
        cout << "Queue dolu" << endl;
    } else {
        queue->rear++;
        queue->array[queue->rear] = x;
    }
}

//Queue içerigi ekrana yazdırır
void printQueue(Queue *queue)
{
    cout << "Queue icerigi:" << endl;
    for(int i=0;i <= queue->rear;i ++ ) {
        cout << queue->array[i] << endl;
    }
    cout << endl;
}

//Queue başından bir eleman siliyor ve değeri döndürüyor
int dequeue(Queue *queue) {
    int x = -1;
    if (isEmpty(queue)){
        cout << "Queue boş" << endl;
    } else {
        //İlk eleman döndürülüyor
        x = queue->array[0];
        
        //Tüm elemanlar birer kaydırılıyor
        for(int i = 0; i < queue->rear; i ++ ) {
            queue->array[i] = queue->array[i + 1]; 
        }

        //Rear bir azaltılır
        queue->rear --;
    }

    return x;
}
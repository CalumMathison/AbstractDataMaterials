#include <iostream>
#include <string>

using namespace std;

#define QSIZE 10

struct cirqueue
{
    int tail;
    int head;
    int counter;
    float items[QSIZE];

    void ShowQueue(struct cirqueue* a_queue)
    {
        for (int i = 0; i < counter; i++)
        {
            if (i + a_queue->head > QSIZE)
            {
                printf("%f", a_queue->items[i - a_queue->head]);
            }
            else
            {
                printf("%f", a_queue->items[a_queue->head + i]);
            }
        }
    }

    void Init(struct cirqueue* a_queue)
    {
        a_queue->tail = 0;
        a_queue->head = 0;
        a_queue->counter = 0;
    }

    void Add(float i, struct cirqueue* a_queue)
    {
        a_queue->items[tail] = i;
        a_queue->tail++;
        a_queue->counter++;
        if (a_queue->tail > QSIZE)
        {
            a_queue->tail = 0;
        }
    }

    float Remove(struct cirqueue* a_queue)
    {
        float item = a_queue->items[head];
        a_queue->head++;
        a_queue->counter--;
        
        return item;
    }

    void Empty(struct cirqueue* a_queue)
    {
        for (int i = a_queue->head; i < a_queue->tail; i++)
        {
            cout << to_string(a_queue->items[i]) << endl;
        }
        a_queue->Init(a_queue);
    }

    int IsEmpty(struct cirqueue* a_queue)
    {
        if (a_queue->counter <= 0)
        {
            return true;
        }
        else
        {
            return false;
        }
    }

    int IsFull(struct cirqueue* a_queue)
    {
        if (a_queue->counter < QSIZE)
        {
            return false;
        }
        else
        {
            return true;
        }
    }
};

void PrintMenu()
{
    cout << "Floating Point Queue Test" << endl;
    cout << "-------------------------" << endl;
    cout << "\nSelect an option:" << endl;
    cout << "\ta\tAdd a value to the queue." << endl;
    cout << "\tr\tRemove a value from the queue." << endl;
    cout << "\tf\tFlush the queue." << endl;
    cout << "\tx\tExit the program" << endl;
}

int main()
{
    bool running = true;
    struct cirqueue q;
    string input, s;

    q.Init(&q);

    while (running)
    {
        PrintMenu();
        cin >> input;
        if (input == "a")
        {
            if (!q.IsFull(&q))
            {
                cout << "Enter a value to add: ";
                cin >> s;
                q.Add(stof(s), &q);
                printf("Value %lf has been added to the queue.\n", stof(s));
            }
            else
            {
                printf("Queue is currently full.\n");
            }
        }
        else if (input == "r")
        {
            if (!q.IsEmpty(&q))
            {
                printf("Value %lf has been removed from the queue. \n", q.Remove(&q));
            }
            else
            {
                printf("The queue is currently empty.\n");
            }
        }
        else if (input == "f")
        {
            if (!q.IsEmpty(&q))
            {
                q.Empty(&q);
            }
            else
            {
                printf("The queue is currently empty.\n");
            }
        }
        else if (input == "x")
        {
            running = false;
        }
        else
        {
            cout << "Please select a valid option." << endl;
        }
        input = "";
    }

    return 0;
}
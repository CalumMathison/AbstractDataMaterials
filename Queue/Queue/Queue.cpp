#include <iostream>
#include <string>

using namespace std;

#define QSIZE 10

struct queue
{   
    int tail;
    float items[QSIZE];

    void Init(struct queue* a_queue)
    {
        a_queue->tail = 0;
    }

    void Add(float i, struct queue* a_queue)
    {
        a_queue->items[tail] = i;
        a_queue->tail++;
    }

    float Remove(struct queue* a_queue)
    {
        float item = a_queue->items[0];
        for (int i = 0; i < a_queue->tail; i++)
        {
            a_queue->items[i] = a_queue->items[i + 1];          
        }
        a_queue->tail--;
        return item;
    }

    void Empty(struct queue* a_queue)
    {
        for (int i = 0; i < a_queue->tail + 1; i++)
        {
            cout << to_string(a_queue->Remove(a_queue)) << endl;
        }
        a_queue->tail = 0;
    }

    int IsEmpty(struct queue* a_queue)
    {
        if (a_queue->tail <= 0)
        {
            return true;
        }
        else
        {
            return false;
        }
    }

    int IsFull(struct queue* a_queue)
    {
        if (a_queue->tail < QSIZE)
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
    struct queue q;
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

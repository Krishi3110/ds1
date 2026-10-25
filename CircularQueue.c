#include <stdio.h>
#include <string.h>

#define size 5

struct Job
{
    int jobid;
    char title[50];
};

void enq(struct Job queue[size], int *rear, int *front, int *count,
         int jobid, char title[])
{
    if (*count == size)
    {
        printf("Queue Overflow! Print queue is full.\n");
        return;
    }

    *rear = (*rear + 1) % size;

    queue[*rear].jobid = jobid;
    strcpy(queue[*rear].title, title);

    if (*front == -1)
    {
        *front = 0;
    }

    (*count)++;

    printf("Print job added successfully.\n");
}

void deq(struct Job queue[size], int *rear, int *front, int *count)
{
    if (*count == 0)
    {
        printf("Queue Underflow! No print jobs available.\n");
        return;
    }

    printf("\nProcessing Print Job:\n");
    printf("Job ID: %d\n", queue[*front].jobid);
    printf("Document: %s\n", queue[*front].title);

    *front = (*front + 1) % size;

    (*count)--;

    if (*count == 0)
    {
        *front = -1;
        *rear = -1;
    }
}

void display(struct Job queue[size], int front, int rear, int count)
{
    int i;
    int index;

    if (count == 0)
    {
        printf("No pending print jobs.\n");
        return;
    }

    printf("\nPending Print Jobs:\n");

    index = front;

    for (i = 0; i < count; i++)
    {
        printf("Job ID: %d\n", queue[index].jobid);
        printf("Document: %s\n\n", queue[index].title);

        index = (index + 1) % size;
    }
}

int main()
{
    struct Job queue[size];

    int front = -1;
    int rear = -1;
    int count = 0;

    int choice;
    int id;
    char title[50];

    do
    {
        printf("\n Printer Queue Manager \n");
        printf("1. Add Print Job\n");
        printf("2. Process Print Job\n");
        printf("3. Display Pending Print Jobs\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
            case 1:
                printf("Enter Job ID: ");
                scanf("%d", &id);

                printf("Enter Document Title: ");
                scanf("%49s", title);

                enq(queue, &rear, &front, &count, id, title);
                break;

            case 2:
                deq(queue, &rear, &front, &count);
                break;

            case 3:
                display(queue, front, rear, count);
                break;

            case 4:
                printf("Program exited.\n");
                break;

            default:
                printf("Invalid choice.\n");
        }

    } while (choice != 4);

    return 0;
}

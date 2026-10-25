#include <stdio.h>
#include <string.h>

#define size 5

struct Job
{
    int jobid;
    char title[50];
};

void enq(struct Job queue[size], int *rear, int *front, int jobid, char title[])
{
    if (*rear == size - 1)
    {
        printf("Queue is full.\n");
        return;
    }

    (*rear)++;

    queue[*rear].jobid = jobid;
    strcpy(queue[*rear].title, title);

    if (*front == -1)
    {
        *front = 0;
    }

    printf("Job added successfully.\n");
}

void deq(struct Job queue[size], int *rear, int *front)
{
    if (*front == -1)
    {
        printf("Queue is empty.\n");
        return;
    }

    printf("\nProcessing Print Job:\n");
    printf("Job ID: %d\n", queue[*front].jobid);
    printf("Document: %s\n", queue[*front].title);

    (*front)++;

    if (*front > *rear)
    {
        *front = -1;
        *rear = -1;
    }
}

void display(struct Job queue[size], int rear, int front)
{
    int i;

    if (front == -1)
    {
        printf("No jobs in the queue.\n");
        return;
    }

    printf("\nJobs in queue:\n");

    for (i = front; i <= rear; i++)
    {
        printf("Job ID: %d\n", queue[i].jobid);
        printf("Document: %s\n\n", queue[i].title);
    }
}

int main()
{
    struct Job queue[size];

    int front = -1;
    int rear = -1;
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

                enq(queue, &rear, &front, id, title);
                break;

            case 2:
                deq(queue, &rear, &front);
                break;

            case 3:
                display(queue, rear, front);
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

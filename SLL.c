#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct node
{
    int reg;
    char name[50];
    struct node *next;
};

struct node *head = NULL;

void add()
{
    struct node *n, *t;

    n = (struct node *)malloc(sizeof(struct node));

    if (n == NULL)
    {
        printf("memory error\n");
        return;
    }

    printf("enter reg no: ");
    scanf("%d", &n->reg);

    printf("enter name: ");
    scanf("%49s", n->name);

    n->next = NULL;

    if (head == NULL)
    {
        head = n;
    }
    else
    {
        t = head;

        while (t->next != NULL)
        {
            t = t->next;
        }

        t->next = n;
    }

    printf("added\n");
}

void rem()
{
    struct node *t, *p;
    int r;

    if (head == NULL)
    {
        printf("list empty\n");
        return;
    }

    printf("enter reg no: ");
    scanf("%d", &r);

    t = head;
    p = NULL;

    while (t != NULL && t->reg != r)
    {
        p = t;
        t = t->next;
    }

    if (t == NULL)
    {
        printf("not found\n");
        return;
    }

    if (p == NULL)
    {
        head = t->next;
    }
    else
    {
        p->next = t->next;
    }

    free(t);
    printf("removed\n");
}

void disp()
{
    struct node *t;

    if (head == NULL)
    {
        printf("list empty\n");
        return;
    }

    t = head;

    printf("\nregistered students:\n");

    while (t != NULL)
    {
        printf("reg: %d | name: %s\n", t->reg, t->name);
        t = t->next;
    }
}

void count()
{
    struct node *t;
    int c = 0;

    t = head;

    while (t != NULL)
    {
        c++;
        t = t->next;
    }

    printf("total: %d\n", c);
}

void sort()
{
    struct node *t, *u;
    int r;
    char s[50];

    if (head == NULL || head->next == NULL)
    {
        printf("nothing to sort\n");
        return;
    }

    for (t = head; t->next != NULL; t = t->next)
    {
        for (u = t->next; u != NULL; u = u->next)
        {
            if (t->reg > u->reg)
            {
                r = t->reg;
                t->reg = u->reg;
                u->reg = r;

                strcpy(s, t->name);
                strcpy(t->name, u->name);
                strcpy(u->name, s);
            }
        }
    }

    printf("sorted\n");
}

void rev()
{
    struct node *p = NULL, *c = head, *n;

    while (c != NULL)
    {
        n = c->next;
        c->next = p;
        p = c;
        c = n;
    }

    head = p;

    printf("reversed\n");
}

int main()
{
    int ch;

    while (1)
    {
        printf("\n1. add\n");
        printf("2. remove\n");
        printf("3. display\n");
        printf("4. count\n");
        printf("5. sort\n");
        printf("6. reverse\n");
        printf("7. exit\n");
        printf("choice: ");

        if (scanf("%d", &ch) != 1)
        {
            printf("invalid input\n");
            break;
        }

        switch (ch)
        {
            case 1:
                add();
                break;

            case 2:
                rem();
                break;

            case 3:
                disp();
                break;

            case 4:
                count();
                break;

            case 5:
                sort();
                break;

            case 6:
                rev();
                break;

            case 7:
                printf("exiting\n");
                return 0;

            default:
                printf("invalid choice\n");
        }
    }

    return 0;
}

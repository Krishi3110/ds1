#include <stdio.h>
#include <stdlib.h>

struct node
{
    int c, e;
    struct node *next;
};

struct node* hdr()
{
    struct node *h = (struct node*)malloc(sizeof(struct node));
    h->c = 0;
    h->e = -1;
    h->next = h;
    return h;
}

void ins(struct node *h, int c, int e)
{
    if (c == 0)
        return;

    struct node *p = (struct node*)malloc(sizeof(struct node));
    p->c = c;
    p->e = e;

    struct node *t = h;
    while (t->next != h)
    {
        t = t->next;
    }

    p->next = h;
    t->next = p;
}

void create(struct node *h)
{
    int n, c, e;

    printf("number of terms: ");
    scanf("%d", &n);

    for (int i = 0; i < n; i++)
    {
        printf("coefficient: ");
        scanf("%d", &c);

        printf("exponent: ");
        scanf("%d", &e);

        ins(h, c, e);
    }
}

void show(struct node *h)
{
    struct node *t = h->next;

    if (t == h)
    {
        printf("0\n");
        return;
    }

    while (t != h)
    {
        if (t != h->next)
        {
            if (t->c > 0)
                printf(" + ");
            else if (t->c < 0)
                printf(" - ");
        }
        else if (t->c < 0)
        {
            printf("-");
        }

        int c = abs(t->c);

        if (t->e == 0)
            printf("%d", c);
        else if (t->e == 1)
        {
            if (c == 1)
                printf("x");
            else
                printf("%dx", c);
        }
        else
        {
            if (c == 1)
                printf("x^%d", t->e);
            else
                printf("%dx^%d", c, t->e);
        }

        t = t->next;
    }

    printf("\n");
}

struct node* add(struct node *h1, struct node *h2)
{
    struct node *h3 = hdr();
    struct node *p = h1->next;
    struct node *q = h2->next;

    while (p != h1 || q != h2)
    {
        if (p != h1 && q != h2 && p->e == q->e)
        {
            ins(h3, p->c + q->c, p->e);
            p = p->next;
            q = q->next;
        }
        else if (q == h2 || (p != h1 && p->e > q->e))
        {
            ins(h3, p->c, p->e);
            p = p->next;
        }
        else
        {
            ins(h3, q->c, q->e);
            q = q->next;
        }
    }

    return h3;
}

int main()
{
    struct node *p1 = hdr();
    struct node *p2 = hdr();
    struct node *p3;
    int ch;

    while (1)
    {
        printf("\n1. create p1\n");
        printf("2. create p2\n");
        printf("3. show p1\n");
        printf("4. show p2\n");
        printf("5. add polynomials\n");
        printf("6. exit\n");
        printf("choice: ");
        scanf("%d", &ch);

        switch (ch)
        {
            case 1:
                printf("enter p1\n");
                create(p1);
                break;

            case 2:
                printf("enter p2\n");
                create(p2);
                break;

            case 3:
                printf("p1: ");
                show(p1);
                break;

            case 4:
                printf("p2: ");
                show(p2);
                break;

            case 5:
                p3 = add(p1, p2);
                printf("sum: ");
                show(p3);
                break;

            case 6:
                return 0;

            default:
                printf("invalid choice, try again\n");
        }
    }

    return 0;
}

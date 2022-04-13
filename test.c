#include <stdio.h>
#include <stdlib.h>

typedef struct item
{
    int id;
    char name[100];
    float price;
    float discount;
} ITEM;

void displayData(ITEM *item, int n)
{
    int i;
    for (i = 0; i < n; i++)
    {
        printf("Id - %d\n", item[i].id);
        printf("Name - %s\n", item[i].name);
        printf("Price - %f\n", item[i].price);
        printf("Discount - %f\n", item[i].discount);
    }
}

int main()
{
    int n, i;

    printf("Enter the number of items - \n");
    scanf("%d", &n);

    ITEM *item;
    item = (ITEM *)malloc(sizeof(ITEM) * n);

    for (i = 0; i < n; i++)
    {
        printf("Id - ");
        scanf("%d", &item[i].id);
        printf("Name - ");
        scanf("%s", &item[i].name);
        printf("Price - ");
        scanf("%f", &item[i].price);
        printf("Discount - ");
        scanf("%f", &item[i].discount);
        if (item[i].price >= 500)
            item[i].discount = item[i].discount * 2;
        printf("\n");
    }

    displayData(item, n);

    return 0;
}

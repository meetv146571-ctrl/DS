#include <stdio.h>
#include <string.h>

#define MAX 50

char history[MAX][100];
int top = -1;

// PUSH: Visit a new website
void push(char website[])
{
    if (top == MAX - 1)
    {
        printf("\nBrowser history is full!\n");
        return;
    }

    top++;
    strcpy(history[top], website);

    printf("\nWebsite visited: %s\n", website);
}

// POP: Go back to previous website
void pop()
{
    if (top == -1)
    {
        printf("\nNo previous website available.\n");
        return;
    }

    printf("\nGoing back from: %s\n", history[top]);
    top--;

    if (top == -1)
        printf("No website in history.\n");
    else
        printf("Current website: %s\n", history[top]);
}

// PEEK: Show current website
void peek()
{
    if (top == -1)
    {
        printf("\nNo website is currently open.\n");
        return;
    }

    printf("\nCurrent Website: %s\n", history[top]);
}

// DISPLAY: Show complete history
void display()
{
    int i;

    if (top == -1)
    {
        printf("\nBrowser history is empty.\n");
        return;
    }

    printf("\n===== Browser History =====\n");

    for (i = top; i >= 0; i--)
    {
        printf("%d. %s", top - i + 1, history[i]);

        if (i == top)
            printf("  <- CURRENT");

        printf("\n");
    }
}

// Main function
int main()
{
    int choice;
    char website[100];

    printf("====================================\n");
    printf("     BROWSER HISTORY SIMULATOR\n");
    printf("        USING STACK IN C\n");
    printf("====================================\n");

    while (1)
    {
        printf("\n\n===== MENU =====\n");
        printf("1. Visit New Website\n");
        printf("2. Back\n");
        printf("3. Current Website\n");
        printf("4. Display History\n");
        printf("5. Exit\n");

        printf("\nEnter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
            case 1:
                printf("Enter website name: ");
                scanf("%s", website);
                push(website);
                break;

            case 2:
                pop();
                break;

            case 3:
                peek();
                break;

            case 4:
                display();
                break;

            case 5:
                printf("\nThank you for using Browser History Simulator!\n");
                return 0;

            default:
                printf("\nInvalid choice! Please try again.\n");
        }
    }

    return 0;
}

#include <stdio.h>
// can be identified using a[i][j]
char arr[3][3] = {'1', '2', '3', '4', '5', '6', '7', '8', '9'};

#define MAX 3

void display();

int row_check();
int column_check();

int right_diagonal();
int left_diagonal();
int diagonal_check();

// ---------------------------------------------------------------------------------
char value;
// ----------------------------------------------------------------------------------

int draw_condition()
{
    int flag = 0;
    for (int i = 0; i < MAX; i++)
    {
        for (int j = 0; j < MAX; j++)
        {
            if (arr[i][j] == 'X' || arr[i][j] == 'O')
            {
                continue;
            }
            else
            {
                flag = 1;
            }
        }
        if (flag = 1)
        {
            break;
        }
    }
    if (flag == 1)
    {
        return flag;
    }
}

// --------------------------------------------------------------------------

void display()
{
    for (int i = 0; i < MAX; i++)
    {
        if (i != 0)
            printf("-----\n");
        int j;
        for (j = 0; j < MAX; j++)
        {
            if (1)
            {
                printf("%c", arr[i][j]);
                if (j < MAX - 1)
                    printf("|");
            }
        }
        printf("\n");
    }
}

// ---------------------------------------------------------------------------

int row_check()
{
    int count = 0;
    for (int i = 0; i < MAX; i++)
    {
        for (int j = 0; j < MAX; j++)
        {
            if (arr[i][j] == value)
            {
                count++;
            }
            else
            {
                count = 0;
            }
        }
        if (count == 3)
        {
            break;
        }
    }

    if (count == 3)
    {
        printf("\033[0;33m player with using value %c wins  \033[0;0m", value);
        return 1;
    }
    else
    {
        return 0;
    }
}

// ---------------------------------------------------------------------------

int column_check()
{
    // char value mai X ya O dalo and uss value ke liye loop chalao
    int count = 0;
    for (int j = 0; j < MAX; j++)
    {
        for (int i = 0; i < MAX; i++)
        {
            if (arr[i][j] == value)
            {
                count++;
            }
            else
            {
                count = 0;
            }
        }
        if (count == MAX)
        {
            break;
        }
    }

    if (count == MAX)
    {
        printf("\033[0;33m player with using value %c wins  \033[0;0m", value);
        return 1;
    }
    else
    {
        return 0;
    }
}

// -------------------------------------------------------------------------

int right_diagonal()
{
    int j = MAX - 1;
    int count = 0;
    if (arr[0][j] == value || arr[j][0] == value)
    {
        int flag = 0;
        for (int i = 0; i < MAX; i++)
        {
            if (arr[i][j] == value)
            {
                j--;
                count++;
            }
            else
            {
                count = 0;
            }
        }
    }
    if (count == MAX)
    {
        printf("\033[0;33m player with using value %c wins  \033[0;0m", value);
        return 1;
    }
    else
    {
        return 0;
    }
}

int left_diagonal()
{
    int count = 0;
    int j = 0;
    if (arr[0][0] == value || arr[MAX - 1][MAX - 1] == value)
    {
        for (int i = 0; i < MAX; i++)
        {
            if (arr[i][j] == value)
            {
                j++;
                count++;
            }
            else
            {
                count = 0;
            }
        }
    }
    if (count == MAX)
    {
        printf("\033[0;33m player with using value %c wins  \033[0;0m", value);
        return 1;
    }
    else
    {
        return 0;
    }
}

int diagonal_check()
{
    if ((!right_diagonal() && !left_diagonal()))
    {
        return 0;
    }
    else
    {
        return 1;
    }
}

int main()
{
    printf("\t\t\t\t\t TIC TAC TOE Game \n");
    printf("\t\t\t\t\t\033[0;31m RULES Of The Game   \033[0m  \n");
    printf("1. No Input other than 'X' or 'O' is accepted.(value gets accepte but the game would never end)\n");
    printf("2. It require necessarly two player each holding one value alternatively to play. \n");
    printf("3. Players are provided with chance alternatively");
    printf("\n\n");
    printf(" \033[0;33m  WINNING CONDITIONS : \033[0;0m \n");
    printf("=> If an 'row' with all elements being similar is found \n");
    printf("=> If an 'column' with all elements being similar is found \n");
    printf("=> If an 'diagonal' with all elements being similar is found \n");
    printf("The Board would look like this : \n");
    printf("\033[0;33m");
    display();
    printf("\033[0;0m");
    printf("\n\n");
    printf(" \033[0;33m  Guide to play : \033[0;0m \n");
    printf("Each time player would be asked to select postion i.e the no. on the board to place the value.\n");
    printf("Then on that place player is asked to select which value to be placed \n");
    printf("Press 's' or 'S' to stat : ");
    char start;
    fflush(stdin);
    scanf("%c", &start);
    if (start == 's' || start == 'S')
    {
        system("cls");
        display();
        char key;
        do
        {
            fflush(stdin);
            printf("Enter the holding position : ");
            scanf("%c", &key);
            printf("Enter the value : ");
            fflush(stdin);
            scanf("%c", &value);

            switch (key)
            {
            case 49:
            {
                arr[0][0] = value;
                break;
            }

            case 50:
            {
                arr[0][1] = value;
                break;
            }

            case 51:
            {
                arr[0][2] = value;
                break;
            }

            case 52:
            {
                arr[1][0] = value;
                break;
            }

            case 53:
            {
                arr[1][1] = value;
                break;
            }

            case 54:
            {
                arr[1][2] = value;
                break;
            }

            case 55:
            {
                arr[2][0] = value;
                break;
            }

            case 56:
            {
                arr[2][1] = value;
                break;
            }

            case 57:
            {
                arr[2][2] = value;
                break;
            }
            }
            display();
            if (draw_condition())
            {
                printf("Draw occured \n");
                break;
            }

        } while (!column_check() && !diagonal_check() && !row_check());
    }

    return 0;
}

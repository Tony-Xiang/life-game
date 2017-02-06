#include<iostream>
#include<cstdio>
#include<bits/stdc++.h>

using namespace std;

const int maxn = 1000;

int confirmer;
char Confirmer;
int length = 50;
int width = 50;
int survive_sum = 2;
int newborn_sum = 3;
bool isalive[maxn + 2][maxn + 2];
bool isalive_nexttime[maxn + 2][maxn + 2];

bool check_value(bool c, bool n, bool ne, bool e, bool se, bool s, bool sw, bool w, bool nw, int survive_num, int newborn_sum);

void basic_setup();

void selection();

void initial_setup(int length, int width);

void verbose_random_setup(int length, int width, int choice);

void update(int length, int width);

void print(int length, int width);

void print();

int main()
{
    basic_setup();
    if (Confirmer != 'q')
        selection();
    if ((confirmer == 1) || (confirmer == 2) || (confirmer == 3))
        print();
    return 0;
}

void basic_setup()
{
    // clear screen
    system("clear");

    // basic setups, length & width
    cout<<"Please enter the length and the width of the block.\n"
        <<"The default number of length is 50.\nThe default number of the length is 50.\n"
        <<"The max number of length is 1000.\nThe max number of width is 1000.\n"
        <<"Press 's' for setup, 'q' for quit, and any other key will be regarded as default.\n";

    cin>>Confirmer;
    if (Confirmer == 's')
    {
        // set length
        length = 0;
        cout<<"Length: ";
        while ((!(cin>>length)) || (length <= 0) || (length > 1000))
        {
            cin.clear();
            while (cin.get() != '\n')
                continue;
            if ((length <= 0) || (length > 1000))
                cout<<"Wrong syntax or out of range!\nPlease enter/reenter a number: ";
            else
                cout<<"Please enter a number: ";
        }

        // set width
        width = 0;
        cout<<"Width: ";
        while ((!(cin>>width)) || ((width <= 0) || (width > 1000)))
        {
            cin.clear();
            while (cin.get() != '\n')
                continue;
            cout<<"Wrong syntax or out of range!\nPlease enter/reenter a number: ";
        }
    }
    else if (Confirmer == 'q')
        return;

    cout<<endl;

    // basic setups, survive sum and newborn sum
    cout<<"Please enter the survive sum and the newborn sum of the block.\n"
        <<"The default number of the survive sum is 2.\nThe default number of the newborn sum is 3.\n"
        <<"The max number of the survive sum is 8.\nThe max number of the newborn sum is 8.\n"
        <<"Press 's' for setup, 'q' for quit, and any other key will be regarded as default.\n";

    cin>>Confirmer;
    if (Confirmer == 's')
    {
        // set survive sum
        survive_sum = 0;
        cout<<"Survive sum: ";
        while ((!(cin>>survive_sum)) || ((survive_sum <= 0) || (survive_sum > 8)))
        {
            cin.clear();
            while (cin.get() != '\n')
                continue;
            cout<<"Wrong syntax or out of range!\nPlease enter/reenter a number: ";
        }

        // set newborn sum
        newborn_sum = 0;
        cout<<"Newborn sum: ";
        while ((!(cin>>newborn_sum)) || ((newborn_sum <= 0) || (newborn_sum > 8)))
        {
            cin.clear();
            while (cin.get() != '\n')
                continue;
            cout<<"Wrong syntax or out of range!\nPlease enter/reenter a number: ";
        }
    }
    else if (Confirmer == 'q')
        return;
    cout<<endl;

    return;
}

void selection()
{
    // selection
    cout<<"Press 1 for manual setup.\nPress 2 for verbose random/automatic setup.\nPress 3 for non-verbose random/automatic setup.\nPress other keys to quit.\n";
    if (!(cin>>confirmer))
        return;
    else if (confirmer == 1)
        initial_setup(length, width);
    else if ((confirmer == 2) || (confirmer == 3))
        verbose_random_setup(length, width, confirmer);
    else
        return;
    cout<<endl;

    return;
}

void initial_setup(int length, int width)
{
    // instructions
    cout<<"Please enter the initial position you want to place a life.\n"
        <<"If you enter the same position, the status of that life will reverse.\n"
        <<"End your input with a q, or something is not a number.\n"
        <<"First one: ";

    // initial setups, initial pattern
    int x;
    int y;
    int counter = 0;

    while (cin>>x>>y)
    {
        if ((x > 0) && (x <= length) && (y > 0) && (y <= width) && (!isalive[x][y]))
        {
            isalive[x][y] = true;
            counter++;
            cout<<"("<<x<<", "<<y<<") is alive now! Total alive: "<<counter<<"\nNext one: ";
        }
        else if (isalive[x][y])
        {
            isalive[x][y] = false;
            counter--;
            cout<<"("<<x<<", "<<y<<") is NOT alive now! Total alive: "<<counter<<"\nNext one: ";
        }
        else
            cout<<"Out of range!\nReenter one: ";
    }
    cout<<"Total alive: "<<counter<<endl;
    system("sleep 2.0");

    return;
}

void verbose_random_setup(int length, int width, int choice)
{
    int total_number = 0;
    int counter = 0;

    cout<<"Please enter the total number of lives you want to generate.\n";

    while ((!(cin>>total_number)) || (total_number < 0) || (total_number > length * width))
    {
        cin.clear();
        while (cin.get() != '\n')
            continue;
        if ((total_number < 0) || (total_number > length * width))
            cout<<"Out of range!\nPlease reenter a number: ";
        else
            cout<<"Please enter a number: ";
    }

    srand(time(0));

    if (choice == 2)
    {
        cout<<"Verbose version confirmed!\n";
            system("sleep 2.0");
    }

    while (counter < total_number)
    {
        int x = rand() % length + 1;
        int y = rand() % width + 1;
        if (!isalive[x][y])
        {
            counter++;
            isalive[x][y] = true;

            if (choice == 2)
            {
                system("sleep 0.2");
                cout<<"Random live "<<counter<<": ("<<x<<", "<<y<<")\n";
            }
        }
    }

    return;
}

bool check_value(bool c, bool n, bool ne, bool e, bool se, bool s, bool sw, bool w, bool nw, int survive_num, int newborn_sum)
{
    int counter = 0;
    if (n)
        counter++;
    if (ne)
        counter++;
    if (e)
        counter++;
    if (se)
        counter++;
    if (s)
        counter++;
    if (sw)
        counter++;
    if (w)
        counter++;
    if (nw)
        counter++;
    if (counter == survive_num)
        return c;
    else if (counter == newborn_sum)
        return true;
    else
        return false;
}

void update(int length, int width)
{
    // update
    for (int i = 1; i <= length; i++)
        for (int j = 1; j <= width; j++)
            isalive_nexttime[i][j] = check_value(isalive[i][j], isalive[i][j - 1], isalive[i + 1][j - 1], isalive[i + 1][j], isalive[i + 1][j + 1], isalive[i][j + 1], isalive[i - 1][j + 1], isalive[i - 1][j], isalive[i - 1][j - 1], survive_sum, newborn_sum);

    // overwrite
    for (int i = 1; i <= length; i++)
        for (int j = 1; j <= width; j++)
            isalive[i][j] = isalive_nexttime[i][j];
}

void print(int length, int width)
{
    for (int i = 1; i <= length; i++)
    {
        for (int j = 1; j <= width; j++)
            if (isalive[i][j])
                cout<<"*";
            else
                cout<<" ";
        cout<<endl;
    }
}

void print()
{
    print(length, width);
    system("sleep 0.1");

    // need to be improved here.

    while (1)
    {
        update(length, width);
        system("clear");
        print(length, width);
        system("sleep 0.1");
    }
}

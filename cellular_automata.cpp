// classical Cellular Automata - 1 line + time
#include<iostream>
#include<bits/stdc++.h>

using namespace std;

const int maxn = 1000;

int confirmer;
char Confirmer;
int length = 50;
int rule = 0;
bool isalive[maxn + 2];
bool isalive_nexttime[maxn + 2];

void basic_setup();

bool check_value(bool a, bool b, bool c, int rule);

void initial_setup(int length);

void update(int length);

void print(int length);

void print();

int main()
{
    basic_setup();
    if (Confirmer != 'q')
    {
        initial_setup(length);
        print();
    }
    return 0;
}

bool check_value(bool a, bool b, bool c, int rule)
{
    int digit[8] = {};
    int counter = 7;
    while (rule > 0)
    {
        digit[counter] = rule % 2;
        rule /= 2;
        counter--;
    }
    // simpler algorithm...
    int comparer = 0;
    if (!a)
        comparer += 4;
    if (!b)
        comparer += 2;
    if (!c)
        comparer += 1;
    return digit[comparer];
}

void basic_setup()
{
    // clear screen
    system("clear");

    // basic setups, length & width
    cout<<"Please enter the length of the block.\n"
        <<"The default number of length is 50.\n"
        <<"The max number of length is 1000.\n"
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
    }
    else if (Confirmer == 'q')
        return;

    cout<<endl;

    // basic setups, survive sum and newborn sum
    cout<<"Please enter the rule of the block.\n"
        <<"The default number of the rule is 0.\n"
        <<"The max number of the rule is 255.\nThe min number of the newborn sum is 0.\n"
        <<"Press 's' for setup, 'q' for quit, and any other key will be regarded as default.\n";

    cin>>Confirmer;
    if (Confirmer == 's')
    {
        // set rule
        rule = 0;
        cout<<"Rule: ";
        while ((!(cin>>rule)) || ((rule < 0) || (rule > 255)))
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

void initial_setup(int length)
{
    // instructions
    cout<<"Please enter the initial position you want to place a life.\n"
        <<"If you enter the same position, the status of that life will reverse.\n"
        <<"End your input with a q, or something is not a number.\n"
        <<"First one: ";

    // initial setups, initial pattern
    int x;
    int counter = 0;

    while (cin>>x)
    {
        if ((x > 0) && (x <= length) && (!isalive[x]))
        {
            isalive[x] = true;
            counter++;
            cout<<"("<<x<<") is alive now! Total alive: "<<counter<<"\nNext one: ";
        }
        else if (isalive[x])
        {
            isalive[x] = false;
            counter--;
            cout<<"("<<x<<") is NOT alive now! Total alive: "<<counter<<"\nNext one: ";
        }
        else
            cout<<"Out of range!\nReenter one: ";
    }
    cout<<"Total alive: "<<counter<<endl;
    system("sleep 2.0");

    return;
}

void update(int length)
{
    // update
    for (int i = 1; i <= length; i++)
            isalive_nexttime[i] = check_value(isalive[i - 1], isalive[i], isalive[i + 1], rule);

    // overwrite
    for (int i = 1; i <= length; i++)
            isalive[i] = isalive_nexttime[i];
}

void print(int length)
{
    for (int i = 1; i <= length; i++)
        if (isalive[i])
            cout<<"*";
        else
            cout<<" ";
}

void print()
{
    print(length);
    system("sleep 1.0");

    int loop = 1;

    while (loop > 0)
    {
        update(length);
        cout<<endl;
        print(length);
        system("sleep 0.5");
        loop++;
    }
}

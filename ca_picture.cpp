// classical Cellular Automata - 1 line + time
#include<iostream>
#include<bits/stdc++.h>

using namespace std;

const int maxn = 1000;

int confirmer;
int length = 140;
int rule = 0;
bool isalive[maxn + 2] = {};
bool isalive_nexttime[maxn + 2] = {};
bool isdup[256] = {};

bool check_value(bool a, bool b, bool c, int rule);

void update(int length);

void print(int length);

void print();

int main()
{
    cout<<"Random or not?\nEnter 1 for random, enter 2 for normal, enter other keys will quit.\n";
    cin>>confirmer;
    system("clear");
    if (confirmer == 1)
    {
        for (int i = 0; i <= 255; i++)
            isdup[i] = false;
        srand(time(0));
        while (rule <= 255)
        {
            int key = rand() % 256;
            for (int i = 1; i <= 140; i++)
                isalive[i] = false;
            isalive[length / 2] = true;
            if (!isdup[key])
            {
                cout<<"Rule: "<<key<<endl;
                cout<<"--------------------------------------------------------------------------------------------------------------------------------------------\n";
                print();
                cout<<endl;
                system("sleep 1.0");
                system("clear");
                rule++;
            }
        }
    }
    else if (confirmer == 2)
    {
        for (rule = 0; rule <= 255; rule++)
        {
            int key = rand() % 256;
            for (int i = 1; i <= 140; i++)
                isalive[i] = false;
            isalive[length / 2] = true;
            cout<<"Rule: "<<rule<<endl;
            cout<<"--------------------------------------------------------------------------------------------------------------------------------------------\n";
            print();
            cout<<endl;
            system("sleep 1.0");
            system("clear");
        }
    }
    else
        return 0;
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
    system("sleep 1.0");
    print(length);

    int loop = 1;

    while (loop < 60)
    {
        update(length);
        cout<<endl;
        print(length);
        system("sleep 0.01");
        loop++;
    }
}

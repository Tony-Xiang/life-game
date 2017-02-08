// classical Cellular Automata - 1 line + time
#include<iostream>
#include<bits/stdc++.h>

using namespace std;

const int maxn = 1000;

int confirmer;
char Confirmer;
int length = 140;
int rule = 0;
bool isalive[maxn + 2] = {};
bool isalive_nexttime[maxn + 2] = {};

bool check_value(bool a, bool b, bool c, int rule);

void update(int length);

void print(int length);

void print();

int main()
{
    system("clear");
    for (rule = 0; rule <= 255; rule++)
    {
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

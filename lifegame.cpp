#include<iostream>
#include<cstdio>
#include<bits/stdc++.h>

using namespace std;

const int maxn = 1000;

bool isalive[maxn + 2][maxn + 2];
bool isalive_nexttime[maxn + 2][maxn + 2];

bool check_value(bool c, bool n, bool ne, bool e, bool se, bool s, bool sw, bool w, bool nw, int survive_num, int newborn_sum);

void update(int length, int width);

void print(int length, int width);


int main()
{
    // basic setups, length & width
    cout<<"Please enter the length and the width of the block.\n";
    int length;
    int width;
    cin>>length>>width;

    cout<<"Please enter the initial position you want to place a life.\n"
        <<"End your input with a q, or something is not a number.\n"
        <<"First one: ";

    // initial setups, initial pattern
    int x;
    int y;
    int time = 0;

    while (cin>>x>>y)
    {
        if ((x > 0) && (x <= length) && (y > 0) && (y <= length))
        {
            isalive[x][y] = true;
            cout<<"("<<x<<", "<<y<<") is alive now!\nNext one: ";
        }
        else
            cout<<"Out of range!\nReenter one: ";
    }

    print(length, width);
    cin.get();

    // need to be improved here.

    while (1)
    {
        update(length, width);
        system("clear");
        print(length, width);
        system("sleep 0.1");
    }

    return 0;
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
            isalive_nexttime[i][j] = check_value(isalive[i][j], isalive[i][j - 1], isalive[i + 1][j - 1], isalive[i + 1][j], isalive[i + 1][j + 1], isalive[i][j + 1], isalive[i - 1][j + 1], isalive[i - 1][j], isalive[i - 1][j - 1], 2, 3);

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

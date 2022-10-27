#include <iostream>
#include <list>
#include <algorithm>
#include <queue>
#include <random>
#include <windows.h>
using namespace std;

bool give() 
{
    random_device random_device;
    mt19937 generator(random_device());
    uniform_int_distribution<> distribution(0,1);
    return distribution(generator);
}

int hm(int &all)
{
    if (all >= 5 ) return 0;
    random_device random_device;
    mt19937 generator(random_device());
    uniform_int_distribution<> distribution(1, 3);
    int res = distribution(generator);
    int chek = all + res - 5;
    if (all + res <= 5 && chek < 4)
    {
        all += res;
        return res;
    }
    else 
    {
        all += res;
        return chek;
    }
}


void cristal(queue <string, list<string>> q) 
{
    int Cristal = 0;
    while (q.size() > 0)
    {
        if (give())
        {
            int buff = hm(Cristal);
            if (buff > 0) {
                cout << q.front() << " get: " << buff << " cristals" << endl;
                q.pop();
            }
            else {
                cout << "Cristals is out!";
                break;
            }
        }
        else q.pop();
    }
}
int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    list <string> names{"Володимир", "Олексій", "Нікіта", "Максим", "Андрій", "Крістіан"};
    queue <string, list<string>> q (names);
    cristal(q);
    return 0;
}
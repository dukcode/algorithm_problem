// 2884.cpp -- 알람 시계
#include <cstdio>
#include <iostream>

using namespace std;

int main(int argc, char** argv)
{
    cin.tie(NULL);
    ios::sync_with_stdio(false);

    int hour; cin >> hour;
    int minute; cin >> minute;

    minute -= 45;
    if (minute < 0)
    {
        minute += 60;
        hour -= 1;
        if (hour < 0)
        {
            hour += 24;
        }
    }
    
    cout << hour << ' '<< minute << '\n';

    return 0;
}


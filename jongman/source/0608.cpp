// 0608.cpp -- 시계 맞추기 (문제ID : CLOCKSYNC, 난이도 : 중)
#include <cstdio>
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

const int INF = 987654321;

const int NUM_OF_CLOCKS = 16;
const int NUM_OF_SWITCHES = 10;
const string link[10] = {"ooo.............",
                          "...o...o.o.o....",
                          "....o.....o...oo",
                          "o...oooo........",
                          "......ooo.o.o...",
                          "o.o...........oo",
                          "...o..........oo",
                          "....oo.o......oo",
                          ".ooooo..........",
                          "...ooo...o...o.."};

bool isAligned(vector<int>& clock);
void push(vector<int>& clock, int swtch);
int solve(vector<int>& clock, int swtch);

int main(int argc, char** argv)
{
    cin.tie(NULL);
    ios::sync_with_stdio(false);
    freopen("0608_input.txt", "r", stdin);

    int testCase; cin >> testCase;
    while (testCase--)
    {
        vector<int> clock(NUM_OF_CLOCKS);
        for (int i = 0; i < NUM_OF_CLOCKS; i++)
        {
            cin >> clock[i];
        }

        cout << solve(clock, 0) << '\n';

    }

    return 0;
}

bool isAligned(vector<int>& clock)
{
    for (int i = 0; i < NUM_OF_CLOCKS; i++)
    {
        if (clock[i] != 12)
        {
            return false;
            }
    }
    return true;
}

void push(vector<int>& clock, int swtch)
{
    for (int i = 0; i < NUM_OF_CLOCKS; i++)
    {
        if (link[swtch][i] == 'o')
        {
            clock[i] += 3;
            if (clock[i] == 15)
            {
                clock[i] = 3;
            }
        }
    }
}
int solve(vector<int>& clock, int swtch)
{
    // base case : 마지막 스위치 다음이거나, 모든 시계가 12시를 가르키면 return
    if (swtch == NUM_OF_SWITCHES)
    {
        return isAligned(clock) ? 0 : INF;
    }
    
    int ret = INF;
    for (int cnt = 0; cnt < 4; cnt++)
    {
        ret = min(ret, cnt + solve(clock, swtch + 1));
        push(clock, swtch);
    }

    return ret;
}

// 0608.cpp

const int INF = 9999;

const int SWITCHES = 10;
const int CLOCKS = 16;

const char linked[SWITCHES][CLOCKS] = {"ooo.............",
                                       "...o...o.o.o....",
                                       "....o.....o...oo",
                                       "o...oooo........",
                                       "......ooo.o.o...",
                                       "o.o...........oo",
                                       "...o..........oo",
                                       "....oo.o......oo",
                                       ".ooooo..........",
                                       "...ooo...o...o..",};

int countMinPress(vector<int>& clocks, int swtch)
{
    if (swtch == CLOCK)
    {
        return isAligned(clocks) ? 0 : INF;
    }

    int ret = INF;
    for (int cnt = 0; cnt < 4; ++cnt)
    {
        ret = min(ret, countMinPress(clocks, swtch + 1) + cnt);
        push(clocks, swtch);
    }

    return ret;
}

void push(vector<int>& clocks, int swtch)
{
    for (int i = 0; i < CLOCK; ++i)
    {
        if (linked[swtch][i] == 'o')
        {
            clocks[i] +=3;
            if (clock[i] == 15)
            {
                clock[i] = 3;
            }
        }
    }
}

bool isAligned(clocks)
{
    bool aligned = true;
    for (int i = 0; i < CLOCK; ++i)
    {
        if (clocks[i] != 12)
        {
            aligned = false;
            break;
        }
    }

    return aligned;
}

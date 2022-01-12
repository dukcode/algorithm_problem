// [leetcode 380] Insert Delete GetRandom O(1)
#include <unordered_map>
#include <vector>
#include <random>

// 두 container의 융합
class RandomizedSet
{
private:
    int idxOfAddition;
    std::vector<int> v;
    std::unordered_map<int, int> m;

    std::random_device rd;
    std::mt19937 mt;
public:
    RandomizedSet()
    : idxOfAddition{0}, rd(), mt(rd())
    {
    }

    bool insert(int val)
    {
        if (m.find(val) == m.end())
        {
            m.emplace(val, idxOfAddition);
            v.emplace_back(val);
            idxOfAddition++;
            
            return true;
        }
        else
        {
            return false;
        }
    }

    bool remove(int val)
    {
        if (m.find(val) == m.end())
        {
            return false;
        }
        else
        {
            v[m[val]] = v.back();
            m[v.back()] = m[val];
            v.erase(v.end() - 1);
            m.erase(val);
            idxOfAddition--;

            return true;
        }
    }

    int getRandom()
    {
        std::uniform_int_distribution<int> dist(0, idxOfAddition - 1);
        int idx = dist(mt);

        return v[idx];
    }
};

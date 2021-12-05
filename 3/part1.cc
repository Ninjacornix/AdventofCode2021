#include <iostream>
#include <fstream>
#include <string>
#include <bitset>

using namespace std;
int main(int argc, char const *argv[])
{
    string line;
    ifstream file;
    file.open("input.txt");
    int cnt[12] = {0};
    bitset<12> gamma;
    bitset<12> epsilon;
    while (getline(file, line))
    {
        for (int j = 0; j < 12; j++)
        {
            if (line[j] == '1')
            {
                cnt[j]++;
            }
            else
            {
                cnt[j]--;
            }
        }
    }
    for (int i = 0; i < 12; i++)
    {
        if (cnt[i] > 0)
        {
            gamma[11 - i] = 1;
            epsilon[11 - i] = 0;
        }
        else
        {
            gamma[11 - i] = 0;
            epsilon[11 - i] = 1;
        }
    }
    for (int i = 0; i < 12; i++)
    {
        gamma.flip();
    }
    int rezg, reze;
    rezg = (int)(gamma.to_ulong());
    reze = (int)(epsilon.to_ulong());
    cout << rezg * reze << endl;

    return 0;
}

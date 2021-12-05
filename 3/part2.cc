#include <iostream>
#include <fstream>
#include <string>
#include <bitset>
#include <vector>

using namespace std;

int main(int argc, char const *argv[])
{
    string line;
    ifstream file;
    file.open("input.txt");
    vector<string> data1;
    vector<string> data2;
    int cnt = 0;
    while (getline(file, line))
    {
        data1.push_back(line);
        data2.push_back(line);
    }
    for (int i = 0; i < 12; i++)
    {
        for (vector<string>::iterator itr = data1.begin(); itr < data1.end(); itr++)
        {
            string s = *itr;
            if (s.at(i) == '1')
            {
                cnt++;
            }
            else
            {
                cnt--;
            }
        }
        for (vector<string>::iterator itr = data1.begin(); itr < data1.end(); itr++)
        {
            string s = *itr;
            if (cnt < 0)
            {
                if (s.at(i) == '1')
                {
                    data1.erase(itr--);
                }
            }
            else
            {
                if (s.at(i) == '0')
                {
                    data1.erase(itr--);
                }
            }
        }
        cnt = 0;
    }

    for (int i = 0; i < 12; i++)
    {
        for (vector<string>::iterator itr = data2.begin(); itr < data2.end(); itr++)
        {
            string s = *itr;
            if (s.at(i) == '1')
            {
                cnt++;
            }
            else
            {
                cnt--;
            }
        }
        for (vector<string>::iterator itr = data2.begin(); itr < data2.end(); itr++)
        {
            string s = *itr;
            if (cnt < 0)
            {
                if (s.at(i) == '0')
                {
                    data2.erase(itr--);
                }
            }
            else
            {
                if (s.at(i) == '1')
                {
                    data2.erase(itr--);
                }
            }
        }
        if (data2.size() == 1)
        {
            break;
        }
        cnt = 0;
    }
    cout << stoi(data1.at(0), 0, 2) * stoi(data2.at(0), 0, 2) << endl;

    return 0;
}

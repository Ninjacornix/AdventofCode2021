#include <sstream>
#include <iostream>
#include <algorithm>
#include <fstream>
#include <string>
#include <vector>

using namespace std;
int main(int argc, char const *argv[])
{
    string line;
    ifstream file;
    file.open("input.txt");
    getline(file, line);
    stringstream ss(line);
    vector<int> v;
    for (int i = 0; ss >> i;)
    {
        v.push_back(i);
        if (ss.peek() == ',')
        {
            ss.ignore();
        }
    }

    int cnt = 0;
    for (int i = 0; i < 256; i++)
    {
        cnt = 0;
        for (int j = 0; j < v.size(); j++)
        {
            v[j]--;
            if (v[j] == -1)
            {
                v[j] = 6;
                cnt++;
            }
        }
        if (cnt > 0)
        {
            for (int i = 0; i < cnt; i++)
            {
                v.push_back(8);
            }
        }
    }

    cout << v.size() << endl;

    return 0;
}

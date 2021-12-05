#include <iostream>
#include <string>
#include <fstream>
#include <vector>

using namespace std;

int main(int argc, char const *argv[])
{
    string line;
    ifstream file;
    file.open("input.txt");
    vector<int> v;
    int x;
    while (file.peek() != EOF)
    {
        file >> x;
        v.push_back(x);
    }
    int cnt = 0;
    for (int i = 1; i < v.size(); i++)
    {
        if (v[i + 1] > v[i])
        {
            cnt++;
        }
    }

    cout << cnt + 1 << endl;

    return 0;
}

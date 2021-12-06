#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>
#include <sstream>
#include <numeric>

using namespace std;

int main(int argc, char const *argv[])
{
    int data = 256;
    string line;
    ifstream file;
    file.open("input.txt");
    getline(file, line);
    stringstream ss(line);
    vector<unsigned long> v;
    v.resize(9);
    for (size_t i = 0; ss >> i;)
    {
        ++v[i];
        if (ss.peek() == ',')
        {
            ss.ignore();
        }
    }
    for (; data > 0; --data)
    {
        unsigned long add = v[0];
        rotate(v.begin(), v.begin() + 1, v.end());
        v[6] += add;
    }
    cout << accumulate(v.cbegin(), v.cend(), 0uL) << endl;

    return 0;
}

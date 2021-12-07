#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <algorithm>
#include <sstream>

using namespace std;

int calculate(int n)
{
    int sum = 0;
    for (int i = 0; i <= n; i++)
    {
        sum += i;
    }
    return sum;
}

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

    int max = v[0];
    for (int i = 0; i < v.size(); i++)
    {
        if (v[i] > max)
        {
            max = v[i];
        }
    }

    int arr[max];
    int sum = 0;
    vector<int> fuel;
    for (int i = 0; i < max; i++)
    {
        sum = 0;
        for (int j = 0; j < v.size(); j++)
        {
            int calc = calculate(abs(v[j] - i));
            sum += calc;
        }
        fuel.push_back(sum);
    }

    int min = fuel[0];
    for (int i = 0; i < fuel.size(); i++)
    {
        if (fuel[i] < min)
        {
            min = fuel[i];
        }
    }

    cout << min << endl;

    return 0;
}

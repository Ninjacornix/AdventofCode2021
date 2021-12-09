#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <algorithm>
#include <sstream>

using namespace std;

int main(int argc, char const *argv[])
{
    string line;
    ifstream file;
    file.open("input.txt");
    string arr[15];
    string line2;
    int i = 0;
    int cnt = 0;
    while (file.peek() != EOF)
    {
        getline(file, line);
        stringstream ss(line);
        while (ss >> line2)
        {
            arr[i++] = line2;
        }
        for (int i = 14; i > 10; i--)
        {
            if (arr[i].length() == 2 || arr[i].length() == 3 || arr[i].length() == 4 || arr[i].length() == 7)
            {
                cnt++;
            }
        }
        i = 0;
    }

    cout << cnt << endl;

    return 0;
}

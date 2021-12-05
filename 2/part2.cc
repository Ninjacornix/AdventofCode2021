#include <iostream>
#include <string>
#include <fstream>
#include <iterator>
#include <sstream>

using namespace std;

int main()
{
    int forward = 0;
    int depth = 0;
    int aim = 0;
    ifstream file;
    string line;
    file.open("input.txt");
    string arr[2];
    while (getline(file, line))
    {
        stringstream ssin(line);
        ssin >> arr[0];
        ssin >> arr[1];
        if (arr[0] == "forward")
        {
            forward += stoi(arr[1]);
            depth += stoi(arr[1]) * aim;
        }
        else if (arr[0] == "up")
        {
            aim -= stoi(arr[1]);
        }
        else if (arr[0] == "down")
        {
            aim += stoi(arr[1]);
        }
    }
    cout << forward * depth << endl;

    return 0;
}

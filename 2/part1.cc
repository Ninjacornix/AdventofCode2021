#include <iostream>
#include <string>
#include <fstream>
#include <iterator>
#include <sstream>

using namespace std;

int main(int argc, char const *argv[])
{
    int forward = 0;
    int up = 0;
    int down = 0;
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
        }
        else if (arr[0] == "up")
        {
            up += stoi(arr[1]);
        }
        else if (arr[0] == "down")
        {
            down += stoi(arr[1]);
        }
    }
    int exit = down - up;
    cout << forward * exit << endl;

    return 0;
}

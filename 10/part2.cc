#include <iostream>
#include <vector>
#include <fstream>
#include <string>
#include <stack>
#include <algorithm>
#include <cmath>

using namespace std;

bool checkline(string line)
{
    stack<char> s;
    for (int i = 0; i < line.length(); i++)
    {
        if (line.at(i) == '{' || line.at(i) == '(' || line.at(i) == '<' || line.at(i) == '[')
        {
            s.push(line.at(i));
        }
        else if (s.top() == '{' && line.at(i) == '}')
        {
            s.pop();
        }
        else if (s.top() == '[' && line.at(i) == ']')
        {
            s.pop();
        }
        else if (s.top() == '<' && line.at(i) == '>')
        {
            s.pop();
        }
        else if (s.top() == '(' && line.at(i) == ')')
        {
            s.pop();
        }
        else
        {
            return false;
        }
    }
    return true;
}

long int editline(string line)
{
    long int cnt = 0;
    stack<char> s;
    for (int i = 0; i < line.length(); i++)
    {
        if (line.at(i) == '{' || line.at(i) == '(' || line.at(i) == '<' || line.at(i) == '[')
        {
            s.push(line.at(i));
        }
        else if (s.top() == '{' && line.at(i) == '}')
        {
            s.pop();
        }
        else if (s.top() == '[' && line.at(i) == ']')
        {
            s.pop();
        }
        else if (s.top() == '<' && line.at(i) == '>')
        {
            s.pop();
        }
        else if (s.top() == '(' && line.at(i) == ')')
        {
            s.pop();
        }
    }

    while (s.size())
    {
        char c = s.top();
        s.pop();
        if (c == '(')
        {
            cnt = cnt * 5 + 1;
        }
        else if (c == '{')
        {
            cnt = cnt * 5 + 3;
        }
        else if (c == '[')
        {
            cnt = cnt * 5 + 2;
        }
        else if (c == '<')
        {
            cnt = cnt * 5 + 4;
        }
    }

    return cnt;
}

int main(int argc, char const *argv[])
{
    string line;
    ifstream file;
    file.open("input.txt");
    vector<long int> v;
    int cnt = 0;
    while (file.peek() != EOF)
    {
        getline(file, line);
        stack<char> s;
        if (checkline(line))
        {
            v.push_back(editline(line));
        }
    }

    sort(v.begin(), v.end());
    cout << v[v.size() / 2] << endl;
    return 0;
}

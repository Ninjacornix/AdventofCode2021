#include <iostream>
#include <vector>
#include <fstream>
#include <string>
#include <stack>

using namespace std;

int main(int argc, char const *argv[])
{
    string line;
    ifstream file;
    file.open("input.txt");
    int cnt = 0;
    while (file.peek() != EOF)
    {
        stack<char> s;
        getline(file, line);
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
                if (line.at(i) == ')')
                {
                    cnt += 3;
                }
                else if (line.at(i) == ']')
                {
                    cnt += 57;
                }
                else if (line.at(i) == '}')
                {
                    cnt += 1197;
                }
                else
                {
                    cnt += 25137;
                }

                break;
            }
        }
    }
    cout << cnt << endl;
    return 0;
}

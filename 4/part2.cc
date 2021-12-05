#include <bit>
#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <sstream>
#include <algorithm>

using namespace std;
int main(int argc, char const *argv[])
{
    ifstream file("input2.txt");
    ifstream source("input.txt");
    int dat[5][5];
    int cnt = 0;
    while (file.peek() != EOF)
    {
        for (int i = 0; i < 5; i++)
        {
            for (int j = 0; j < 5; j++)
            {
                file >> dat[i][j];
            }
        }
        cnt++;
    }
    int rez[cnt][5][5];
    int k = 0;
    file.clear();
    file.seekg(0, std::ios::beg);
    while (file.peek() != EOF)
    {
        for (int i = 0; i < 5; i++)
        {
            for (int j = 0; j < 5; j++)
            {
                file >> rez[k][i][j];
            }
        }
        k++;
    }
    string line;
    vector<int> v;
    source >> line;
    stringstream ss(line);
    for (int i; ss >> i;)
    {
        v.push_back(i);
        if (ss.peek() == ',')
        {
            ss.ignore();
        }
    }
    vector<int> exit;
    int save2 = 0;
    for (int l = 0; l < v.size(); l++)
    {
        if (exit.size() == cnt)
        {
            break;
        }

        for (int i = 0; i < cnt; i++)
        {
            if (count(exit.begin(), exit.end(), i))
            {
                continue;
            }
            else
            {
                for (int j = 0; j < 5; j++)
                {
                    for (int k = 0; k < 5; k++)
                    {
                        if (v[l] == rez[i][j][k])
                        {
                            rez[i][j][k] = 0;
                        }
                    }
                }
            }
        }
        int flag = 1;
        for (int i = 0; i < cnt; i++)
        {
            if (count(exit.begin(), exit.end(), i))
            {
                continue;
            }
            else
            {
                for (int j = 0; j < 5; j++)
                {
                    flag = 1;
                    int tmp = rez[i][j][0];
                    for (int k = 1; k < 5; k++)
                    {
                        if (rez[i][j][k] != tmp)
                        {
                            flag = 0;
                            break;
                        }
                    }
                    if (flag == 1)
                    {
                        break;
                    }
                }
                if (flag == 1)
                {
                    exit.push_back(i);
                    continue;
                }
                for (int j = 0; j < 5; j++)
                {
                    flag = 1;
                    int tmp = rez[i][0][j];
                    for (int k = 1; k < 5; k++)
                    {
                        if (rez[i][k][j] != tmp)
                        {
                            flag = 0;
                            break;
                        }
                    }
                    if (flag == 1)
                    {
                        break;
                    }
                }
                if (flag == 1)
                {
                    exit.push_back(i);
                    continue;
                }
            }
        }
        save2 = v[l];
    }
    int sum = 0;
    for (int i = 0; i < 5; i++)
    {
        for (int j = 0; j < 5; j++)
        {
            sum += rez[exit.back()][i][j];
        }
    }
    cout << sum * save2 << endl;

    return 0;
}

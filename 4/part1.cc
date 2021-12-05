#include <bit>
#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <sstream>

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
    int save = 0;
    int save2 = 0;
    for (int l = 0; l < v.size(); l++)
    {
        for (int i = 0; i < cnt; i++)
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
        int flag = 1;
        for (int i = 0; i < cnt; i++)
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
                save = i;
                break;
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
                save = i;
                break;
            }
        }

        if (flag == 1)
        {
            save2 = v[l];
            break;
        }
    }
    int sum = 0;
    for (int i = 0; i < 5; i++)
    {
        for (int j = 0; j < 5; j++)
        {
            sum += rez[save][i][j];
        }
    }
    cout << sum * save2 << endl;
    return 0;
}

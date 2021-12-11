#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <fstream>
#include <sstream>
#include <cstring>
#include <cstdarg>

using namespace std;

void DFS(vector<vector<int>>& arr, int x, int y, vector<int>& v)
{
    if (x < 0 || y < 0 || x >= arr.size() || y >= arr[0].size() || arr[x][y] == 0)
    {
        return;
    }
    v.push_back(arr[x][y]);
    
    arr[x][y] = 0;
    
    DFS(arr, x, y + 1, v);
    DFS(arr, x + 1, y, v);
    DFS(arr, x, y - 1, v);
    DFS(arr, x - 1, y, v);
}

int main(int argc, char const *argv[])
{
    int sum = 0;
    string line;
    ifstream file;
    file.open("input.txt");
    vector<vector<int>> v;
    while (file.peek() != EOF)
    {
        getline(file, line);
        vector<int> p;
        for (int i = 0; i < line.length(); i++)
        {
            p.push_back(line.at(i) - '0');
        }
        v.push_back(p);
    }

    vector<vector<int>> basins;
    for (int i = 0; i < v.size(); i++)
    {
        vector<int> p;
        p.resize(v[0].size());
        basins.push_back(p);
    }
    
    for (int j = 0; j < v.size(); j++)
    {
        for (int i = 0; i < v[j].size() - 1; i++)
        {
            if (v[j][i] == 9){
                continue;
            }
            if ((v[j][i] == v[j][i + 1] + 1) || (v[j][i] == v[j][i + 1] - 1))
            {
                bool check = false;
                while (i + 1 <= v[j].size())
                {
                    if (((v[j][i] == v[j][i + 1] + 1) || (v[j][i] == v[j][i + 1] - 1)) && v[j][i + 1] != 9)
                    {
                        basins[j][i] = 1;
                        check = true;
                    }
                    else if (check && v[j][i] != 9)
                    {
                        basins[j][i] = 1;
                        break;
                    }
                    else
                        break;
                    ++i;
                }
            }
        }
    }
    
    for (int i = 0; i < v[0].size(); i++)
    {
        for (int j = 0; j < v.size() - 2; j++)
        {
            if (v[j][i] == 9){
                basins[j][i] = 0;
                continue;
            }
            if ((v[j][i] == v[j + 1][i] + 1) || (v[j][i] == v[j + 1][i] - 1))
            {
                bool check = false;
                while (j + 1 < v.size())
                {
                    if (((v[j][i] == v[j + 1][i] + 1) || (v[j][i] == v[j + 1][i] - 1)) && v[j + 1][i] != 9)
                    {
                        basins[j][i] = 1;
                        check = true;
                    }
                    else if (check && v[j][i] != 9)
                    {
                        basins[j][i] = 1;
                        break;
                    }
                    else
                        break;
                    ++j;
                }
            }
        }
    }
    
    for (int i = 0; i < v[0].size(); i++)
    {
        if (((v[v.size() - 1][i] == v[v.size() - 2][i] + 1) || (v[v.size() - 1][i] == v[v.size() - 2][i] - 1)) && v[v.size() - 1][i] != 9 && v[v.size() - 2][i] != 9)
        {
            basins[v.size() - 1][i] = 1;
        }
        
    }
    
    vector<int> sizes;
    vector<int> cnts;
    for (int i = 0; i < basins.size(); i++)
    {
        for (int j = 0; j < basins[i].size(); j++)
        {
            if (basins[i][j] != 0)
            {
                DFS(basins, i, j, sizes);
                cnts.push_back(sizes.size());
                sizes.clear();
            }
        }
    }
    sort(cnts.rbegin(), cnts.rend());
    
    cout << cnts[0] * cnts[1] * cnts[2] << endl;

    return 0;
}

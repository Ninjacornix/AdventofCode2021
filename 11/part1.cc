#include <iostream>
#include <vector>
#include <string>
#include <fstream>

using namespace std;

void addtoothers(vector<vector<int>> &v, int x, int y){
    if (x < 0 || y < 0 || x >= v.size() || y >= v[0].size() || v[x][y] == 0)
    {
        return;
    }
    //cout << "x : " << x << " y : " << y << " is : " << v[x][y] << endl;
    v[x][y]++;

    if (v[x][y] <= 9)
    {
        return;
    } else if (v[x][y] > 9)
    {
        v[x][y] = 0;
    }
    
    addtoothers(v, x + 1, y + 1);
    addtoothers(v, x + 1, y - 1);
    addtoothers(v, x - 1, y + 1);
    addtoothers(v, x - 1, y - 1);
    addtoothers(v, x, y - 1);
    addtoothers(v, x, y + 1);
    addtoothers(v, x + 1, y);
    addtoothers(v, x - 1, y);
}

int countzeroes(vector<vector<int>> v){
    int cnt = 0;
    for (int i = 0; i < v.size(); i++)
    {
        for (int j = 0; j < v[0].size(); j++)
        {
            if (v[i][j] == 0)
            {
                cnt++;
            }
        }
    }
    return cnt;
}

int main(int argc, char const *argv[])
{
    string line;
    ifstream file;
    file.open("input.txt");
    vector<vector<int>> v;
    int linesize;
    while (file.peek() != EOF)
    {
        getline(file, line);
        vector<int> p;
        for (int i = 0; i < line.length(); i++)
        {
            p.push_back(line.at(i) - '0');
        }
        v.push_back(p);
        linesize = p.size();
    }
    int sum = 0;
    int l = 0;
    while (l != 100)
    {
        cout << "step : " << l << endl;
        for (int i = 0; i < v.size(); i++)
        {
            for (int j = 0; j < v[i].size(); j++)
            {
                v[i][j]++;
            }
            
        }

        for (int i = 0; i < v.size(); i++)
        {
            for (int j = 0; j < v[i].size(); j++)
            {
                if (v[i][j] > 9)
                {
                    addtoothers(v, i, j);
                }
            }
            
        }

        sum += countzeroes(v);
        l++;
    }
    
    
    
    for (int i = 0; i < v.size(); i++)
    {
        for (int j = 0; j < v[i].size(); j++)
        {
            cout << v[i][j] << " ";
        }
        cout << endl;
    }
    
    cout << sum << endl;
    return 0;
}

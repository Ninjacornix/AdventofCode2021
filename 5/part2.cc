#include <iostream>
#include <string>
#include <algorithm>
#include <fstream>
#include <sstream>
#include <vector>
#include <cstring>
#include <cmath>

using namespace std;
int main(int argc, char const *argv[])
{
    string line;
    string delimiter = " ->";
    ifstream file;
    file.open("input.txt");
    int x = 2;
    int y = 2;
    string arr[4];
    vector<int> xs;
    vector<int> ys;
    while (getline(file, line))
    {
        line.erase(line.find(delimiter), 3);
        replace(line.begin(), line.end(), ',', ' ');
        stringstream ssin(line);
        int i = 0;
        while (ssin.good())
        {
            ssin >> arr[i];
            i++;
        }
        xs.push_back(stoi(arr[0]));
        xs.push_back(stoi(arr[2]));
        ys.push_back(stoi(arr[1]));
        ys.push_back(stoi(arr[3]));
        if (stoi(arr[0]) > x || stoi(arr[2]) > x)
        {
            x = stoi(arr[0]) > stoi(arr[2]) ? stoi(arr[0]) : stoi(arr[2]);
        }
        if (stoi(arr[1]) > y || stoi(arr[3]) > y)
        {
            y = stoi(arr[1]) > stoi(arr[3]) ? stoi(arr[1]) : stoi(arr[3]);
        }
    }
    int vents[x + 1][y + 1];
    memset(vents, 0, (x + 1) * (y + 1) * sizeof(int));
    file.clear();
    file.seekg(0);
    for (int i = 0; i < xs.size(); i = i + 2)
    {
        if (xs[i] == xs[i + 1])
        {
            int movy = ys[i] > ys[i + 1] ? ys[i] - ys[i + 1] : ys[i + 1] - ys[i];
            int smoly = ys[i] < ys[i + 1] ? ys[i] : ys[i + 1];
            for (int j = 0; j <= movy; j++)
            {
                vents[smoly + j][xs[i]]++;
            }
        }
        else if (ys[i] == ys[i + 1])
        {
            int movx = xs[i] > xs[i + 1] ? xs[i] - xs[i + 1] : xs[i + 1] - xs[i];
            int smolx = xs[i] < xs[i + 1] ? xs[i] : xs[i + 1];
            for (int j = 0; j <= movx; j++)
            {
                vents[ys[i]][smolx + j]++;
            }
        }
        else
        {
            float angl = atan2(xs[i] - xs[i + 1], ys[i] - ys[i + 1]);
            int angle = abs(angl * 180 / M_PI);
            if (angle % 45 == 0)
            {
                int movx = xs[i] > xs[i + 1] ? xs[i] - xs[i + 1] : xs[i + 1] - xs[i];
                int movy = ys[i] > ys[i + 1] ? ys[i] - ys[i + 1] : ys[i + 1] - ys[i];
                int mova = movx > movy ? movx : movy;
                for (int j = 0; j <= mova; j++)
                {
                    if (xs[i] > xs[i + 1])
                    {
                        if (ys[i] > ys[i + 1])
                        {
                            vents[ys[i] - j][xs[i] - j]++;
                        }
                        else
                        {
                            vents[ys[i] + j][xs[i] - j]++;
                        }
                    }
                    else
                    {
                        if (ys[i] > ys[i + 1])
                        {
                            vents[ys[i] - j][xs[i] + j]++;
                        }
                        else
                        {
                            vents[ys[i] + j][xs[i] + j]++;
                        }
                    }
                }
            }
        }
    }
    int cnt = 0;
    for (int i = 0; i < x + 1; i++)
    {
        for (int j = 0; j < y + 1; j++)
        {
            if (vents[i][j] >= 2)
            {
                cnt++;
            }
        }
    }
    cout << cnt << endl;

    return 0;
}

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <fstream>
#include <sstream>
#include <cstring>
#include <cstdarg>

using namespace std;

int x = 0;

int testnums(int count, ...){
    va_list args;
    va_start(args, count);
    int checknum = va_arg(args, int);
    bool flag = true;
    for (int i = 1; i < count; ++i) {
        if (checknum < va_arg(args, int))
        {
            continue;
        } else {
            flag = false;
            break;
        }
        
    }
    if(flag){
        x++;
        return checknum;
    } else {
        return 0;
    }
}



int main(int argc, char const *argv[])
{
    int sum = 0;
    string line;
    ifstream file;
    file.open("input.txt");
    int lines = 0;
    while (file.peek() != EOF)
    {
        getline(file, line);
        lines++;
    }
    int len = line.length();
    int arr[lines][len];
    memset(arr, 0, lines * len * sizeof(int));
    file.clear();
    file.seekg(0, ios::beg);
    int j = 0;
    while (file.peek() != EOF)
    {
        getline(file, line);
        for (int i = 0; i < line.length(); i++)
        {
            arr[j][i] = (int)line[i] - '0';
        }
        j++;
    }
    for (int i = 0; i < lines; i++)
    {
        for (int j = 0; j < len; j++)
        {
            if ((i == 0 && j == 0) || (i == lines-1 && j == 0) || (i == 0 && j == len-1) || (i == lines-1 && j == len-1))
            {
                if (i == 0 && j == 0)
                {
                    sum += testnums(3, arr[i][j], arr[i+1][j], arr[i][j+1]);
                } else if (i == lines-1 && j == 0)
                {
                    sum += testnums(3, arr[i][j], arr[i+1][j], arr[i][j-1]);
                } else if (i == 0 && j == len-1)
                {
                    sum += testnums(3, arr[i][j], arr[i-1][j], arr[i][j+1]);
                } else {
                    sum += testnums(3, arr[i][j], arr[i-1][j], arr[i][j-1]);
                }
                
            } else if (i == 0 || i == lines-1 || j == 0 || j == len-1)
            {
                if (i == 0)
                {
                    sum += testnums(4, arr[i][j], arr[i][j-1], arr[i][j+1], arr[i+1][j]);
                } else if(i == lines-1){
                    sum += testnums(4, arr[i][j], arr[i][j-1], arr[i][j+1], arr[i-1][j]);
                } else if(j == 0){
                    sum += testnums(4, arr[i][j], arr[i][j+1], arr[i-1][j], arr[i+1][j]);
                } else {
                    sum += testnums(4, arr[i][j], arr[i][j-1], arr[i-1][j], arr[i+1][j]);
                }
            } else {
                sum += testnums(5, arr[i][j], arr[i][j-1], arr[i-1][j], arr[i+1][j], arr[i][j + 1]);
            }
        }
        
    }
    cout << sum + x << endl;
    
    return 0;
}

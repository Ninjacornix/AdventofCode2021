#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <algorithm>
#include <sstream>

using namespace std;

char countstring(string s1, string s2, string s3, string s4, vector<char> check)
{
    int freq[7] = {0};
    char let[]{'a', 'b', 'c', 'd', 'e', 'f', 'g'};
    for (int i = 0; i < s1.length(); i++)
    {
        for (int j = 0; j < s2.length(); j++)
        {
            for (int k = 0; k < s3.length(); k++)
            {
                for (int l = 0; l < s4.length(); l++)
                {
                    if (s1[i] == s2[j] && s1[i] == s3[k] && s1[i] == s4[l])
                    {
                        freq[s1.at(i) - 'a']++;
                    }
                }
            }
        }
    }
    char c;
    for (int i = 0; i < 7; i++)
    {
        if (freq[i] > 0)
        {
            if (count(check.begin(), check.end(), let[i]))
            {
                c = let[i];
            }
        }
    }
    return c;
}

int main(int argc, char const *argv[])
{
    string end = "";
    string line;
    ifstream file;
    file.open("input.txt");
    string arr[15];
    string line2;
    vector<string> segment;
    vector<string> wire;
    int j = 0;
    char letters[7]{};
    int exit = 0;
    vector<char> customleters{'a', 'b', 'c', 'd', 'e', 'f', 'g'};
    while (file.peek() != EOF)
    {
        getline(file, line);
        stringstream ss(line);
        while (ss >> line2)
        {
            arr[j++] = line2;
        }
        j = 0;
        for (int k = 0; k < 15; k++)
        {
            if (k > 10)
            {
                segment.push_back(arr[k]);
            }
            else if (k < 10)
            {
                wire.push_back(arr[k]);
            }
        }
        sort(wire.begin(), wire.end(), [](const string &first, const string &second)
             { return first.size() < second.size(); });

        string first = wire.front();
        string second = wire.at(1);
        string third = wire.at(2);
        string forth = wire.back();
        string c1 = wire.at(6);
        string c2 = wire.at(7);
        string c3 = wire.at(8);
        string k1 = wire.at(3);
        string k2 = wire.at(4);
        string k3 = wire.at(5);

        letters[5] = countstring(first, c1, c2, c3, customleters);
        customleters.erase(find(customleters.begin(), customleters.end(), letters[5]));

        for (int i = 0; i < first.length(); i++)
        {
            if (find(customleters.begin(), customleters.end(), first.at(i)) != customleters.end())
            {
                letters[2] = *(find(customleters.begin(), customleters.end(), first.at(i)));
                customleters.erase(find(customleters.begin(), customleters.end(), first.at(i)));
                break;
            }
        }

        for (int i = 0; i < second.length(); i++)
        {
            if (find(customleters.begin(), customleters.end(), second.at(i)) != customleters.end())
            {
                letters[0] = *(find(customleters.begin(), customleters.end(), second.at(i)));
                customleters.erase(find(customleters.begin(), customleters.end(), second.at(i)));
                break;
            }
        }

        letters[3] = countstring(k1, k2, k3, third, customleters);
        customleters.erase(find(customleters.begin(), customleters.end(), letters[3]));

        for (int i = 0; i < third.size(); i++)
        {
            if (find(customleters.begin(), customleters.end(), third.at(i)) != customleters.end())
            {
                letters[1] = *(find(customleters.begin(), customleters.end(), third.at(i)));
                customleters.erase(find(customleters.begin(), customleters.end(), third.at(i)));
                break;
            }
        }

        letters[6] = countstring(c1, c2, c3, forth, customleters);
        customleters.erase(find(customleters.begin(), customleters.end(), letters[6]));

        for (int i = 0; i < forth.length(); i++)
        {
            if (find(customleters.begin(), customleters.end(), forth.at(i)) != customleters.end())
            {
                letters[4] = *(find(customleters.begin(), customleters.end(), forth.at(i)));
                customleters.erase(find(customleters.begin(), customleters.end(), forth.at(i)));
                break;
            }
        }

        for (int i = 0; i < segment.size(); i++)
        {
            if (segment[i].length() == 2)
            {
                end.append("1");
            }
            else if (segment[i].length() == 3)
            {
                end.append("7");
            }
            else if (segment[i].length() == 4)
            {
                end.append("4");
            }
            else if (segment[i].length() == 7)
            {
                end.append("8");
            }
            else if (segment[i].length() == 5)
            {
                if (segment[i].find(letters[0]) != string::npos && segment[i].find(letters[2]) != string::npos && segment[i].find(letters[3]) != string::npos && segment[i].find(letters[4]) != string::npos && segment[i].find(letters[6]) != string::npos)
                {
                    end.append("2");
                }
                else if (segment[i].find(letters[0]) != string::npos && segment[i].find(letters[2]) != string::npos && segment[i].find(letters[3]) != string::npos && segment[i].find(letters[5]) != string::npos && segment[i].find(letters[6]) != string::npos)
                {
                    end.append("3");
                }
                else if (segment[i].find(letters[0]) != string::npos && segment[i].find(letters[1]) != string::npos && segment[i].find(letters[3]) != string::npos && segment[i].find(letters[5]) != string::npos && segment[i].find(letters[6]) != string::npos)
                {
                    end.append("5");
                }
            }
            else if (segment[i].length() == 6)
            {
                if (segment[i].find(letters[0]) != string::npos && segment[i].find(letters[1]) != string::npos && segment[i].find(letters[2]) != string::npos && segment[i].find(letters[4]) != string::npos && segment[i].find(letters[5]) != string::npos && segment[i].find(letters[6]) != string::npos)
                {
                    end.append("0");
                }
                else if (segment[i].find(letters[0]) != string::npos && segment[i].find(letters[1]) != string::npos && segment[i].find(letters[3]) != string::npos && segment[i].find(letters[4]) != string::npos && segment[i].find(letters[5]) != string::npos && segment[i].find(letters[6]) != string::npos)
                {
                    end.append("6");
                }
                else if (segment[i].find(letters[0]) != string::npos && segment[i].find(letters[1]) != string::npos && segment[i].find(letters[2]) != string::npos && segment[i].find(letters[3]) != string::npos && segment[i].find(letters[5]) != string::npos && segment[i].find(letters[6]) != string::npos)
                {
                    end.append("9");
                }
            }
        }

        wire.clear();
        segment.clear();
        fill_n(letters, 7, 0);
        customleters.clear();
        customleters = {'a', 'b', 'c', 'd', 'e', 'f', 'g'};
        exit += stoi(end);
        end = "";
    }

    cout << exit << endl;

    return 0;
}

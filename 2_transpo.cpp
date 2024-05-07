#include <bits/stdc++.h>
using namespace std;

string encrypt(string str, vector<int> key)
{
    int col = key.size();
    int row = (str.length() + col - 1) / col;

    vector<vector<char>> grid(row, vector<char>(col));

    for (int i = 0, k = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            if (k < str.length())
            {
                grid[i][j] = str[k];
                k++;
            }
            else
                break;
        }
    }

    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            cout << grid[i][j] << " ";
        }
        cout << endl;
    }
    string str1 = "";
    map<int, string> mp;
    for (int col = 0; col < key.size(); col++)
    {
        str1 = "";
        for (int i = 0; i < row; i++)
        {
            str1 += grid[i][col];
        }
        mp[key[col]] = str1;
    }
    str1 = "";
    for (auto x : mp)
    {
        cout<<x.first<<" "<<x.second<<" ";
        str1 += x.second;
    }
    return str1;
}

int main()
{

    string str = "ILovemyIndia";
    // cout<<"Enter Your Message:- "<<endl;cin>>str;
    vector<int> Key = {4, 2, 1, 6, 3, 5};

    cout << encrypt(str, Key);
}
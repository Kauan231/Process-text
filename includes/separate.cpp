#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <sstream>
#include <boost/algorithm/string.hpp>
#include <algorithm>

using namespace std;

vector<string> separate(string path)
{
    string line;
    vector <string> lines, words, word;
    vector <string> ::iterator it, it2;
    ifstream file_to_open;
    file_to_open.open(path);
    if(file_to_open.is_open())
    {
        for(int i = 0; getline(file_to_open, line); i++)
        {
            lines.push_back(line);
        }
        file_to_open.close();
    }
    for(it=lines.begin(); it!=lines.end(); it++)
    {
        boost::split(words, *it, boost::is_any_of(" "));
        for(it2=words.begin(); it2!=words.end(); it2++)
        {
            string my_str = (string)*it2;
            my_str.erase(remove(my_str.begin(), my_str.end(), ','), my_str.end());
            my_str.erase(remove(my_str.begin(), my_str.end(), '.'), my_str.end());
            boost::algorithm::to_lower(my_str);
            word.push_back(my_str);
        }
        words.erase(words.begin(), words.end());
    }
    return word;
}
vector<string> get_keys(vector<string> all_words)
{
    vector<string> key_words;
    key_words = all_words;
    sort(key_words.begin(), key_words.end());
    key_words.erase(unique(key_words.begin(), key_words.end()), key_words.end());
    return key_words;
}

void show_repeat(vector<string> keys, vector<string> arr_of_words)
{
    vector <string> ::iterator it4;
    for(it4=keys.begin(); it4!= keys.end(); it4++)
    {
        cout <<"{ " << *it4 << " } Appears [ " << count(arr_of_words.begin(), arr_of_words.end(), *it4) << " ] Times" << endl;
    }
}

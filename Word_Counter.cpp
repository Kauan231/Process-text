// reading a text file
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <sstream>
#include <boost/algorithm/string.hpp>

using namespace std;


void read_from_file(vector <string> &lines)
{
    ifstream file_to_read;
    file_to_read.open("InputText");
    string line;
    if(file_to_read.is_open())
    {
        for(int i = 0; getline(file_to_read, line); i++)
        {
            lines.push_back(line); // Read lines into a array
        }
        file_to_read.close();
    }
}

void separate_by_word(vector <string> lines, vector <string> &individual_words_array)
{
    vector <string> temp_word_array;
    vector <string> ::iterator it;
    vector <string> ::iterator it2;
    for(it=lines.begin(); it!= lines.end(); it++) // iterates all the lines
    {
        boost::split(temp_word_array, *it, boost::is_any_of(" ")); // Temporary divided words array
        for(it2=temp_word_array.begin(); it2!=temp_word_array.end(); it2++)
        {
            individual_words_array.push_back(*it2); // Pushes each word individually to the main array
        }
        temp_word_array.erase(temp_word_array.begin(), temp_word_array.end()); // Clears temporary array
    }
}

void count_number_of_occurrences(vector <string> individual_words_array)
{
    vector <string> ::iterator it3;
    for(it3=individual_words_array.begin(); it3!=individual_words_array.end(); it3++)
    {
        cout << "Term [ " << *it3 << " ] Appears { " << count(individual_words_array.begin(), individual_words_array.end(), *it3) << " } Times \n";
    }
}

int main()
{
    vector <string> array_of_words;
    vector <string> array_of_lines;
    read_from_file(array_of_lines); // Copies each line of text to array
    separate_by_word(array_of_lines, array_of_words); // Transforms a array of lines into a array of words
    count_number_of_occurrences(array_of_words); // Counts occurrences of a word in the text
}

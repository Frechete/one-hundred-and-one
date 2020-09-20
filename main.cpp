#include <iostream>
#include <map>
#include <sstream>
#include <algorithm>

using namespace std;

//Consolle program, provide the input string. I. e.:
//we left to the bank and borrowed one hundred thousands. We got so upset!
//the police stopped us, and fined fifty hundred million dollars.
int main()
{

    long number, tot_number = 0;
    map<string, long>convert;
    map<string, long>convert_mult;
    string lower_number, temp, temp_lower_number;

    convert["one"] = 1;
    convert["two"] = 2;
    convert["three"] = 3;
    convert["four"] = 4;
    convert["five"] = 5;
    convert["six"] = 6;
    convert["seven"] = 7;
    convert["eight"] = 8;
    convert["nine"] = 9;
    convert["ten"] = 10;

    convert["eleven"] = 11;
    convert["twelve"] = 12;
    convert["thirteen"] = 13;
    convert["fourteen"] = 14;
    convert["fifteen"] = 15;
    convert["sixteen"] = 16;
    convert["seventeen"] = 17;
    convert["eighteen"] = 18;
    convert["ninteen"] = 19;
    convert["twenty"] = 20;
    convert["thirty"] = 30;
    convert["forty"] = 40;
    convert["fifty"] = 50;
    convert["sixty"] = 60;
    convert["seventy"] = 70;
    convert["eighty"] = 80;
    convert["ninety"] = 90;

    convert_mult["thousand"] = 1000;
    convert_mult["hundred"] = 100;
    convert_mult["thousands"] = 1000;
    convert_mult["hundreds"] = 100;
    convert_mult["millions"] = 1000000;
    convert_mult["million"] = 1000000;
    cout<<"Enter the string :";
    string number_in_word, tempString;
    getline(cin,number_in_word);//get the number in words

    if (number_in_word.empty())
    {
        cout<<" Entered: " + number_in_word + " null string!";
        return 1;
    }
    stringstream sstream_x(number_in_word);

    cout << "\nThe string: \n" << endl;
    temp_lower_number = "";
    while(getline(sstream_x,tempString, ' '))
    {
        lower_number = tempString;
        transform(lower_number.begin(), lower_number.end(), lower_number.begin(), ::tolower);

        temp = "";
        bool current = false;
        for (int i = 0; i < (int)lower_number.size(); ++i)
        {
            if (lower_number[i] >= 'a' && lower_number[i] <= 'z')
            {
                temp = temp + lower_number[i];
            }
            else
            {
                //leave the special characters in temp
                temp_lower_number = temp_lower_number + lower_number[i];
                current = true;
            }
        }

        lower_number = temp;
        number=0;
        number = convert[lower_number];
        if (!(number) && (lower_number.compare("and") != 0))
        {
            number = convert_mult[lower_number];
            if (number)
            {
                tot_number *= number;
            }
            else if (tot_number > 0)
            {
                if (!current)
                    cout << " " << tot_number << temp_lower_number << " " << tempString;
                else
                    cout << " " << tot_number << " " << tempString;
                tot_number = 0;
                temp_lower_number = "";
            }
            else
            {
                cout << " " << tempString;
                temp_lower_number = "";
            }
        }
        else if (number)
        {
            tot_number += number;
        }
        else if ((tot_number > 0) && (lower_number.compare("and") != 0))
        {
            cout << " " << tot_number << temp_lower_number << " " << tempString;
            tot_number = 0;
            temp_lower_number = "";
        }
        else if ((lower_number.compare("and") != 0) || (tot_number == 0))
        {
            cout << " " << tempString;
            temp_lower_number = "";
            //tot_number = 0;
        }
        if (current && (tot_number > 0))
        {
            cout << " " << tot_number << temp_lower_number;
            tot_number = 0;
            temp_lower_number = "";
        }
    }
    if (tot_number > 0)
    {
        cout << " " << tot_number << temp_lower_number << endl;
        tot_number = 0;
    }

    return 0;
}

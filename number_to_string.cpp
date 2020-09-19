#include<iostream>
#include<cmath>
#include <regex>
#include <string>
using namespace std;

/**
 * @brief invert
 * Method to invert the number
 * @param value input number
 * @param lim input number size
 * @return invertd number
 */
int invert(int value,int lim)
{
    if(lim==1)
        return value;
    else
        return (((value%10)*pow(10,lim-1))+invert(value/10,lim-1));
}


/**
 * @brief coutNumberOnes
 * Method to print word equivalent of a number
 * @param digit is the digit being processed
 */
void coutNumberOnes(int digit)
{
        switch(digit) //TO print digit at ones place
        {
        case 1:
            cout<<"one ";
            break;
        case 2:
            cout<<"two ";
            break;
        case 3:
            cout<<"three ";
            break;
        case 4:
            cout<<"four ";
            break;
        case 5:
            cout<<"five ";
            break;
        case 6:
            cout<<"six ";
            break;
        case 7:
            cout<<"seven ";
            break;
        case 8:
            cout<<"eight ";
            break;
        case 9:
            cout<<"nine ";
            break;
        }
}


/**
 * @brief coutNumberTeens
 * Method to print word equivalent of a number
 * TO print values such as ten,thirteen etc.
 * @param digit is the digit being processed
 */
void coutNumberTeens(int digit)
{
            switch(digit) // TO print values such as ten,thirteen etc.
            {
            case 0:
                cout<<"ten";
                break;
            case 1:
                cout<<"eleven";
                break;
            case 2:
                cout<<"twelve";
                break;
            case 3:
                cout<<"thirteen";
                break;
            case 4:
                cout<<"fourteen";
                break;
            case 5:
                cout<<"fifteen";
                break;
            case 6:
                cout<<"sixteen";
                break;
            case 7:
                cout<<"seventeen";
                break;
            case 8:
                cout<<"eighteen";
                break;
            case 9:
                cout<<"nineteen";
                break;
            }
}

/**
 * @brief coutNumber
 * Method to print word equivalent of a number
 * @param digit is the digit being processed
 * @param l is the length of number
 * @param r TO print values such as ten,thirteen etc.
 */
void coutNumber(int digit,int l,int r=12)
{
    if(l != 2)
    {
        coutNumberOnes(digit);
    }
    else if(l==2) // to print digit at tens place
    {
        switch(digit)
        {
        case 1:
            coutNumberTeens(r);
            break;
        case 2:
            cout<<"twenty ";
            break;
        case 3:
            cout<<"thirty ";
            break;
        case 4:
            cout<<"fourty ";
            break;
        case 5:
            cout<<"fifty ";
            break;
        case 6:
            cout<<"sixty ";
            break;
        case 7:
            cout<<"seventy ";
            break;
        case 8:
            cout<<"eighty ";
            break;
        case 9:
            cout<<"ninty ";
            break;
        case 0:
            cout<<"";
            break;

        }
    }
}

/**
 * @brief removeSpaces
 * Function to remove spaces
 * @param str imput string to be trimmed
 * @return trimmed string
 */
string removeSpaces(string str)
{
    stringstream ss;
    string temp;
    regex e("^\\s+|\\s+$");

    // Storing the whole string
    // into string stream
    ss << str;

    // Making the string empty
    str = "";

    // Running loop till end of stream
    while (!ss.eof())
    {

        // Extracting word by word from stream
        ss >> temp;
        regex_replace(temp, e, "");

        // Concatenating in the string to be
        // returned
        if (temp.compare(" ") != 0)
            str = str + temp;
    }
    return str;
}

/**
 * @brief main
 * Take a string from console output of numbers and convert it to number text
 * @return 0 success
 *         1 otherwise
 */
int main()
{
    int num,temp,length=0,result,n,m=0;
    string name;
    cout<<"Enter the number :";
    getline(cin >> ws, name);
    name = removeSpaces(name);
    cout<<" Entered: " + name + " Out: ";
    if (name.empty())
    {
        cout<<" Entered: " + name + " null string!";
        return 1;
    }
    num=stoi(name);
    temp=num;
    if (num < 0)
    {
        cout<<" Entered: " + name + " Negative number!";
        return 1;
    }
    for(; num>0; num/=10)
    {
        length++;
    }

    result=invert(temp,length);
    while(result)
    {
        n=result%10;
        m=m*10+n;
        result/=10;
        if(length==1)
        {
            coutNumber(n,length);
        }
        else if(length==2)
        {
            if(n==1)
            {
                coutNumber(n,length,result);
                break;
            }
            else
            {
                coutNumber(n,length);
                length--;
            }
        }
        else if(length==3)
        {
            length--;
            if(n!=0)
            {
                coutNumber(n,1);
                cout<<"hundred ";
            }
        }
        else if(length==4)
        {
            coutNumber(n,length);
            length--;
            cout<<"thousand ";
        }
        else if(length==5)
        {
            length--;
            if(n==1)
            {
                coutNumber(n,2,n%10);
                n=result%10;
                m=m*10+n;
                result/=10;

                length--;
                cout<<" thousand ";
            }
            else
            {
                coutNumber(n,2);
            }
        }
        else if(length==6)
        {
            length--;
            if(n!=0)
            {
                coutNumber(n,length);
                cout<<"hundred ";
            }
        }
        else if(length==7)
        {
            coutNumber(n,length);
            length--;
            cout<<"million ";
        }
        else if(length==8)
        {
            length--;
            if(n==1)
            {
                coutNumber(n,2,n%10);
                n=result%10;
                m=m*10+n;
                result/=10;

                length--;
                cout<<" million ";
            }
            else
            {
                coutNumber(n,2);
            }
        }
        else if(length==9)
        {
            length--;
            if(n!=0)
            {
                coutNumber(n,length);
                cout<<"hundred ";
            }
        }
        else
        {
            cout<<"billions not supported ";
            return 1;
        }

    }
    return 0;
}

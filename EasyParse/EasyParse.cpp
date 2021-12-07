
#include <iostream>

#include <fstream>
#include <string>

using namespace std;


int counter() {

    string M = "Parse.txt";                     //pobiera adresy na kazdy plik.

    ifstream read;
    read.open(M);
    string a;
    int count = 0;
    while (!read.eof()) {

        read >> a;
        count += a.length();

    }
    read.close();
    return count;
}
bool find_name(int n,char* buff ,int i ) {
    
    for (i ; i < n; i++) {
        if (buff[i] == 'e' && buff[i - 1] == 'm' && buff[i - 2] == 'a' && buff[i - 3] == 'n') {

            return true;


        }
        else return false;

    }

}

bool find_price(int n, char* buff, int i) {

    for (i; i < n; i++) {
        if (buff[i] == 'e' && buff[i - 1] == 'c' && buff[i - 2] == 'i' && buff[i - 3] == 'r') {

            return true;


        }
        else return false;

    }

}

void printer(string *arr , int m) {

    for (int i = 0; i < m; i++) {
        cout << i << ": " << arr[i] << '\n';
    }
}

void find_items_names(int n, char* buff) {

    string name_found;
    string empty_string;

    int m = 0;
    for (int i = 0; i < n; i++) {
        if (find_name(n, buff, i)) {
            m++;
        }

    }
    string* arr_names = new string[m];
    int j = 0;
    for (int i = 0; i < n; i++) {
        if (find_name(n, buff, i)) {
            i = i + 3;

            while (buff[i] != ']') {

                name_found += buff[i];
                i++;
            }

            arr_names[j] = name_found;
            name_found = empty_string;
            j++;


        }

    }

    printer(arr_names, m);
}

void find_items_prices(int n, char* buff) {

    string price_found;
    string empty_string;

    int m = 0;
    for (int i = 0; i < n; i++) {
        if (find_price(n, buff, i)) {
            m++;
        }

    }
    string* arr_prices = new string[m];


    int j = 0;
    for (int i = 0; i < n; i++) {
        if (find_price(n, buff, i)) {
            i = i + 2;

            while (buff[i] != '}') {

                price_found += buff[i];
                i++;
            }

            arr_prices[j] = price_found;
            price_found = empty_string;
            j++;


        }

    }

    printer(arr_prices, m);
}



void txt_parser() {


    string M1 = "Parse.txt";                     //pobiera adresy na kazdy plik.

    ifstream read;

    read.open(M1);

    int n = counter();
    
    char* buff = new char[n + 1];
    buff[n] = 0;
    char* buff_parse = new char[n + 1];
    buff_parse[n] = 0;


    read.getline(buff, n);

    find_items_names(n,buff);

    find_items_prices(n, buff);

    read.close();
    
}




int main()
{


    txt_parser();



    return 0;
}


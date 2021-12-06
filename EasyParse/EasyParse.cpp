
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



void reader() {


    string M1 = "Parse.txt";                     //pobiera adresy na kazdy plik.

    ifstream read;

    read.open(M1);

    int n = counter();
    
    char* buff = new char[n + 1];
    buff[n] = 0;
    char* buff_parse = new char[n + 1];
    buff_parse[n] = 0;


    read.getline(buff, n);
    
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
        if (find_name(n,buff,i)) {
            i = i+3;

            while (buff[i]!=']') {

                name_found += buff[i];
                i++;
           }

           arr_names[j] = name_found;
           name_found = empty_string;
           j++;
            
          
        }
        
    }

    


    for (int i = 0; i < m; i++) {
        cout <<i <<": " << arr_names[i]<<'\n';
    }

    read.close();
    
}




int main()
{
    reader();

    return 0;
}


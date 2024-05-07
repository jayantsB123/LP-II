#include <iostream>
#include <string>

using namespace std;

int main() {
     string str = "Hello World";
     string str1;
    
     cout << "Original string: " << str <<  endl;
     cout << "XOR with 127: ";

    for (char c : str) {
        str1 += c ^ 127; // XOR each character with 127
         cout<<c<<" ";
        //  cout<<str1<<" ";
         cout << (char)(c ^ 127)<< endl;
    }
     cout <<  endl;

    cout<<"Str1 after encryption:- "<<str1<<endl;

    string ans="";
    for(auto x:str1){
        ans+=x^127;
    }
    cout<<"After Decryption:- "<<ans<<endl;
    
    return 0;
}

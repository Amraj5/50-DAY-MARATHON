#include <iostream>
#include <string>
#include <cctype>
using namespace std;
// A string analyser in C++ using the latest means.
void analyse(const string &c){
    int digitCount= 0, vowelCount=0, consonantCount=0, spaceCount=0, totalCount=0;
    for ( char ch: c)
    {
        if (isdigit(ch)){
            digitCount++;
        }
        else if(isspace(ch)){
            spaceCount++;
        }
        else if(isalpha(ch)){
            char lower = tolower(ch);
            if(lower =='a'|| lower =='e'||  lower =='i'||  lower =='o'||  lower =='u' ){
                vowelCount++;
            }
            else{
                consonantCount++;
            }
        }
    }
    
    cout << "The total characters available is "<< c.length()<<endl;
    cout << "The total digits here is "<< digitCount<<endl;
    cout << "The total spaces here is "<< spaceCount<<endl;
    cout << "The total vowels here is "<< vowelCount<< endl;
    cout << "The total Consonants here is "<< consonantCount<<endl;
};
int main(){
    cout<< "How are you doing adventurer?"<<endl;
    cout<<endl;
    cout<< "It is time to know the worth of your words in all five ramifications"<<endl;
    cout<<endl;
    cout << "The one at the beginning tells you the weight"<<endl;
    cout<<endl;
    cout<< "The next one tells you the power of your spells"<<endl;
    cout<<endl;
    cout<<"The following one tells you the weakness of your powers"<<endl;
    cout<<endl;
    cout <<"The next one gives the light of your powers"<<endl;
    cout<<endl;
    cout<<"The last gives you the evil that resides in you"<<endl;
    cout<<endl;
    cout<< "Input your spells so we can know it's worth: "<<endl;
    cout<<endl;
    string spell;
    getline(cin, spell);
    analyse(spell);
    return 0;
}
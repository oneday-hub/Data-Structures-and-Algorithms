/* lecture : 59 ; time : 
 question : cherry's birthday is coming this month! She wants to plan a birthday party and 
            is perparing an invite list with her friend Aashi. she asks Aashi to tell her names 
            to add to the list.
           
            Aashii is a random guy and keeps coming up with names of people randomly to add to the 
            invite list, even if the name is already on the list! Cherry hates redundancy and hence, 
            enlists the names only once.

            find the final invite-list, that contain names without any repetition.
            
            input :
            First line of each test contains an integer N, the numer of names that Aashi pops up with.

            output :
            output the final invite list with each name in a new line. The names in the final invite-list are sorted lexicographically

*/
#include<iostream>
#include<set>
using namespace std;
int main(){
    set<string> invitelist;

    int n;
    cin>>n;
    while(n--){
        string name ;
        //cout<<"Enter the no of names : ";
        cin>>name;
        invitelist.insert(name);
    }
    cout<<"printing the invite list 5: ";
    for (auto name:invitelist){
        cout<<name<<endl;
    }
    return 0;
}

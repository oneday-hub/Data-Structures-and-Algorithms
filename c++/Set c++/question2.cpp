/* lecture : 59 ; time : 
 question : Add the common elements
            given 2 vectors v1 and v2. find out the common elements between the two and return the 
            sum of them.

            input :
            v1 = {1,1,2,3,3,3}
            v2 = {5,6,7,5,2,3,6}

            output :
            5

            Explaination : The values common between v1 and v2 are : 2, 3. so sum is 2+3 = 5.
*/
#include<iostream>
#include<set>
#include<vector>
using namespace std;

int main(){
    int n, m;

    // Input sizes of two vectors
    cin >> n >> m;

    vector<int> v1(n); // First vector of size n
    vector<int> v2(m); // Second vector of size m

    // Input elements of v1
    cout << "Enter elements of v1: " << endl;
    for(int i = 0; i < n; i++){
        cin >> v1[i];
    }

    // Input elements of v2
    cout << "Enter elements of v2: " << endl;
    for(int i = 0; i < m; i++){
        cin >> v2[i];
    }

    int ans_sum = 0; // To store the sum of common elements
    set<int> s1;     // Set to store unique elements of v1

    // Insert all elements of v1 into the set
    for(auto ele : v1){
        s1.insert(ele);
    }

    // Check for common elements in v2 and add them to ans_sum
    for(auto ele : v2){
        if(s1.find(ele) != s1.end()){ // If element exists in the set
            ans_sum += ele;
        }
    }

    // Output the result
    cout << "Ans: " << ans_sum << endl;

    return 0;
}

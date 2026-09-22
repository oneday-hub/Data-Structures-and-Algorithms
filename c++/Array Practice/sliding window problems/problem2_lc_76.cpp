// leetcode 76 : Minimum Window Substring
/*
"e"
"Y"
"g"
"g"
"zxgsxsczeymhaqkerxyumpjazzjfqsgRVJWEHWXNOUOpsorapwtdlyhxoplpvyVCQYSOGYAXNjwnpnrivyftoalcqnkptmudwpic"
"OVUCOQNYXSWOHGEYWAJXVNR"
"zzzzzzzzz"
"zzzzzzzzzz"
"HRULTrctorlsshmgtarxadgosylsmxsorskzqfdkujoJQTUHzRLPPyjllmvqopolorblqrijdpytjzxxvnyqihohrszawlvetnrgcnrknuandawlfzthoeoeiqsxliroreemjvqfzuimacidfymmpyljzxtwatvqszhtsjsmpgzjozxvcygidhsunqtvlbvamafbjmplrbrehjmvvlxyluuaqgbrmfxrygeylkzlflbfcwqnemigwhrrshdqiwvifoifxsaxfyqnibcwrkffbtjqxjubgrfvexqhocdvyyavdmujnfwwecqkantiaogsrgvwtwwkcczydpevynzvirsppgrdmfhbdtczprkrrvxxlxjcvauaharesmqjxhjwmrrtspsbobgofrnvdzbwiibqhrrqbtxyspnszwpxbqrwtavsmhhqrqkjegvhbeftfbicnhamhwyonlwlzysocyzshhyknbdkelplkkvazqpnzhydraoyiodssA"
"HRULTPQPJA"
"RBCPEYZQBMHUMPFLRRUELWUXBLNRTZHLKZMKBEQPNRLTVVYMZJQGVWRHBQCYFMMVCCZXBGDFZJVVYKWXVSNRNIUQNPKCETURLVQBVZMJQOGFTODPPJLFWDWUELJUUvamwdzmthclrlftcjhqadncmirlmzopyzgeamfdjqowanvsfhbdoegawcdnfholkmbvsjtfijgzoimzwspmozwhlkyusyxtstlaoiubxuxcancdKBPCECUOIBTUQBKDYIWUGGGWOFULSXHFBULUDFJPOFOJZBVRTCPQIRSXKVJFGXCVMYQHWGJMVTRPEKZLZRLXWERLPUMQYPBlhcbetrmdjjcslbzcayvtxkpczonehbyvrplbrpjtbwbqwnmhpftcjmdxlmiRCEZBHMFRULUBNTHKMBQNLVYZQVRBCFMCZBDZVYWVNNUNKEULQVMQGTDPLWWEJUUMXZQFDZIYYJRWVGJPMHYZXJDRVJEBKHhffnxramgnukqvcutbqhlgxuhtgoxudeqrcisnmtqcztsyeqdlklbuiwkqzobuitspvohwliaknzzpppexcnaeepejntqdviyhekbwwxdjuaghqjfrksponrdwkdemedsntxuhgvwbjA"
"RBCPEYZQBMHUMPFLRRUELWUXBLNRTZHLKZMKBEQPNRLTVVYMZJQGVWRHBQCYFMMVCCZXBGDFZJVVYKWXVSNRNIUQNPKCETURLVQBVZMJQOGFTODPPJLFWDWUELJUUBUFMHXXZSQLFUDFZOIWYGYGJGRUWWVIGYJDPKMBHQYUZTXBJIDORUVCJEECBPKBHKA"
"ABCllBBBBBlllllllABCDEFAAAllBBBBllZ"
"ABAAACDEFZ"
"ZSLDMKRUWQRDUHYZPEKTCSFOCIBQJVFZRBQVLNDVLHYKELDIHFOWMLDWCZTSTDJFKZOIQOGZYCOMCDBCMMQQURWNQNEKHSMLZMHPXVRCDQOZQKFXQJYXHEIPPLWQOSVTDZIHUNMOVZHBEDUJEFVLLLRNSUMWLWNBFSQXLRKVCQHRCWNFMIRVJQRISDCIJZYTHHOVBQOXPEVWOLTWYINUWWLNCOMZXPJNGNTWYIWQJFKVCTHCJERXLQOBBFHHZRFJJSIQYQDWYBTYKMQVFHOKHUMGPVIPWZGTMCKZEGWGKXIHUIJWJZMOULSMHQWZSPFTRDLZUVNWXBCKYESRNXFSSDIDWGVMQZOZEDSUGJMKUNMGMVWHFFBTWUMNJCKHXVRLSNWOTLGXQHNKSMSDRBIYWDTRGDZJHIGMIZNOKLOZVESGGQBLMBIWCOHSTRQEVZA"
"AhxByySKjQEmNdfgyqVhLuXKELUmNwBKnoxXMeOQOxqphcmftZkiqyzGOEUmtLhrBCbYkWNGrFhTaeWxrdNnwGFDFnVWHtXdJXUFqoEdoCRaqhMeXchQljqMlbJgcnsgVzxdduFVGGlxpzmIWZCLLJHfclwtRKGckNmitLXJaqEPzQaoGkdfUmSWuxsXSsihtOEeXEhIcDKjuyPdDbsVfroicpYNcPtegIMskYRRgXObOXfwPRrajGzxuCxNqgxIlSDGPhEuVlNqVQajUJpOZUMjXxsObrVhcViRidPvizmyOmDCoUnXbocUBweIdMPfmbzbvBEmDooZpYEdrOIJpFxmRdVhIEVSwYaJqWqbflPKSbrPhCgUFvaGViZTdkYYXSgpFbLRrIjsjrStTHdBqFbfsbgSOsSTdCXsRmZLhiuWosgjlcPXUzTLUFtmgNgooqteQqMvxDpJVTQjFvHYrmOqWfFpnHBUkiCaYCQpDZKSoPOnmVDavpxckwusmFsLQESlJulplWoucfcvNSbXNYHPINlSfBZHWGcPxykQurSzjfgLxtKMLyFDjJJuOoqrFrcLmYYuMcqeRKoIBIoOlUyHznxsHwibUTuTaaQopMSJqVxLZRfutStGcIVNhrbFgDHVBTCocxlHvBLlINXHYBuJpdGvZqXenqnJHuQvBpVnLOpMBYEcPOlTWoYUBvTTTvQcvJMglYgshNzxbHuhXfdedJJeSJCqhakDNlNjIREgCXhogTfxBiBbghIyyJjTVJVWQdqCyEpYTMloxLbxtJNXqfwJCvQcezblztCegIHorfHnoeEEBZrwPeveKqRxCyZImzjVRgaRkIkRqzxCjsTgKvkVvlIVIiKUPCybvHcWlhZntixLaHxEYjjdEWzyDNqOHRhheOTacIsCncMfRCLUwlWMGgDskDiaKFVFkvzsBGqrpywgvkjokjyeaxxfintejzyedqsycwtdzqhocktoqloyyeocexoxmpfgiyecollixxasxemwzsxucfdfuysnmmmzwrdvxgpirbzhechkqjxvswskbjtlhserzgnwfnqyyorjgfvlricsjesucykzbgfbaujcigyirgtpatwdhfwoujjoryryywpevwzixeocjigrrkzsgfjudawrzwnrpcsjfuplqbqkprcgrnjbtdepgjkhbgbuuumikevbqwgeukdbystfxhhqbgsgsmpwxauwlvtgrypqwufjveitlxytgmvzwptbhqfixadtvgropzodnkyspchuuknjtmctrmewztoyffliaktdcmolbimndnfelazwwbogyjvdzhvthiegoerlghlubmucxnadosforhzstbrzeplnwnelrxaijphventqqavqksqvvepnjejtqfhjrgbhwxqxwxpvreryyizyqbuzuifgpeexanoculgkxnpupgqndpcqvzlnbsxszafhsorkpvjpfzsjmbuifqxkfdemyqlgcpaodpyhihviekqbywvtubujfjglocsxaccxpwtumxeijtoqafokjrsdwjavnwcvtclqemkoadvkaydupveyijejpblkvicygovadnzexsplomzkfxstghgrhorbnpumxrdyytktekbwewwbmlbxcmhvhpmdqvsioethwawkaoiyxlusoaolpeetatdcqegtyfpsynsnrhbwnjjmsiqazstmwqvilemwzhjzlmubserxwuzqasgvwldkobgsouieebbbrituligojxrklsaiwvvzkpuyjvtymeprfarjdbonzlqepcreldeqnwrhzxtbbmvorrkmxcffpotkzznsatezzagcthclkzobsfcvcvijbzqvdwqlhnqbizkjjrwloswaexufzswbdghjadnuruqjmzjkijdqcwmxwfxzadartconewannbnmzgdzgnuinrabdhfhxwsplwzfnaandtdogzjijqadbvebzywuymgihdzvbxbudqeyalmr"
"GBFVFKDDGMWULCRMCITORHONDWEYEHLZWHCPUKIVIVKTCRIRRVIZCRKPZBEEHHICQCJXNJLMTYECQWVJVTJIBBTXCERINNDCJSJJXHNYMJQTTTBUYWTOPEYBMOLVBQHJXZGJBYHXNILBHCTBVHDFNVIGSRZLVJSMQTTUHHUOIBIKRMYYLFOJJDFLMKLSQPGWHZBSNIPHYNXSNWJSEQLFDVOPSKZDQCYCUBHFWOYHFQTVJDMQNFULTUXPWLZRXCTSOSFBHTSIRLFSXYYTZVGFUCPSKPWJYSVEIVRFJIOEYZDEBPMIBUXUCDOPRVVOXMUZOJUQVNVEPGDSINCGRPXOOXRRYMIPNYVDPKDIEXEOSXWSUGQPEJXLNGKRHJLLCZWIGGVFVJMQXMRCEFUXJXHWVFDFGNWTFGNWYCBLUEOGZOQOMXKBNULEKXLVNEQKSBA"
*/

/*
Input: s = "ADOBECODEBANC", t = "ABC"
Output: "BANC"
Explanation: The minimum window substring "BANC" includes 'A', 'B', and 'C' from string t.
Example 2:

Input: s = "a", t = "a"
Output: "a"
Explanation: The entire string s is the minimum window.
Example 3:

Input: s = "a", t = "aa"
Output: ""
Explanation: Both 'a's from t must be included in the window.
Since the largest window of s only has one 'a', return empty string.
*/
#include <bits/stdc++.h>
using namespace std;

string minWindow(string s, string t){
    if(t.size() > s.size()){
        return "";
    }
    
    unordered_map<char, int> required;
    unordered_map<char , int> window;

    for(char ch : t){
        required[ch]++;
    }

    int requiredkinds = required.size();
    int formedkinds = 0;

    int left = 0; 
    int minlength = INT_MAX;
    int startindex = 0; 


    for(int right = 0; right < s.size(); right++){
        char rightcurr = s[right];

        window[rightcurr]++;

        if(required.count(rightcurr) && window[rightcurr] == required[rightcurr]){
            formedkinds++;
        }

        while(formedkinds == requiredkinds){
            int currlength = right - left + 1; 

            if(currlength < minlength){
                minlength = currlength;
                startindex = left;
            }

            char leftcurr = s[left];

            window[leftcurr]--;

            if(required.count(leftcurr) && window[leftcurr] < required[leftcurr]){
                formedkinds--;
            }

            left++;
        }
    }

    if(minlength == INT_MAX){
        return "";
    }

    return s.substr(startindex, minlength);
}
int main() {
    string s = "ADOBECODEBANC";
    string t = "ABC";

    cout << minWindow(s, t) << endl;
    return 0;
}
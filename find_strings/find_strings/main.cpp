
#include <vector>
#include <string>
#include <iostream>
#include <algorithm>
using namespace std;

struct suffix
{
    long index;
    long rank[2];
};

long cmp(struct suffix a, struct suffix b)
{
    return (a.rank[0] == b.rank[0])? (a.rank[1] < b.rank[1] ?1: 0):
    (a.rank[0] < b.rank[0] ?1: 0);
}

vector<long> buildSuffixArray(string txt, long n)
{
    
    struct suffix suffixes[n];
    
    for (long i = 0; i < n; i++)
    {
        suffixes[i].index = i;
        suffixes[i].rank[0] = txt[i] - 'a';
        suffixes[i].rank[1] = ((i+1) < n)? (txt[i + 1] - 'a'): -1;
    }
    
    sort(suffixes, suffixes+n, cmp);
    
    long ind[n];
    
    for (long k = 4; k < 2*n; k = k*2)
    {
        // Assigning rank and index values to first suffix
        long rank = 0;
        long prev_rank = suffixes[0].rank[0];
        suffixes[0].rank[0] = rank;
        ind[suffixes[0].index] = 0;
        
        for (long i = 1; i < n; i++)
        {
            if (suffixes[i].rank[0] == prev_rank &&
                suffixes[i].rank[1] == suffixes[i-1].rank[1])
            {
                prev_rank = suffixes[i].rank[0];
                suffixes[i].rank[0] = rank;
            }
            else // Otherwise increment rank and assign
            {
                prev_rank = suffixes[i].rank[0];
                suffixes[i].rank[0] = ++rank;
            }
            ind[suffixes[i].index] = i;
        }
        
        for (long i = 0; i < n; i++)
        {
            long nextindex = suffixes[i].index + k/2;
            suffixes[i].rank[1] = (nextindex < n)?
            suffixes[ind[nextindex]].rank[0]: -1;
        }
        
        sort(suffixes, suffixes+n, cmp);
    }
    
    vector<long>suffixArr;
    for (long i = 0; i < n; i++)
        suffixArr.push_back(suffixes[i].index);
    
    return  suffixArr;
}


vector<long> kasai(string txt, vector<long> suffixArr)
{
    long n = (long)suffixArr.size();
    vector<long> lcp(n, 0);
    
    vector<long> invSuff(n, 0);
    
    for (long i=0; i < n; i++)
        invSuff[suffixArr[i]] = i;
    
    long k = 0;
    
    for (long i=0; i<n; i++)
    {
        if (invSuff[i] == n-1)
        {
            k = 0;
            continue;
        }
        
        long j = suffixArr[invSuff[i]+1];
        
        while (i+k<n && j+k<n && txt[i+k]==txt[j+k])
            k++;
        
        lcp[invSuff[i]] = k;
        
        if (k>0)
            k--;
    }
    
    return lcp;
}

void printLex(long k, string str, vector<long> SubStrNum, vector<long> sufArr, vector<long> lcp)
{
    long Index = (upper_bound(SubStrNum.begin(), SubStrNum.end(), k) - SubStrNum.begin()) - 1; //bin search, finding the index of sufArr
    long PrintIndex = sufArr[Index]; //the actual index of string that we start with
    
    long Aux = lcp[Index - 1];
    
    while (Aux > 0) //printing the initial letters that are common with the previous suffix
    {
        cout << str[PrintIndex];
        PrintIndex++;
        Aux--;
    }
    
    Aux = k - SubStrNum[Index];
    
    while (Aux > -1) //printing the rest
    {
        cout<<str[PrintIndex];
        PrintIndex++;
        Aux--;
    }
    
    cout<<endl;
}

int main()
{
    long N;
    cin >> N;
    string str;
    char c = 33;
    vector<long> Dist(123456);
    long Pos = -1;
    
    for (long i = 0; i < N; i++)
    {
        string s;
        cin >> s;
        long len = (long)s.length();

        s += c;
        
        for (long j = 0; j <= len; j++)
        {
            Pos++;
            Dist[Pos] = len - j;
        }

        str += s;
        c++;
    }
    
    vector<long>suffixArr = buildSuffixArray(str, (long)str.length());
    long n = (long)suffixArr.size();
    vector<long>lcp = kasai(str, suffixArr);
    vector<long> SubStrNum(n); //SubStrNum[i] lexicographically smallest substring starting at i in suffArr
    long Lex = 1; //lex index
    
    for (long i = 0; i < n; i++) //filling in SubStrNum[i]
    {
        if (i == 0)
        {
            SubStrNum[i] = Lex;
            Lex += Dist[suffixArr[i]];
        }
        else
        {
            SubStrNum[i] = Lex;
            Lex += (Dist[suffixArr[i]] - lcp[i-1]);
        }
    }
    
    long MaxLex = Lex;
    long Q;
    cin >> Q;
    
    for (long q = 0; q < Q; q++)
    {
        long k;
        cin >> k;
        if (k > MaxLex)
        {
            cout <<"INVALID" << endl;
        }
        else printLex(k, str, SubStrNum, suffixArr, lcp);
    }

    return 0;
}


















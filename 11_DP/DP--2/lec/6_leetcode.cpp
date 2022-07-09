
unodered_map<int,pair<int,int> > mm;
vector<vector<vector< int> > > mem;
int findMaxForm(vector<string > &str,int m,int n)
{
    int position=0;
    mem.assign(str.size()+1,vector<vector<int> > (m+1,vector<int>(n+1,-1)))  ;

    for(auto s:str)
    {
        pair<int,int> ans={0,0};
        for(aut c:s)
        {
            if(c=='0')ans.first++;
            else ans.second++;
        }
        mm[position]=ans;
        position++;
    }
    return helper(str,m,n,0);
}
int helper(vector<string> & str,int m,int n,int pos)
{
    if(pos>=str.size())
    {
        if(m>=0 and n>=0)return 0;
        else 
         return -1e9;
    }

    if(m>=0 and n>=0 and mem[pos][m][n]!=-1)
    return mem[pos][m][n];

    if(m>=0 and n>=0)
    {
        return mem[pos][m][n]=max(1+helper(str,m-mm[pos].first,n-mm[pos].second,pos+1),helper(str,m,n,pos+1));
    }
    return -1e9;
}




class Solution {
    int count(vector< pair<int, int> > &cnt, int m, int n)
    {
        int res = 0, ones = 0, zeros = 0;
        for(pair<int, int>& p:cnt)
        {
            if(p.first + zeros <= m && p.second + ones <= n)
            {
                res++;
                zeros += p.first;
                ones += p.second;
            }
        }
        return res;
    }
public:
    int findMaxForm(vector<string>& strs, int m, int n) {
        vector< pair<int, int> > cnt;
        for(string& s:strs)
        {
            int ones = 0, zeros = 0;
            for(char c:s)
            {
                if(c=='0') zeros++;
                else ones++;
            }
            cnt.push_back({zeros, ones});
        }
        // cout << cnt[0].first << ", " << cnt[0].second << endl;
        sort(cnt.begin(), cnt.end(), [](const pair<int, int>& a, const pair<int, int>& b)
             {
                 return a.first==b.first?a.second<b.second:a.first<b.first;
             });
        int rtn = count(cnt, m , n);
        sort(cnt.begin(), cnt.end(), [](const pair<int, int>& a, const pair<int, int>& b)
             {
                 return a.second==b.second?a.first<b.first:a.second<b.second;
             });
        rtn = max(rtn, count(cnt, m , n));
        sort(cnt.begin(), cnt.end(), [](const pair<int, int>& a, const pair<int, int>& b)
             {
                 return ((a.first+a.second)==(b.first+b.second))?(a.first<b.first):((a.first+a.second)<(b.first+b.second));
             });
        rtn = max(rtn, count(cnt, m , n));
        return rtn;
    }
};
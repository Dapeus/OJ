#include<bits/stdc++.h>

using namespace std;

vector<int>v[30],u[30];
int main()
{
    string s, word; 
    cin>>s;
    for(int i=0;i<s.size();i++)
    {
        if(s[i]>='A'&&s[i]<='Z')s[i]+=32;
        v[s[i]-'a'].push_back(i+1);
    }
    int ans=0;
    while(cin>>word){
        int flag=1,cnt=0;
        for (int i = 0; i < word.size(); i++)
        {
            int j=word[i]-'a';
            vector<int>::iterator pos=upper_bound(v[j].begin(),v[j].end(),cnt); 
            if(pos==v[j].end()){
                flag=0;
                break;
            }
            cnt=*pos; 
        } 
        if(flag)ans++;
        if(getchar()=='\n')break;
    }
    cout<<ans<<endl;
    system("pause");
    return 0;
}
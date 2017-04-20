#include <iostream>
#include <vector>
using namespace std;

int main()
{
    int n;
    cout<<"\nEnter number of states of NFA (states numbered from 0 to n-1): ";
    cin>>n;
    int m;
    cout<<"\nEnter number of input alphabets: ";
    cin>>m;
    vector<char> inpalpha(m);
    int i;
    cout<<"\nEnter alphabets one by one: ";
    for(i=0;i<m;++i)
        cin>>inpalpha[i];
    cout<<"\nEnter initial state number: ";
    int ini;
    cin>>ini;
    cout<<"\nEnter number of final states: ";
    int fin;
    cin>>fin;
    vector<int> finstates(fin);
    cout<<"\nEnter final states one by one: ";
    for(i=0;i<fin;++i)
        cin>>finstates[i];
    vector<vector<vector<int> > > nfatable(n,vector<vector<int> >(m,vector<int>()));
    int j;
    cout<<"\nEnter state transitions: ";
    for(i=0;i<n;++i) {
        for(j=0;j<m;++j) {
            cout<<"\nNo. of states in delta(q"<<i<<","<<inpalpha[j]<<"): ";
            int x;
            cin>>x;
            vector<int> temp(x);
            cout<<"\nEnter states one by one: ";
            int q;
            int w;
            for(q=0;q<x;++q) {
            cin>>w;
            nfatable[i][j].push_back(w);
            }
        }
    }
   /* for(i=0;i<n;++i) {
        for(j=0;j<m;++j) {
            cout<<"\nq"<<i<<","<<inpalpha[j]<<"): ";
            int q;
            for(q=0;q<nfatable[i][j].size();++q) {
            cout<<nfatable[i][j][q]<<" ";
            }
        }
    }*/
    vector<vector<int> > dfastates;
    vector<int> st;
    st.push_back(ini);
    dfastates.push_back(st);
    int k=0;
    vector<vector<int> > dfatable;
    while(k<dfastates.size()) {
        vector<int> temp;
        for(i=0;i<m;++i) {
            vector<int> temp2;
            for(j=0;j<dfastates[k].size();++j) {
                int q;
                for(q=0;q<nfatable[dfastates[k][j]][i].size();++q) {
                    int w=0;
                    int s=nfatable[dfastates[k][j]][i][q];
                    for(w=0;w<temp2.size();++w) {
                        if(temp2[w]==s)
                            break;
                        else if(temp2[w]>s) {
                            temp2.insert(temp2.begin()+w,s);
                            break;
                        }
                    }
                    if(w==temp2.size())
                        temp2.push_back(s);
                }
            }
            int w=-1;
            for(j=0;j<dfastates.size();++j) {
                if(dfastates[j].size()==temp2.size()) {
                    int q;
                    for(q=0;q<temp2.size();++q) {
                        if(dfastates[j][q]!=temp2[q])
                            break;
                    }
                    if(q==temp2.size()) {
                        w=j;
                        break;
                    }
                }
            }
            if(w==-1) {
                    dfastates.push_back(temp2);
                    w=dfastates.size()-1;
                }
            temp.push_back(w);
        }
        dfatable.push_back(temp);
        ++k;
    }
    cout<<"\n\n";
    cout<<"\nThe five tupple DFA corresponding to the given NFA is as follows: ";
    cout<<"\nStates: ";
    for(i=0;i<dfastates.size();++i) {
            cout<<"\n[";
            for(j=0;j<dfastates[i].size();++j) {
        cout<<"q"<<dfastates[i][j];
            }
    cout<<"]";
    }
    cout<"\n\n";
    cout<<"\nInitial state is: [q"<<dfastates[0][0]<<"]";
    cout<<"\n";
    cout<<"\nFinal states are: ";
    for(i=0;i<dfastates.size();++i) {
            int f=0;
        for(j=0;j<dfastates[i].size();++j) {
            for(k=0;k<finstates.size();++k) {
                if(dfastates[i][j]==finstates[k]) {
                    f=1;
                    break;
                }
            }
            if(f==1)
                break;
        }
        if(f==0)
            continue;
        cout<<"\n[";
            for(j=0;j<dfastates[i].size();++j) {
        cout<<"q"<<dfastates[i][j];
            }
    cout<<"]";
    }
    cout<<"\n";
    cout<<"\t\t";
    for(k=0;k<m;++k) {
        cout<<inpalpha[k]<<"\t";
    }
    for(i=0;i<dfastates.size();++i) {
        cout<<"\n[";
            for(j=0;j<dfastates[i].size();++j) {
        cout<<"q"<<dfastates[i][j];
            }
    cout<<"]\t\t";
    for(k=0;k<m;++k) {
        cout<<"[";
            for(j=0;j<dfastates[dfatable[i][k]].size();++j) {
        cout<<"q"<<dfastates[dfatable[i][k]][j];
            }
    cout<<"]\t";
    }
    }
    return 0;
}

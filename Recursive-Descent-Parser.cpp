#include <iostream>
#include <vector>
#include <string>
using namespace std;
bool E(int &t, string inp, vector<string> &prodseq);
bool F(int &t, string inp,vector<string> &prodseq) {
    if(t>=inp.size())
        return false;
if(inp[t]=='i') {
    ++t;
    if(prodseq.size()==0) {
            prodseq.push_back("i");
        }
        else {
                int j;
            string w=prodseq[prodseq.size()-1];
            for(j=0;j<w.size();++j) {
                if(w[j]=='F')
                    break;
            }
            w.erase(w.begin()+j);
            w.insert(j,"i");
            prodseq.push_back(w);
        }
    return true;
}
else if(inp[t]=='(') {
            if(prodseq.size()==0) {
            prodseq.push_back("(E)");
        }
        else {
                int j;
            string w=prodseq[prodseq.size()-1];
            for(j=0;j<w.size();++j) {
                if(w[j]=='F')
                    break;
            }
            w.erase(w.begin()+j);
            w.insert(j,"(E)");
            prodseq.push_back(w);
        }
    ++t;
    bool q1=E(t,inp,prodseq);
    if(q1==false)
        return false;
    if(t>=inp.size())
        return false;
    if(inp[t]==')') {
        ++t;

        return true;
    }
    else
        return false;
    }
    else
        return false;
}
bool B(int &t, string inp,vector<string> &prodseq) {
    if(t>=inp.size())
        return false;
if(inp[t]=='*') {
        if(prodseq.size()==0) {
            prodseq.push_back("*FB");
        }
        else {
                int j;
            string w=prodseq[prodseq.size()-1];
            for(j=0;j<w.size();++j) {
                if(w[j]=='B')
                    break;
            }
            w.erase(w.begin()+j);
            w.insert(j,"*FB");
            prodseq.push_back(w);
        }
    ++t;
   bool q1=F(t,inp,prodseq);
    if(q1==false)
        return false;
    bool q2=B(t,inp,prodseq);
    if(q2==false)
        return false;
    else {

        return true;
    }
}
else {
        int j;
    string w=prodseq[prodseq.size()-1];
    for(j=0;j<w.size();++j) {
           if(w[j]=='B')
               break;
     }
     w.erase(w.begin()+j);
     prodseq.push_back(w);
    return true;
}
}
bool T(int &t, string inp,vector<string> &prodseq) {
    if(prodseq.size()==0) {
            prodseq.push_back("FB");
        }
        else {
                int j;
            string w=prodseq[prodseq.size()-1];
            for(j=0;j<w.size();++j) {
                if(w[j]=='T')
                    break;
            }
            w.erase(w.begin()+j);
            w.insert(j,"FB");
            prodseq.push_back(w);
        }
    bool q1=F(t,inp,prodseq);
    if(q1==false)
        return false;
    bool q2=B(t,inp,prodseq);
    if(q2==false)
        return false;
    else {

        return true;
    }
}
bool A(int &t, string inp,vector<string> &prodseq) {
    if(t>=inp.size())
        return false;
if(inp[t]=='+') {
        if(prodseq.size()==0) {
            prodseq.push_back("+TA");
        }
        else {
                int j;
            string w=prodseq[prodseq.size()-1];
            for(j=0;j<w.size();++j) {
                if(w[j]=='A')
                    break;
            }
            w.erase(w.begin()+j);
            w.insert(j,"+TA");
            prodseq.push_back(w);
        }
    ++t;
    bool q1=T(t,inp,prodseq);
    if(q1==false)
        return false;
    bool q2=A(t,inp,prodseq);
    if(q2==false)
        return false;
    else {
        return true;
    }
}
else {
    int j;
    string w=prodseq[prodseq.size()-1];
    for(j=0;j<w.size();++j) {
           if(w[j]=='A')
               break;
     }
     w.erase(w.begin()+j);
     prodseq.push_back(w);
    return true;
}
}
bool E(int &t, string inp, vector<string> &prodseq) {
    if(prodseq.size()==0) {
            prodseq.push_back("TA");
        }
        else {
                int j;
            string w=prodseq[prodseq.size()-1];
            for(j=0;j<w.size();++j) {
                if(w[j]=='E')
                    break;
            }
            w.erase(w.begin()+j);
            w.insert(j,"TA");
            prodseq.push_back(w);
        }
    bool q1=T(t,inp,prodseq);
    if(q1==false)
        return false;
    bool q2=A(t,inp,prodseq);
    if(q2==false)
        return false;
    else {
        return true;
    }
}
int main()
{
    string inp;
    cout<<"\nEnter the input string: ";
    cin>>inp;
    inp+="$";
    int t=0;
    vector<string> prodseq;
    bool q=E(t,inp,prodseq);
    if(q==false||t>=inp.size()||inp[t]!='$') {
    cout<<"\nString cannot be parsed";
    return 0;
    }
    cout<<"\nLeft most derivation of the string is";
    int i;
    for(i=0;i<prodseq.size();++i) {
        if(i==0)
            cout<<"\nE->"<<prodseq[i];
        else
            cout<<"\n ->"<<prodseq[i];
    }
    return 0;
}

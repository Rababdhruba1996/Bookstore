#include<bits/stdc++.h>
using namespace std;
int n;
struct st
{
    string bn,author,P;
    int t,pg,dp,sz,p,total;
} S[100];
class book
{
protected:
    string book_name,author;
    int tk,page;
    double discount_price;
    int discount;
public:
    book()
    {

    }
    book(string a,string b,int c,int d,double f): book_name(a),author(b),tk(c),page(d),discount_price(f)
    {

    }
    void get_Detail()
    {
        cout<<"Enter book name: ";
        getline(cin,book_name);
        cout<<"Enter author name: ";
        getline(cin,author);
        cout<<"Enter price: ";
        cin>>tk;
        cout<<"Enter discount: ";
        cin>>discount;
        cout<<"Enter page: ";
        cin>>page;
    }
    virtual void print()
    {
        cout<<"Detail for hard copy: "<<endl;
        cout<<"Book name: ";
        cout<<book_name<<endl;
        cout<<"author name: ";
        cout<<author<<endl;
        cout<<"Price: ";
        cout<<tk<<endl;
        cout<<"Discount price: ";
        cout<<discount_price<<endl;
        cout<<"Page: ";
        cout<<page<<endl;
    }
    //friend class soft;
};
class audio: public book
{
protected:
    int sz,Price;
public:
    audio()
    {

    }
    audio(int a,int b): sz(a),Price(b)
    {

    }
    void get_detail()
    {
        cout<<"Enter size of audio book: ";
        cin>>sz;
        cout<<"Enter price: ";
        cin>>Price;
    }
    virtual void print()
    {
        cout<<"Detail for audio copy: "<<endl;
        if(sz==0)
        {
            cout<<"No audio copy."<<endl;
        }
        else
        {
            cout<<"Size of audio book: ";
            cout<<sz<<endl;
            cout<<"Price: ";
            cout<<Price<<endl;
        }
    }
    //friend class soft;
};
class soft : public audio
{
private:
    string price;
    int total;
public:
    soft()
    {

    }
    soft(string a,int b): price(a),total(b)
    {

    }
    void get_detail3()
    {
        get_Detail();
        get_detail();
        cout<<"Enter price of soft copy: ";
        cin>>price;
    }
    void print()
    {
        book::print();
        audio::print();
        cout<<"Detail for soft copy: "<<endl;
        if(price=="0")
            cout<<"No soft copy."<<endl;
        else
        {
            cout<<"Price of soft copy: ";
            cout<<price<<endl;
        }
    }
    soft dis(soft x)
    {
        x.discount_price=x.tk-((x.tk*x.discount)/100.00);
        return (x);
    }
    soft operator +(soft &obj)
    {
        soft x;
        x.discount_price=(this->discount_price) + (obj.discount_price);
        return (x);
    }
    void totalp(soft a)
    {
        cout<<"Total price: "<<a.discount_price<<endl;
    }
    friend soft searching(int n,soft d[],string s1,string s2);
    friend st copying(soft D);
};
soft searching(int n,soft d[],string s1,string s2)
{
    for(int i=0; i<n; i++)
    {
        if(d[i].book_name==s1&&d[i].author==s2)
        {
            return d[i];
            //id[i].print_detail();
            break;
        }
    }
}
st copying(soft D)
{
    st S;
    S.bn=D.book_name;
    S.author=D.author;
    S.p=D.Price;
    S.t=D.tk;
    S.pg=D.page;
    S.dp=D.discount_price;
    S.sz=D.sz;
    S.P=D.price;
    S.total=D.discount_price;
    return S;
}
int main()
{
    audio *a;
    ofstream output;
    outfile.open("rabu", ios::out);
    soft s[100],t[100];
    cout<<"Enter the number of book: ";
    cin>>n;
    string s1,s2;
    for(int i=0; i<n; i++)
    {
        getchar();
        s[i].get_detail3();
    }
    for(int i=0; i<n; i++)
    {
        s[i]=s[i].dis(s[i]);
    }
    getchar();
    int n1,k=0;
    cout<<"Enter how many book you want to buy: ";
    cin>>n1;
    getchar();
    for(int i=1; i<=n1; i++)
    {
        cout<<"Enter your book name: ";
        getline(cin,s1);
        cout<<"Enter author name: ";
        getline(cin,s2);
        t[k]=searching(n,s,s1,s2);
        k++;
    }
    if(k>0)
    {
    for(int i=0; i<k; i++)
        S[i]=copying(t[i]);
    for(int i=0; i<k; i++)
    {
        output<<"Detail for hard copy: "<<endl;
        output<<"Book name: ";
        output<<S[i].bn<<endl;
        output<<"author name: ";
        output<<S[i].author<<endl;
        output<<"Price: ";
        output<<S[i].t<<endl;
        output<<"Discount price: ";
        output<<S[i].dp<<endl;
        output<<"Page: ";
        output<<S[i].pg<<endl;
        output<<"Detail for audio copy: "<<endl;
        if(S[i].sz==0)
        {
            output<<"No audio copy."<<endl;
        }
        else
        {
            output<<"Size of audio book: ";
            output<<S[i].sz<<endl;
            output<<"Price: ";
            output<<S[i].p<<endl;
        }
        output<<"Detail for soft copy: "<<endl;
        if(S[i].P=="0")
            output<<"No soft copy."<<endl;
        else
        {
            output<<"Price of soft copy: ";
            output<<S[i].P<<endl;
        }
    }
    for(int i=0;i<k;i++)
    {
        a=&t[i];
        a->print();
    }
    for(int i=1; i<k; i++)
    {
        t[i]=t[i-1]+t[i];
    }
        S[k]=copying(t[k-1]);
        output<<"Total Price: "<<S[k].total<<endl;
    }
    else
    {
        output<<"SORRY! :( NO SUCH BOOK!"<<endl;
    }
    return 0;
}

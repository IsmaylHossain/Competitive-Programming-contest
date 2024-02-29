#include<bits/stdc++.h>

using namespace std;

#define endl            "\n"
 
#define ui              unsigned int
#define ll              long long int
#define ld              long double
#define ull             unsigned long long int
 
 
#define ff              first
#define ss              second
#define pb              push_back
#define mp              make_pair
 
 
#define pii             pair<int,int>
#define vi              vector<int>
#define mii             map<int,int>
#define pqb             priority_queue<int>
#define pqs             priority_queue<int,vi,greater<int> > //read??
 
 
#define setbits(x)      __builtin_popcountll(x) //return total setbit
#define zrobits(x)      __builtin_ctzll(x)      //return total 0 until 1 found
#define ps(x,y)         fixed<<setprecision(y)<<x
#define mk(arr,n,type)  type *arr=new type[n];
#define sz(x)           (int)x.size()
#define tc(t)           int t; cin>>t; while(t--)
 
 
#define arrsort(ar,n)   sort(ar,ar+n);
#define vsort(v)        sort(v.begin(),v.end())
#define vrev(v)         reverse(v.begin(),v.end())
#define arrev(ar,n)     reverse(ar,ar+n)
 
 
#define fo(i,k,n)       for(i=k;k<n?i<n:i>n;k<n?i+=1:i-=1)
#define deb(x)          cout << #x << "=" << x << endl
#define deb2(x, y)      cout << #x << "=" << x << "," << #y << "=" << y << endl
#define iter(it, a)     for(auto it = a.begin(); it != a.end(); it++)
#define riter(it,a)     for(auto it = a.rbegin();it != a.rend(); it++)
#define for0(i,n)       for(ll i=0;i<n;i++)
 
 
 
#define fast            ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0)
 
 
#define PI              acos(-1.0)
#define EPS             1e-12
 
 
const ll                inf = 1000000000;
const ll                mod = 1000000000 + 7;
 
 
 
#define mxe(v) *max_element(all(v))
#define all(x) (x).begin(),(x).end()
#define ok     cout<<"ok"<<endl


bool isLeapYear(int year) {
    if ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0)) {
        return true;
    }
    return false;
}

int getDaysInMonth(int month, int year) {
    switch (month) {
        case 2:
            return isLeapYear(year) ? 29 : 28;
        case 4:
        case 6:
        case 9:
        case 11:
            return 30;
        default:
            return 31;
    }
}

int getDayIndex(string day) {
    if(day == "Sun") return 0;
    if(day == "Mon") return 1;
    if(day == "Tue") return 2;
    if(day == "Wed") return 3;
    if(day == "Thu") return 4;
    if(day == "Fri") return 5;
    if(day == "Sat") return 6;
}

int main() {
    int T;
    cin >> T;

    for (int t = 1; t <= T; ++t) {
         string dateStr;
        cin.ignore();

        getline(cin, dateStr);

        istringstream ss(dateStr);
        string datePart;
        
        getline(ss, datePart, '/'); 
        int day = stoi(datePart);

        getline(ss, datePart, '/'); 
        int month = stoi(datePart);

        getline(ss, datePart, ' '); 
        int year = stoi(datePart);

        string dayName;
        ss >> dayName;

        int totalDays = getDaysInMonth(month, year);
        int dayIndex = getDayIndex(dayName);

        vector<int> calendar(35, 0);

        for(int i = 0; i < totalDays; i++) {
            calendar[i] = i+1;
        }

        rotate(calendar.rbegin(), calendar.rbegin() + 1, calendar.rend());
        rotate(calendar.rbegin(), calendar.rbegin() + 1, calendar.rend());
        rotate(calendar.rbegin(), calendar.rbegin() + 1, calendar.rend());
        rotate(calendar.rbegin(), calendar.rbegin() + 1, calendar.rend());
        rotate(calendar.rbegin(), calendar.rbegin() + 1, calendar.rend());
        rotate(calendar.rbegin(), calendar.rbegin() + 1, calendar.rend());

        cout << "|---------------------------|\n";
        cout << "|Sun|Mon|Tue|Wed|Thu|Fri|Sat|\n";
        cout << "|---------------------------|\n";

         for (int i = 0; i < 5; ++i) {
            cout << "|";
            for (int j = 0; j < 7; ++j) {
                int index = i * 7 + j;
                if (calendar[index] == 0) {
                    cout << " - ";
                } else {
                    cout << " " << setw(2) << calendar[index];
                }
                cout << "|";
            }
            cout << "\n|---------------------------|\n";
        }

        cout << endl;
    
    }

 
}
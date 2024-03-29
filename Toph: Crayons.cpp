///**Bismillahir Rahmanir Rahim.**
///Amantu Amir, University of Barishal, Bangladesh
///Accepted
#include <bits/stdc++.h>
#define int                   long long int
#define clr(a, v)             memset(a, v, sizeof a)
#define all(v)                v.begin(), v.end()
#define ast(v)                sort(v.begin(),v.end())
#define dst(v)                sort(v.begin(),v.end(), greater <int> ())
#define fast ios_base::       sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define ass(cur, v)           cur.assign(v.begin(), v.end())
#define rep(i, l, r)          for (int i = l; i < r; i++)
#define rep2(i, l, r)         for (int i = l-1; i >= r; i--)
#define sfs(s)                scanf("%s", s)
#define sf(n)                 scanf("%lld", &n)
#define sff(n, m)             scanf("%lld %lld",&n,&m)
#define sfff(n, m, o)         scanf("%lld %lld %lld",&n,&m,&o)
#define PP(n, m)              cout << n << " " << m << "\n"
#define PPP(a, b, c)          cout<<a<<" "<<b<<" "<<c<<"\n"
#define mxe(a,n)              *max_element(all(a))
#define mne(a,n)              *min_element(all(a))
#define SUM(a)                accumulate(all(a),0)
#define I(n)                  cin >> n
#define II(n, m)              cin >> n >> m
#define III(a, b, c)          cin >> a >> b >> c
#define MIN(a, b, c)          min(a, min(b, c))
#define MAX(a, b, c)          max(a, max(b, c))
#define MID(b, e)             (b+(e-b))/2
#define left(node)            node*2
#define right(node)           node*2+1
#define CAS(a)                cout << "Case " << a << ":"
#define pf(n)                 printf("%lld", n)
#define pff(n,m)              printf("%lld %lld\n",n,m)
#define prln(n)               printf("%lld\n", n)
#define P(n)                  cout << n
#define debug                 cout << " debug\n"
#define yes                   cout << "YES\n"
#define no                    cout << "NO\n"
#define sp                    cout << " "
#define nl                    cout << "\n"
#define ub                    upper_bound
#define lb                    lower_bound
#define pii                   pair<int,int>
#define vecI                  vector<int>
#define vecS                  vector<string>
#define vecC                  vector<char>
#define mp                    make_pair
#define pb                    push_back
#define S                     second
#define F                     first

using namespace std;
const int N = 1e5+5;
const int mod = 1e9+7;
bool is_prime[N+50];
vector<int>prime,primeFactor;
int digit(int n){return log10(n)+1;}
int biton(int n,int pos){return n=n|(1<<pos);}
int bitoff(int n,int pos){return n=n&~(1<<pos);}
bool check(int n,int pos){return (bool)(n&(1<<pos));}
string toString(int n){stringstream ss;ss<<n;string s;ss>>s;return s;}
int toInt(string s){stringstream ss;ss<<s;int n;ss>>n;return n;}
bool isVowel(char ch){ ch=toupper(ch); if(ch=='A'||ch=='U'||ch=='I'||ch=='O'||ch=='E') return true; return false;}
bool isConst(char ch){if (isalpha(ch) && !isVowel(ch)) return true; return false;}
int digit_sum_1toN(int n){if (n<10)return n*(n+1)/2;int d = log10(n);int a[100];a[0] = 0, a[1] = 45;for (int i=2; i<=d; i++)a[i] = a[i-1]*10 + 45*ceil(pow(10,i-1));int p = ceil(pow(10, d));int msd = n/p;return msd*a[d] + (msd*(msd-1)/2)*p +msd*(1+n%p) + digit_sum_1toN(n%p);}
void sieve(){prime.push_back(2);for(int i=4;i<=N;i+=2)is_prime[i]=1;for(int i=3; i<100; i+=2){if(is_prime[i] == 0){prime.push_back(i);for(int j = i*i; j<N; j += (i*2))is_prime[j]=1;}}}
bool isPrime(int n){if(n == 1) return false;if(n == 2) return true;if(n%2 == 0) return false;for(int i = 3; i * i <= n; i += 2 )if(n%i == 0) return false;return true;}
void primeFac(int n){int tmp = sqrt(n);for(int i = 0; prime[i] <= tmp; i++){if(n%prime[i] == 0){while(n%prime[i] == 0){n /= prime[i];primeFactor.pb(prime[i]);}}}if(n > 1)primeFactor.pb(n);}
int SOD(int n){int sum = 1;for(int i = 0; prime[i] <= n; i++){if(n%prime[i] == 0){int cnt = 1;while(n%prime[i] == 0){n /= prime[i];cnt++;}sum *= (pow(prime[i], cnt) - 1)/ (prime[i] - 1);}}return sum;}
int NOD(int n){int till=sqrt(n+1);int p,divisor=1;for(int i=0;prime[i]<=till;i++){if(n%prime[i]==0){p=1;while(n%prime[i]==0){n/=prime[i];p++;}till=sqrt(n);divisor*=p;}}if(n>1)divisor*=2;return divisor;}
vecI single(vecI vec){ast(vec);vec.erase(unique(all(vec)),vec.end()); return vec;}
bool isDigit(char ch){if(ch >= 48 && ch <= 57) return true; else return false;}
string UPPER(string s){transform(all(s),s.begin(),::toupper);return s;}
string LOWER(string s){transform(all(s),s.begin(),::tolower);return s;}
//Template end
//-------------------******Alhamdulillah******--------------------//


struct temp{
    char idx;
    int l, r, id;
};

temp Q[N];
int k, ans, a[10];
map<int,int> m;
int v[N], ar[N];
string res[N];

bool cmp(temp a, temp b){
    int block_a = a.l/k;
    int block_b = b.l/k;
    if(block_a == block_b) return a.r < b.r;
    return block_a < block_b;
}

void add(int x){
    ar[v[x]]++;
    if(ar[v[x]] == 1){
        ans++;
    }
}

void remove(int x){
    ar[v[x]]--;
    if(ar[v[x]] == 0){
        ans--;
    }
}

void solve(int n, int q){
    k = sqrt(n);
    sort(Q, Q+q, cmp);
    int currL = 0, currR = 0;
    rep(i, 0, q){
        while(currL > Q[i].l) add(--currL);
        while(currR < Q[i].r) add(++currR);
        while(currL < Q[i].l) remove(currL++);
        while(currR > Q[i].r) remove(currR--);
        if(a[Q[i].idx-'A'] <= ans) res[Q[i].id] = "Yes";
        else res[Q[i].id] = "No";
    }
}


int32_t main(){
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    fast;
    int tc = 1, cas = 0;
    while(tc--){
        rep(i, 0, 5){
            I(a[i]);
        }
        int n, q; II(n, q);
        int x, cnt = 1, c = 1;
        rep(i, 1, n+1){
            I(x);
            if(m.find(x) == m.end()){       //array compressed
                m[x] = cnt;
                cnt++;
            }
            x = m[x];
            v[c++] = x;
        }
        rep(i, 0, q){
            III(Q[i].idx, Q[i].l, Q[i].r);
            Q[i].id = i;
        }
        solve(n, q);
        rep(i, 0, q){
           P(res[i]); nl;
        }
    }
    return 0;

}

//--------------------******Alhamdulillah******-------------------//


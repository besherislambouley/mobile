/*
 * we use binary search on answer , now consider every point as a center of a circle with radius Mid 
 * now find the segment the i'th circle covers , and check if the segments covers all the road 
*/
#define fast ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0)
#include <bits/stdc++.h>
using namespace std;
#define sqr 547
#define mp make_pair
#define mid (l+r)/2
#define pb push_back
#define ppb pop_back
#define fi first
#define se second
#define lb lower_bound
#define ub upper_bound
#define ins insert
#define era erase
#define C continue
#define mem(dp,i) memset(dp,i,sizeof(dp))
#define mset multiset
#define all(x) x.begin(), x.end()
typedef long long ll;
typedef short int si;
typedef long double ld;
typedef pair<int,int> pi;
typedef pair<ll,ll> pll;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef vector<pi> vpi;
typedef vector<pll> vpll;
const ll inf=1e18;
const ll mod=1e9+7;
const ld pai=acos(-1);
ll N , En ;
pll A [1000009] ;
bool Check ( double Mid ) {
  	double Mx = 0 ;
        for ( int i = 0 ; i < N ; i ++ ) {
                double Len = sqrt ( Mid * Mid  - A [i] .se * A [i] .se ) ;
                double L = A [i].fi - Len , R = A [i].fi + Len ;
		if ( L <= Mx ) Mx = max ( Mx , R ) ; 
        }
        return ( Mx >= En )  ;
}
int main () {
        cin >> N >> En ;
        for ( int i = 0 ; i < N ; i ++ ) scanf("%lld%lld",&A[i].fi,&A[i].se) ;
        double L = 1 , R = 5e8 ;
        while ( R - L > 0.001 ) {
                double Mid = ( L + R ) / 2.0 ;
                if ( Check ( Mid ) ) R = Mid ;
                else L = Mid ;
        }
        cout << fixed << setprecision (4) << L << endl ;
}

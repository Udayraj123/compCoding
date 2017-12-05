    #include <bits/stdc++.h>
     
    #define ll long long int
     
    #define pb push_back
    #define mp make_pair
    #define F first
    #define S second
     
    #define DEBUG(x) cout << '>' << #x << ':' << x << endl;
    #define REP(i,n) for(ll i=0;i<(n);i++)
    #define FOR(i,a,b) for(ll i=(a);i<=(b);i++)
    #define FORD(i,a,b) for(ll i=(a);i>=(b);i--)
    #define all(v) (v).begin(),(v).end()
     
    using namespace std;
    ///////////////////////////////////////////////////////
    #define MAX 1000010
     
    vector <int> g[MAX][MAX];
     
    bool v[MAX]={false};
    int sp[MAX];
     
    void Sieve(){
 
	//for (int i = 3; i < MAX; i += 2)
	//	v[i] = false;
	//cout<<"Running"<<"\n";
	for (int i = 2; i < MAX; i += 2)	
		sp[i] = 2;//even numbers have smallest prime factor 2
	//cout<<"Running"<<"\n";	
	for (int i = 3; i < MAX; i += 2){
		//DEBUG(i);
		if (v[i]==false){
			sp[i] = i;
			for (ll j = i; (j*i) < MAX; j += 2){
				if (v[j*i]==false){	
					v[j*i] = true;
					 sp[j*i] = i;
				}
			}
		}
		//cout<<"done"<<"\n";
	}
}
     
     
    vector <int> factorize(int k) {
    	vector <int> ans;
    	while(k>1) {
    		ans.push_back(sp[k]);
    		k/=sp[k];
    	}
    	return ans;
    }
    inline void swap(int* a, int *b){
    	int temp;
    	temp = *a;
    	*a=*b;
    	*b=temp;
     
    }
     
    /*void solve2(int l, int r, int x, int y,vector <int> f){
     
    	ll count=0;
     
    		FOR(i,l-1,r-1){
    		//cout<<(a+i)->pfactors.size();
    		for (unsigned j=0; j<(f+i).size() ; j++){
        		if( (f+i)[j]>=x && (f+i)[j]<=y )
    				count++;
    			else if( (f+i)[j]>y )
    				break;
    		}
    	}
     
    	cout<<count<<"\n";
    			
     
    }*/
     
    int main(){
    	std::ios_base::sync_with_stdio(false);
    	cin.tie(NULL);
    	//cout<<"Running"<<"\n";
    	Sieve();
    	//cout<<"Running"vector <int> g[MAX][MAX];<"\n";
    	int n;
    	cin>>n;
    	int a[n];
    	vector <int> f[n];
    	FOR(i,0,n-1){
    		cin>>a[i];
    		f[i]=factorize(a[i]);
    	}


    	FOR(i,0,n-1)	
    		g[i][i].insert(g[i][i].end(), f[i].begin(), f[i].end());

    	FOR(l,2,n){
        	FOR(i,0,n-l){
            	ll j=i+l-1;
            	g[i][j].insert(g[i][j].end(), g[i][j-1].begin(), g[i][j-1].end());
           		g[i][j].insert(g[i][j].end(), f[j].begin(), f[j].end());
            	sort(g[i][j].begin(),g[i][j].end());
        	}
    	}
    	int q;
    	cin>>q;
    	int l,r,x,y;
    	while(q--){
    		cin>>l>>r>>x>>y;
    		if (l>r)
    			swap(l,r);
    		if(x>y)
    			swap(x,y);
     
    		ll count=0;
     
    		//cout<<(a+i)->pfactors.size();
    		for (unsigned j=0; j<(g[l-1][r-1]).size() ; j++){
        		if( (g[l-1][r-1])[j]>=x && (g[l-1][r-1])[j]<=y )
    				count++;
    			else if( (g[l-1][r-1])[j]>y )
    				break;
    		}
    		
     
    	cout<<count<<"\n";
     
    	}
    	
    	
     
     
        return 0;
    } 
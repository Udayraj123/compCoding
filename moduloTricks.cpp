#include<bits/stdc++.h>
#define ll long long int
#define MOD 10//00000007
#define MAX 100000
using namespace std;

template<typename Number, Number m>
class modNum
{
private:
	Number a;
public:
	// for printing : cout<<(sumX+sumZ);
    friend ostream& operator<<(ostream& os, modNum const & num) {
          return os << num.a;
      }
	modNum(Number a) : a(a % m) {}
	Number get() const { return a; }

	modNum operator+= (modNum b){ a = (a + b.get()) % m; return a; }
	modNum operator*= (modNum b){ a = (a * b.get()) % m; return a; }
	modNum operator/= (modNum b){ a = (a / b.get()) % m; return a; }
	modNum operator-= (modNum b){ a = (a - b.get()) % m; return a; }
	modNum operator + (modNum b){modNum t = (a + b.get()) % m; return t;}
	modNum operator * (modNum b){modNum t = (a * b.get()) % m; return t;}
	modNum operator / (modNum b){modNum t = (a / b.get()) % m; return t;}
	modNum operator - (modNum b){modNum t = (a - b.get()) % m; return t;}

};
typedef modNum<ll, MOD> num_t;
num_t sumX(5),sumZ(6),Y(9);
int main()
{
	cout<<(sumX*sumX + sumX+sumZ)*Y;
	// (((sumX*sumZ) % MOD + (sumX + sumZ) % MOD) % MOD * Y) % MOD;
	return 0;
}
// 'using' keyword if used for type alias, its identical to typedef.
/*
using namespace std; // to import namespace in the current namespace
using T = int; // type alias
using SuperClass::X; // using super class methods in derived class

public:
	// If we print only public things -
	// ostream& print(ostream& os) const {
	//         return os <<a;
	//     }

// When left operand is not a member of same class. & Hence in case it needs to access private members, we need 'friend'
//but for right operand , is it diff?!
// ostream& operator<<(ostream& os, num_t& obj) {
//     return obj.print(os);
// }

// Another method - When 
template<typename Number, Number m>
modNum<Number, m> operator+(
  modNum<Number, m> lhs,
  modNum<Number, m> rhs) {
  return (lhs.get() + rhs.get())%m;
}

*/
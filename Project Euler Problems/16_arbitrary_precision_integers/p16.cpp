#include <bits/stdc++.h>
using namespace std;
#define dbarrt(x, n) cerr << #x << ": " << '\n', _dbarrt((x), (n))
#define dbarr(x, n) cerr << #x << ": ", _dbarr((x), (n))
template <typename T>
void _dbarr(const T a, size_t sz)
{
    for (size_t i = 0; i < sz; ++i)
        cerr << a[i] << ' ';
    cerr << '\n';
}
template <typename T>
void _dbarrt(const T a, size_t sz)
{
    for (size_t i = 0; i < sz; ++i)
        cerr << a[i] << '\n';
    cerr << "i:" << '\n';
    for (size_t i = 0; i < sz; ++i)
        cerr << i << '\n';
}
#define sim template < class c
#define ris return * this
#define dor > debug & operator <<
#define eni(x) sim > typename \
  enable_if<sizeof dud<c>(0) x 1, debug&>::type operator<<(c i) {
sim > struct rge { c b, e; };
sim > rge<c> range(c i, c j) { return rge<c>{i, j}; }
sim > auto dud(c* x) -> decltype(cerr << *x, 0);
sim > char dud(...);
struct debug {
#ifdef CPH
~debug() { cerr << endl; }
eni(!=) cerr << boolalpha << i; ris; }
eni(==) ris << range(begin(i), end(i)); }
sim, class b dor(pair < b, c > d) {
  ris << "(" << d.first << ", " << d.second << ")";
}
sim dor(rge<c> d) {
  *this << "[";
  for (auto it = d.b; it != d.e; ++it)
    *this << ", " + 2 * (it == d.b) << *it;
  ris << "]";
}
#else
sim dor(const c&) { ris; }
#endif
};
#define HERE cerr << "Passing [" << __FUNCTION__ << "] in LINE " << __LINE__ << '\n'
#define imie(x) " [" << #x ": " << (x) << "] "
using ll = long long;
using ld = long double;
constexpr int INF = INT_MAX;
constexpr ll LLINF = LLONG_MAX;
#define PI 3.141592653589793238L
const char nl = '\n';

struct big_int {
    vector<int> num;
    const int base = 1000*1000*1000;

    big_int(){}

    big_int(const big_int& b)
    {
        num.assign(b.num.begin(), b.num.end());
    }

    big_int& operator=(const big_int &other) {
        num.assign(other.num.begin(), other.num.end());
        return *this;
    }

    big_int(const string& s)
    {
        for (int i = int(s.length()); i > 0; i -= 9)
            if (i < 9)
                num.push_back(atoi(s.substr(0, i).c_str()));
            else
                num.push_back(atoi(s.substr(i - 9, 9).c_str()));
        while (num.size() > 1 && num.back() == 0)
            num.pop_back();
    }

    big_int(char *s)
    {
        for (int i = int(strlen(s)); i > 0; i -= 9)
        {
            s[i] = 0;
            num.push_back(atoi(i >= 9 ? s + i - 9 : s));
        }
        while (num.size() > 1 && num.back() == 0)
            num.pop_back();
    }


    // returns the result of 'this' + b
    big_int add(const big_int& b) const
    {
        big_int a(*this);
        int carry = 0;
        for (size_t i = 0; i < max(num.size(), b.num.size()) || carry; ++i)
        {
            if (i == num.size())
                a.num.push_back(0);
            a.num[i] += carry + (i < b.num.size() ? b.num[i] : 0);
            carry = num[i] >= base;
            if (carry)
                a.num[i] -= base;
        }
        return a;
    }

    // returns the result of 'this' + b, for this >= b
    big_int sub(const big_int& b) const
    {
        big_int a(*this);
        int carry = 0;
        for (size_t i = 0; i < b.num.size() || carry; ++i)
        {
            a.num[i] -= carry + (i < b.num.size() ? b.num[i] : 0);
            carry = num[i] < 0;
            if (carry)
                a.num[i] += base;
        }
        while (num.size() > 1 && num.back() == 0)
            a.num.pop_back();
        return a;
    }

    // multiply 'this' by b, returns the result stored in c
    big_int mult(const big_int& b) const
    {
        big_int c;
        c.num.assign(num.size() + b.num.size(), 0);
        for (size_t i = 0; i < num.size(); ++i)
            for (int j = 0, carry = 0; j < (int)b.num.size() || carry; ++j)
            {
                long long cur = c.num[i + j] + num[i] * 1ll * (j < (int)b.num.size() ? b.num[j] : 0) + carry;
                c.num[i + j] = int(cur % base);
                carry = int(cur / base);
            }
        while (c.num.size() > 1 && c.num.back() == 0)
            c.num.pop_back();
        return c;
    }
    
    big_int pow(uint64_t exp) const
    {
        big_int result(string("1")), b(*this);
        while(exp > 0)
        {
            if(exp&1)
                result = result.mult(b);
            b = b.mult(b);
            exp >>= 1;
        }
        return result;
    }

    big_int digit_sum() const
    {
        big_int d_sum(string("0"));
        string s(this->to_string());
        for(const char& c : s)
            d_sum = d_sum.add(big_int(std::to_string(int(c - '0'))));
        return d_sum;
    }

    void print(const int after = -1) const
    {
        printf("%d", num.empty() ? 0 : num.back());
        for (int i = int(num.size()) - 2; i >= 0; --i)
            printf("%09d", num[i]);
        if(after != -1)
            putchar(after);
    }

    string to_string() const
    {
        string s(num.empty() ? "0" : std::to_string(num.back()));
        char tmp[10];
        for(int i = int(num.size())-2; i >= 0; --i)
        {
            sprintf(tmp, "%09d", num[i]);
            s.append(tmp);
        }
        return s;
    }

    friend ostream& operator<<(ostream &os, const big_int &b) {
        return os << b.to_string();
    }
};
class BigInt{
    string digits;
public:
 
    //Constructors:
    BigInt(unsigned long long n = 0);
    BigInt(string &);
    BigInt(const char *);
    BigInt(BigInt &);
 
    //Helper Functions:
    friend void divide_by_2(BigInt &a);
    friend bool Null(const BigInt &);
    friend int Length(const BigInt &);
    int operator[](const int)const;
 
               /* * * * Operator Overloading * * * */
 
    //Direct assignment
    BigInt &operator=(const BigInt &);
 
    //Post/Pre - Incrementation
    BigInt &operator++();
    BigInt operator++(int temp);
    BigInt &operator--();
    BigInt operator--(int temp);
 
    //Addition and Subtraction
    friend BigInt &operator+=(BigInt &, const BigInt &);
    friend BigInt operator+(const BigInt &, const BigInt &);
    friend BigInt operator-(const BigInt &, const BigInt &);
    friend BigInt &operator-=(BigInt &, const BigInt &);
 
    //Comparison operators
    friend bool operator==(const BigInt &, const BigInt &);
    friend bool operator!=(const BigInt &, const BigInt &);
 
    friend bool operator>(const BigInt &, const BigInt &);
    friend bool operator>=(const BigInt &, const BigInt &);
    friend bool operator<(const BigInt &, const BigInt &);
    friend bool operator<=(const BigInt &, const BigInt &);
 
    //Multiplication and Division
    friend BigInt &operator*=(BigInt &, const BigInt &);
    friend BigInt operator*(const BigInt &, const BigInt &);
    friend BigInt &operator/=(BigInt &, const BigInt &);
    friend BigInt operator/(const BigInt &, const BigInt &);
 
    //Modulo
    friend BigInt operator%(const BigInt &, const BigInt &);
    friend BigInt &operator%=(BigInt &, const BigInt &);
 
    //Power Function
    friend BigInt pow(BigInt &, const BigInt &);
    friend BigInt pow_self(BigInt &, const BigInt &);

    //Square Root Function
    friend BigInt sqrt(BigInt &a);
 
    //Read and Write
    friend ostream &operator<<(ostream &,const BigInt &);
    friend istream &operator>>(istream &, BigInt &);
 
    //Others
    friend BigInt NthCatalan(int n);
    friend BigInt NthFibonacci(int n);
    friend BigInt Factorial(int n);
    friend BigInt digit_sum(const BigInt& a);
};
 
BigInt::BigInt(string & s){
    digits = "";
    int n = s.size();
    for (int i = n - 1; i >= 0;i--){
        if(!isdigit(s[i]))
            throw("ERROR");
        digits.push_back(s[i] - '0');
    }
}
BigInt::BigInt(unsigned long long nr){
    do{
        digits.push_back(nr % 10);
        nr /= 10;
    } while (nr);
}
BigInt::BigInt(const char *s){
    digits = "";
    for (int i = strlen(s) - 1; i >= 0;i--)
    {
        if(!isdigit(s[i]))
            throw("ERROR");
        digits.push_back(s[i] - '0');
    }
}
BigInt::BigInt(BigInt & a){
    digits = a.digits;
}
 
bool Null(const BigInt& a){
    if(a.digits.size() == 1 && a.digits[0] == 0)
        return true;
    return false;
}
int Length(const BigInt & a){
    return a.digits.size();
}
int BigInt::operator[](const int index)const{
    if(int(digits.size()) <= index || index < 0)
        throw("ERROR");
    return digits[index];
}
bool operator==(const BigInt &a, const BigInt &b){
    return a.digits == b.digits;
}
bool operator!=(const BigInt & a,const BigInt &b){
    return !(a == b);
}
bool operator<(const BigInt&a,const BigInt&b){
    int n = Length(a), m = Length(b);
    if(n != m)
        return n < m;
    while(n--)
        if(a.digits[n] != b.digits[n])
            return a.digits[n] < b.digits[n];
    return false;
}
bool operator>(const BigInt&a,const BigInt&b){
    return b < a;
}
bool operator>=(const BigInt&a,const BigInt&b){
    return !(a < b);
}
bool operator<=(const BigInt&a,const BigInt&b){
    return !(a > b);
}
 
BigInt &BigInt::operator=(const BigInt &a){
    digits = a.digits;
    return *this;
}
 
BigInt &BigInt::operator++(){
    int i, n = digits.size();
    for (i = 0; i < n && digits[i] == 9;i++)
        digits[i] = 0;
    if(i == n)
        digits.push_back(1);
    else
        digits[i]++;
    return *this;
}
BigInt BigInt::operator++(int temp){
    BigInt aux;
    aux = *this;
    ++(*this);
    return aux;
}
 
BigInt &BigInt::operator--(){
    if(digits[0] == 0 && digits.size() == 1)
        throw("UNDERFLOW");
    int i, n = digits.size();
    for (i = 0; digits[i] == 0 && i < n;i++)
        digits[i] = 9;
    digits[i]--;
    if(n > 1 && digits[n - 1] == 0)
        digits.pop_back();
    return *this;
}
BigInt BigInt::operator--(int temp){
    BigInt aux;
    aux = *this;
    --(*this);
    return aux;
}
 
BigInt &operator+=(BigInt &a,const BigInt& b){
    int t = 0, s, i;
    int n = Length(a), m = Length(b);
    if(m > n)
        a.digits.append(m - n, 0);
    n = Length(a);
    for (i = 0; i < n;i++){
        if(i < m)
            s = (a.digits[i] + b.digits[i]) + t;
        else
            s = a.digits[i] + t;
        t = s / 10;
        a.digits[i] = (s % 10);
    }
    if(t)
        a.digits.push_back(t);
    return a;
}
BigInt operator+(const BigInt &a, const BigInt &b){
    BigInt temp;
    temp = a;
    temp += b;
    return temp;
}
 
BigInt &operator-=(BigInt&a,const BigInt &b){
    if(a < b)
        throw("UNDERFLOW");
    int n = Length(a), m = Length(b);
    int i, t = 0, s;
    for (i = 0; i < n;i++){
        if(i < m)
            s = a.digits[i] - b.digits[i]+ t;
        else
            s = a.digits[i]+ t;
        if(s < 0)
            s += 10,
            t = -1;
        else
            t = 0;
        a.digits[i] = s;
    }
    while(n > 1 && a.digits[n - 1] == 0)
        a.digits.pop_back(),
        n--;
    return a;
}
BigInt operator-(const BigInt& a,const BigInt&b){
    BigInt temp;
    temp = a;
    temp -= b;
    return temp;
}
 
BigInt &operator*=(BigInt &a, const BigInt &b)
{
    if(Null(a) || Null(b)){
        a = BigInt();
        return a;
    }
    int n = a.digits.size(), m = b.digits.size();
    vector<int> v(n + m, 0);
    for (int i = 0; i < n;i++)
        for (int j = 0; j < m;j++){
            v[i + j] += (a.digits[i] ) * (b.digits[j]);
        }
    n += m;
    a.digits.resize(v.size());
    for (int s, i = 0, t = 0; i < n; i++)
    {
        s = t + v[i];
        v[i] = s % 10;
        t = s / 10;
        a.digits[i] = v[i] ;
    }
    for (int i = n - 1; i >= 1 && !v[i];i--)
            a.digits.pop_back();
    return a;
}
BigInt operator*(const BigInt&a,const BigInt&b){
    BigInt temp;
    temp = a;
    temp *= b;
    return temp;
}
 
BigInt &operator/=(BigInt& a,const BigInt &b){
    if(Null(b))
        throw("Arithmetic Error: Division By 0");
    if(a < b){
        a = BigInt();
        return a;
    }
    if(a == b){
        a = BigInt(1);
        return a;
    }
    int i, lgcat = 0, cc;
    int n = Length(a);//, m = Length(b);
    vector<int> cat(n, 0);
    BigInt t;
    for (i = n - 1; t * 10 + a.digits[i]  < b;i--){
        t *= 10;
        t += a.digits[i] ;
    }
    for (; i >= 0; i--){
        t = t * 10 + a.digits[i];
        for (cc = 9; cc * b > t;cc--);
        t -= cc * b;
        cat[lgcat++] = cc;
    }
    a.digits.resize(cat.size());
    for (i = 0; i < lgcat;i++)
        a.digits[i] = cat[lgcat - i - 1];
    a.digits.resize(lgcat);
    return a;
}
BigInt operator/(const BigInt &a,const BigInt &b){
    BigInt temp;
    temp = a;
    temp /= b;
    return temp;
}
 
BigInt &operator%=(BigInt& a,const BigInt &b){
    if(Null(b))
        throw("Arithmetic Error: Division By 0");
    if(a < b){
        a = BigInt();
        return a;
    }
    if(a == b){
        a = BigInt(1);
        return a;
    }
    int i, lgcat = 0, cc;
    int n = Length(a);//, m = Length(b);
    vector<int> cat(n, 0);
    BigInt t;
    for (i = n - 1; t * 10 + a.digits[i] < b;i--){
        t *= 10;
        t += a.digits[i];
    }
    for (; i >= 0; i--){
        t = t * 10 + a.digits[i];
        for (cc = 9; cc * b > t;cc--);
        t -= cc * b;
        cat[lgcat++] = cc;
    }
    a = t;
    return a;
}
BigInt operator%(const BigInt &a,BigInt &b){
    BigInt temp;
    temp = a;
    temp %= b;
    return temp;
}
 
BigInt pow_self(BigInt & a,const BigInt & b){
    BigInt Exponent, Base(a);
    Exponent = b;
    a = 1;
    while(!Null(Exponent)){
        if(Exponent[0] & 1)
            a *= Base;
        Base *= Base;
        divide_by_2(Exponent);
    }
    return a;
}
BigInt pow(BigInt & a,BigInt & b){
    BigInt temp(a);
    pow_self(temp,b);
    return temp;
}
 
void divide_by_2(BigInt & a){
    int add = 0;
    for (int i = a.digits.size() - 1; i >= 0;i--){
        int digit = (a.digits[i] >> 1) + add;
        add = ((a.digits[i] & 1) * 5);
        a.digits[i] = digit;
    }
    while(a.digits.size() > 1 && !a.digits.back())
        a.digits.pop_back();
}
 
BigInt sqrt(BigInt & a){
    BigInt left(1), right(a), v(1), mid, prod;
    divide_by_2(right);
    while(left <= right){
        mid += left;
        mid += right;
        divide_by_2(mid);
        prod = (mid * mid);
        if(prod <= a){
            v = mid;
            ++mid;
            left = mid;
        }
        else{
            --mid;
            right = mid;
        }
        mid = BigInt();
    }
    return v;
}
 
BigInt NthCatalan(int n){
    BigInt a(1),b;
    for (int i = 2; i <= n;i++)
        a *= i;
    b = a;
    for (int i = n + 1; i <= 2 * n;i++)
        b *= i;
    a *= a;
    a *= (n + 1);
    b /= a;
    return b;
}
 
BigInt NthFibonacci(int n){
    BigInt a(1), b(1), c;
    if(!n)
        return c;
    n--;
    while(n--){
        c = a + b;
        b = a;
        a = c;
    }
    return b;
}
 
BigInt Factorial(int n){
    BigInt f(1);
    for (int i = 2; i <= n;i++)
        f *= i;
    return f;
}

BigInt digit_sum(const BigInt& a)
{
    uint64_t sum = 0;
    for(const auto& d : a.digits)
        sum += d;
    return BigInt(sum);
}
 
istream &operator>>(istream &in,BigInt&a){
    string s;
    in >> s;
    int n = s.size();
    for (int i = n - 1; i >= 0;i--){
        if(!isdigit(s[i]))
            throw("INVALID NUMBER");
        a.digits[n - i - 1] = s[i];
    }
    return in;
}
 
ostream &operator<<(ostream &out,const BigInt &a){
    for (int i = a.digits.size() - 1; i >= 0;i--)
        cout << (short)a.digits[i];
    return cout;
}

int main()
{
    cin.tie(0);
    ios::sync_with_stdio(0);
    int n = 1000, exp = 1000;
    cerr << "[Program Start]" << nl;
    auto begin = std::chrono::steady_clock::now();
    
    BigInt b(2), e(exp);
    for(int i = 0; i < n; ++i, b = 2)
        cout << digit_sum(pow(b, e)) << nl;
    
    auto end = std::chrono::steady_clock::now();
    auto duration = std::chrono::duration_cast<std::chrono::milliseconds>(end - begin);
    cerr << "[Time Elasped: " << duration.count() << " ms]" << nl;
    
    cerr << "[Program Start]" << nl;
    begin = std::chrono::steady_clock::now();
    
    for(int i = 0; i < n; ++i)
        cout << big_int(string("2")).pow(exp).digit_sum() << nl;
    
    end = std::chrono::steady_clock::now();
    duration = std::chrono::duration_cast<std::chrono::milliseconds>(end - begin);
    cerr << "[Time Elasped: " << duration.count() << " ms]" << nl;
    return 0;
}

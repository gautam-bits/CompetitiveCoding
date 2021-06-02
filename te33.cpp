
#include <bits/stdc++.h>
using namespace std;




//taken from (https://github.com/williamchanrico/biginteger-cpp/blob/master/BigInt.cpp) 
class BigInt {
public:
    bool neg = false;
    std::string number = "0";

    BigInt(){}

    BigInt(const BigInt& other){
        this -> neg = other.neg;
        this -> number = other.number;
    }

    BigInt(int number){
        if(number < 0){
            this -> neg = true;
            number *= -1;
        }

        if(number == 0){
            this -> number = "0";
            return;
        }

        this -> number = "";

        while(number > 0){
            this -> number += (number % 10) + '0';
            number /= 10;
        }
    }

    BigInt(long long int number){
        if(number < 0){
            this -> neg = true;
            number *= -1;
        }

        if(number == 0){
            this -> number = "0";
            return;
        }

        this -> number = "";

        while(number > 0){
            this -> number += (number % 10) + '0';
            number /= 10;
        }
    }

    BigInt(unsigned long long int number){
        if(number < 0){
            this -> neg = true;
            number *= -1;
        }

        if(number == 0){
            this -> number = "0";
            return;
        }

        this -> number = "";

        while(number > 0){
            this -> number += (number % 10) + '0';
            number /= 10;
        }
    }

    BigInt(const char *number){
        std::string number_(number);
        *(this) = number_;
    }

    BigInt(std::string number){
        while(number[0] == '-'){
            this -> neg = !this -> neg;
            number.erase(0, 1);
        }

        reverse(number.begin(), number.end());

        while(number.size() > 1 && number[number.size() - 1] == '0')
            number.erase(number.size() - 1, number.size());

        if(number == "")
            number = "0";

        this -> number = number;

        if(number == "0")
            this -> neg = false;
    }

    friend bool operator == (BigInt first, BigInt second){
        return first.number == second.number && second.neg == first.neg;
    }

    friend bool operator != (BigInt first, BigInt second){
        return !(first == second);
    }

    friend bool operator < (BigInt first, BigInt second){
        if(first.neg && !second.neg) return true;
        if(!first.neg && second.neg) return false;

        if(first.neg && second.neg){
            first.neg = false;
            second.neg = false;

            return first > second;
        }

        if((first.number).size() < (second.number).size()) return true;
        if((first.number).size() > (second.number).size()) return false;

        std::string temp1 = first.number; reverse(temp1.begin(), temp1.end());
        std::string temp2 = second.number; reverse(temp2.begin(), temp2.end());

        for(unsigned int i = 0; i < temp1.size(); i++)
            if(temp1[i] < temp2[i])
                return true;
            else if(temp1[i] > temp2[i])
                return false;

        return false;
    }

    friend bool operator <= (BigInt first, BigInt second){
        return (first == second) || (first < second);
    }

    friend bool operator > (BigInt first, BigInt second){
        if(!first.neg && second.neg) return true;
        if(first.neg && !second.neg) return false;

        if(first.neg && second.neg){
            first.neg = false;
            second.neg = false;

            return first < second;
        }

        if((first.number).size() > (second.number).size()) return true;
        if((first.number).size() < (second.number).size()) return false;

        std::string temp1 = first.number; reverse(temp1.begin(), temp1.end());
        std::string temp2 = second.number; reverse(temp2.begin(), temp2.end());

        for(unsigned int i = 0; i < temp1.size(); i++)
            if(temp1[i] > temp2[i])
                return true;
            else if(temp1[i] < temp2[i])
                return false;

        return false;
    }

    friend bool operator >= (BigInt first, BigInt second){
        return (first == second) || (first > second);
    }

    void operator = (unsigned long long int number){
        if(number < 0){
            this -> neg = true;
            number *= -1;
        }

        this -> number = "";

        while(number > 0){
            this -> number += (number % 10) + '0';
            number /= 10;
        }
    }

    friend std::istream& operator >> (std::istream& in, BigInt &bigint){
        std::string number; in >> number;

        bigint.neg = false;

        while(number[0] == '-'){
            bigint.neg = !bigint.neg;
            number.erase(0, 1);
        }

        reverse(number.begin(), number.end());

        while(number.size() > 1 && number[number.size() - 1] == '0')
            number.erase(number.size() - 1, number.size());

        bigint.number = number;

        if(number == "0")
            bigint.neg = false;

        return in;
    }

    friend std::ostream& operator << (std::ostream& out, const BigInt &bigint){
        std::string number = bigint.number;
        reverse(number.begin(), number.end());

        if(bigint.neg)
            number = '-' + number;

        out << number;

        return out;
    }

    friend void swap(BigInt &first, BigInt &second){
        BigInt temp(first);

        first = second;
        second = temp;
    }

    friend BigInt abs(BigInt bigint){
        bigint.neg = false;

        return bigint;
    }

    friend BigInt operator + (BigInt first, BigInt second){
        bool neg = false;

        if(!first.neg && second.neg){
            second.neg = false; return first - second;
        }

        if(first.neg && !second.neg){
            first.neg = false; return second - first;
        }

        if(first.neg && second.neg){
            neg = true;
            first.neg = second.neg = false;
        }

        int n = first.number.size();
        int m = second.number.size();

        int carry = 0;

        std::string result;

        for(int i = 0; i < std::max(n, m); i++){
            int add = carry;

            if(i < n) add += first.number[i] - '0';
            if(i < m) add += second.number[i] - '0';

            carry = add / 10;

            result += add % 10 + '0';
        }

        if(carry != 0)
            result += carry + '0';

        reverse(result.begin(), result.end());

        BigInt result_(result);
        result_.neg = neg;

        return result_;
    }

    friend BigInt operator + (BigInt bigint){
        return bigint;
    }

    friend BigInt operator - (BigInt first, BigInt second){
        if(second.neg){
            second.neg = false;
            return first + second;
        }

        if(first.neg){
            second.neg = true;
            return first + second;
        }

        bool neg = false;

        if(first < abs(second)){
            neg = true;

            swap(first, second);
            first = abs(first);
        }

        int n = first.number.size();
        int m = second.number.size();

        int carry = 0;

        std::string result;

        for(int i = 0; i < std::max(n, m); i++){
            int add = carry;

            if(i < n) add += first.number[i] - '0';
            if(i < m) add -= second.number[i] - '0';

            if(add < 0){
                carry = -1;
                result += add + 10 + '0';
            }

            else {
                carry = 0;
                result += add + '0';
            }
        }

        reverse(result.begin(), result.end());

        BigInt result_(result);

        result_.neg = neg;

        return result_;
    }

    friend BigInt operator - (BigInt second){
        BigInt first("0"); return first - second;
    }

    friend BigInt operator * (BigInt first, BigInt second){
        bool neg = first.neg != second.neg;

        first.neg = false;
        second.neg = false;

        int n = first.number.size();
        int m = second.number.size();

        BigInt result_;

        for(int i = 0; i < n; i++){
            int carry = 0;

            std::string result;

            for(int j = 0; j < i; j++)
                result += '0';

            for(int j = 0; j < m; j++){
                int add = carry + (first.number[i] - '0') * (second.number[j] - '0');

                carry = add / 10;

                result += add % 10 + '0';
            }

            if(carry != 0)
                result += carry + '0';

            reverse(result.begin(), result.end());

            BigInt current(result);

            result_ += current;
        }

        result_.neg = neg;

        return result_;
    }

    friend BigInt operator / (BigInt first, BigInt second){
        if(second == "0")
            throw "Division with 0";

        bool neg = first.neg != second.neg;

        first.neg = false;
        second.neg = false;

        BigInt quotient;

        int i = first.size() - 1;

        BigInt current(first.number[i] - '0');

        --i;

        while(true){
            BigInt result = current;

            bool l = false;

            while(result < second && i >= 0){
                result = result * 10 + (first.number[i--] - '0');

                if(l)
                    quotient *= 10;

                l = true;
            }

            int c = 0;

            BigInt result_(result);

            while(result_ >= second){
                result_ -= second;
                c++;
            }

            quotient = quotient * 10 + c;

            current = result_;

            if(i < 0)
                break;
        }

        quotient.neg = neg;

        return quotient;
    }

    friend BigInt operator % (BigInt first, BigInt second){
        if(second == "0")
            throw "Modulo with 0";

        first.neg = false;
        second.neg = false;

        int i = first.size() - 1;

        BigInt current(first.number[i] - '0');

        --i;

        while(true){
            BigInt result = current;

            while(result < second && i >= 0)
                result = result * 10 + (first.number[i--] - '0');

            int c = 0;

            BigInt result_(result);

            while(result_ >= second){
                result_ -= second;
                c++;
            }

            current = result_;

            if(i < 0)
                break;
        }

        current.neg = second.neg;

        return current;
    }

    friend BigInt pow(BigInt x, BigInt y, BigInt mod = 0){
        if(mod != 0)
            x %= mod;

        BigInt res = 1;

        while(y != 0){
            if(y % 2 == 1){
                res *= x;

                if(mod != 0)
                    res %= mod;
            }

            x *= x;

            if(mod != 0)
                x %= mod;

            y /= 2;
        }

        return res;
    }

    friend BigInt operator & (BigInt first_, BigInt second_){
        std::string first = first_.int_to_base(2);
        std::string second = second_.int_to_base(2);

        unsigned int n = std::min(first.size(), second.size());

        reverse(first.begin(), first.end());
        reverse(second.begin(), second.end());

        std::string result(n, '~');

        for(unsigned int i = 0; i < n; i++){
            if(first[i] == '1' && second[i] == '1')
                result[i] = '1';
            else
                result[i] = '0';
        }

        reverse(result.begin(), result.end());

        return BigInt().base_to_int(result, 2);
    }

    friend BigInt operator | (BigInt first_, BigInt second_){
        std::string first = first_.int_to_base(2);
        std::string second = second_.int_to_base(2);

        unsigned int n = std::max(first.size(), second.size());

        reverse(first.begin(), first.end());
        reverse(second.begin(), second.end());

        std::string result(n, '~');

        for(unsigned int i = 0; i < n; i++){
            if(first.size() <= i || second.size() <= i){
                if(first.size() > i) result[i] = first[i];
                if(second.size() > i) result[i] = second[i];

                continue;
            }

            if(first[i] == '1' || second[i] == '1')
                result[i] = '1';
            else
                result[i] = '0';
        }

        reverse(result.begin(), result.end());

        return BigInt().base_to_int(result, 2);
    }

    friend BigInt operator ^ (BigInt first_, BigInt second_){
        std::string first = first_.int_to_base(2);
        std::string second = second_.int_to_base(2);

        unsigned int n = std::max(first.size(), second.size());

        reverse(first.begin(), first.end());
        reverse(second.begin(), second.end());

        std::string result(n, '~');

        for(unsigned int i = 0; i < n; i++){
            if(first.size() <= i || second.size() <= i){
                if(first.size() > i){
                    if(first[i] == '0')
                        result[i] = '0';
                    else
                        result[i] = '1';
                }

                if(second.size() > i){
                    if(second[i] == '0')
                        result[i] = '0';
                    else
                        result[i] = '1';
                }

                continue;
            }

            if(first[i] == second[i])
                result[i] = '0';
            else
                result[i] = '1';
        }

        reverse(result.begin(), result.end());

        return BigInt().base_to_int(result, 2);
    }

    friend BigInt operator << (BigInt first, BigInt second){
        BigInt x = pow(2, second);

        return first * x;
    }

    friend BigInt operator >> (BigInt first, BigInt second){
        BigInt x = pow(2, second);

        return first / x;
    }

    int to_int(BigInt bigint){
        int n = 0;

        for(int i = bigint.number.size() - 1; i >= 0; i--)
            n = (n * 10) + (bigint.number[i] - '0');

        return n;
    }

    std::string int_to_base(int base){
        std::string result;

        BigInt bigint(*this);

        while(bigint > 0){
            BigInt r = bigint % base;

            if(r >= 10)
                result += (char)(to_int(r / 10) + 'A');
            else
                result += (char)(to_int(r) + '0');

            bigint /= base;
        }

        reverse(result.begin(), result.end());

        return result;
    }

    BigInt base_to_int(std::string str, int base){
        BigInt result;

        for(unsigned int i = 0; i < str.size(); i++){
            BigInt add;

            if('0' <= str[i] && str[i] <= '9')
                add += str[i] - '0';
            else
                add += (str[i] - 'A') + 10;

            result = result * base + add;
        }

        return result;
    }

    int size(){
        return this -> number.size();
    }

    void operator ++ (){*(this) = *(this) + 1;}
    void operator -- (){*(this) = *(this) - 1;}

    void operator += (BigInt bigint){*(this) = *(this) + bigint;}
    void operator -= (BigInt bigint){*(this) = *(this) - bigint;}

    void operator *= (BigInt bigint){*(this) = *(this) * bigint;}
    void operator /= (BigInt bigint){*(this) = *(this) / bigint;}
    void operator %= (BigInt bigint){*(this) = *(this) % bigint;}

    void operator &= (BigInt bigint){*(this) = *(this) & bigint;}
    void operator |= (BigInt bigint){*(this) = *(this) | bigint;}
    void operator ^= (BigInt bigint){*(this) = *(this) ^ bigint;}

    void operator <<= (BigInt bigint){*(this) = *(this) << bigint;}
    void operator >>= (BigInt bigint){*(this) = *(this) >> bigint;}
};



map<pair<BigInt,BigInt>,BigInt> mp;
set<BigInt> st;



BigInt precedence(char op){
	if(op == '+'||op == '-')
	return 1;
	if(op == '*'||op == '/' || op == '#' || op == '$')
	return 2;
	return 0;
}

BigInt applyOp(BigInt a, BigInt b, char op){
    BigInt te = 332923839;
    BigInt te2 = 50550593;
	switch(op){
		case '+': return a + b;
		case '-': return a - b;
		case '*': return a * b;
		case '/': return a / b;
        case '#': {
            if(mp.find({a,b}) != mp.end()) {
                return mp[{a,b}];
            }
            else if(st.empty()) {
                st.insert("9323783383373");
                mp[{a,b}] = "9323783383373";
                return BigInt("9323783383373");
            }

            else {

                BigInt te = *st.rbegin();

                te += BigInt(rand());

                st.insert(te);
                mp[{a,b}] = te;
                return te;
                
            }
         } ;
        case '$': return  te*a + b*te + a*b*b + 69*b + b - 22*a;
	}
}

BigInt evaluate(string tokens){
	int i;
	
	stack <BigInt> values;
	
	stack <char> ops;
	
	for(i = 0; i < tokens.length(); i++){
		
		if(tokens[i] == ' ')
			continue;
		else if(tokens[i] == '('){
			ops.push(tokens[i]);
		}

		else if(isdigit(tokens[i])){
			BigInt val = 0;

			while(i < tokens.length() &&
						isdigit(tokens[i]))
			{
				val = (val*10) + (BigInt)(tokens[i]-'0');
				i++;
			}
			
			values.push(val);
			

			i--;
		}
		

		else if(tokens[i] == ')')
		{
			while(!ops.empty() && ops.top() != '(')
			{
				BigInt val2 = values.top();
				values.pop();
				
				BigInt val1 = values.top();
				values.pop();
				
				char op = ops.top();
				ops.pop();
				
				values.push(applyOp(val1, val2, op));
			}
			
			if(!ops.empty())
			ops.pop();
		}
		
		else
		{
			while(!ops.empty() && precedence(ops.top())
								>= precedence(tokens[i])){
				BigInt val2 = values.top();
				values.pop();
				
				BigInt val1 = values.top();
				values.pop();
				
				char op = ops.top();
				ops.pop();
				
				values.push(applyOp(val1, val2, op));
			}
			
			ops.push(tokens[i]);
		}
	}
	
	while(!ops.empty()){
		BigInt val2 = values.top();
		values.pop();
				
		BigInt val1 = values.top();
		values.pop();
				
		char op = ops.top();
		ops.pop();
				
		values.push(applyOp(val1, val2, op));
	}
	
	return values.top();
}

int main() {
	// cout << evaluate("(9999999999999999999999999999999999999999+1)") << "\n";
	// cout << evaluate("(100000000000000000000*100000000000000000000)") << "\n";
	// cout << evaluate("(1*(1+2))") << "\n";
	// cout << evaluate("100 * ( 2 + 12 ) / 14");


    int t;

    cin>>t;


    for(int tno = 1; tno <= t ; tno++) {
        mp.clear();
        st.clear();
        int n;
        cin>>n;

        vector<string> arr(n);
        vector<int> ans(n);
        vector<int> ans2(n);

        map<BigInt,int> se;
        map<BigInt,int> se2;

        int itr = 1;



        for(int i = 0 ; i < n ; i++) cin>>arr[i];


        for(int i = 0 ; i < n ; i++) {
            BigInt temp = evaluate(arr[i]);

            if(se.size() != 0 && se.find(temp) != se.end()) {
                ans[i] = se[temp];
            }
            else {
                ans[i] = itr;
                se[temp] = itr;

                itr++;

            }
        }

        // mp.clear();
        // st.clear();

        // for(int i = 0 ; i < n ; i ++){
        //     for(int j = 0 ; j < arr[i].size() ; j++){
        //         if(arr[i][j] == '#') {
        //             //cout<<"yo";
        //             arr[i][j] = '$';
        //         }
        //     }
        // }

        // itr = 1;



        // for(int i = 0 ; i < n ; i++) {
        //     BigInt temp = evaluate(arr[i]);

        //     if(se2.size() != 0 && se2.find(temp) != se2.end()) {
        //         ans2[i] = se2[temp];
        //     }
        //     else {
        //         ans2[i] = itr;
        //         se2[temp] = itr;

        //         itr++;

        //     }
        // }

        // if(ans != ans2) assert(0);
        // if(se2.size() > se.size()){
        //     ans = ans2;
        // }


        cout<<"Case #"<<tno<<": ";

        for(int i = 0 ; i < n ; i++) cout<<ans[i]<<" ";

        cout<<"\n";

        


    }
    
	return 0;
}


#include <iostream>
using namespace std;
template <typename T> 

class Vector {
private:
	int sz;
	T * buf;
public:
	Vector( int n ){
		sz = n;
		buf = new T[sz];
		for (int i = 0; i < sz; i++){
			buf[i] = 0;
		}
	};
	Vector(initializer_list<T> L ){
		sz = L.size();

		buf = new T[sz];
		int count = 0;
		for (auto n : L){
			buf[count] = n;
			count++;
		}
	};	
	~Vector(){
		delete []buf;
	};
	Vector( const Vector & v ){
		sz = v.sz;
		buf = new T[v.sz];
		for (int i = 0; i < sz; i++){
			buf[i] = v.buf[i];
		}
	};
	int size (){		
		return sz;
	}; 


	T & operator [] ( const int i ){ 
		if(i < sz){
			return buf[i];
		}
		else{

			throw "Exception: Accessing out-of-bound index!";

		}
		return buf[i];
	
	};
	T operator * ( const Vector & v ) const{ 
		T count = 0.0;
		if (sz > v.sz){
			for (int i = 0; i < v.sz; i++){
				count += buf[i] * v.buf[i];
			}
		}
		else{
			for (int i = 0; i < sz; i++){
				count += buf[i] * v.buf[i];
			}

		}
		return count;
	};
	Vector operator + ( const Vector & v ) const{ 
		T temp = 0.0;
		if (sz < v.sz){
			for (int i = 0; i < v.sz; i++){
				temp = (buf[i] + v.buf[i]);
				buf[i] = temp;
			}
		}
		else{
			for (int i = 0; i < sz; i++){
				temp = (buf[i] + v.buf[i]);
				v.buf[i] = temp;
			}

		}
	};
	const Vector & operator = ( const Vector & v ){
		sz = v.sz;
		delete [] buf;
		buf = new T[v.sz];
		for (int i = 0; i < v.sz; i++){
			buf[i] = v.buf[i];
		}
	};
	bool operator == ( const Vector & v ) const{
		bool temp = false;
		if (sz == v.sz){
			for (int i = 0; i < sz; i++){
				if (buf[i] == v.buf[i]){
					temp = true;
				}
				else{
					if (buf[i] != v.buf[i]);
					return false;
				}
			}
		}
		else{
			return false;
		}
		return true;
	};
	bool operator != ( const Vector & v ) const{
		bool temp = true;
		if (sz == v.sz){
			for (int i = 0; i < sz; i++){
				if (buf[i] == v.buf[i]){
					temp = false;
				}
				else{
					if (buf[i] != v.buf[i]);
					return true;
				}
			}
		}
		else{
			return true;
		}
		return false;
	};
	friend Vector operator * (const int n, const Vector &v){
		Vector temp(v);
		for (int i = 0; i < temp.sz; i++){
			temp.buf[i] = temp.buf[i] * n; 
		}
		return temp;


	};
	friend Vector operator + ( const int n, const Vector & v ){
		Vector temp(v);
		for (int i = 0; i < temp.sz; i++){
			temp.buf[i] = temp.buf[i] + n; 
		}
		return temp;
	};
	friend ostream& operator << ( ostream & o, const Vector & v ){	
		std::cout << "(";
		for (int i = 0; i < v.sz - 1; i++){
			std::cout << v.buf[i] << ",";
		}
		std::cout << v.buf[v.sz-1] << ")" << endl;
	}
		
};

int main(){
	Vector<int> v1(10);
	cout << "Testing Vector Constructor:" << endl;
	cout << "Vector<int> v1(10) = " << v1;
	cout << "v1.sz = " << v1.size() << endl << endl;;


	Vector<int> intVec{1,3,5,7,9};
	Vector<int> intVec2{2,4,6,8,10};
	cout << "Testing Vector Initializer List Constructor:" << endl;
	cout << "Vector<int> intVec{1,3,5,7,9} = " << intVec;
	cout << "Vector<int> intVec2{2,4,6,8,10} = " << intVec2;
	Vector<double> dbVec{2.2, 4.4, 6.8, 8.2, 10.1, 12.0};
	cout << "Vector<double> dbVec{2.0,4.0,6.0,8.0,10.0,12.0} = " << dbVec;
	cout << "intVec.sz = " << intVec.size() << endl;
	cout << "dbVec.sz = " << dbVec.size() << endl << endl;


	Vector<int> iv(intVec);
	cout << "Testing Vector Constructor with Deep-Copy:" << endl;
	cout << "Vector<int> iv(intVec) = " << iv;
	cout << "iv.sz = " << iv.size() << endl << endl;


	cout << "Testing Vector.size():" << endl;
	cout << "intVec.size() = " << intVec.size() << endl << endl;


	cout << "Testing Vector Operator []:" << endl;
	cout << "intVec[2] = " << intVec[2] << endl;
	cout << "intVec[8] = ";
	try{
		cout << intVec[8] << endl << endl;
	}
	catch (const char* msg){
		cerr << msg << endl << endl;;
	}


	cout << "Testing Vector Operator *:" << endl;
	cout << "intVec * intVec2 = " << intVec * intVec2 << endl << endl;


	cout << "Testing Vector Operator =: " << endl;
	Vector<int> eq1{1,2,3};
	Vector<int> eq2{2, 4, 1, 51};
	eq1 = eq2;
	cout << "eq1 = {1,2,3}, and eq2 = {2,4,1,51}" << endl;
	cout << "eq1 = eq2:  " << eq1 << endl;


	cout << "Testing bool operator ==: " << endl;
	Vector<int> intVecCopy{1,3,5,7,9};
	bool temp = (intVec == intVec2);
	cout << "bool compare = (intVec == intVec2)" << endl;
	cout << "compare = ";
	if(temp == false){
		cout << "false" << endl;
	}
	else{
		cout << "true" << endl;
	}
	cout << "Vector<int> intVecCopy{1,3,5,7,9}" << endl;
	bool temp2 = (intVec == intVecCopy);
	cout << "bool compare = (intVec == intVecCopy)" << endl;
	cout << "compare = ";
	if(temp2 == false){
		cout << "false" << endl << endl;
	}
	else{
		cout << "true" << endl << endl;
	}



	cout << "Testing bool operator !=:" << endl;
	Vector<int> intVecCopy2{1,3,5,7,9};
	bool temp3 = (intVec != intVec2);
	cout << "bool compare = (intVec != intVec2)" << endl;
	cout << "!compare = ";
	if(temp3 == false){
		cout << "false" << endl;
	}
	else{
		cout << "true" << endl;
	}
	cout << "Vector<int> intVecCopy{1,3,5,7,9}" << endl;
	bool temp4 = (intVec != intVecCopy2);
	cout << "bool compare = (intVec != intVecCopy)" << endl;
	cout << "!compare = ";
	if(temp4 == false){
		cout << "false" << endl << endl;
	}
	else{
		cout << "true" << endl << endl;
	}


	cout << "Testing friend Vector operator *:" << endl;
	cout << "intVec = " << intVec;
	cout << "8 * intVec = " << 8 * intVec << endl << endl;


	cout << "Testing friend Vector operator +:" << endl;
	cout << "intVec = " << intVec;
	cout << "10 + intVec = " << 10 + intVec << endl << endl;

	cout << "Testing friend ostream& operator <<:" << endl;
	cout << "cout << intVec << endl; prints:" << endl;
	cout << intVec;

	return 0;
}

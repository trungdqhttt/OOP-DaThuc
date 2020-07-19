#include<iostream>
#include<cmath>
using namespace std;
class DaThuc {
	float* heso;
	int bacDT;
public:
	DaThuc() {
		bacDT = 0;
	}
	DaThuc(int);
	DaThuc(const DaThuc&); // copy constructor
	friend ostream& operator << (ostream&, const DaThuc&); // cout <<
	friend istream& operator >> (istream&, DaThuc&); // cin >>
	float tinhGiaTri(const float); // Tính giá trị từ x nhập vào
	int timBacMax(); // Tìm bậc lớn nhất của đa thức
	DaThuc operator + (DaThuc); // +
	DaThuc operator - (DaThuc); // -
	float operator [] (int); // Lấy chỉ số
	~DaThuc() {
		delete[] heso;
	}
};


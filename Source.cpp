#include"DaThuc.h"

int main() {
	DaThuc dt1;
	DaThuc dt2;
	cout << "\n\n\t\t NHAP HAI DA THUC\n";
	cout << "\n Nhap da thuc thu nhat";
	cin >> dt1;
	cout << "\n Nhap da thuc thu hai";
	cin >> dt2;

	cout << "\n\n\t\t HAI DA THUC DA NHAP\n";
	cout << "\n Da thuc 1: " << dt1;
	cout << "\n Da thuc 2: " << dt2;

	cout << "\n\n\t\t TONG HAI DA THUC\n " << dt1 + dt2;
	cout << "\n\n\t\t HIEU HAI DA THUC\n " << dt1 - dt2;

	int x;
	cout << "\n\n Nhap gia tri x: ";
	cin >> x;

	cout << "\n\n\t\t THAY x = " << x << " VAO 2 DA THUC TA DUOC\n";
	cout << "\n Da thuc 1 = " << dt1.tinhGiaTri(x);
	cout << "\n Da thuc 2 = " << dt2.tinhGiaTri(x);

	cout << "\n\n\t\t HE SO DI VOI x CO BAC CAO NHAT\n";
	cout << "\n Da thuc 1: " << dt1[dt1.timBacMax()];
	cout << "\n Da thuc 2: " << dt2[dt2.timBacMax()];
	
	cout << endl;
	system("pause");
	return 0;
}
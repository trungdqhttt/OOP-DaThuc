#include"DaThuc.h"

DaThuc::DaThuc(int n) {
	bacDT = n;
	heso = new float[bacDT + 1];
	for (int i = 0; i <= bacDT; i++) {
		heso[i] = 0;
	}
}

DaThuc::DaThuc(const DaThuc& dt) {
	bacDT = dt.bacDT;
	heso = new float[bacDT + 1];
	for (int i = 0; i <= bacDT; i++) {
		heso[i] = dt.heso[i];
	}
}

DaThuc DaThuc::operator + (DaThuc dt) {
	int bacDT_Tong;
	bacDT_Tong = ((bacDT > dt.bacDT) ? bacDT : dt.bacDT);

	DaThuc Tong(bacDT_Tong);
	for (int i = 0; i <= bacDT_Tong; i++) {
		if (bacDT >= i && dt.bacDT >= i) {
			Tong.heso[i] = heso[i] + dt.heso[i];
		}
		else if (dt.bacDT < i) {
			Tong.heso[i] = heso[i];
		}
		else if (bacDT < i) {
			Tong.heso[i] = dt.heso[i];
		}
	}
	while (bacDT_Tong > 0 && Tong.heso[bacDT_Tong] == 0) {
		bacDT_Tong--;
	}
	Tong.bacDT = bacDT_Tong;
	return Tong;
}

DaThuc DaThuc::operator - (DaThuc dt) {
	int bacDT_Hieu;
	bacDT_Hieu = ((bacDT > dt.bacDT) ? bacDT : dt.bacDT);

	DaThuc Hieu(bacDT_Hieu);
	for (int i = 0; i <= bacDT_Hieu; i++) {
		if (bacDT >= i && dt.bacDT >= i) {
			Hieu.heso[i] = heso[i] - dt.heso[i];
		}
		else if (dt.bacDT < i) {
			Hieu.heso[i] = heso[i];
		}
		else if (bacDT < i) {
			Hieu.heso[i] = dt.heso[i];
		}
	}
	while (bacDT_Hieu > 0 && Hieu.heso[bacDT_Hieu] == 0) {
		bacDT_Hieu--;
	}
	Hieu.bacDT = bacDT_Hieu;
	return Hieu;
}

float DaThuc::tinhGiaTri(const float n) {
	float Tong = 0;
	for (int i = bacDT; i > 0; i--) {
		Tong += pow(n, i) * heso[i];
	}
	return Tong + heso[0];
}

float DaThuc::operator [] (int i) {
	if (i >= 0 && i <= bacDT) {
		return heso[i];
	}
}

int DaThuc::timBacMax() {
	return bacDT;
}

istream& operator >> (istream& is, DaThuc& dt) {
	cout << "\n Nhap bac da thuc: ";
	is >> dt.bacDT;
	dt.heso = new float[dt.bacDT + 1];
	for (int i = dt.bacDT; i >= 0; i--) {
		cout << "\n Nhap he so bac " << i << ": ";
		is >> dt.heso[i];
	}
	return is;
}

ostream& operator << (ostream& os, const DaThuc& dt) {
	for (int i = dt.bacDT; i > 0; i--) {
		if (i != 1) {
			if (i != dt.bacDT) {
				os << abs(dt.heso[i]) << "x^" << i;
			}
			else {
				os << dt.heso[i] << "x^" << i;
			}
		}
		else {
			os << abs(dt.heso[i]) << "x";
		}

		if (dt.heso[i - 1] >= 0) {
			os << " + ";
		}
		else {
			os << " - ";
		}
	}
	os << abs(dt.heso[0]);

	return os;
}



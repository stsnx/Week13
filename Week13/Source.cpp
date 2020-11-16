#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<vector>
using namespace std;
struct info {
	int subbyte;
	char d;
};


void makebinEncode(char *x,int l,char *t) {	
	vector<int> dec;
	vector<info> base;
	for (int i = 0; i < l; i++) {
		vector<int> temp;
		int tempv = *x;
		while (tempv > 0) {
			temp.push_back(tempv % 2);
			tempv /= 2;
		}
		if (tempv < 128) {
			dec.push_back(0);
		}
		for (int j = temp.size() - 1; j >= 0; j--) {
			dec.push_back(temp[j]);
		}
		x++;
	}
	
	
	int over=0;
	if (dec.size() % 6 != 0)
	{
		if (dec.size() % 6 == 4) {
			over = 1;
			for (int i = 0; i < 8; i++) {
			dec.push_back(0);
			}
		}
		else if (dec.size() % 6 == 2) {
			over = 2;
			for (int i = 0; i < 8; i++) {
				dec.push_back(0);
			}
		}
		
	}
	/*for (int j = 0; j < dec.size(); j++) {
		cout << dec[j];
		if ((j + 1) % 6 == 0) cout << ' ';
	}*/
	/*cout << endl;
	cout<< dec.size()<<endl;*/
	for (int j = 0; j < dec.size(); j += 6) {
		if (j + 5 < dec.size()) {
			info Temp;
			Temp.subbyte = 0;
			int m = 1;
			for (int k = 0; k < 6; k++) {
				Temp.subbyte += dec[j + 5 - k] * m;
				m *= 2;
			}
			base.push_back(Temp);
		}
	}
	if (over==1) {
			info Temp;
			Temp.subbyte = 64;
			base.push_back(Temp);
	}
	if (over==2) {
			info Temp;
			Temp.subbyte = 64;
			base.push_back(Temp);
			base.push_back(Temp);
	}
	/*for (int j = 0; j < base.size(); j++) {
		cout << base[j].subbyte<<' ';
	}
	cout << endl;*/
	for (int j = 0; j < base.size(); j++) {
		base[j].d = *(t + base[j].subbyte);
	}
	for (int j = 0; j < base.size(); j++) {
		cout << base[j].d;
	}
}

int main() {
	char x[100];
	char table[66] = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789+/=";
	
	scanf("%[^\n]",x);
	makebinEncode(x,strlen(x),table);
	
	return 0;
}

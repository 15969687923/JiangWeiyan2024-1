#include <iostream>
#include <string>
#include <stdlib.h>
#include <math.h>
#include <windows.h>
#include <vector>

using namespace std;

void order(vector<int>, int num_subredes);//
int convert_octeto(string);
void calc(int, string,  vector<int>, int);
void check( vector<int>, int);

int main() {
	int num_subnet = 0;
	int suma = 0;
	vector<int> location;
	int octeto_final;
	string num_network;

	cout << endl << " ����IP:  ";
	cin >> num_network;

	cout << endl << "����Ҫ��������������:";
	cin >> num_subnet;

	location.resize(num_subnet);

	for (int i = 0; i < num_subnet; i++) {
		cout << endl << "��������Ҫ������"<< i + 1 <<  "��������IP����: ";      // ���������ŵ�ip����
		cin >> location[i];
	}

	check(location, num_subnet);
	octeto_final = convert_octeto(num_network);
	order(location, num_subnet);
	calc(octeto_final, num_network, location, num_subnet);


	cin.ignore();
	cin.get();
	return 0;
}

void order( vector<int> location, int num_subnet) { // �Ӵ�С���������С�

	int a;

	for (int i = 0; i < num_subnet; i++) {
		for (int j = 0; j < num_subnet-1; j++) {
			if(location[j+1] > location[j]) {
				a = location[j];
				location[j] = location[j+1];
				location[j+1] = a;
			}
		}
	}
}

int convert_octeto(string num_network) { // ��ȡip�����һ���ֽڣ��Ա㽫�䷵�ص�main��ʹ�������в�����

	string delimiter = ".";
	string a;
	int octeto;
	size_t pos;
	num_network = num_network + ".";

	while ((pos = num_network.find(delimiter)) !=  string::npos) {

		a = num_network.substr(0, pos);

		num_network.erase(0, pos + delimiter.length());
	}

	octeto = atoi(a.c_str());

	return octeto;
}

void calc(int octeto_final, string num_network,  vector<int> location, int num_subnet) {

	int bits_occupy= 0;
	string prim_ip;
	string ult_ip;
	string broad_ip;
	string yanma;
	size_t found;
	int octeto2;
	//ȡips������ĵ�һ��ֵ���������滻Ϊn���Բ鿴��ӽ�������������ips����2�����Ƕ���
	for (int i = 0; i < num_subnet; i++) {
		octeto_final = octeto_final + bits_occupy; //���������ַ�͵�һ��ip

		if (log2(location[i]+2) <= 7 && log2(location[i]+2) >= 6) {
			bits_occupy= 128 ;
			yanma = "255.255.255.128";
		}

		if (log2(location[i]+2) <= 6 && log2(location[i]+2) >= 5) {
			bits_occupy= 64 ;
			yanma = "255.255.255.192";
		}

		if (log2(location[i]+2) <= 5 && log2(location[i]+2) >= 4) {
			bits_occupy= 32 ;
			yanma = "255.255.255.224";
		}

		if (log2(location[i]+2) <= 4 && log2(location[i]+2) >= 3) {
			bits_occupy= 16 ;
			yanma = "255.255.255.240";
		}

		if (log2(location[i]+2) <= 3 && log2(location[i]+2) >= 2) {
			bits_occupy= 8 ;
			yanma = "255.255.255.248";
		}

		if (log2(location[i]+2) <= 2 && log2(location[i]+2) >= 1) {
			bits_occupy= 4 ;
			yanma = "255.255.255.252";
		}

		cout << endl << "���� " << i+1 << endl << endl;
		cout  << " "<< "IP��Ҫ�� " << location[i] << endl << endl;
		octeto2 = octeto_final + bits_occupy; //���ڹ㲥������ip
			int x1;
			for(int j=0;; j++) {
				if(location[i]<=((int)pow(2,j)-2)) {
					x1=j;
					break;
				}
			}
			x1 = 32-x1;
			found = num_network.string::find_last_of(".");
			num_network = num_network.substr(0, found) + "." +  to_string(octeto_final);
			cout << "     " << "�����ַ: " << num_network <<"/"<<x1<<endl;

//		cout << "                                                                      " << endl;
//		cout << "     " << "��������: " << yanma << endl;
		cout << "                                                                      " << endl;
		// ���õ���һ��ip�����ǽ�1�ӵ����һ���ֽڵĽ����
		found = num_network.string::find_last_of(".");
		prim_ip = num_network.substr(0, found) + "." +  to_string(octeto_final+1);

		cout << "     " << "��һ��IP: "<< prim_ip <<  endl;

		cout << "                                                                      " << endl;
		// �ӹ㲥�м�ȥ1�õ����һ��ip��
		ult_ip = num_network.substr(0, found) + "." +  to_string(octeto2-2);

		cout << "     " << "���IP: "<< ult_ip <<  endl;

		cout << "                                                                      " << endl;
		// �õ��㲥ip���������һ��ip��ȥ1�Ľ����
//		found = num_network.string::find_last_of(".");
//		broad_ip = num_network.substr(0, found) + "." +  to_string(octeto2-1);
//
//		cout << "     " << "�㲥: " << broad_ip <<  endl << endl << endl;

	}
}

void check( vector<int>location, int num_subnet) { //����Ƿ񳬹�256������ip
	int sumabits = 0;
	int bits_occupy= 0;
	for (int i = 0; i < num_subnet; i++) {
		if (log2(location[i]+2) <= 7 && log2(location[i]+2) >= 6) {
			bits_occupy= 128 ;
		}

		if (log2(location[i]+2) <= 6 && log2(location[i]+2) >= 5) {
			bits_occupy= 64 ;
		}

		if (log2(location[i]+2) <= 5 && log2(location[i]+2) >= 4) {
			bits_occupy= 32 ;
		}

		if (log2(location[i]+2) <= 4 && log2(location[i]+2) >= 3) {
			bits_occupy= 16 ;
		}

		if (log2(location[i]+2) <= 3 && log2(location[i]+2) >= 2) {
			bits_occupy= 8 ;
		}

		if (log2(location[i]+2) <= 2 && log2(location[i]+2) >= 1) {
			bits_occupy= 4 ;
		}

		sumabits = sumabits + bits_occupy;
	}

	if(sumabits > 256 ) { // ͨ��ɾ��ÿ����������2��ip������Ƿ񳬹�������

		cout << " ���ܷ�����ô��ip��ַ��";

		cin.ignore();
		cin.get();
		exit(1);
	}
}

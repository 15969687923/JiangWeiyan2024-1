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

	cout << endl << " 输入IP:  ";
	cin >> num_network;

	cout << endl << "你想要创建多少子网络:";
	cin >> num_subnet;

	location.resize(num_subnet);

	for (int i = 0; i < num_subnet; i++) {
		cout << endl << "输入您想要创建第"<< i + 1 <<  "个子网的IP数量: ";      // 输入子网号的ip数量
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

void order( vector<int> location, int num_subnet) { // 从大到小的气泡排列。

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

int convert_octeto(string num_network) { // 获取ip的最后一个字节，以便将其返回到main并使用它进行操作。

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
	//取ips数数组的第一个值，并将其替换为n，以查看最接近或等于所请求的ips数的2的幂是多少
	for (int i = 0; i < num_subnet; i++) {
		octeto_final = octeto_final + bits_occupy; //用于网络地址和第一个ip

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

		cout << endl << "子网 " << i+1 << endl << endl;
		cout  << " "<< "IP的要求 " << location[i] << endl << endl;
		octeto2 = octeto_final + bits_occupy; //用于广播和最新ip
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
			cout << "     " << "网络地址: " << num_network <<"/"<<x1<<endl;

//		cout << "                                                                      " << endl;
//		cout << "     " << "子网掩码: " << yanma << endl;
		cout << "                                                                      " << endl;
		// 它得到第一个ip，这是将1加到最后一个字节的结果。
		found = num_network.string::find_last_of(".");
		prim_ip = num_network.substr(0, found) + "." +  to_string(octeto_final+1);

		cout << "     " << "第一个IP: "<< prim_ip <<  endl;

		cout << "                                                                      " << endl;
		// 从广播中减去1得到最后一个ip。
		ult_ip = num_network.substr(0, found) + "." +  to_string(octeto2-2);

		cout << "     " << "最后IP: "<< ult_ip <<  endl;

		cout << "                                                                      " << endl;
		// 得到广播ip，这是最后一个ip减去1的结果。
//		found = num_network.string::find_last_of(".");
//		broad_ip = num_network.substr(0, found) + "." +  to_string(octeto2-1);
//
//		cout << "     " << "广播: " << broad_ip <<  endl << endl << endl;

	}
}

void check( vector<int>location, int num_subnet) { //检查是否超过256个可用ip
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

	if(sumabits > 256 ) { // 通过删除每个新子网的2个ip来检查是否超过了限制

		cout << " 不能分配这么多ip地址。";

		cin.ignore();
		cin.get();
		exit(1);
	}
}

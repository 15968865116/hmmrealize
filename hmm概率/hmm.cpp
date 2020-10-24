
#include <iostream>
#include <vector>
using namespace std;

/*
* XΪ�۲������˴�ʵ����ʹ��0��1�������������
* B�ǹ۲���ʾ��� ����ÿһ��״̬����ȡ����Ӧ����ĸ���
* Pi��һ����ʼ���ʷֲ�����
* A��״̬ת�ƾ��󣬱�ʾ�ڵ�ǰ״̬��ת�Ƶ�������״̬�ĸ���
* ���������ڼ�����������
*/
double computehmm(vector<int> X, vector<vector<double>> B, vector<double> Pi, vector<vector<double>> A) {
	vector<double> X_gailv;
	//�����һ���۲����µĵĸ������
	for (unsigned int i = 0; i < Pi.size(); i++) {
		double gailv = Pi[i] * B[i][X[0]];
		X_gailv.push_back(gailv);
	}
	for (unsigned int i = 1; i < X.size(); i++) {
		vector<double> ls = X_gailv;
		for (unsigned int j = 0; j < Pi.size(); j++) {
			/*��ǰ���ʼ��㣺����ǰһ��״̬�ĸ�����������ת�Ƶ���״̬�ĸ���֮��,ͬʱ�ڴ�״̬��ȡ����Ӧ�۲�����ĸ���*/
			X_gailv[j] =ls[0]*A[0][j]*B[j][X[i]]+ ls[1] * A[1][j] * B[j][X[i]] + ls[2] * A[2][j] * B[j][X[i]] +ls[3] * A[3][j] * B[j][X[i]];
			
		}
	}
	double allgailv = 0;
	for (unsigned int i = 0; i < Pi.size(); i++) {
		cout << X_gailv[i];
		allgailv = allgailv + X_gailv[i];

	}
	return allgailv;


}
int main(){
	
	vector<vector<double>> B = { {0.5,0.5},{0.3,0.7},{0.6,0.4},{0.8,0.2} };
	vector<double> Pi = { 0.25,0.25,0.25,0.25 };
	vector<vector<double>> A = { {0,1,0,0},{0.4,0,0.6,0},{0,0.4,0,0.6},{0,0,0.5,0.5} };
	vector<int> X = { 0,0,1,1,0 };
	double a = computehmm(X, B, Pi, A);
	cout << '/n';
	cout << a;
}


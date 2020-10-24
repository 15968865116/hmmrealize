
#include <iostream>
#include <vector>
using namespace std;

/*
* X为观测结果（此处实例仅使用0，1代表两种情况）
* B是观测概率矩阵 代表每一个状态内能取到对应情况的概率
* Pi是一个初始概率分布矩阵
* A是状态转移矩阵，表示在当前状态下转移到其他各状态的概率
* 本函数用于计算条件概率
*/
double computehmm(vector<int> X, vector<vector<double>> B, vector<double> Pi, vector<vector<double>> A) {
	vector<double> X_gailv;
	//计算第一个观测结果下的的概率情况
	for (unsigned int i = 0; i < Pi.size(); i++) {
		double gailv = Pi[i] * B[i][X[0]];
		X_gailv.push_back(gailv);
	}
	for (unsigned int i = 1; i < X.size(); i++) {
		vector<double> ls = X_gailv;
		for (unsigned int j = 0; j < Pi.size(); j++) {
			/*当前概率计算：是由前一个状态的各个可能性下转移到此状态的概率之和,同时在此状态下取到对应观测情况的概率*/
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


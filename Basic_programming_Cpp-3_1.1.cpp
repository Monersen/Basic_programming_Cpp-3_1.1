
#include <iostream>
#include <fstream>
using namespace std;

int main(int argc, char** argv)
{
	ifstream fin("in.txt");
	ofstream fout("out.txt");
	if (fin.is_open()) {

		int N, tmp_N;
		fin >> N;

		int* arr = new int[N];

		for (int i = 0; i < N; ++i) {
			fin >> arr[i];
		}

		int M, tmp_M;
		fin >> M;

		int* arr_1 = new int[M];

		for (int i = 0; i < M; ++i) {
			fin >> arr_1[i];
		}


		fout << M << endl;
		tmp_M = arr_1[M - 1];
		for (int i = M - 2; i >= 0; i--)
		{
			arr_1[i + 1] = arr_1[i];
		}
		arr_1[0] = tmp_M;
		for (int i = 0; i < M; i++)
		{
			fout << arr_1[i] << " ";
		}

		fout << endl;

		fout << N << endl;
		tmp_N = arr[0];
		for (int i = 1; i < N; ++i)
		{
			arr[i - 1] = arr[i];
		}
		arr[N - 1] = tmp_N;
		for (int i = 0; i < N; i++)
		{
			fout << arr[i] << " ";
		}


		delete[] arr;
		delete[] arr_1;

	}
	else {
		cout << "file in.txt does not exist" << endl;
	}
	fin.close();
	fout.close();


}


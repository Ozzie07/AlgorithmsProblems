#include <bits/stdc++.h>
#define LENGTH 100001
using namespace std;

class Score
{
	int kor_score;
	int eng_score;
	int math_score;
	string name;

public:

	Score(int k, int e, int m, string _name) {
		kor_score = k, eng_score = e,
			math_score = m, name = _name;
	}

	Score() { kor_score = 0, eng_score = 0, math_score = 0, name = '0'; }

	bool operator > (Score _input)
	{
		if (this->kor_score == _input.kor_score)
		{
			if (this->eng_score == _input.eng_score)
			{
				if (this->math_score == _input.math_score)
					return this->name > _input.name;
				return this->math_score < _input.math_score;
			}
			return this->eng_score > _input.eng_score;
		}
		return this->kor_score < _input.kor_score;
	}

	friend ostream& operator << (ostream& os, Score _in);
};

ostream& operator << (ostream& os, Score _in)
{
	cout << _in.name << ' ';
	return os;
}


//it is Shit code. arr2 is nothing.
template <class T>
void Merge(T* arr, T* arr2, int start, int end)
{
	int partition = (start + end) / 2;

	int L_start = start;
	int L_idx = L_start;
	int L_end = partition;

	int R_start = partition + 1;
	int R_idx = R_start;
	int R_end = end;

	int length = end - start + 1;

	for (size_t i = 0; i < length; i++)
	{
		if (arr[L_idx] > arr[R_idx])
			arr2[i] = arr[R_idx++];
		else
			arr2[i] = arr[L_idx++];

		if (R_idx > R_end)
		{
			for (L_idx; L_idx <= L_end; L_idx++)
				arr2[++i] = arr[L_idx];
			break;
		}

		if (L_idx > L_end)
		{
			for (R_idx; R_idx <= R_end; R_idx++)
				arr2[++i] = arr[R_idx];
			break;
		}
	}

	int j = L_start;
	for (size_t i = 0; i < length; i++)
	{
		arr[j++] = arr2[i];
	}
}



template <class T>
void MergeSort(T* arr, T* arr2, int start, int end)
{
	if (start >= end)
		return;
	int partition = (start + end) / 2;
	MergeSort(arr, arr2, start, partition);
	MergeSort(arr, arr2, partition + 1, end);
	Merge<T>(arr, arr2, start, end);
}

template <class T>
void Sort(T* arr, T* arr2, int length)
{
	MergeSort(arr, arr2, 0, length - 1);
}


int main() {
	//	freopen("input.txt", "r", stdin);
	//	freopen("output.txt", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	//\n faster than endl. endl makes buffer flush explicitly.


	//it is Shit code. arr2 is nothing.
	Score arr[LENGTH];
	Score arr2[LENGTH];

	int numOfInput;
	int kor, eng, math;
	string name;
	cin >> numOfInput;
	for (size_t i = 0; i < numOfInput; i++)
	{
		cin >> name >> kor >> eng >> math;
		arr[i] = Score(kor, eng, math, name);
	}

	Sort(arr, arr2, numOfInput);

	for (size_t i = 0; i < numOfInput; i++)
	{
		cout << arr[i] << '\n';
	}
	cout << endl;

	return 0;
}
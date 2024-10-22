#include "utility.h"
#include <random>
using namespace std;

// �����_���Ȕԍ��z����쐬����
vector<int> CreateRandomIndices(int n)
{
	// �ԍ���z��Ɋi�[
	vector<int> indices(n);
	for (int i = 0; i < n; i++)
	{
		indices[i] = i;
	}

	// �ԍ��̔z����V���b�t��
	Shuffle(indices);

	return indices;
	
}

// �z����V���b�t������
void Shuffle(vector<int>& indices)
{
	const int n = static_cast<int>(indices.size());	
	random_device rd;
	mt19937 rand(rd());
	for (int i = n - 1; i > 0; i--)
	{
		const int j = uniform_int_distribution<>(0, i)(rand);
		const int tmp = indices[i];
		indices[i] = indices[j];
		indices[j] = tmp;
	}
}

// �Ԉ�����ԍ��̔z����쐬
vector<int> CreateWrongIndices(int n, int correctIndex)
{
	// �ԍ���z��Ɋi�[
	vector<int> indices(n - 1);
	for (int i = 0; i < correctIndex; i++)
	{
		indices[i] = i;

	}
	for (int i = correctIndex; i < n - 1; i++)
	{
		indices[i] = i + 1;

	}
	// �ԍ��̔z����V���b�t��
	Shuffle(indices);

	return indices;
}
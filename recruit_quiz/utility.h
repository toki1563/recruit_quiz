#pragma once
#include <vector>

// �����_���Ȕԍ��z����쐬����
std::vector<int> CreateRandomIndices(int n);

// �z����V���b�t������
void Shuffle(std::vector<int>& indices);

// �Ԉ�����ԍ��̔z����쐬����
// n            �쐬����ԍ��͈̔�
// correctIndex �����̔ԍ�
std::vector<int> CreateWrongIndices(int n, int correctIndex);
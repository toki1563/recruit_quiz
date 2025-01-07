#pragma once
#include <vector>
#include <string>

// �����_���Ȕԍ��z����쐬����
std::vector<int> CreateRandomIndices(int n);

// �z����V���b�t������
void Shuffle(std::vector<int>& indices);

// �Ԉ�����ԍ��̔z����쐬����
// n            �쐬����ԍ��͈̔�
// correctIndex �����̔ԍ�
std::vector<int> CreateWrongIndices(int n, int correctIndex);

// ������𕪊�����
// s �������镶����
// c ��؂蕶��
std::vector<std::string> Split(const std::string & s, char c);
#pragma once
#include <string>
#include <vector>


// ��蕶�Ɠ������܂Ƃ߂�\����
struct Question
{
	std::string q; // ��蕶
	std::string a; // ����
};

// ���̔z���\���^
using QuestionList = std::vector<Question>;
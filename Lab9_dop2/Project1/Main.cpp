#include <iostream>
#include <string>
#include <vector>
#include <Windows.h>
#include "List.h"
using namespace std;

class Univer {
public:
	Univer() {}

	void AddStudent(Student _data) {

		switch (_data.course)
		{
		case 1:
			courseOne.push_back(_data);
			break;
		case 2:
			courseTwo.push_back(_data);
			break;
		case 3:
			courseThree.push_back(_data);
			break;
		case 4:
			courseFour.push_back(_data);
			break;
		default:
			throw exception("Ошибка определения курса!");
		}

	}

	void SortStudent() {
		if (this->courseOne.get_size() != 0)
			this->courseOne.sort();
		if (this->courseTwo.get_size() != 0)
			this->courseTwo.sort();
		if (this->courseThree.get_size() != 0)
			this->courseThree.sort();
		if (this->courseFour.get_size() != 0)
			this->courseFour.sort();
	}

	void PrintStudent() {
		if (courseOne.get_size() != 0) {
			cout << "------------------- Курс 1 -------------------" << endl;
			for (int i = 0; i < courseOne.get_size(); i++) {
				cout << i + 1 << ". " << courseOne[i].lastName << " " << courseOne[i].firstName << " " << courseOne[i].otch 
					<< " " << courseOne[i].group << " группа." << endl;
			}
			cout << "----------------------------------------------" << endl;
		}
		if (courseTwo.get_size() != 0) {
			cout << "------------------- Курс 2 -------------------" << endl;
			for (int i = 0; i < courseTwo.get_size(); i++) {
				cout << i + 1 << ". " << courseTwo[i].lastName << " " << courseTwo[i].firstName << " " << courseTwo[i].otch
					<< " " << courseTwo[i].group << " группа." << endl;
			}
			cout << "----------------------------------------------" << endl;
		}
		if (courseThree.get_size() != 0) {
			cout << "------------------- Курс 3 -------------------" << endl;
			for (int i = 0; i < courseThree.get_size(); i++) {
				cout << i + 1 << ". " << courseThree[i].lastName << " " << courseThree[i].firstName << " " << courseThree[i].otch
					<< " " << courseThree[i].group << " группа." << endl;
			}
			cout << "----------------------------------------------" << endl;
		}
		if (courseFour.get_size() != 0) {
			cout << "------------------- Курс 4 -------------------" << endl;
			for (int i = 0; i < courseFour.get_size(); i++) {
				cout << i + 1 << ". " << courseFour[i].lastName << " " << courseFour[i].firstName << " " << courseFour[i].otch
					<< " " << courseFour[i].group << " группа." << endl;
			}
			cout << "----------------------------------------------" << endl;
		}
	}

	void GetGroupAverageMark() {
		if (courseOne.get_size() != 0) {
			cout << "------------------- Курс 1 -------------------" << endl;
			float averageMark = 0, tempAverageMark = 0;
			int count = 0;

			for (int i = 1; i < 10; i++) {
				for (int j = 0; j < courseOne.get_size(); j++) {
					if (courseOne[j].group == i) {
						for (int k = 0; k < 5; k++) {
							tempAverageMark += courseOne[j].mark[k];
						}
						tempAverageMark /= 5;

						averageMark += tempAverageMark;
						count++;
					}
					tempAverageMark = 0;
				}
				if (averageMark == 0) {
					averageMark = 0; tempAverageMark = 0; count = 0;
					continue;
				}
				averageMark /= count;
				cout << "Средний бал в " << i << " группе равен " << averageMark << endl;
				averageMark = 0; tempAverageMark = 0; count = 0;
			}
			cout << "----------------------------------------------" << endl;
		}
		if (courseTwo.get_size() != 0) {
			cout << "------------------- Курс 2 -------------------" << endl;
			float averageMark = 0, tempAverageMark = 0;
			int count = 0;

			for (int i = 1; i < 10; i++) {
				for (int j = 0; j < courseTwo.get_size(); j++) {
					if (courseTwo[j].group == i) {
						for (int k = 0; k < 5; k++) {
							tempAverageMark += courseTwo[j].mark[k];
						}
						tempAverageMark /= 5;

						averageMark += tempAverageMark;
						count++;
					}
					tempAverageMark = 0;
				}
				if (averageMark == 0) {
					averageMark = 0; tempAverageMark = 0; count = 0;
					continue;
				}
				averageMark /= count;
				cout << "Средний бал в " << i << " группе равен " << averageMark << endl;
				averageMark = 0; tempAverageMark = 0; count = 0;
			}
			cout << "----------------------------------------------" << endl;
		}
		if (courseThree.get_size() != 0) {
			cout << "------------------- Курс 3 -------------------" << endl;
			float averageMark = 0, tempAverageMark = 0;
			int count = 0;

			for (int i = 1; i < 10; i++) {
				for (int j = 0; j < courseThree.get_size(); j++) {
					if (courseThree[j].group == i) {
						for (int k = 0; k < 5; k++) {
							tempAverageMark += courseThree[j].mark[k];
						}
						tempAverageMark /= 5;

						averageMark += tempAverageMark;
						count++;
					}
					tempAverageMark = 0;
				}
				if (averageMark == 0) {
					averageMark = 0; tempAverageMark = 0; count = 0;
					continue;
				}
				averageMark /= count;
				cout << "Средний бал в " << i << " группе равен " << averageMark << endl;
				averageMark = 0; tempAverageMark = 0; count = 0;
			}
			cout << "----------------------------------------------" << endl;
		}
		if (courseFour.get_size() != 0) {
			cout << "------------------- Курс 4 -------------------" << endl;
			float averageMark = 0, tempAverageMark = 0;
			int count = 0;

			for (int i = 1; i < 10; i++) {
				for (int j = 0; j < courseFour.get_size(); j++) {
					if (courseFour[j].group == i) {
						for (int k = 0; k < 5; k++) {
							tempAverageMark += courseFour[j].mark[k];
						}
						tempAverageMark /= 5;

						averageMark += tempAverageMark;
						count++;
					}
					tempAverageMark = 0;
				}
				if (averageMark == 0) {
					averageMark = 0; tempAverageMark = 0; count = 0;
					continue;
				}
				averageMark /= count;
				cout << "Средний бал в " << i << " группе равен " << averageMark << endl;
				averageMark = 0; tempAverageMark = 0; count = 0;
			}
			cout << "----------------------------------------------" << endl;
		}
	}

	void GetYongerStudent() {
		if (courseOne.get_size() != 0) {
			cout << "------------------- Курс 1 -------------------" << endl;
			string studentOld = courseOne[0].lastName + " " + courseOne[0].firstName + " " + courseOne[0].otch;
			auto current = courseOne[0];

			for (int i = 1; i < courseOne.get_size(); i++) {
				if (current.date.year < courseOne[i].date.year) {
					current = courseOne[i];
					studentOld = courseOne[i].lastName + " " + courseOne[i].firstName + " " + courseOne[i].otch;
				}
				else if (current.date.year == courseOne[i].date.year) {
					if (current.date.month < courseOne[i].date.month) {
						current = courseOne[i];
						studentOld = courseOne[i].lastName + " " + courseOne[i].firstName + " " + courseOne[i].otch;
					}
					else if (current.date.month == courseOne[i].date.month) {
						if (current.date.date < courseOne[i].date.date) {
							current = courseOne[i];
							studentOld = courseOne[i].lastName + " " + courseOne[i].firstName + " " + courseOne[i].otch;
						}
					}
				}
			}
			cout << "Самый младший " << studentOld << endl;
			cout << "----------------------------------------------" << endl;
		}
		if (courseTwo.get_size() != 0) {
			cout << "------------------- Курс 2 -------------------" << endl;
			string studentOld = courseTwo[0].lastName + " " + courseTwo[0].firstName + " " + courseTwo[0].otch;
			auto current = courseTwo[0];

			for (int i = 1; i < courseTwo.get_size(); i++) {
				if (current.date.year < courseTwo[i].date.year) {
					current = courseTwo[i];
					studentOld = courseTwo[i].lastName + " " + courseTwo[i].firstName + " " + courseTwo[i].otch;
				}
				else if (current.date.year == courseTwo[i].date.year) {
					if (current.date.month < courseTwo[i].date.month) {
						current = courseTwo[i];
						studentOld = courseTwo[i].lastName + " " + courseTwo[i].firstName + " " + courseTwo[i].otch;
					}
					else if (current.date.month == courseTwo[i].date.month) {
						if (current.date.date < courseTwo[i].date.date) {
							current = courseTwo[i];
							studentOld = courseTwo[i].lastName + " " + courseTwo[i].firstName + " " + courseTwo[i].otch;
						}
					}
				}
			}
			cout << "Самый младший " << studentOld << endl;
			cout << "----------------------------------------------" << endl;
		}
		if (courseThree.get_size() != 0) {
			cout << "------------------- Курс 3 -------------------" << endl;
			string studentOld = courseThree[0].lastName + " " + courseThree[0].firstName + " " + courseThree[0].otch;
			auto current = courseThree[0];

			for (int i = 1; i < courseThree.get_size(); i++) {
				if (current.date.year < courseThree[i].date.year) {
					current = courseThree[i];
					studentOld = courseThree[i].lastName + " " + courseThree[i].firstName + " " + courseThree[i].otch;
				}
				else if (current.date.year == courseThree[i].date.year) {
					if (current.date.month < courseThree[i].date.month) {
						current = courseThree[i];
						studentOld = courseThree[i].lastName + " " + courseThree[i].firstName + " " + courseThree[i].otch;
					}
					else if (current.date.month == courseThree[i].date.month) {
						if (current.date.date < courseThree[i].date.date) {
							current = courseThree[i];
							studentOld = courseThree[i].lastName + " " + courseThree[i].firstName + " " + courseThree[i].otch;
						}
					}
				}
			}
			cout << "Самый младший " << studentOld << endl;
			cout << "----------------------------------------------" << endl;
		}
		if (courseFour.get_size() != 0) {
			cout << "------------------- Курс 4 -------------------" << endl;
			string studentOld = courseFour[0].lastName + " " + courseFour[0].firstName + " " + courseFour[0].otch;
			auto current = courseFour[0];

			for (int i = 1; i < courseFour.get_size(); i++) {
				if (current.date.year < courseFour[i].date.year) {
					current = courseFour[i];
					studentOld = courseFour[i].lastName + " " + courseFour[i].firstName + " " + courseFour[i].otch;
				}
				else if (current.date.year == courseFour[i].date.year) {
					if (current.date.month < courseFour[i].date.month) {
						current = courseFour[i];
						studentOld = courseFour[i].lastName + " " + courseFour[i].firstName + " " + courseFour[i].otch;
					}
					else if (current.date.month == courseFour[i].date.month) {
						if (current.date.date < courseFour[i].date.date) {
							current = courseFour[i];
							studentOld = courseFour[i].lastName + " " + courseFour[i].firstName + " " + courseFour[i].otch;
						}
					}
				}
			}
			cout << "Самый младший " << studentOld << endl;
			cout << "----------------------------------------------" << endl;
		}
	}

	void GetOldestStudent() {
		if (courseOne.get_size() != 0) {
			cout << "------------------- Курс 1 -------------------" << endl;
			string studentOld = courseOne[0].lastName + " " + courseOne[0].firstName + " " + courseOne[0].otch;
			auto current = courseOne[0];

			for (int i = 1; i < courseOne.get_size(); i++) {
				if (current.date.year > courseOne[i].date.year) {
					current = courseOne[i];
					studentOld = courseOne[i].lastName + " " + courseOne[i].firstName + " " + courseOne[i].otch;
				}
				else if (current.date.year == courseOne[i].date.year) {
					if (current.date.month > courseOne[i].date.month) {
						current = courseOne[i];
						studentOld = courseOne[i].lastName + " " + courseOne[i].firstName + " " + courseOne[i].otch;
					}
					else if (current.date.month == courseOne[i].date.month) {
						if (current.date.date > courseOne[i].date.date) {
							current = courseOne[i];
							studentOld = courseOne[i].lastName + " " + courseOne[i].firstName + " " + courseOne[i].otch;
						}
					}
				}
			}
			cout << "Самый старший " << studentOld << endl;
			cout << "----------------------------------------------" << endl;
		}
		if (courseTwo.get_size() != 0) {
			cout << "------------------- Курс 2 -------------------" << endl;
			string studentOld = courseTwo[0].lastName + " " + courseTwo[0].firstName + " " + courseTwo[0].otch;
			auto current = courseTwo[0];

			for (int i = 1; i < courseTwo.get_size(); i++) {
				if (current.date.year > courseTwo[i].date.year) {
					current = courseTwo[i];
					studentOld = courseTwo[i].lastName + " " + courseTwo[i].firstName + " " + courseTwo[i].otch;
				}
				else if (current.date.year == courseTwo[i].date.year) {
					if (current.date.month > courseTwo[i].date.month) {
						current = courseTwo[i];
						studentOld = courseTwo[i].lastName + " " + courseTwo[i].firstName + " " + courseTwo[i].otch;
					}
					else if (current.date.month == courseTwo[i].date.month) {
						if (current.date.date > courseTwo[i].date.date) {
							current = courseTwo[i];
							studentOld = courseTwo[i].lastName + " " + courseTwo[i].firstName + " " + courseTwo[i].otch;
						}
					}
				}
			}
			cout << "Самый старший " << studentOld << endl;
			cout << "----------------------------------------------" << endl;
		}
		if (courseThree.get_size() != 0) {
			cout << "------------------- Курс 3 -------------------" << endl;
			string studentOld = courseThree[0].lastName + " " + courseThree[0].firstName + " " + courseThree[0].otch;
			auto current = courseThree[0];

			for (int i = 1; i < courseThree.get_size(); i++) {
				if (current.date.year > courseThree[i].date.year) {
					current = courseThree[i];
					studentOld = courseThree[i].lastName + " " + courseThree[i].firstName + " " + courseThree[i].otch;
				}
				else if (current.date.year == courseThree[i].date.year) {
					if (current.date.month > courseThree[i].date.month) {
						current = courseThree[i];
						studentOld = courseThree[i].lastName + " " + courseThree[i].firstName + " " + courseThree[i].otch;
					}
					else if (current.date.month == courseThree[i].date.month) {
						if (current.date.date > courseThree[i].date.date) {
							current = courseThree[i];
							studentOld = courseThree[i].lastName + " " + courseThree[i].firstName + " " + courseThree[i].otch;
						}
					}
				}
			}
			cout << "Самый старший " << studentOld << endl;
			cout << "----------------------------------------------" << endl;
		}
		if (courseFour.get_size() != 0) {
			cout << "------------------- Курс 4 -------------------" << endl;
			string studentOld = courseFour[0].lastName + courseFour[0].firstName + courseFour[0].otch;
			auto current = courseFour[0];

			for (int i = 1; i < courseFour.get_size(); i++) {
				if (current.date.year > courseFour[i].date.year) {
					current = courseFour[i];
					studentOld = courseFour[i].lastName + " " + courseFour[i].firstName + " " + courseFour[i].otch;
				}
				else if (current.date.year == courseFour[i].date.year) {
					if (current.date.month > courseFour[i].date.month) {
						current = courseFour[i];
						studentOld = courseFour[i].lastName + " " + courseFour[i].firstName + " " + courseFour[i].otch;
					}
					else if (current.date.month == courseFour[i].date.month) {
						if (current.date.date > courseFour[i].date.date) {
							current = courseFour[i];
							studentOld = courseFour[i].lastName + " " + courseFour[i].firstName + " " + courseFour[i].otch;
						}
					}
				}
			}
			cout << "Самый старший " << studentOld << endl;
			cout << "----------------------------------------------" << endl;
		}
	}

	void GetBestStudent() {
		if (courseOne.get_size() != 0) {
			cout << "------------------- Курс 1 -------------------" << endl;
			
			string student = courseOne[0].lastName + " " + courseOne[0].firstName + " " + courseOne[0].otch;
			auto current = courseOne[0];

			for (int i = 0; i < courseOne.get_size(); i++)
				if (GetAverageMark(current) < GetAverageMark(courseOne[i])) {
					student = courseOne[i].lastName + " " + courseOne[i].firstName + " " + courseOne[i].otch;
					current = courseOne[i];
				}

			cout << "Лучший студент " << student << endl;

			cout << "----------------------------------------------" << endl;
		}
		if (courseTwo.get_size() != 0) {
			cout << "------------------- Курс 2 -------------------" << endl;
			
			string student = courseTwo[0].lastName + " " + courseTwo[0].firstName + " " + courseTwo[0].otch;
			auto current = courseTwo[0];

			for (int i = 0; i < courseTwo.get_size(); i++)
				if (GetAverageMark(current) < GetAverageMark(courseOne[i])) {
					student = courseTwo[i].lastName + " " + courseTwo[i].firstName + " " + courseTwo[i].otch;
					current = courseTwo[i];
				}

			cout << "Лучший студент " << student << endl;

			cout << "----------------------------------------------" << endl;
		}
		if (courseThree.get_size() != 0) {
			cout << "------------------- Курс 3 -------------------" << endl;
			
			cout << "----------------------------------------------" << endl;
		}
		if (courseFour.get_size() != 0) {
			cout << "------------------- Курс 4 -------------------" << endl;
			
			
			cout << "----------------------------------------------" << endl;
		}
	}

private:

	float GetAverageMark(struct Student student) {
		return (student.mark[0] + student.mark[1] +
			student.mark[2] + student.mark[3] + student.mark[4]) / 5;
	}

	List<Student> courseOne;
	List<Student> courseTwo;
	List<Student> courseThree;
	List<Student> courseFour;
};

int main(int argc, char** argv) {
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	Univer univ;
	univ.AddStudent({ "Александров", "Александр", "Александрович", {1, 1, 2000}, 1, 3, {7, 7, 7, 7, 7} });
	univ.AddStudent({ "Петров", "Петр", "Петрович", {26, 8, 2000}, 1, 3, {8, 8, 8, 8, 8} });
	univ.AddStudent({ "Иванов", "Иван", "Иванович", {13, 4, 2000}, 1, 2, {8, 8, 8, 8, 8} });
	univ.AddStudent({ "Андреев", "Андрей", "Андреевич", {27, 12, 2000}, 1, 2, {9, 9, 9, 9, 9} });
	univ.AddStudent({ "Головач", "Елена", "Игоревна", {17, 7, 2000}, 2, 7, {7, 7, 7, 7, 7} });
	univ.AddStudent({ "Навальный", "Алексей", "Анатольевич", {18, 7, 2000}, 2, 7, {9, 9, 9, 9, 9} });
	univ.SortStudent();
	univ.PrintStudent();
	univ.GetGroupAverageMark();
	univ.GetOldestStudent();
	univ.GetYongerStudent();
	univ.GetBestStudent();
	
	return EXIT_SUCCESS;
}
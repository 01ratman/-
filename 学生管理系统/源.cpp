#include <iostream>
#include <fstream>
#include <vector>
#include<cstdlib>
#define show_Menu 0
#define student_menu 1
#define course_menu 2
#define grades_menu 3
#define exit_1 4
static int flag = 0;
using namespace std;
// ѧ����
class Student {
public:
	string ID;      // ѧ��
	string name;    // ����
	string major;   // רҵ
	string gender;    // �Ա�

	// ���캯��
	Student(string id, string n, string m, string gen) {
		ID = id;
		name = n;
		major = m;
		gender = gen;
	}
};
// �γ���
class Course {
public:
	string ID;      // �γ̺�
	string name;    // �γ�����
	int credit;     // ѧ��
	int hours;      // ѧϰʱ��

	// ���캯��
	Course(string id, string n, int c, int h) {
		ID = id;
		name = n;
		credit = c;
		hours = h;
	}
};
class Grades {
public:
	string stu_id;
	string cou_id;
	double score;
	Grades(string id, string id2, double sc)
	{
		stu_id = id;
		cou_id = id2;
		score = sc;
	}
};
static vector<Student> students;
static vector<Course> courses;
static vector<Grades> grades;
void addStudentToFile(Student s);
vector<Student> loadStudentsFromFile();
void saveStudentsToFile(vector<Student> students);
void addStudent(vector<Student>& students);
void deleteStudent(vector<Student>& students);
void modifyStudent(vector<Student>& students);
void queryStudent(vector<Student>& students);
void showAllStudents(vector<Student>& students);

void addCourseToFile(Course c);
vector<Course> loadCoursesFromFile();
void saveCoursesToFile(vector<Course> courses);
void addCourse(vector<Course>& courses);
void deleteCourse(vector<Course>& courses);
void modifyCourse(vector<Course>& courses);
void queryCourse(vector<Course>& courses);
void showAllCourses(vector<Course>& courses);

void addGradesToFile(Grades g);
vector<Grades> loadGradesFromFile();
void saveGradesToFile(vector<Grades> grades);
void addGrades(vector<Grades> &grades);
void deleteGrades(vector<Grades> &grades);
void modifyGrades(vector<Grades> &grades);
void queryGrades(vector<Grades> &grades);
void showAllGrades(vector<Grades> &grades);

void controller();
void ShowMenu();
void studentmenu();
void coursemenu();
void gradesmenu();
void exit1();


// ���ѧ����¼���ļ���
void addStudentToFile(Student s) {
	ofstream fout0("students.txt", ios::app);//ָ���ļ�ĩβ��ָ��
	if (fout0.is_open()) {
		fout0 << s.ID << " " << s.name << " " << s.major << " " << s.gender << endl;
		fout0.close();
	}
}

// ��������ѧ����¼���ڴ���
vector<Student> loadStudentsFromFile() 
{
	ifstream fin0("students.txt");
	if (fin0.is_open())
	{
		string id, name, major, gender;
		while (fin0 >> id >> name >> major >> gender)
		{
			Student s(id, name, major, gender);
			students.push_back(s);
		}
		fin0.close();
	}
	return students;
}


// ��������ѧ����¼���ļ���
void saveStudentsToFile(vector<Student> students) {
	ofstream fout1("students.txt", ios::trunc);/*trunc��Ҫ�����޸��ļ��ڵ����ݣ��������Ǵ�һ�����ݣ�
	Ȼ������������������������ݣ����û���ҵ�������½�һ�������ٴ洢*/
	if (fout1.is_open()) {
		for (auto &s : students) {
			fout1<< s.ID << " " << s.name << " " << s.major << " " << s.gender << endl;
		}
		fout1.close();
	}
}

// ���ѧ��
void addStudent(vector<Student>& students) 
{
	system("cls");
	string id, name, major,gender;

	cout << "������ѧ�ţ�";
	cin >> id;

	cout << "������������";
	cin >> name;

	cout << "������רҵ��";
	cin >> major;

	cout << "�������Ա�(��/��)��";
	cin >> gender;

	Student s(id, name, major, gender);

	// ����ѧ����ӵ�vector�������ļ���
	students.push_back(s);
	addStudentToFile(s);
	cout << "��ӳɹ���" << endl;
	system("pause");
}

// ɾ��ѧ��
void deleteStudent(vector<Student>& students) 
{
	system("cls");
	string id;

	cout << "������Ҫɾ����ѧ�ţ�";
	cin >> id;

	for (int i = 0; i < students.size(); i++) {
		if (students[i].ID == id) {
			// ��vector�������ļ���ɾ����ѧ����Ϣ
			students.erase(students.begin() + i);
			saveStudentsToFile(students);
			cout << "ɾ���ɹ���" << endl;
			system("pause");
		}
	}

	cout << "û���ҵ���Ӧ��ѧ����¼��" << endl;
	system("pause");
}

// �޸�ѧ����Ϣ
void modifyStudent(vector<Student>& students) 
{
	system("cls");
	string id;

	cout << "������Ҫ�޸ĵ�ѧ�ţ�";
	cin >> id;

	for (int i = 0; i < students.size(); i++) {
		if (students[i].ID == id) {
			cout << "������Ҫ�޸ĵ���Ϣ��" << endl;
			cout << "ѧ�ţ�" << students[i].ID << endl;
			cout << "������";
			cin >> students[i].name;
			cout << "רҵ��";
			cin >> students[i].major;
			cout << "�Ա�(m/f)��";
			cin >> students[i].gender;

			// �����ļ��и�ѧ����¼
			saveStudentsToFile(students);

			cout << "�޸ĳɹ���" << endl;
			system("pause");

		}
	}

	cout << "û���ҵ���Ӧ��ѧ����¼��" << endl;
	system("pause");
}

// ��ѯѧ����Ϣ
void queryStudent(vector<Student>& students) 
{
	system("cls");
	string id;

	cout << "������Ҫ��ѯ��ѧ�ţ�";
	cin >> id;

	for (int i = 0; i < students.size(); i++) 
	{
		if (students[i].ID == id) {
			cout << "ѧ�ţ�" << students[i].ID << endl;
			cout << "������" << students[i].name << endl;
			cout << "רҵ��" << students[i].major << endl;
			cout << "�Ա�" << students[i].gender << endl;
			system("pause");
		}
	}

	cout << "û���ҵ���Ӧ��ѧ����¼��" << endl;
	system("pause");
}

// ��ʾ����ѧ����Ϣ
void showAllStudents(vector<Student>& students) 
{
	system("cls");
	for (auto &a : students) 
	{
		cout << "ѧ�ţ�" << a.ID << endl;
		cout << "������" << a.name << endl;
		cout << "רҵ��" << a.major << endl;
		cout << "�Ա�" << a.gender << endl;
		cout << "\n\n";
	}
	system("pause");
}


// ��ӿγ̼�¼���ļ���
void addCourseToFile(Course c) {
	ofstream fout5("courses.txt", ios::app);
	if (fout5.is_open()) {
		fout5 << c.ID << " " << c.name << " " << c.credit << " " << c.hours << endl;
		fout5.close();
	}
}

// �������пγ̼�¼���ڴ���
vector<Course> loadCoursesFromFile() {
	ifstream fin5("courses.txt");
	if (fin5.is_open()) {
		string id, name;
		int credit, hours;

		while (fin5 >> id >> name >> credit >> hours) {
			Course c(id, name, credit, hours);
			courses.push_back(c);
		}
		fin5.close();
	}
	return courses;
}

// �������пγ̼�¼���ļ���
void saveCoursesToFile(vector<Course> courses) {
	ofstream fout9("courses.txt", ios::trunc);
	if (fout9.is_open()) {
		for (auto &c : courses) {
			fout9 << c.ID << " " << c.name << " " << c.credit << " " << c.hours << endl;
		}
		fout9.close();
	}
}

// ��ӿγ���Ϣ
void addCourse(vector<Course>& courses) 
{
	system("cls");
	string id, name;
	int credit, hours;

	cout << "������γ̺ţ�";
	cin >> id;

	cout << "������γ����ƣ�";
	cin >> name;

	cout << "������ѧ�֣�";
	cin >> credit;

	cout << "������ѧϰʱ��(Сʱ)��";
	cin >> hours;

	Course c(id, name, credit, hours);

	// ���¿γ���ӵ�vector�������ļ���
	courses.push_back(c);
	addCourseToFile(c);

	cout << "��ӳɹ���" << endl;
	system("pause");
}

// ɾ���γ���Ϣ
void deleteCourse(vector<Course>& courses) 
{
	system("cls");
	string id;

	cout << "������Ҫɾ���Ŀγ̺ţ�";
	cin >> id;

	for (int i = 0; i < courses.size(); i++) {
		if (courses[i].ID == id) {
			// ��vector�������ļ���ɾ���ÿγ���Ϣ
			courses.erase(courses.begin() + i);
			saveCoursesToFile(courses);

			cout << "ɾ���ɹ���" << endl;
			system("pause");
		}
	}

	cout << "û���ҵ���Ӧ�Ŀγ̼�¼��" << endl;
	system("pause");
}

// �޸Ŀγ���Ϣ
void modifyCourse(vector<Course>& courses)
{
	system("cls");
	string id;

	cout << "������Ҫ�޸ĵĿγ̺ţ�";
	cin >> id;

	for (int i = 0; i < courses.size(); i++) {
		if (courses[i].ID == id) {
			cout << "������Ҫ�޸ĵ���Ϣ��" << endl;
			cout << "�γ̺ţ�" << courses[i].ID << endl;
			cout << "�γ����ƣ�";
			cin >> courses[i].name;
			cout << "ѧ�֣�";
			cin >> courses[i].credit;
			cout << "ѧϰʱ��(Сʱ)��";
			cin >> courses[i].hours;

			// �����ļ��иÿγ̼�¼
			saveCoursesToFile(courses);

			cout << "�޸ĳɹ���" << endl;
			system("pause");
		}
	}

	cout << "û���ҵ���Ӧ�Ŀγ̼�¼��" << endl;
	system("pause");
}

// ��ѯ�γ���Ϣ
void queryCourse(vector<Course>& courses) 
{
	system("cls");
	string id;
	cout << "������Ҫ��ѯ�Ŀγ̺ţ�";
	cin >> id;

	for (int i = 0; i < courses.size(); i++) {
		if (courses[i].ID == id) {
			cout << "�γ̺ţ�" << courses[i].ID << endl;
			cout << "�γ����ƣ�" << courses[i].name << endl;
			cout << "ѧ�֣�" << courses[i].credit << endl;
			cout << "ѧϰʱ��(Сʱ)��" << courses[i].hours << endl;
			system("pause");
		}
	}

	cout << "û���ҵ���Ӧ�Ŀγ̼�¼��" << endl;
	system("pause");
}

// ��ʾ���пγ���Ϣ
void showAllCourses(vector<Course>& courses) 
{
	system("cls");
	for (auto &c : courses) 
	{
		cout << "�γ̺ţ�" << c.ID << endl;
		cout << "�γ����ƣ�" << c.name << endl;
		cout << "ѧ�֣�" << c.credit << endl;
		cout << "ѧϰʱ��(Сʱ)��" << c.hours << endl;
		cout << "\n\n";
	}
	system("pause");
}

void addGradesToFile(Grades g)
{
	ofstream fouta("grades.txt", ios::app);
	if (fouta.is_open()) {
		fouta << g.stu_id << "," << g.cou_id << "," << g.score << endl;
		fouta.close();
	}
}
vector<Grades> loadGradesFromFile() {
	ifstream fina("grades.txt");
	if (fina.is_open()) {
		string stu_id, cou_id;
		int score;
		while (fina >> stu_id >> cou_id >> score) {
			Grades c(stu_id, cou_id, score);
			grades.push_back(c);
		}
		fina.close();
	}
	return grades;
}
void saveGradesToFile(vector<Grades>grades)
{
	ofstream foutb("grades.txt", ios::trunc);
	if (foutb.is_open()) {
		for (auto &c : grades) {
			foutb << c.stu_id << " " << c.cou_id << " " << c.score << endl;
		}
		foutb.close();
	}
}
void addGrades(vector<Grades> &grades)
{
	system("cls");
	string stu_id, cou_id;
	int score;
	cout << "������ѧ�ţ�";
	cin >> stu_id;

	cout << "������γ̺ţ�";
	cin >> cou_id;

	cout << "������ɼ���";
	cin >> score;

	Grades c(stu_id, cou_id, score);

	// ���¿γ���ӵ�vector�������ļ���
	grades.push_back(c);
	addGradesToFile(c);

	cout << "��ӳɹ���" << endl;
	system("pause");
}
void deleteGrades(vector<Grades> &grades)
{
	system("cls");
	string stu_id;
	string cou_id;
	cout << "������Ҫɾ����ѧ�ţ�";
	cin >> stu_id;
	cout << "������Ҫɾ���Ŀγ̺ţ�";
	cin >> cou_id;

	for (int i = 0; i < grades.size(); i++) {
		if (grades[i].stu_id == stu_id && grades[i].cou_id == cou_id) {
			// ��vector�������ļ���ɾ���ÿγ���Ϣ
			grades.erase(grades.begin() + i);
			saveGradesToFile(grades);
			cout << "ɾ���ɹ���" << endl;
			system("pause");
		}
	}

	cout << "û���ҵ���Ӧ�ĳɼ���¼��" << endl;
	system("pause");
}
void modifyGrades(vector<Grades> &grades)
{
	system("cls");
	string stu_id, cou_id;
	cout << "������Ҫ�޸ĵ�ѧ�ţ�";
	cin >> stu_id;
	cout << "������Ҫ�޸ĵĿγ̺�" << endl;
	cin >> cou_id;
	for (int i = 0; i < grades.size(); i++) {
		if (grades[i].stu_id == stu_id && grades[i].cou_id == cou_id) {
			cout << "������Ҫ�޸ĵ���Ϣ��" << endl;
			cout << "ѧ�ţ�" << grades[i].stu_id << endl;
			cout << "�γ̺ţ�" << grades[i].cou_id << endl;
			cout << "������ɼ�" << endl;
			cin >> grades[i].score;
			// �����ļ��иÿγ̼�¼
			saveGradesToFile(grades);
			cout << "�޸ĳɹ���" << endl;
			system("pause");
		}
	}

	cout << "û���ҵ���Ӧ�ĳɼ���¼��" << endl;
	system("pause");
}
void queryGrades(vector<Grades> &grades)
{
	system("cls");
	string stu_id, cou_id;
	cout << "������Ҫ��ѯ��ѧ�ţ�" << endl;
	cin >> stu_id;
	cout << "������Ҫ��ѯ�Ŀγ̺ţ�" << endl;
	cin >> cou_id;
	for (int i = 0; i < grades.size(); i++) {
		if (grades[i].stu_id == stu_id && grades[i].cou_id == cou_id) {
			cout << "ѧ�ţ�" << grades[i].stu_id << endl;
			cout << "�γ̺ţ�" << grades[i].cou_id << endl;
			cout << "�ɼ���" << grades[i].score << endl;
			system("pause");
		}
	}
	cout << "û���ҵ���Ӧ�Ŀγ̼�¼��" << endl;
	system("pause");
}

void showAllGrades(vector<Grades> &grades)
{
	system("cls");
	for (auto &c : grades) {
		cout << "ѧ�ţ�" << c.stu_id << endl;
		cout << "�γ̺ţ�" << c.cou_id << endl;
		cout << "�ɼ���" << c.score << endl;
		cout << "\n\n";
	}
	system("pause");
}

int main()
{
	students = loadStudentsFromFile();
	courses = loadCoursesFromFile();
	grades = loadGradesFromFile();
	controller();
	return 0;
}
void controller()
{
	while (1)
	{
		switch (flag)
		{
		case show_Menu:
			ShowMenu();
			break;
		case student_menu:
			studentmenu();
			break;
		case course_menu:
			coursemenu();
			break;
		case grades_menu:
			gradesmenu();
			break;
		case exit_1:
			exit1();
			break;
		}
	}
}
void ShowMenu()
{
	system("cls");
	int chance;
	cout << "0���˳�ϵͳ" << endl;
	cout << "1������ѧ����Ϣ" << endl;
	cout << "2������γ���Ϣ" << endl;
	cout << "3������ɼ���Ϣ" << endl;
	cin >> chance;
	switch (chance)
	{
	case 0:flag = exit_1; break;
	case 1:flag = student_menu; break;
	case 2:flag = course_menu; break;
	case 3:flag = grades_menu; break;
	default:
		cout << "���������" << endl;
		system("pause"); 
		break;
	}
}
void studentmenu()
{
	system("cls");
	int chance;
	cout << "0:������һ��" << endl;
	cout << "1������ѧ����Ϣ" << endl;
	cout << "2��ɾ��ѧ����Ϣ" << endl;
	cout << "3���޸�ѧ����Ϣ" << endl;
	cout << "4������ѧ����Ϣ" << endl;
	cout << "5����ʾ����ѧ����Ϣ" << endl;
	cin >> chance;
	switch (chance)
	{
	case 0:flag = show_Menu; break;
	case 1:addStudent(students); break;
	case 2:deleteStudent(students); break;
	case 3:modifyStudent(students); break;
	case 4:queryStudent(students); break;
	case 5:showAllStudents(students); break;
	default:
		cout << "��������" << endl;
		system("pause");
		break;
	}
}
void coursemenu()
{
	system("cls");
	int chance;
	cout << "0:������һ��" << endl;
	cout << "1�����ӿγ���Ϣ" << endl;
	cout << "2��ɾ���γ���Ϣ" << endl;
	cout << "3���޸Ŀγ���Ϣ" << endl;
	cout << "4�����ҿγ���Ϣ" << endl;
	cout << "5����ʾ���пγ���Ϣ" << endl;
	cin >> chance;
	switch (chance)
	{
	case 0:flag = show_Menu; break;
	case 1:addCourse(courses); break;
	case 2:deleteCourse(courses); break;
	case 3:modifyCourse(courses); break;
	case 4:queryCourse(courses); break;
	case 5:showAllCourses(courses); break;
	default:
		cout << "��������" << endl;
		system("pause");
		break;
	}
}
void gradesmenu()
{
	system("cls");
	int chance;
	cout << "0:������һ��" << endl;
	cout << "1�����ӳɼ���Ϣ" << endl;
	cout << "2��ɾ���ɼ���Ϣ" << endl;
	cout << "3���޸ĳɼ���Ϣ" << endl;
	cout << "4�����ҳɼ���Ϣ" << endl;
	cout << "5����ʾ���гɼ���Ϣ" << endl;
	cin >> chance;
	switch (chance)
	{
	case 0:flag = show_Menu; break;
	case 1:addGrades(grades); break;
	case 2:deleteGrades(grades); break;
	case 3:modifyGrades(grades); break;
	case 4:queryGrades(grades); break;
	case 5:showAllGrades(grades); break;
	default:
		cout << "��������" << endl;
		system("pause");
		break;
	}

}
void exit1()
{
	cout << "��ӭ�´�ʹ��" << endl;
	system("pause");
	exit(0);
}


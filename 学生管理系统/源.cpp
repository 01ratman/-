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
// 学生类
class Student {
public:
	string ID;      // 学号
	string name;    // 姓名
	string major;   // 专业
	string gender;    // 性别

	// 构造函数
	Student(string id, string n, string m, string gen) {
		ID = id;
		name = n;
		major = m;
		gender = gen;
	}
};
// 课程类
class Course {
public:
	string ID;      // 课程号
	string name;    // 课程名字
	int credit;     // 学分
	int hours;      // 学习时间

	// 构造函数
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


// 添加学生记录到文件中
void addStudentToFile(Student s) {
	ofstream fout0("students.txt", ios::app);//指向文件末尾的指针
	if (fout0.is_open()) {
		fout0 << s.ID << " " << s.name << " " << s.major << " " << s.gender << endl;
		fout0.close();
	}
}

// 加载所有学生记录到内存中
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


// 保存所有学生记录到文件中
void saveStudentsToFile(vector<Student> students) {
	ofstream fout1("students.txt", ios::trunc);/*trunc主要用于修改文件内的数据，其作用是打开一段数据，
	然后清空这段数据再往里面存数据，如果没有找到，则会新建一段数据再存储*/
	if (fout1.is_open()) {
		for (auto &s : students) {
			fout1<< s.ID << " " << s.name << " " << s.major << " " << s.gender << endl;
		}
		fout1.close();
	}
}

// 添加学生
void addStudent(vector<Student>& students) 
{
	system("cls");
	string id, name, major,gender;

	cout << "请输入学号：";
	cin >> id;

	cout << "请输入姓名：";
	cin >> name;

	cout << "请输入专业：";
	cin >> major;

	cout << "请输入性别(♂/♀)：";
	cin >> gender;

	Student s(id, name, major, gender);

	// 将新学生添加到vector容器和文件中
	students.push_back(s);
	addStudentToFile(s);
	cout << "添加成功！" << endl;
	system("pause");
}

// 删除学生
void deleteStudent(vector<Student>& students) 
{
	system("cls");
	string id;

	cout << "请输入要删除的学号：";
	cin >> id;

	for (int i = 0; i < students.size(); i++) {
		if (students[i].ID == id) {
			// 从vector容器和文件中删除该学生信息
			students.erase(students.begin() + i);
			saveStudentsToFile(students);
			cout << "删除成功！" << endl;
			system("pause");
		}
	}

	cout << "没有找到对应的学生记录！" << endl;
	system("pause");
}

// 修改学生信息
void modifyStudent(vector<Student>& students) 
{
	system("cls");
	string id;

	cout << "请输入要修改的学号：";
	cin >> id;

	for (int i = 0; i < students.size(); i++) {
		if (students[i].ID == id) {
			cout << "请输入要修改的信息：" << endl;
			cout << "学号：" << students[i].ID << endl;
			cout << "姓名：";
			cin >> students[i].name;
			cout << "专业：";
			cin >> students[i].major;
			cout << "性别(m/f)：";
			cin >> students[i].gender;

			// 更新文件中该学生记录
			saveStudentsToFile(students);

			cout << "修改成功！" << endl;
			system("pause");

		}
	}

	cout << "没有找到对应的学生记录！" << endl;
	system("pause");
}

// 查询学生信息
void queryStudent(vector<Student>& students) 
{
	system("cls");
	string id;

	cout << "请输入要查询的学号：";
	cin >> id;

	for (int i = 0; i < students.size(); i++) 
	{
		if (students[i].ID == id) {
			cout << "学号：" << students[i].ID << endl;
			cout << "姓名：" << students[i].name << endl;
			cout << "专业：" << students[i].major << endl;
			cout << "性别：" << students[i].gender << endl;
			system("pause");
		}
	}

	cout << "没有找到对应的学生记录！" << endl;
	system("pause");
}

// 显示所有学生信息
void showAllStudents(vector<Student>& students) 
{
	system("cls");
	for (auto &a : students) 
	{
		cout << "学号：" << a.ID << endl;
		cout << "姓名：" << a.name << endl;
		cout << "专业：" << a.major << endl;
		cout << "性别：" << a.gender << endl;
		cout << "\n\n";
	}
	system("pause");
}


// 添加课程记录到文件中
void addCourseToFile(Course c) {
	ofstream fout5("courses.txt", ios::app);
	if (fout5.is_open()) {
		fout5 << c.ID << " " << c.name << " " << c.credit << " " << c.hours << endl;
		fout5.close();
	}
}

// 加载所有课程记录到内存中
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

// 保存所有课程记录到文件中
void saveCoursesToFile(vector<Course> courses) {
	ofstream fout9("courses.txt", ios::trunc);
	if (fout9.is_open()) {
		for (auto &c : courses) {
			fout9 << c.ID << " " << c.name << " " << c.credit << " " << c.hours << endl;
		}
		fout9.close();
	}
}

// 添加课程信息
void addCourse(vector<Course>& courses) 
{
	system("cls");
	string id, name;
	int credit, hours;

	cout << "请输入课程号：";
	cin >> id;

	cout << "请输入课程名称：";
	cin >> name;

	cout << "请输入学分：";
	cin >> credit;

	cout << "请输入学习时间(小时)：";
	cin >> hours;

	Course c(id, name, credit, hours);

	// 将新课程添加到vector容器和文件中
	courses.push_back(c);
	addCourseToFile(c);

	cout << "添加成功！" << endl;
	system("pause");
}

// 删除课程信息
void deleteCourse(vector<Course>& courses) 
{
	system("cls");
	string id;

	cout << "请输入要删除的课程号：";
	cin >> id;

	for (int i = 0; i < courses.size(); i++) {
		if (courses[i].ID == id) {
			// 从vector容器和文件中删除该课程信息
			courses.erase(courses.begin() + i);
			saveCoursesToFile(courses);

			cout << "删除成功！" << endl;
			system("pause");
		}
	}

	cout << "没有找到对应的课程记录！" << endl;
	system("pause");
}

// 修改课程信息
void modifyCourse(vector<Course>& courses)
{
	system("cls");
	string id;

	cout << "请输入要修改的课程号：";
	cin >> id;

	for (int i = 0; i < courses.size(); i++) {
		if (courses[i].ID == id) {
			cout << "请输入要修改的信息：" << endl;
			cout << "课程号：" << courses[i].ID << endl;
			cout << "课程名称：";
			cin >> courses[i].name;
			cout << "学分：";
			cin >> courses[i].credit;
			cout << "学习时间(小时)：";
			cin >> courses[i].hours;

			// 更新文件中该课程记录
			saveCoursesToFile(courses);

			cout << "修改成功！" << endl;
			system("pause");
		}
	}

	cout << "没有找到对应的课程记录！" << endl;
	system("pause");
}

// 查询课程信息
void queryCourse(vector<Course>& courses) 
{
	system("cls");
	string id;
	cout << "请输入要查询的课程号：";
	cin >> id;

	for (int i = 0; i < courses.size(); i++) {
		if (courses[i].ID == id) {
			cout << "课程号：" << courses[i].ID << endl;
			cout << "课程名称：" << courses[i].name << endl;
			cout << "学分：" << courses[i].credit << endl;
			cout << "学习时间(小时)：" << courses[i].hours << endl;
			system("pause");
		}
	}

	cout << "没有找到对应的课程记录！" << endl;
	system("pause");
}

// 显示所有课程信息
void showAllCourses(vector<Course>& courses) 
{
	system("cls");
	for (auto &c : courses) 
	{
		cout << "课程号：" << c.ID << endl;
		cout << "课程名称：" << c.name << endl;
		cout << "学分：" << c.credit << endl;
		cout << "学习时间(小时)：" << c.hours << endl;
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
	cout << "请输入学号：";
	cin >> stu_id;

	cout << "请输入课程号：";
	cin >> cou_id;

	cout << "请输入成绩：";
	cin >> score;

	Grades c(stu_id, cou_id, score);

	// 将新课程添加到vector容器和文件中
	grades.push_back(c);
	addGradesToFile(c);

	cout << "添加成功！" << endl;
	system("pause");
}
void deleteGrades(vector<Grades> &grades)
{
	system("cls");
	string stu_id;
	string cou_id;
	cout << "请输入要删除的学号：";
	cin >> stu_id;
	cout << "请输入要删除的课程号：";
	cin >> cou_id;

	for (int i = 0; i < grades.size(); i++) {
		if (grades[i].stu_id == stu_id && grades[i].cou_id == cou_id) {
			// 从vector容器和文件中删除该课程信息
			grades.erase(grades.begin() + i);
			saveGradesToFile(grades);
			cout << "删除成功！" << endl;
			system("pause");
		}
	}

	cout << "没有找到对应的成绩记录！" << endl;
	system("pause");
}
void modifyGrades(vector<Grades> &grades)
{
	system("cls");
	string stu_id, cou_id;
	cout << "请输入要修改的学号：";
	cin >> stu_id;
	cout << "请输入要修改的课程号" << endl;
	cin >> cou_id;
	for (int i = 0; i < grades.size(); i++) {
		if (grades[i].stu_id == stu_id && grades[i].cou_id == cou_id) {
			cout << "请输入要修改的信息：" << endl;
			cout << "学号：" << grades[i].stu_id << endl;
			cout << "课程号：" << grades[i].cou_id << endl;
			cout << "请输入成绩" << endl;
			cin >> grades[i].score;
			// 更新文件中该课程记录
			saveGradesToFile(grades);
			cout << "修改成功！" << endl;
			system("pause");
		}
	}

	cout << "没有找到对应的成绩记录！" << endl;
	system("pause");
}
void queryGrades(vector<Grades> &grades)
{
	system("cls");
	string stu_id, cou_id;
	cout << "请输入要查询的学号：" << endl;
	cin >> stu_id;
	cout << "请输入要查询的课程号：" << endl;
	cin >> cou_id;
	for (int i = 0; i < grades.size(); i++) {
		if (grades[i].stu_id == stu_id && grades[i].cou_id == cou_id) {
			cout << "学号：" << grades[i].stu_id << endl;
			cout << "课程号：" << grades[i].cou_id << endl;
			cout << "成绩：" << grades[i].score << endl;
			system("pause");
		}
	}
	cout << "没有找到对应的课程记录！" << endl;
	system("pause");
}

void showAllGrades(vector<Grades> &grades)
{
	system("cls");
	for (auto &c : grades) {
		cout << "学号：" << c.stu_id << endl;
		cout << "课程号：" << c.cou_id << endl;
		cout << "成绩：" << c.score << endl;
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
	cout << "0：退出系统" << endl;
	cout << "1：管理学生信息" << endl;
	cout << "2：管理课程信息" << endl;
	cout << "3：管理成绩信息" << endl;
	cin >> chance;
	switch (chance)
	{
	case 0:flag = exit_1; break;
	case 1:flag = student_menu; break;
	case 2:flag = course_menu; break;
	case 3:flag = grades_menu; break;
	default:
		cout << "错误的数字" << endl;
		system("pause"); 
		break;
	}
}
void studentmenu()
{
	system("cls");
	int chance;
	cout << "0:返回上一级" << endl;
	cout << "1：增加学生信息" << endl;
	cout << "2：删除学生信息" << endl;
	cout << "3：修改学生信息" << endl;
	cout << "4：查找学生信息" << endl;
	cout << "5：显示所有学生信息" << endl;
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
		cout << "错误数字" << endl;
		system("pause");
		break;
	}
}
void coursemenu()
{
	system("cls");
	int chance;
	cout << "0:返回上一级" << endl;
	cout << "1：增加课程信息" << endl;
	cout << "2：删除课程信息" << endl;
	cout << "3：修改课程信息" << endl;
	cout << "4：查找课程信息" << endl;
	cout << "5：显示所有课程信息" << endl;
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
		cout << "错误数字" << endl;
		system("pause");
		break;
	}
}
void gradesmenu()
{
	system("cls");
	int chance;
	cout << "0:返回上一级" << endl;
	cout << "1：增加成绩信息" << endl;
	cout << "2：删除成绩信息" << endl;
	cout << "3：修改成绩信息" << endl;
	cout << "4：查找成绩信息" << endl;
	cout << "5：显示所有成绩信息" << endl;
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
		cout << "错误数字" << endl;
		system("pause");
		break;
	}

}
void exit1()
{
	cout << "欢迎下次使用" << endl;
	system("pause");
	exit(0);
}


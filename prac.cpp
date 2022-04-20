#pragma once
#ifndef student_h
#define student_h
#include <string>
#include <vector>

#define PRINT_HEADER(msg) std::cout << "**** ->" << msg << " <-****\n"

extern std::vector<std::string> college_names;
const int SIZE = 3;

struct Student
{
    std::string f_name{};
    std::string l_name{};
    int studentID;
    std::string col_name{};
};

class College
{
    std::vector<int> ratings;
    std::vector<Student> students;
    std::string names[SIZE];
    std::vector<std::string> cnames;
    bool add{false};

public:
    College();
    College(std::vector<std::string> names);
    std::vector<std::string> m_name;
    College &operator+=(const Student &st);
    void operator==(const std::vector<Student> &st);
    void print() const;
    void scanStudentForCollege();
};
#endif //! student_h

// this if student.cpp file--------- -----------------------

#include <iostream>
#include <string>
#include <vector>
#include <thread>
#include <algorithm>

College::College()
{
}

College::College(std::vector<std::string> cn)
{
    for (int i = 0; i < SIZE; i++)
        cnames.push_back(cn[i]);
}

College &College::operator+=(const Student &st)
{
    auto findCollege = [=](const Student &st)
    {
        for (auto &c : college_names)
            if (st.col_name == c)
                add = true;
        return add;
    };

    if (findCollege(st))
        students.push_back(st);
    else
        throw "Unknow College name:" + st.col_name;

    return *this;
}
void College::print() const
{
    for (auto &s : students)
        std::cout << s.f_name << "" << s.l_name
                  << "" << s.studentID << std::endl;
}

void College::operator==(const std::vector<Student> &st)
{
    auto findStudentWithCollege = [=](const Student &st)
    {
        std::string c_name;
        for (int i = 0; i != students.size(); i++)
        {
            if (st.col_name == college_names[i])
                c_name = college_names[i];
        }
        return c_name;
    };

    for (auto c : st)
        c.col_name = findStudentWithCollege(c);
}

void collegeStu(const std::vector<Student>::iterator begin,
                const std::vector<Student>::iterator end)
{
    std::transform(begin, end, begin, [](const Student &st)
                   {
 std::string c_name;
 for (int i = 0; i != SIZE; i++) {
  if (st.col_name == college_names[i])
   c_name = college_names[i];
 }
 return c_name; });

    College cl;

    for (auto c = begin; c != end; c++)
        cl.m_name.push_back(c->col_name);
}

void College::scanStudentForCollege()
{
    thread_local step = 0;
    std::thread t1(collegeStu, students.begin(), students.end());
    t1.join();
}

// this is main file --------- -----------------------

// main.cpp
#include <iostream>
#include <string>
#include <vector>
#include <memory>

std::vector<std::string> college_names{
    "Seneca",
    "Cambrian",
    "Fanshawe",
};

int main()
{
    PRINT_HEADER("College and Student Program");
    std::vector st{
        {"Mia", "Yang", 2638, "Seneca"},
        {"Mia", "Yang", 2638, "Seneca"},
        {"Mia", "Yang", 2638, "Seneca"},
        {"Mia", "Yang", 2638, "Seneca"}};

    std::unique_ptr<College &> c(new College);
    std::unique_ptr<College> c3 = c;
    try
    {
        ((*c += st[0]) += st[1]);
    }
    catch (std::string &msg)
    {
        std::cout << msg << std::endl;
    }

    c->scnaStudnetForCollege();
    c->print();
}

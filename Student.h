//
// Created by sunzhijun on 18-2-1.
//

#ifndef SUANFA_STUDENT_H
#define SUANFA_STUDENT_H

#include <iostream>

using namespace std;

struct Student{
    string name;
    int score;
    bool operator<(const Student &other_student){
        return score < other_student.score;
    }

    friend ostream& operator<<(ostream &os, const Student &student){
        os<<"Student: "<<student.name<<" "<<student.score<<endl;
        return os;
    }
};


#endif //SUANFA_STUDENT_H

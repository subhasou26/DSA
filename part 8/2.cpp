#include <bits/stdc++.h>
using namespace std;
struct Student{
    string name;
    int age;
};
int main()
{
    Student s1;
    s1.name="Subhadip";
    s1.age=19;
    cout<<s1.name<<"  "<<s1.age<<endl;
    
    Student *s2;
    s2=new Student;
    s2->name="Saheli";
    (*s2).age=18;
    cout<<(*s2).name<<"  "<<(*s2).age;
    free(s2);


   //******* array of structure of array******
    int length=3;
    Student *array;
    array=new Student[length]; // array of structure
    array[0].name="subhadip";
    array[0].age=19;

    array[1].name="Saheli";
    array[1].age=18;

    array[2].name="Pritha";
    (*(array+2)).age=18;

    cout<<"Array...\n";
    for(int i=0;i<length;i++){
        cout<<array[i].name<<" "<<array[i].age<<endl;
    }

free(array);

    return 0;
}
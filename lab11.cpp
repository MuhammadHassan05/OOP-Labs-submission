/*Task 1
#include<iostream>
using namespace std;
class Faculty
{
public:
    virtual void Print() =0;
};
class Administration:virtual public Faculty
{
public:
    void Print() override
    {
        cout<<"Administration class"<<endl;
    }
};
class Teacher:virtual public Faculty
{
public:
    void Print() override
    {
        cout<<"Teacher class"<<endl;
    }
};
class AdministratorTeacher:public Administration,public Teacher
{
public:
    void Print() override
    {
        Administration::Print();
        Teacher::Print();
    }
};
int main()
{
    Faculty* FacultyArray[3]={
        FacultyArray[0]=new Administration,
        FacultyArray[1]=new Teacher,
        FacultyArray[2]=new AdministratorTeacher
    };
    for(int i=0; i<3; i++)
    {
        FacultyArray[i]->Print();
    }
    for(int i=0; i<3; i++)
    {
        delete FacultyArray[i];
    }
    return 0;
}
    */
    /*Task 2
    #include<iostream>
    using namespace std;
    class BasicShape
    {
    private:
        double Area;
    public:
        virtual void CalculateArea() = 0;
        void SetArea(double area)
        {
            Area=area;
        }
        double GetArea() const
        {
            return Area;
        }
    };
    class Circle:public BasicShape
    {
    private:
        long CenterX,CenterY;
        double Radius;
    public:
        Circle(long CX=0.0, long CY=0.0, double radius=0.0)
        {
            CenterX=CX;
            CenterY=CY;
            Radius=radius;
            CalculateArea();
        }
        void CalculateArea() override
        {
            double area;
            area=Radius*Radius*3.14;
            SetArea(area);
        }
        long GetX() const
        {
            return CenterX;
        }
        long GetY() const
        {
            return CenterY;
        }
        double GetRadius() const
        {
            return Radius;
        }
    };
    class Rectangle:public BasicShape
    {
    private:
        long Length,Width;
    public:
        Rectangle(long l=0.0, long w=0.0)
        {
            Length=l;
            Width=w;
            CalculateArea();
        }
        void CalculateArea() override
        {
            double area=Length*Width;
            SetArea(area);
        }
        long GetLength() const
        {
            return Length;
        }
        long GetWidth() const
        {
            return Width;
        }
    };
    int main()
    {
        BasicShape* Array[2]={
            Array[0]=new Circle(9.876,8.654,3.5),
            Array[1]=new Rectangle(4.67,8.721)
        };
        for(int i=0; i<2; i++)
        {
            cout<<Array[i]->GetArea()<<endl;
        }
        for(int i=0; i<2; i++)
        {
            delete Array[i];
        }
        return 0;
    }
        */
        /* Task 3
        #include<iostream>
        #include<stdexcept>
        #include<string>
        using namespace std;
        template<typename U>
        U FindMax(U Num1, U Num2)
        {
            if(Num1>Num2)
            {
                return Num1;
            }else
            {
                return Num2;
            }
        }
        class OutOfBoundException
        {
        private:
            string Message;
        public:
            OutOfBoundException(const string &msg):Message(msg)
            {
            }
            const char* What() const
            {
                return Message.c_str();
            }
        };
        template<typename T>
        class SafeArray
        {
        private:
            T Data[10];
        public:
            void SetData(int index,T value)
            {
                if(index<0 || index>=10)
                {
                    throw out_of_range("index"+ std::to_string(index)+ "is out of bound");
                }
                Data[index]=value;
            }
            T GetValue(int index)
            {
                if(index<0 || index>=10)
                {
                    throw OutOfBoundException("index "+ std::to_string(index)+ " is out of bound");
                }
                return Data[index];
            }
        };
        int main()
        {
            cout<<"The max integer value is "<<FindMax(4,5)<<endl;
            cout<<"The max float value is "<<FindMax(4.4f,7.8f)<<endl;
            cout<<"The larger string is "<<FindMax(string("Hello"),string("Ali"))<<endl;
            SafeArray<int> Array;
            try
            {
                Array.SetData(4,30);
                cout<<"The value of the data at index no 4 is "<<Array.GetValue(4)<<endl;
                cout<<Array.GetValue(12);
            }
            catch(const OutOfBoundException& e)
            {
                cout<<e.What()<<endl;
            }
            return 0;
        }
            */
            /*Task no 4
         #include<iostream>
         using namespace std;
         class UniversityEmployee
         {
         public:
             virtual double CalculateSalary() const = 0;
             virtual void PrintRole() const
             {
                 cout<<"University Employee"<<endl;
             }
             virtual ~UniversityEmployee()
             {
             }
         };
         class Lecturer:public UniversityEmployee
         {
         public:
             double CalculateSalary() const override
             {
                 return 60000.0;
             }
             void PrintRole() const
             {
                 cout<<"University Lecturer"<<endl;
             }
             ~Lecturer()
             {
             }
         };
         class Professor:public UniversityEmployee
         {
         public:
             double CalculateSalary() const override
             {
                 return 120000.0+20000.0;
             }
             void PrintRole() const
             {
                 cout<<"University Professor"<<endl;
             }
             ~Professor()
             {
             }
         };
         class AdjunctFaculty:public UniversityEmployee
         {
         private:
             int LectureCount;
         public:
             AdjunctFaculty(int lc):LectureCount(lc)
             {
             }
             double CalculateSalary() const override
             {
                 return LectureCount*2000.0;
             }
             void PrintRole() const
             {
                 cout<<"Adjunct Faculty"<<endl;
             }
             ~AdjunctFaculty()
             {
             }
         };
         int main()
         {
             UniversityEmployee* Employees[3]=
             {
                 Employees[0]=new Lecturer,
                 Employees[1]=new Professor,
                 Employees[2]=new AdjunctFaculty(12)
             };
             for(int i=0; i<3; i++)
             {
                 Employees[i]->PrintRole();
                 cout<<"Monthly Salary "<<Employees[i]->CalculateSalary()<<endl;
                 cout<<endl;
             }
             for(int i=0; i<3; i++)
             {
                 delete Employees[i];
             }
             return 0;
         }
         */

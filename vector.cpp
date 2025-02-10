#include<iostream>


class vector
{
public:
    vector()=default;
    explicit vector(double x):x(x){}
    vector(double x,double y);
    friend std::ostream &operator<<(std::ostream &os,const vector &temp);
    vector operator+(const vector &temp);
    vector operator-(const vector &temp);
    vector operator/(const double &num);
    vector operator*(const int &num);
    bool operator==(const vector &temp);
    vector &operator++(); //post
    vector operator++(int); //post
    double operator[](int);
    friend std::istream &operator>>(std::istream &is, vector &temp);
  
private:
    double x;
    double y;

};
vector::vector(double x,double y):x(x),y(y){}

std::istream& operator>>(std::istream &is, vector &temp)
{
    is >> temp.x >> temp.y;
    return is;
}

double vector::operator[](int index)
{
    if (index == 0)
    {
        return this->x;
    }
    else if (index == 1)
    {
       return this->y;
    }
    else
    {
        throw std::out_of_range("out of range");
    }
}

vector vector::operator++(int) //post
{   
    vector temp=*this;
    this->x++;
    this->y++;
    return temp;
}

vector &vector::operator++() //pre
{   
    this->x++;
    this->y++;
    return *this;
}

bool vector::operator==(const vector &temp)
{
    return ( (this->x == temp.x) && (this->y==temp.y) );
}

vector vector::operator/(const double &num)
{
   return vector(this->x / num, this->y / num);
}

vector vector::operator*(const int &num)
{
   return vector(this->x * num, this->y * num);
}

vector vector::operator-(const vector &temp)
{
    return vector(this->x-temp.x,this->y-temp.y);
}

vector vector::operator+(const vector &temp)
{
    return vector(this->x+temp.x,this->y+temp.y);
}


std::ostream &operator<<(std::ostream &os, const  vector &temp)
{
    os << "(" << temp.x << ", " << temp.y <<")";
    return os;
}


int main()
{
    vector v1(2,3);
    vector v2(3,4);
    
    //output operator
    std::cout << "v1: " << v1 << "\n";
    std::cout << "v2: " << v2 << "\n";
    
    //addition and substraction
    std::cout << "v1+v2: " << v1+v2 << "\n";
    std::cout << "v1-v2: " << v1-v2 << "\n";

    //multiplication and division
    std::cout << "v1 * 2: " << v1 * 2 << "\n";
    std::cout << "v1 / 2: " << v1 / 2 << "\n";
    std::cout << "v2 * 2: " << v2 * 2 << "\n";
    std::cout << "v2 / 2: " << v2 / 2 << "\n";

    //comparison
    std::cout << "v1 == v2: " << (v1 == v2 ? "yes" : "no") << "\n";

    //postincrement and preincrement 
    std::cout << "++v1 = " << ++v1 << "\n";
    std::cout << "v1++ = " << v1++ << "\n";
    std::cout << "After v1++: " << v1 << "\n";

    //subscript
    std::cout << "v1[0]: " << v1[0] << ", v1[1]: " << v1[1] << "\n";

    //input operator
    vector v3;
    std::cout << "Enter vector values (x y): ";
    std::cin >> v3;
    std::cout << "You entered: " << v3 << "\n";
    


    return 0;
}
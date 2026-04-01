#include <iostream>
using namespace std;
#include <string>
#include <cmath>

class VectorN{
    private:
    int n;
    double *p;
    public:
    VectorN(int size, double array[]){
        n=size;
        p=new double [n];
        for(int i=0;i<n;i++){
            p[i]=array[i];
        }
    }
    VectorN(){
        n=0;
        p=nullptr;
    }
    ~VectorN(){
        delete[] p;
    }
    double getNorm(){
        double sum=0;
        for(int i=0;i<n;i++){
            sum+=p[i]*p[i];
        }
        return sqrt(sum);
    }
    void normalize(){
        double coeficient=getNorm();
        for(int i=0;i<n;i++){
            p[i]=p[i]/coeficient;
        }
    }
    double getDistance(VectorN &vector){
        double distance=0;
        for(int i=0;i<n;i++){
            distance+=(p[i]-vector.p[i])*(p[i]-vector.p[i]);
        }
        return sqrt(distance);
    }

    string toString(){
        string stringed="(";
        for(int i=0;i<n;i++){
        stringed+=to_string(p[i]);
        if(i!=n-1){
            stringed+=", ";
        }
        }
        stringed+=")";
        return stringed;
    }
    VectorN(VectorN& vector){
        n=vector.n;
        p=new double[n];
        for(int i=0;i<n;i++){
            p[i]=vector.p[i];
        }
    }
    VectorN operator+(double value){
        VectorN vector2(*this);
        for(int i=0;i<n;i++){
            vector2.p[i]+=value;
        }
        return vector2;
    }
    VectorN operator+(VectorN &vector){
        VectorN vector2(*this);
        for(int i=0;i<n;i++){
            vector2.p[i]+=vector.p[i];
        }
        return vector2;
    }
    VectorN operator-(double value){
        VectorN vector2(*this);
        for(int i=0;i<n;i++){
            vector2.p[i]-=value;
        }
        return vector2;
    }
    VectorN operator-(VectorN &vector){
        VectorN vector2(*this);
        for(int i=0;i<n;i++){
            vector2.p[i]-=vector.p[i];
        }
        return vector2;
    }
    VectorN operator*(double value){
        VectorN vector2(*this);
        for(int i=0;i<n;i++){
            vector2.p[i]*=value;
        }
        return vector2;
    }
    double operator*(VectorN &vector){
        double product=0;
        for(int i=0;i<n;i++){
            product+=p[i]*vector.p[i];
        }
        return product;
    }
    friend ostream& operator<<(ostream& ostr, VectorN& vector) {
        ostr << vector.toString();
        return ostr;
}

};

int main(){
int n=4;
double* array1=new double[n];
for(int i=0;i<n;i++){
    array1[i]=pow(2,i);
}
double* array2=new double[n];
for(int i=0;i<n;i++){
    array2[i]=pow(3,i);
}
double* array3=new double[n];
for(int i=0;i<n;i++){
    array3[i]=pow(4,i);
}

VectorN vector1(n,array1);
VectorN vector2(n,array2);
VectorN vector3(n,array3);
VectorN vector4;
cout<<vector1.getNorm()<<endl;
vector1.normalize();
cout<<vector1<<endl;
cout<<vector2.getDistance(vector3)<<endl;
cout<<vector1.toString()<<endl;
cout<<vector2.toString()<<endl;
VectorN vector5=vector2+vector3;
cout<<vector5.toString()<<endl;
vector5=vector5 +1;
cout<<vector5.toString()<<endl;
vector5=vector3-vector2;
cout<<vector5.toString()<<endl;
vector5=vector5*5;
cout<<vector5.toString()<<endl;
vector5=vector5-1;
cout<<vector5.toString()<<endl;




}
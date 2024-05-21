#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

double const PI = 3.14;

class circle
{
protected:

    double r;

public:

    circle(double r)
    {
        this->r = r;
    }

    circle(){}

    double get_r()
    {
        return r;
    }

    void set_r(double r)
    {
        this->r = r;
    }

    double virtual get_S()
    {
        return PI * pow(r,2);
    }

    double get_L()
    {
        return 2 * PI * r; 
    }

    void virtual get_info()
    {
        cout << "S = " << get_S() << "\t";
        cout << "L = " << get_L() << "\t";
        cout << "r = " << r << "\t";
        cout << endl;

    }

};

class cone : public circle
{
private:

    double h;

public:
    
    cone(double h, double r):circle(r)
    {
        this->h = h;
    }

    cone(){}

    double cone_V()
    {
        return (PI * pow(get_r(), 2) * h) / 3;
    }

    double get_h()
    {
        return h;
    }

    double get_S() override
    {
        double l = sqrt(pow(get_r(), 2) + pow(h,2));
        return PI * pow(r,2) + PI * r * l;
    }

    void get_info() override
    {
        cout << "V = " << cone_V() <<"\t";
        cout << "S = " << get_S() << "\t";
        cout << "r = " << r << "\t";
        cout << "h = " << h << "\t";
        cout << endl;

    }

};

double average_V(std::vector <cone> conus)
{
    double S = 0;
    for(int i = 0; i < conus.size(); i++)
    {
        S += conus[i].cone_V();
    }

    return S / conus.size();
}

void cone_sort(vector <cone>& conus)
{
    bool is_sortred = false;
    for(int i = 0; (i < conus.size() - 1) && !is_sortred; i++)
    {
        is_sortred = true;
        for(int j = 0; j < conus.size() - 1; j++)
        {
            if(conus[j].cone_V() > conus[j+1].cone_V())
            {
                cone tmp = conus[j];
                conus[j] = conus[j+1];
                conus[j+1] = tmp;
                is_sortred = false;
            }
        }
    }
}

int main()
{
    vector <cone> conus;

    int cone_count;

    cout << "Enter count of cone: ";

    cin >> cone_count;

    for(int i = 0; i < cone_count; i++)
    {
        conus.push_back(cone(rand()%100, rand() % 100));
    }

    double V = average_V(conus);

    vector <cone> new_conus;

    for(int i = 0; i < conus.size(); i++)
    {
        if(conus[i].cone_V() < V)
            new_conus.push_back(conus[i]);
    }

    for(vector<cone>::iterator it = conus.begin(); it < conus.end(); it++)
    {
        (*it).get_info();
    }

    cout << endl << "Average V = " << V;

    cout << endl << endl;

    for(int i = 0; i < new_conus.size(); i++)
    {
        new_conus[i].get_info();
    }

    if(new_conus.size() != 0)
    {
        cout << "New vector is not empty"<<endl;

        cone_sort(new_conus);

        for(int i = 0; i < new_conus.size(); i++)
        {
            new_conus[i].get_info();
        }
    }
    else
        cout << "New vector is empty"<<endl;

    

    

    return 0;
}
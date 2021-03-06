#ifndef FUNCTION_FOR_COMPONENT_RATE_H
#define FUNCTION_FOR_COMPONENT_RATE_H
#include <QtCore>


//enum Functions_of_rates  1="-- 0",
//                         2="-- 1 - d if d \u2208 [0, 1),\n    0 if d \u2208 [1, \u221E)",
//                         3="-- d if d \u2208 [0; +\u221E)",
//                         4="-- 1",
//                         5="-- exp(-d) if d \u2208 [0; +\u221E)",
//                         6="-- 0 if d \u2208 [0,1)\n    d - 1 if d \u2208 [1; +\u221E)",
//                         7="-- 0 if d \u2208 [0,1)\n    d - 1 if d \u2208 [1; +\u221E)",
//                         8="-- min(d)";

namespace Ui {
    class function_for_component_rate;
}

namespace simbad{
namespace gui{

enum Functions{
    null,
    triangle,
    modul,
    one,
    exp_minus,
    zero_next_to_null,
    min
};

enum Restrictions{
    zero,
    circle,
    square
};


enum Approach_of_influence{
    no,
    sum,
    exp_minus_sum,
    exp_plus_sum,
    product
};


class function_for_component_rate
{
    Functions Function_for_rate;
    float Multiplication_by_constant;
    Restrictions Restriction_of_the_range;
    float Range_of_the_function;
    Approach_of_influence Approach;

public:

//constructor
    function_for_component_rate ();
    function_for_component_rate (const function_for_component_rate& that);
    function_for_component_rate & operator = (const function_for_component_rate& that)
        {
            Function_for_rate = that.Function_for_rate;
            Multiplication_by_constant = that.Multiplication_by_constant;
            Restriction_of_the_range = that.Restriction_of_the_range;
            Range_of_the_function = that.Range_of_the_function;
            Approach = that.Approach;

            return *this;
        }

// Overloading operators

    bool operator == (const function_for_component_rate& that)
    {
        if (       (this->Function_for_rate  == that.Function_for_rate ) and
                   (this->Multiplication_by_constant == that.Multiplication_by_constant)  and
                   (this->Restriction_of_the_range == that.Restriction_of_the_range)  and
                   (this->Range_of_the_function == that.Range_of_the_function)  and
                   (this->Approach == that.Approach)
           ) return true;

                return false;
    }

    void set_Functions_from_string(QString A);
    void set_Restrictions_from_string(QString A);
    void set_Approach_of_influence_from_string(QString A);
    void set_Multiplication_by_constant(float value);
    void set_Range_of_the_function(float value);

    QString get_string_of_Functions();
    QString get_string_of_Restrictions();
    QString get_string_of_Approach_of_influence();
    float get_Multiplication_of_constant();
    float get_Range_of_function();

    Functions get_Functions();
    Restrictions get_Restrictions();
    Approach_of_influence get_Approach_of_influence();


};






}//namespace gui
}//namespace simbad

#endif // FUNCTION_FOR_COMPONENT_RATE_H

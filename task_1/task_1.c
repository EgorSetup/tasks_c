#include <stdio.h>
#include <math.h>

// general var
long start_alice_capital = 1000000;
long start_bob_capital = 1000000;
int salary_alice = 200000;
int satary_bob = 200000;

long flat_cost = 21000000;
int flat_rent_month_pay = 40000;

int hcs_month_pay = 6000;
int eat_month_pay = 10000;
int other_month_pay = 3000;

// deposit var
float procent_deposit_year = 16;
short num_deposit_year = 30;

// mortgage var
short num_mortgage_years = 30;
float procent_rate_year = 6;
long first_pay = 1000000;

// func
int sum_month_pay_bob();
// calculation from mortgage-calculator.ru
float mortgage()
{
    float procent_rate_month = procent_rate_year / 12 / 100;
    float general_rate = pow((1 + procent_rate_month), num_mortgage_years * 12);
    float month_pay = (flat_cost - first_pay) * procent_rate_month * general_rate / (general_rate - 1);
    return month_pay;
}

float deposit()
{
    float procent_month = procent_deposit_year / 12 / 100;
    float new_sum_deposit = start_bob_capital;
    for(int i = 1; i <= num_deposit_year; i++)
    {
        new_sum_deposit = (procent_month * new_sum_deposit) + new_sum_deposit + (satary_bob - sum_month_pay_bob());
    }
    return new_sum_deposit;
}

float sum_month_pay_alice()
{
    float mortgage_month_pay = mortgage();
    float sum_month_pay_alice = hcs_month_pay + eat_month_pay + other_month_pay + mortgage_month_pay;
    return sum_month_pay_alice;
}

int sum_month_pay_bob()
{
    int sum_month_pay_bob = hcs_month_pay + eat_month_pay + other_month_pay + flat_rent_month_pay;
    return sum_month_pay_bob;
}


int main()
{
    printf("%f, %f", sum_month_pay_alice(), deposit());
}

#include <stdio.h>
#include <math.h>

float deposit()
{
    float procent_month = 16.0 / 12 / 100;
    float new_sum_deposit = 100000;
    for(int i = 1; i <= 360; i++)
    {
        new_sum_deposit = (procent_month * new_sum_deposit) + new_sum_deposit;
    }
    return new_sum_deposit;
}

int main()
{
    printf("%.20f", deposit());
}

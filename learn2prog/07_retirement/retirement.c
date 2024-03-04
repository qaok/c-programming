#include <stdio.h>
#include <stdlib.h>

struct _retire_info {
  int months;
  double contribution, rate_of_return;
};
typedef struct _retire_info retire_info;



double compute(int startAge, int month, double initial, retire_info o) {
  double curValue;
  while (o.months != 0) {
    printf("Age %3d month %2d you have $%.2lf\n",
	   startAge, month, initial);
    curValue = o.rate_of_return * initial + initial + o.contribution;
    initial = curValue;
    if (month == 11) {
      startAge += 1;
      month = 0;
    }
    else {
      month += 1;
    }
    o.months -= 1;
  }
  return initial;
}

void retirement(int startAge, double initial,
		retire_info working, retire_info retired) {
  int ages = startAge / 12;
  int month = startAge % 12;
  int endAge = startAge + working.months;
  initial = compute(ages, month, initial, working);
  ages = endAge / 12;
  month = endAge % 12;
  compute(ages, month, initial, retired);
}

int main(void) {
  retire_info working;
  working.months = 489;
  working.rate_of_return = 0.045 / 12;
  working.contribution = 1000;
  
  retire_info retired;
  retired.months = 384;
  retired.rate_of_return = 0.01 / 12;
  retired.contribution = -4000;
  double startAge = 327;
  double initial = 21345;

  retirement(startAge, initial, working, retired);
  
  return EXIT_SUCCESS;
}

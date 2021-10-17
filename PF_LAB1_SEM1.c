/* THIS PROGRAM WILL GENERATE A PAY SLIP OF AN EMPLOYEE OF A COMPANY*/

#include <stdio.h>
#include <stdlib.h>

int main()
{
    int age,experience;  /*Variables for age and years of experience */
    char grade;          /* grade of the employee i.e. W, Y,X,Z */
    int basic_sal=0;     /*Variable for Basic Salary */
    int perInc_amount=0; /*Amount per year of experience variable */
    int RunPay=0;        /*Running Pay variable*/
    float HRA=0.0,SSB=0.0; /*Variables for HOUSE RENT ALLOWANCE AND SOCIAL   SECURITY BENEFIT*/
    int ARA=0;            /*Variable for Ad-hoc Relief Allowance*/
    int GPay=0;           /* Gross Pay Variable*/
    int IncomeTax=0;  /* float type variable for Income Tax */
    float ITper=0.0;      /* Income Tax Percentage Variable (depends on annual income) */
    int AnnualIncome=0;   /*Annual Income variable (this won't be printed or displayed but is important for Income Tax) */
    int GPF=0;        /*General Provident Fund Variable */
    int Deducts=0;        /*Variable for Deductions from the Gross pay */
    int NetPay=0;         /*variable for Net/total pay */
    label:
    printf("ENTER EMPLOYEE'S AGE (e.g. 20,43,50 etc) : ");     /*Prints Enter employees’ age: in the output */
    scanf("%d",&age);     /*Use to scan/input Employee's age from user */
    printf("ENTER EMPLOYEE'S EXPERIENCE IN YEARS (e.g. 2,4,5 etc) : ");     /*Prints Enter employee's experience */
    scanf("%d",&experience);      /*scans employee's experience (in years) from user */
    printf("ENTER EMPLOYEE'S GRADE (W,X,Y,Z) : ");       /* Prints Enter employee's grade:*/
    scanf(" %c", &grade);      /*scans employee's grade */

    /*Since each grade has a different Basic Salary & per year experience amount. So, we will use if & else statements to apply the following conditions:
    if grade = W  : BASIC SALARY = 10000 : per year experience amount = 700
        if grade = X  : BASIC SALARY = 12900 : per year experience amount = 910
        if grade = Y  : BASIC SALARY = 21700 : per year experience amount = 1500
        if grade = Z  : BASIC SALARY = 32600 : per year experience amount = 2800
    */
if(grade!='W'&& grade!='w'&&grade!='X'&&grade!='x'&&grade!='Y'&&grade!='y'&&grade!='z'&&grade!='Z')
{
    system("cls");
    printf("Invalid Input.\n\n");
    printf("Press ENTER to Input again\n");
    getch();
system("cls");
    goto label;

}
    if(grade=='W'|| grade=='w')
        {
            basic_sal=10000;
            perInc_amount=700;
        }
        else if(grade=='X'|| grade=='x')
            {
                basic_sal=12900;
                perInc_amount=910;
            }else if(grade=='Y'|| grade=='y')
            {
                basic_sal=21700;
                perInc_amount=1500;
            }else if(grade=='Z'||grade=='z')
            {
                basic_sal=32600;
                perInc_amount=2800;
            }
    /*In this Section we will calculate Running Pay */


printf("\n\n_____________________________________________\n\n"); /* prints few lines to increase the readability of the program*/
printf("BASIC PAY\n\n");/*Prints BASIC PAY */
printf("_______________\n\n");/* prints few lines to increase the readability of the program*/
printf("Basic Salary:\t\t\t\t%d\n",basic_sal); /* prints Basic Salary according to the grades*/
printf("Years of Experience:\t\t\t%d",experience);/* prints experience in integers according to the input given by the user*/
RunPay=basic_sal+(experience*perInc_amount); /* Formula to calculate Running pay (Running Pay= basic salary+(experience*peryearamount)*/
printf("\nRunning Pay:\t\t\t\t%d\n\n",RunPay);/* prints Running pay value using the above formula*/

  /*In this Section we will calculate Allowances */

printf("ALLOWANCES\n\n"); /*prints ALLOWANCES */
printf("_______________\n\n"); /*USED FOR SPACING PURPOSE SO THE READABILITY OF PROGRAM INCREASES */
HRA=(45.0/100)*RunPay; /* Formula for House Rent Allowance = 45% of Running pay*/
printf("(HRA)House Rent Allowance:\t\t%.0f\n",HRA); /*prints House Rent Allowance using the above formula */
SSB=(30.0/100)*basic_sal;/* Formula for Social Security Benefit = 30% of Basic Salary*/
printf("(SSB)Social Security Benefit:\t\t%.0f\n",SSB);/*prints SSB using the above formula */

 /*CONDITIONS FOR AD-HOC RELIEF ALLOWANCE:
 if grade of employee is W and age not young than 30 and more than 3 years of experience then give 3000 Rs as ARA
    else give 1500 to employees older than 40 with grades other than W
 */

if(grade=='W'||grade=='w'&&age>=30&&experience>3)
    {
        ARA=3000;
    }else if(age>40)
    {
    ARA=1500;
    }
printf("(ARA)Ad-hoc Relief Allowance:\t\t%d\n\n",ARA); /*prints (ARA)Ad-hoc Relief Allowance: */
GPay=RunPay+(HRA+SSB+ARA); /* Formula for gross pay= running pay + ALL ALLOWANCES*/
printf("Gross Pay:\t\t\t\t%d\n\n",GPay); /* Prints the value for Gross pay using above formula */
printf("DEDUCTIONS\n\n"); /* Prints DEDUCTIONS */
printf("_______________\n\n"); /* SPACING */
AnnualIncome=GPay*12; /* Annual Income formula = Gross pay * 12 */
/* CONDITIONS FOR ANNUAL INCOME AND INCOME TAX :
IF ANNUAL INCOME RANGES FROM 0 TO 400,000/- THEN INCOME TAX = 0% OF GROSS PAY
IF ANNUAL INCOME RANGES FROM 400,001 TO 650,000/- THEN INCOME TAX = 2.5% OF GROSS PAY
IF ANNUAL INCOME RANGES FROM 650,001 TO 1,000,000/- THEN INCOME TAX = 4.75% OF GROSS PAY
IF ANNUAL INCOME RANGES FROM 1,000,001 TO 1,500,000/- THEN INCOME TAX = 7% OF GROSS PAY
IF ANNUAL INCOME IS 1,500,001/- OR GREATER THEN INCOME TAX = 2.5% OF GROSS PAY
*/


if(AnnualIncome>=0 && AnnualIncome<=400000)
    {
        ITper=0.0;
        IncomeTax=ITper*GPay;
    }else if(AnnualIncome>=400001 && AnnualIncome<=650000)
    {
        ITper=(2.5);
        IncomeTax=(ITper/100.0)*GPay;
    }else if(AnnualIncome>=650001 && AnnualIncome<=1000000)
    {
        ITper=(4.75);
        IncomeTax=(ITper/100.0)*GPay;
    }else if(AnnualIncome>=1000001 && AnnualIncome<=1500000)
    {
        ITper=(7.0);
        IncomeTax=(ITper/100.0)*GPay;
    }else if(AnnualIncome>=1500001)
    {
        ITper=(11.5);
        IncomeTax=(ITper/100.0)*GPay;
    }
    printf("(IT)Income Tax at (%f %):\t\t%d\n",ITper,IncomeTax); /*prints the value for income tax using the conditions above*/
    GPF=(10.0/100.0)*GPay;/*General Provident Fund Formula = 10% of Gross Pay*/
    printf("(GPF)General Provident Fund:\t\t%d\n\n",GPF);/*prints GPF using the above formula*/
    Deducts=IncomeTax+GPF;/*Total Deduction = IncomeTax+GPF */
    printf("Total Deductions:\t\t\t%d\n\n",Deducts);/*prints Total Deductions using the above formula*/
    printf("_______________\n\n");/*Spacing*/
    NetPay=GPay-Deducts;/*NET PAY FORMULA = GROSS PAY - TOTAL DEDUCTIONS*/
    printf("NET PAY:\t\t\t%d",NetPay);/*prints NET PAY using the above formula*/
    return 0;
}
/* END OF THE PROGRAM */


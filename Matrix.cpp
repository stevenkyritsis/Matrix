//Steven Kyritsis
//Matrix Program
//
//

#include <iostream>
#include <string>
#include <iomanip>
using namespace std;

const int SIZE = 2;

struct Matrix{
		double a[SIZE][SIZE];
		string name;
	};

Matrix get_matrix(Matrix&);
double get_scalar(double&);
void calc_sum(Matrix&, Matrix&);
void calc_diff(Matrix&, Matrix&);
void scalar_mult(Matrix&, double&);
void calc_prod(Matrix&, Matrix&);
void calc_inverse(Matrix&);

int main()
{
	
	
	double scalar = 4.5;
	
	Matrix A;
	Matrix B;
	
	int input = 0;
	
	//Matrix A Defaults
	A.name = "Matrix A";
	A.a[0][0] = 7.0;
	A.a[0][1] = 2.5;
	A.a[1][0] = -3.0;
	A.a[1][1] = 2.0;
	
	//Matrix B Defaults
	B.name = "Matrix B";
	B.a[0][0] = 8.0;
	B.a[0][1] = 6.5;
	B.a[1][0] = 5.0;
	B.a[1][1] = 1.3;
	
	//MENU
	do{
		cout << "Matrix A Row 1 = ";
		for(int count = 0; count <= 1; count++)
		{
			cout << A.a[0][count] << "\t";
		}
		cout << endl;
		cout << "Matrix A Row 2 = ";
		for(int count = 0; count <= 1; count++)
		{
			cout << A.a[1][count] << "\t";
		}
		cout << endl;
		cout << "Matrix B Row 1 = ";
		for(int count = 0; count < 2; count++)
		{
			cout << B.a[0][count] << "\t";
		}
		cout << endl;
		cout << "Matrix B Row 2 = ";
		for(int count = 0; count < 2; count++)
		{
			cout << B.a[1][count] << "\t";
		}
		cout << endl;
		cout << endl;
		cout << "Which operation would you like to perform on the matrixes?" << endl;
		cout << "1. Edit Matrix \t 2. Subtraction \t 3. Scalar Multiplication" << endl;
		cout << "4. Multiplication \t 5. Inverse \t 6. Addition \t 7. EXIT" << endl;
		cin >> input;
		
		switch (input){
			case 1:{
				int input1 = 0;
				while(input1 < 1 || input1 > 2)
				{
					cout << "Which matrix would you like to edit?\n";
					cout << "1. " << A.name << "\t 2. " << B.name << endl;
					cin >> input1;
				}
				if (input1 == 1)
				{
					get_matrix(A);
				}
				if (input1 == 2)
				{
					get_matrix(B);
				}
				else
					cout << "Error! Please enter 1/2.\n";
				break;
			}
			case 2:{
				calc_diff(A, B);
				break;
			}
			case 3:{
				int input2;

				while(input2 < 1 || input2 > 2)
				{
					cout << "Which matrix would you like to scale?\n";
					cout << "1. " << A.name << "\t 2. " << B.name;
					cin >> input2;
				}
				if (input2 == 1)
				{
					scalar_mult(A, scalar);
				}
				if (input2 == 2)
				{
					scalar_mult(B, scalar);
				}
				else 
					cout << "Error! Please enter either 1/2!\n";
				break;
			}
			case 4:{
				calc_prod(A, B);
				break;
			}
			case 5:{
				int input3;

				while (input3 < 1 || input3 > 2)
				{
					cout << "Which matrix would you like to scale?\n";
					cout << "1. " << A.name << "\t 2. " << B.name;
					cin >> input3;
				}
				if (input3 == 1)
				{
					calc_inverse(A);
				}
				if(input3 == 2)
				{
					calc_inverse(B);
				}
				break;
			}
			case 6:{
				calc_sum(A, B);
				break;
			}
			case 7:{
				return 0;
				break;
			}
			default:{
				cout << "Please enter one of the numebers in the menu.\n";
			}
		}
	}while (input != 7);
return 0;
}

Matrix get_matrix(Matrix &m)
{
	cout << "Position 1X1: ";
	cin >> m.a[0][0];
	cout << endl;
	cout << "Position 1X2: ";
	cin >> m.a[0][1];
	cout << endl;
	cout << "Position 2X1: ";
	cin >> m.a[1][0];
	cout << endl;
	cout << "Position 2X2: ";
	cin >> m.a[1][1];
	cout << endl;
	return m;
}

double get_scalar(double &k)
{
	cout << "Enter a scalar: ";
	cin >> k;
	return k;
}

void calc_sum(Matrix &m1, Matrix &m2)
{
	double sum[2][2];
	//For loop to calculate the sum
	for(int count = 0; count <= 1; count++)
	{
 	   for(int co = 0; co <= 1; co++)
   		{
        	sum[count][co] =m1.a[count][co] + m2.a[count] [co];
   		}
	}
	//For loop to display the first row of the sum
	cout << "|\t ";
		for(int co = 0; co <= 1; co++)
		{
			cout << fixed << showpoint << setprecision(2) << sum[0][co] << "\t ";
		}
	cout << "|" << endl;
	//For loop to display the second row of the sum
	cout << "|\t ";
		for(int co = 0; co <= 1; co++)
		{
			cout << fixed << showpoint << setprecision(2) << sum[1][co] << "\t ";
		}
	cout << "|" << endl;
}

void calc_diff(Matrix &m1, Matrix &m2)
{
	double diff[2][2];
	
	//For loop to calulate the difference
	for(int count = 0; count <= 1; count++)
	{
   		for(int co = 0; co <= 1; co++)
		{
        	diff[count][co] = m1.a[count][co] - m2.a[count][co];
    	}
	}
	
	//For loop to output the first row of results
	cout << "|\t ";
		for (int co = 0; co <= 1; co++)
		{
			cout << fixed << showpoint << setprecision(2) << diff[0][co] << "\t ";
		}
	cout << "|" << endl;
	
	//For loop to output the second row of results
	cout << "|\t ";
		for (int co = 0; co <= 1; co++)
		{
			cout << fixed << showpoint << setprecision(2) << diff[1][co] << "\t ";
		}
	cout << "|" << endl;
}

void scalar_mult(Matrix &m, double &k)
{
	int p[2][2];
	//For loop to calculate scalar multiplication
	for(int count = 0; count <= 1; count++)
	{
		for(int co = 0; co <=1; co++)
		{
			p[count][co] = m.a[count][co] *k;
		}
	}
	
	//For loop to output first row of results
	cout << "|\t ";
		for(int co = 0; co <= 1; co++)
		{
			cout << fixed << showpoint << setprecision(2) << p[0][co] << "\t ";
		}
	cout << "|" << endl;
	
	//For loop for the second row of results
	cout << "|\t ";
		for(int co = 0; co <=1; co++)
		{
			cout << fixed << showpoint << setprecision(2) << p[1][co] << "\t ";
		}
	cout << "|" << endl;
}

void calc_prod(Matrix &m1, Matrix &m2)
{
	double prod[2][2];

	//For loop to calculate product
	for(int count = 0; count <= 1; count++)
	{
		for(int co = 0; co <= 1; co++)
		{
			prod[count][co] = m1.a[count][co] * m2.a[count][co];
		}
	}

	//For loop to output row 1
	cout << "|\t ";
		for(int co = 0; co <=1; co++)
		{
			cout << fixed << showpoint << setprecision(2) << prod[0][co] << "\t ";
		}
	cout << "|" << endl;

	//For loop to output row2
	cout << "|\t ";
		for(int co = 0; co <=1; co++)
		{
			cout << fixed << showpoint << setprecision(2) << prod[1][co] << "\t ";
		}
	cout << "|" << endl;
}

void calc_inverse(Matrix &m)
{
	double m_inverse[2][2];
	double temp = (m.a[0][0] * m.a[1][1]) - (m.a[0][1] * m.a[1][0]);
	
	//For loop to calculate the inverse
	for(int count = 0; count <= 1; count++)
	{
		for(int co = 0; co <= 1; co++)
		{	
			m_inverse[count][co] = m.a[count][co] / temp;
		}
	}
	
	//For loop to output the first row of results
	cout << "|\t ";
		for(int co = 0; co <=1; co++)
		{
			cout << fixed << showpoint << setprecision(2) << m_inverse[0][co] << "\t ";
		}
	cout << "|" << endl;
	
	//For loop to output the second row of results
	cout << "|\t ";
		for(int co = 0; co <=1; co++)
		{
			cout << fixed << showpoint << setprecision(2) << m_inverse[1][co] << "\t ";
		}
	cout << "|" << endl;
}
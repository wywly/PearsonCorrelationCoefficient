#include<iostream>
#include<vector>
using namespace std;
class PearsonCorrelationCoefficient
{
public:
	PearsonCorrelationCoefficient()
	{

	}
	~PearsonCorrelationCoefficient()
	{

	}
	double SamplePearsonCorrelationCoefficient(vector<double>a, vector<double>b, int length)
	{
		return (cov(a, b, length)) / (sqrt(var(a, length)*var(b, length)));
	}
private:
	vector<double>x;
	vector<double>y;
	int length;
	double mean(vector<double>data, int length)
	{
		double sum = 0.0;
		for (int i = 0; i < length; i++)
		{
			sum += data[i];
		}
		return sum / length;
	}
	double var(vector<double>data, int length)
	{
		double sum = 0;
		for (int i = 0; i < length; i++)
		{
			sum += pow(data[i] - mean(data, length), 2);
		}
		return sum;
	}
	double cov(vector<double>a, vector<double>b, int length)
	{
		double sum = 0.0;
		for (int i = 0; i < length; i++)
		{
			sum += (a[i] - mean(a, length))*(b[i] - mean(b, length));
		}
		return sum;
	}
};
int main()
{
	vector<double>CDEXAM1 = { 1.49,1.09,0.96,1.22,1.24,1.32,1.21,0.99,0.96,1.06,1.02,1.05,
		1.02,0.96,1.18,0.99,0.98,1.86,0.99,1.15,1.21,1.08,1.06,0.96 };
	vector<double>IN1 = { 10,7.5,7.5,0,8,0,10,6,8.5,0,8.25,6.5,5,8.5,0,5.5,0,9,8.5,9,0,0,5.5,0 };
	vector<double>CDEXAM2 = { 1.02,0.99,0.84,1.06,1.02,1.02,0.99,0.99 };
	vector<double>IN2 = { 7,8.25,8,8.75,6.5,2.25,7,4.5 };

	PearsonCorrelationCoefficient * pcc1 = new PearsonCorrelationCoefficient();
	cout << "Sample Pearson Correlation Coefficient {CDEXAM1,IN1} : "
		<< pcc1->SamplePearsonCorrelationCoefficient(CDEXAM1, IN1, 24)
		<< endl;

	PearsonCorrelationCoefficient * pcc2 = new PearsonCorrelationCoefficient();
	cout << "Sample Pearson Correlation Coefficient {CDEXAM2,IN2} : " 
		<< pcc1->SamplePearsonCorrelationCoefficient(CDEXAM2, IN2, 8)
		<< endl;

	CDEXAM1.~vector();
	IN1.~vector();
	CDEXAM2.~vector();
	IN2.~vector();

	delete pcc1;
	delete pcc2;

	getchar();
	return 0;
}

/*
Author de Freitas, P.C.P
Description - Pearson Correlation Coefficient
*/
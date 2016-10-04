#include <iostream>
#include <fstream>

using namespace std;

class Point
{
public:
	int x;
	int y;
	bool marked = true;
	//Paretto
	bool Point::operator > (const Point secondPoint)
	
	{
		if (this->x == secondPoint.x && this->y == secondPoint.y) return true;
		else return(secondPoint.x > this->x || secondPoint.y > this->y);
	}
	//Slater
	bool Point::operator >= (const Point secondPoint)

	{
		if (this->x == secondPoint.x || this->y == secondPoint.y) return true;
		else return(secondPoint.x >= this->x || secondPoint.y >= this->y);
	}
	
};

istream & operator >> (istream & is, Point & points)
{
	is >> points.x;
	is >> points.y;
	return is;
}

ostream & operator << (ostream & is, Point & points)
{
	is << points.x << "  " << points.y << endl;
	return is;
}



int main() {
	ifstream inputFileStream("inputs.txt");

	Point* points = new Point[20];
	int i = 0;
	while (!inputFileStream.eof())
	{
		
		inputFileStream >> points[i];
		cout << points[i];
		i++;
	
	}

	// > 1  < 0

	for (size_t i = 0; i < 20; i++)
		for (size_t j = 0; j < 20; j++)
	{	
			if (points[i].marked == true && points[j].marked == true)
			{
				points[j].marked = points[i] > points[j];				// change here
			}
				

	}


	char Matrix[10][10];
	for (size_t i = 0; i < 10; i++)
		for (size_t j = 0; j < 10; j++)
			Matrix[i][j] = ' ';
	
	
	for (size_t i = 0; i < 20; i++)
		{
		if (points[i].marked == true)
			Matrix[points[i].x][points[i].y] = 'X';
		else
			Matrix[points[i].x][points[i].y] = '1';
		}
	ofstream out("matrix.txt");
	out << "Pareto: " << endl;
	//out << "Slater: " << endl;

	for (size_t i = 0; i < 20; i++)
		if (points[i].marked == true)
			out << points[i];
	out << "------------------------"<< endl;
	
	for (int i = 9; i > -1 ; i--)
	{
		out << i << " | ";
		for (int j = 0; j < 10; j++)
		{
			out << Matrix[j][i] << " ";
		}
		out << endl;
	}
	out << "------------------------" << endl << "    ";
	for (int i = 0; i < 10; i++)
		out << i << " ";
	system("pause");
}
#include<iostream>
#include<fstream>
#include<math.h>
#include<ctime>
#include<cstdlib>

using namespace std;

int main(int argc, char *argv[])
{
	int n;
	float std, method, sumsq, diff, minssd;

	srand(time(NULL));

	ifstream input;
	input.open("input.txt");
	input >> n;

	if (input.is_open())
	{
		if (n == 1)
		{
			int m1, k;
			float r1;
			input >> m1 >> k >> std >> method;
			float *d1 = new float[m1];
			float *p1 = new float[k];

			for (int i = 0; i < m1; i++)
			{
				d1[i] = (float) ((rand() % 25550) / 100);
			}

			int k1 = rand() % (m1 - k);
			cout << "k1: " << k1 << endl;

			for (int i = 0; i < k; i++)
			{
				p1[i] = d1[k1 + i];
			}

			int y = rand() % (int) (200 * std);
			float x = (y - (100 * std)) / 100;

			for (int i = 0; i < m1; i++)
			{
				d1[i] += x;
				d1[i] = (int)d1[i];
				if (d1[i] < 0)
				{
					d1[i] = 0;
				}
				else if (d1[i] > 255)
				{
					d1[i] = 255;
				}
			}

			for (int i = 0; i < k; i++)
			{
				p1[i] += x;
				p1[i] = (int) p1[i];
				if (p1[i] < 0)
				{
					p1[i] = 0;
				}
				else if (p1[i] > 255)
				{
					p1[i] = 255;
				}
			}

			for (int i1 = 0; i1 < m1 - k; i1++)
			{
				sumsq = 0.0;
				for (int j1 = 0; j1 < k; j1++)
				{
					diff = d1[i1 + j1] - p1[j1];
					sumsq += diff * diff;
				}
				if (i1 == 0)
				{
					minssd = sumsq;
					r1 = 0;
				}
				if (minssd > sumsq)
				{
					minssd = sumsq;
					r1 = i1;
				}
			}

			cout << "r1: " << r1 << endl;
			cout << "error1: " << r1 - k1 << endl;
			delete[] d1, p1;
		}

		else if (n == 2)
		{
			float r1, r2;
			int m1, m2, k;
			input >> m1 >> m2 >> k >> std >> method;
			float **d2 = new float*[m1];
			float **p2 = new float*[k];

			for (int i = 0; i < m1; i++)
			{
				d2[i] = new float[m2];
			}

			for (int i = 0; i < k; i++) 
			{
				p2[i] = new float[k];
			}

			for (int i = 0; i < m1; i++)
			{
				for (int j = 0; j < m2; j++) 
				{
					d2[i][j] = (float)((rand() % 25550) / 100);
				}
			}

			int k1 = rand() % (m1 - k);
			int k2 = rand() % (m2 - k);

			cout << "k1: " << k1 << endl << "k2: " << k2 << endl;

			for (int i = 0; i < k; i++)
			{
				for (int j = 0; j < k; j++)
				{
					p2[i][j] = d2[k1 + i][k2 + j];
				}
			}

			int y = rand() % (int)(200 * std);
			float x = (y - (100 * std)) / 100;

			for (int i = 0; i < m1; i++)
			{
				for (int j = 0; j < m2; j++) 
				{
					d2[i][j] += x;
					d2[i][j] = (int) d2[i][j];
					if (d2[i][j] < 0) 
					{
						d2[i][j] = 0;
					}
					else if (d2[i][j] > 255)
					{
						d2[i][j] = 255;
					}
				}
			}

			for (int i = 0; i < k; i++)
			{
				for (int j = 0; j < k; j++)
				{
					p2[i][j] += x;
					p2[i][j] = (int) p2[i][j];
					if (p2[i][j] < 0)  
					{
						p2[i][j] = 0;
					}
					else if (p2[i][j] > 255) 
					{
						p2[i][j] = 255;
					}
				}
			}

			for (int i1 = 0; i1 < m1 - k; i1++) 
			{
				for (int i2 = 0; i2 < m2 - k; i2++) 
				{
					sumsq = 0.0;
					for (int j1 = 0; j1 < k; j1++) 
					{
						for (int j2 = 0; j2 < k; j2++)
						{
							diff = d2[i1 + j1][i2 + j2] - p2[j1][j2];
							sumsq += diff * diff;
						}
					}
					if (i1 == 0 && i2 == 0) 
					{
						minssd = sumsq;
						r1 = 0;
						r2 = 0;
					}
					if (minssd > sumsq) 
					{
						minssd = sumsq;
						r1 = i1;
						r2 = i2;
					}
				}
			}

			cout << "r1: " << r1 << endl << "r2: " << r2 << endl;
			cout << "error1: " << r1 - k1 << endl << "error2: " << r2 - k2 << endl;

			for (int i = 0; i < m1; i++)
			{
				delete[] d2[i];
			}
			for (int i = 0; i < k; i++) 
			{
				delete[] p2[i];
			}

			delete d2, p2;
		}

		else if (n == 3)
		{
			int m1, m2, m3, k;
			float r1, r2, r3;
			input >> m1 >> m2 >> m3 >> k >> std >> method;
			float ***d = new float**[m1];
			float ***p = new float**[k];

			for (int i = 0; i < m1; i++) 
			{
				d[i] = new float*[m2];
			}

			for (int i = 0; i < m1; i++)
			{
				for (int j = 0; j < m2; j++) 
				{
					d[i][j] = new float[m3];
				}
			}

			for (int i = 0; i < k; i++) 
			{
				p[i] = new float*[k];
			}

			for (int i = 0; i < k; i++) 
			{
				for (int j = 0; j < k; j++) 
				{
					p[i][j] = new float[k];
				}
			}

			for (int i = 0; i < m1; i++)
			{
				for (int j = 0; j < m2; j++)
				{
					for (int l = 0; l < m3; l++)
					{
						d[i][j][l] = (float)((rand() % 25550) / 100);
					}
				}
			}

			int k1 = rand() % (m1 - k);
			int k2 = rand() % (m2 - k);
			int k3 = rand() % (m3 - k);

			cout << "k1: " << k1 << endl << "k2: " << k2 << endl << "k3: " << k3 << endl;

			for (int i = 0; i < k; i++)
			{
				for (int j = 0; j < k; j++)
				{
					for (int l = 0; l < k; l++) 
					{
						p[i][j][l] = d[k1 + i][k2 + j][k3 + l];
					}
				}
			}

			int y = rand() % (int)(200 * std);
			float x = (y - (100 * std)) / 100;

			for (int i = 0; i < m1; i++)
			{
				for (int j = 0; j < m2; j++) 
				{
					for (int l = 0; l < m3; l++)
					{
						d[i][j][l] += x;
						d[i][j][l] = (int)d[i][j][l];
						if (d[i][j][l] < 0)
						{
							d[i][j][l] = 0;
						}
						else if (d[i][j][l] > 255)
						{
							d[i][j][l] = 255;
						}
					}
				}
			}

			for (int i = 0; i < k; i++) 
			{
				for (int j = 0; j < k; j++) 
				{
					for (int l = 0; l < k; l++) 
					{
						p[i][j][l] += x;
						p[i][j][l] = (int) p[i][j][l];
						if (p[i][j][l] < 0) 
						{
							p[i][j][l] = 0;
						}
						else if (p[i][j][l] > 255)
						{
							p[i][j][l] = 255;
						}
					}
				}
			}

			for (int i1 = 0; i1 < m1 - k; i1++) 
			{
				for (int i2 = 0; i2 < m2 - k; i2++) 
				{
					for (int i3 = 0; i3 < m3 - k; i3++)
					{
						sumsq = 0.0;
						for (int j1 = 0; j1 < k; j1++)
						{
							for (int j2 = 0; j2 < k; j2++) 
							{
								for (int j3 = 0; j3 < k; j3++) 
								{
									diff = d[i1 + j1][i2 + j2][i3 + j3] - p[j1][j2][j3];
									sumsq += diff * diff;
								}
							}
						}
						if (i1 == 0 && i2 == 0 && i3 == 0)
						{
							minssd = sumsq;
							r1 = 0;
							r2 = 0;
							r3 = 0;
						}
						if (minssd > sumsq)
						{
							minssd = sumsq;
							r1 = i1;
							r2 = i2;
							r3 = i3;
						}
					}
				}
			}

			cout << "r1: " << r1 << endl << "r2: " << r2 << endl << "r3: " << r3 << endl;
			cout << "error1: " << r1 - k1 << endl << "error2: " << r2 - k2 << endl << "error3: " << r3 - k3 << endl;

			for (int i = 0; i < m1; i++)
			{
				for (int j = 0; j < m2; j++)
				{
					delete[] d[i][j];
				}
			}

			for (int i = 0; i < k; i++)
			{
				for (int j = 0; j < k; j++) 
				{
					delete[] p[i][j];
				}
			}

			for (int i = 0; i < m1; i++) 
			{
				delete[] d[i];
			}

			for (int i = 0; i < k; i++)
			{
				delete[] p[i];
			}

			delete d, p;
		}

		else
		{
			cout << "Invaild value for n" << endl;
		}

		cout << "Enter any number to quit: ";
		cin >> n;
		input.close();
	}

	else
	{
		cout << "Unable to open file " << endl;
	}

	return 0;
}


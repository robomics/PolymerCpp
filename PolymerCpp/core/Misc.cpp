#include "Misc.h"

using namespace std;

std::minstd_rand randGenerator{};
std::uniform_real_distribution<double> randUniformReal(0.0,1.0);
std::normal_distribution<double> randNormalReal(0.0,1.0);

void setSeed()
{
    randGenerator.seed(std::random_device{}());
}

void setSeed(unsigned long long seed)
{
  randGenerator.seed(seed);
}

void printRandom()
{
	cout << "Random number incoming: " << randNormalReal(randGenerator)
		 << std::endl;
}


void convSegments(vector<double> & outVector,
                      vector<double> & inVector,
                      double convFactor,
                      bool multiplyBool)
{
    outVector.clear();
    for (int i=0; i<inVector.size(); i++)
    {
        if (multiplyBool) {
            outVector.push_back(inVector[i] * convFactor);
        }
        else {
            outVector.push_back(inVector[i] / convFactor);
        }
    }
    return;
}

double sum(vector<double> & vect)
{
    double result = 0.0;
    for (auto & val: vect)
        result += val;
    return result;
}

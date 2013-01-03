#include "TSP_Iterative.h"

namespace com
{
	namespace ecsion
	{
		namespace tsp
		{

			TSP_Iterative::TSP_Iterative(double distMatix[][]) : TSPAlgorithm(distMatix)
			{
			}

			void TSP_Iterative::optimize()
			{
				Alg3Hendler();
			}

			void TSP_Iterative::Alg3Hendler()
			{

				generateInitsol();
				distance = calculateTotalDistance(order);

			}

			void TSP_Iterative::generateInitsol()
			{

				order = new int[cityNum + 1];
				for (int i = 0;i < cityNum;i++)
					order[i] = i;
				order[cityNum] = 0;
			}
		}
	}
}

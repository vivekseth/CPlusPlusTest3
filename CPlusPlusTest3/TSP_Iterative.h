#pragma once

#include "TSPAlgorithm.h"

namespace com
{
	namespace ecsion
	{
		namespace tsp
		{

			class TSP_Iterative : public TSPAlgorithm
			{

			public:
				TSP_Iterative(double distMatix[][]);


				virtual void optimize();

			private:
				void Alg3Hendler();

				void generateInitsol();

			};

		}
	}
}

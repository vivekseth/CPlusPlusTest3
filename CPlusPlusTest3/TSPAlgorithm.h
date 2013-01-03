#pragma once
#import <vector>

namespace com
{
	namespace ecsion
	{
		namespace tsp
		{



			class TSPAlgorithm
			{
				//Helper Classes
			protected:
				class HeapElement
				{
						private:
							TSPAlgorithm *const outerInstance;

				public:
					int index;
					double key;

					HeapElement(TSPAlgorithm *outerInstance, int index, double key);
				};
			protected:
				class Bheap
				{
						private:
							TSPAlgorithm *const outerInstance;

					// class Bheap represents binary heap - an array , viewed as a tree
				public:
//JAVA TO C++ CONVERTER WARNING: Since the array size is not known in this declaration, Java to C++ Converter has converted this array to a pointer.  You will need to call 'delete[]' where appropriate:
//ORIGINAL LINE: HeapElement Heap[];
					//HeapElement *Heap;
                    
                    std::vector<HeapElement> Heap;
                    
					int heapSize;
//JAVA TO C++ CONVERTER WARNING: Since the array size is not known in this declaration, Java to C++ Converter has converted this array to a pointer.  You will need to call 'delete[]' where appropriate:
//ORIGINAL LINE: int[] watch;
					int *watch; // = new int[TspAlg8.cityNum];

					/*
						initialize the watch array wich keeps truck of the place
						of every point inside the heep tree.
						Every point is represented by it's index in the xarray.
					*/

					/* computing the indices of parent and childs of node i */
					virtual int Parent(int i);

					virtual int Left(int i);

					virtual int Right(int i);

					/*
						the constuctor of the Heap -
						creates a new structure of binary Heap (an array) and 
						intializes it.
					*/
					Bheap(TSPAlgorithm *outerInstance, int num_of_elem, double key0, double keyall);

					virtual void Heapify(int i);

					// performs Heap[ind1] <-> Heap[ind2]
					virtual void Exchange(int ind1, int ind2);

					virtual void DoMove(int dest, int source);

					// returns the index of point with smallest value of key
					virtual int ExtractMin();

					// changes key value of specified node to smaller one
					virtual void DecreaseKey(int ind, double key);

					virtual bool NotEmpty();

				};

				//input
			protected:
//JAVA TO C++ CONVERTER WARNING: Since the array size is not known in this declaration, Java to C++ Converter has converted this array to a pointer.  You will need to call 'delete[]' where appropriate:
//ORIGINAL LINE: protected double[][] distMatrix;
				double **distMatrix;
				int cityNum;
//JAVA TO C++ CONVERTER WARNING: Since the array size is not known in this declaration, Java to C++ Converter has converted this array to a pointer.  You will need to call 'delete[]' where appropriate:
//ORIGINAL LINE: protected int[] parent;
				int *parent;

				//output
				double distance;
//JAVA TO C++ CONVERTER WARNING: Since the array size is not known in this declaration, Java to C++ Converter has converted this array to a pointer.  You will need to call 'delete[]' where appropriate:
//ORIGINAL LINE: protected int[] order;
				int order[];

			public:
				TSPAlgorithm(double distMatrix[][]);

				virtual double getDistance();
				virtual int *getOrder();

				virtual void optimize() = 0;

			protected:
				virtual double calculateTotalDistance(int arr[]);

				virtual void BeginHendler();

				virtual void MSTcreate();

				virtual void TSPpath(int array_Renamed[]);



			private:
				void InitializeInstanceFields();
			};
		}
	}
}

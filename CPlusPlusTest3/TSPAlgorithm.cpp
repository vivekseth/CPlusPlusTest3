#include "TSPAlgorithm.h"
#include <vector>

namespace com
{
	namespace ecsion
	{
		namespace tsp
		{

			TSPAlgorithm::HeapElement::HeapElement(TSPAlgorithm *outerInstance, int index, double key) : outerInstance(outerInstance)
			{
				this->index = index;
				this->key = key;
			}

			int TSPAlgorithm::Bheap::Parent(int i)
			{
				return (static_cast<int>(i) / 2); // [i/2]
			}

			int TSPAlgorithm::Bheap::Left(int i)
			{
				return (i*2);
			}

			int TSPAlgorithm::Bheap::Right(int i)
			{
				return (i*2 + 1);
			}

			TSPAlgorithm::Bheap::Bheap(TSPAlgorithm *outerInstance, int num_of_elem, double key0, double keyall) : outerInstance(outerInstance)
			{
                
                Heap.

                Heap = new HeapElement[num_of_elem + 1];
				Heap[1] = new HeapElement(0,key0);
				for (int i = 2;i <= num_of_elem;i++)
					Heap[i] = new HeapElement(i - 1,keyall);

				heapSize = num_of_elem;
				//watch_init();    // initialize the watch array
				this->watch = new int[num_of_elem];
				for (int i = 0; i < num_of_elem; i++)
					watch[i] = i + 1;
			}

			void TSPAlgorithm::Bheap::Heapify(int i)
			{
				int smallest = i;
				int l = Left(i);
				int r = Right(i);
				if ((l <= heapSize) && (Heap[l]->key < Heap[i]->key))
						smallest = l;
				if ((r <= heapSize) && (Heap[r]->key < Heap[smallest]->key))
						smallest = r;
				if (smallest != i)
				{
					Exchange(i,smallest);
					Heapify(smallest);
				}
			}

			void TSPAlgorithm::Bheap::Exchange(int ind1, int ind2)
			{
				watch[Heap[ind1]->index] = ind2;
				watch[Heap[ind2]->index] = ind1;
				HeapElement *temp = new HeapElement(Heap[ind1]->index,Heap[ind1]->key);
				Heap[ind1]->index = Heap[ind2]->index;
				Heap[ind1]->key = Heap[ind2]->key;
				Heap[ind2]->index = temp->index;
				Heap[ind2]->key = temp->key;
			}

			void TSPAlgorithm::Bheap::DoMove(int dest, int source)
			{
				Heap[dest]->index = Heap[source]->index;
				Heap[dest]->key = Heap[source]->key;
				watch[Heap[source]->index] = dest;
			}

			int TSPAlgorithm::Bheap::ExtractMin()
			{
				int ind = Heap[1]->index;
				DoMove(1,heapSize);
				heapSize--;
				Heapify(1);
				return ind;
			}

			void TSPAlgorithm::Bheap::DecreaseKey(int ind, double key)
			{
				int i = watch[ind]; // get position of node in the heap
				int p = Parent(i);
				while ((i > 1) && (Heap[p]->key > key))
				{
					DoMove(i,p);
					i = p;
					p = Parent(i);
				}
				Heap[i]->key = key;
				Heap[i]->index = ind;
				watch[ind] = i;
			}

			bool TSPAlgorithm::Bheap::NotEmpty()
			{
				if (heapSize == 0)
					return false;
				else
					return true;
			}

			TSPAlgorithm::TSPAlgorithm(double distMatrix[][])
			{
				InitializeInstanceFields();
				this->distMatrix = distMatrix;
				this->distance = -1;
				this->cityNum = sizeof(distMatrix) / sizeof(distMatrix[0]);
				this->order = new int[sizeof(distMatrix) / sizeof(distMatrix[0])];
			}

			double TSPAlgorithm::getDistance()
			{
				return distance;
			}

			int *TSPAlgorithm::getOrder()
			{
				return order;
			}

			double TSPAlgorithm::calculateTotalDistance(int arr[])
			{
				int ind1, ind2;
				double weight = 0;
				ind1 = arr[0];
				for (int i = 1;i <= cityNum && i < sizeof(arr) / sizeof(arr[0]);i++)
				{
					ind2 = arr[i];
					weight += distMatrix[ind1][ind2];
					ind1 = ind2;
				}
				return weight;
			}

			void TSPAlgorithm::BeginHendler()
			{

				if (cityNum == 0)
						return;
				if (parent == 0)
						MSTcreate(); // => parent[]!=null
				//nextButton.enable();
			}

			void TSPAlgorithm::MSTcreate()
			{
				//creating binary heap with node 0 as a root
				Bheap *Q = new Bheap(this, cityNum,0,1000);
				/*
					Parent array holds definition of node's parent during construction of
					the minimum spanning tree.
				*/
				parent = new int[cityNum];
				parent[0] = -1; // -1 for null as parent of root


				/*
					Initialize Key array.
					The value of key is the distance of the node from the current
					subtree of MST.
					1000 equals to infinity in this case.
				*/
				double Key[cityNum];
				Key[0] = 0;

				for (int i = 1; i < cityNum;Key[i++] = 1000)
					;


				/*
					bitvector array is used to indicate wich nodes are in Q
					bitvector[i]=true <=> node i is in heap Q
					all bitvector elements intialized to true
				*/
				bool bitvector[cityNum];
				for (int i = 0;i < cityNum;bitvector[i++] = true)
					;
						//		if (distMatrix==null)
						//			calculateDist();
				// the body of Prim's algorithm for finding minimum spanning tree
				int u;
				while (Q->NotEmpty())
				{
					u = Q->ExtractMin();
					bitvector[u] = false; // u isn't in Q any more
					for (int v = 0;v < cityNum;v++)
					{
						if (bitvector[v] && (distMatrix[v][u] < Key[v]))
						{
							parent[v] = u;
							Key[v] = distMatrix[v][u];
							Q->DecreaseKey(v,Key[v]);
						}
					}
				}
			}

			void TSPAlgorithm::TSPpath(int array_Renamed[])
			{
				order = array_Renamed;
			}

			void TSPAlgorithm::InitializeInstanceFields()
			{
				distance = -1;
			}
		}
	}
}

#include "MSTPrim.h"



int main(int argc, char const *argv[])
{
	CreateSampleWeightedGraph();
	PrintGraph();
	CreateDistanceVector();
	Prim();
	// PrintArrayAny(Prim(), g.size, printEdge);
	return 0;
}
#pragma once
#include "Quad.h"
#include "Triangles.h"
#include "iostream"
#include "vector"
class PrimitiveLoader
{
	private:
		std::vector<Quad> quadList;
		std::vector<Triangles> triList;
	public:
		PrimitiveLoader();
		void LoadPrimitive(PrimitveType primitiveType, int spawnNumber, transformList2D transformList[]);
		void DrawPrimitives();
		void ReleasePrimitives();
		~PrimitiveLoader();
	private:
		void LoadQuads(int spawnNumber, transformList2D transformList[]);
		void LoadTris(int spawnNumber, transformList2D transformList[]);

};


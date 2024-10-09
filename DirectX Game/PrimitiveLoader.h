#pragma once
#include "Quad.h"
#include "Triangles.h"
#include "iostream"
#include "vector"
class PrimitiveLoader
{
	private:
		std::vector<Quad> quadList = {};
		//std::vector<Triangles> triList;
	public:
		PrimitiveLoader(float width, float height);
		void LoadPrimitive(PrimitveType primitiveType, int spawnNumber, transformList2D transformList[]);
		void DrawPrimitives();
		void ReleasePrimitives();
		~PrimitiveLoader();
	private:
		void LoadQuads(int spawnNumber, transformList2D transformList[]);
		void LoadQuads(float windowWidth, float windowHeight);
		void LoadTris(int spawnNumber, transformList2D transformList[]);
	private:
		float windowWidth;
		float windowHeight;


};


#pragma once
#include "Quad.h"
#include "Triangles.h"
#include "Cube.h"
#include "iostream"
#include "vector"
class PrimitiveLoader
{
	private:
		std::vector<Quad> quadList = {};
		//std::vector<Triangles> triList;
		std::vector<Cube> cubeList = {};
	public:
		PrimitiveLoader(float width, float height);
		void LoadPrimitives(PrimitveType primitiveType, int spawnNumber);
		void DrawPrimitives();
		void ReleasePrimitives();
		~PrimitiveLoader();
	private:
		Vector3D RandomPos();
		Vector3D RandomRot();
		Vector3D RandomScale();
		void LoadQuads(int spawnNumber);
		void LoadQuads(float windowWidth, float windowHeight);
		void LoadTris(int spawnNumber);
		void LoadCubes(float windowWidth, float windowHeight);
		void LoadCubes(float windowWidth, float windowHeight, Transforms transfomMatrices);
		void LoadCubes(float windowWidth, float windowHeight, int spawnNumber);

	private:
		float windowWidth;
		float windowHeight;


};


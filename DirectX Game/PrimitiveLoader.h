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
		void LoadPrimitives(PrimitveType primitiveType, int spawnNumber, Transforms transformMatrices[]);
		void DrawPrimitives();
		void ReleasePrimitives();
		~PrimitiveLoader();
public:
	std::vector<Cube> GetCubeList();
	private:
		Vector3D RandomPos();
		Vector3D RandomRot();
		Vector3D RandomScale();
		void LoadQuads(float windowWidth, float windowHeight, int spawnNumber, Transforms transfomMatrices[]);
		void LoadQuads(float windowWidth, float windowHeight);
		void LoadTris(int spawnNumber);
		void LoadCubes(float windowWidth, float windowHeight);
		void LoadCubes(float windowWidth, float windowHeight,int spawnNumber, Transforms transfomMatrices[]);
		void LoadCubes(float windowWidth, float windowHeight, int spawnNumber);

	private:
		float windowWidth;
		float windowHeight;


};


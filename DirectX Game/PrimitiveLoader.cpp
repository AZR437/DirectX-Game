#include "PrimitiveLoader.h"

PrimitiveLoader::PrimitiveLoader(float width, float height)
{
	this->windowWidth = width;
	this->windowHeight = height;
}

void PrimitiveLoader::LoadPrimitives(PrimitveType primitiveType, int spawnNumber)
{
	switch (primitiveType)
	{
		case QUAD:
			//this->LoadQuads(spawnNumber, transformList);
			this->LoadQuads(this->windowWidth, this->windowHeight);
			break;
		case TRI:
			//this->LoadTris(spawnNumber, transformList);
			break;
		case CUBE:
			this->LoadCubes(this->windowWidth, this->windowHeight);
			break;
		default:
			break;
	}
}

void PrimitiveLoader::DrawPrimitives()
{
	if (!this->quadList.empty())
	{
		for (int i = 0; i < this->quadList.size(); i++)
		{
			
			this->quadList[i].Draw();
			
		}
	}
	//if (!this->triList.empty())
	//{
	//	for (int i = 0; i < this->triList.size(); i++)
	//	{
	//		//this->triList[i].Draw();
	//	}
	//}
	if (!this->cubeList.empty())
	{
		for (int i = 0; i < this->cubeList.size(); i++)
		{
			this->cubeList[i].Draw();
			std::cout << this->cubeList.size() << std::endl;
		}
	}
}

void PrimitiveLoader::ReleasePrimitives()
{
	if (!this->quadList.empty())
	{
		for (int i = 0; i < this->quadList.size(); i++)
		{
			this->quadList[i].Release();
			this->quadList.erase(this->quadList.begin() + i);
		}
	}
	/*if (!this->triList.empty())
	{
		for (int i = 0; i < this->triList.size(); i++)
		{
			this->triList[i].Release();
			this->triList.erase(this->triList.begin() + i);
		}
	}*/
	if (!this->cubeList.empty())
	{
		for (int i = 0; i < this->cubeList.size(); i++)
		{
			this->cubeList[i].Release();
			this->cubeList.erase(this->cubeList.begin() + i);
			
		}
	}
	delete this;
}

void PrimitiveLoader::LoadQuads(int spawnNumber)
{
	/*for (int i = 0; i < spawnNumber; i++)
	{

		this->quadList.push_back(Quad(transformList[i].transform.x, transformList[i].transform.y, transformList[i].transform.scale));
		this->quadList[i].Load();

	}*/
}

void PrimitiveLoader::LoadQuads(float windowWidth, float windowHeight)
{
	this->quadList.push_back(Quad(windowWidth,windowHeight));
	this->quadList[0].Load();
}

void PrimitiveLoader::LoadTris(int spawnNumber)
{
	/*for (int i = 0; i < spawnNumber; i++)
	{
		this->triList.push_back(Triangles(transformList[i].transform.x, transformList[i].transform.y, transformList[i].transform.scale));
		this->triList[i].Load();
	}*/
}

void PrimitiveLoader::LoadCubes(float windowWidth, float windowHeight)
{
	this->cubeList.push_back(Cube(windowWidth, windowHeight));
	this->cubeList[0].Load();
}

void PrimitiveLoader::LoadCubes(float windowWidth, float windowHeight, Transforms transfomMatrices)
{

}

void PrimitiveLoader::LoadCubes(float windowWidth, float windowHeight, int spawnNumber)
{
	for (int i = 0; i < spawnNumber; i++)
	{
		Vector3D pos = this->RandomPos();
		Transforms transforms= 
		{
			 Vector3D(0.25f,0.25f,0.25f), Vector3D(0,0,0), pos
		};
		this->cubeList.push_back(Cube(windowWidth,windowHeight, transforms));
		this->cubeList[i].Load();

	}
}




PrimitiveLoader::~PrimitiveLoader()
{
}

Vector3D PrimitiveLoader::RandomPos()
{
	
	float randomValueX = ((float)rand() / RAND_MAX) * 2 -1;
	float randomValueY = (float)rand() / RAND_MAX * 2 - 1;
	float randomValueZ = (float)rand() / RAND_MAX * 2 - 1;

	return Vector3D(randomValueX,randomValueY, randomValueZ);
}

Vector3D PrimitiveLoader::RandomRot()
{
	std::srand(time(0));
	float randomValueX = (rand() % 360) * PI / 180;
	float randomValueY = (rand() % 360) * PI / 180;
	float randomValueZ = (rand() % 360) * PI / 180;
	return Vector3D();
}

Vector3D PrimitiveLoader::RandomScale()
{
	std::srand(time(0));
	
	float randomValueX = (float)rand() / RAND_MAX;
	float randomValueY = (float)rand() / RAND_MAX;
	float randomValueZ = (float)rand() / RAND_MAX;

	return Vector3D(randomValueX, randomValueX, randomValueX);
}

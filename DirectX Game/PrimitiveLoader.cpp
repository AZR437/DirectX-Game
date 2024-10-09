#include "PrimitiveLoader.h"

PrimitiveLoader::PrimitiveLoader(float width, float height)
{
	this->windowWidth = width;
	this->windowHeight = height;
}

void PrimitiveLoader::LoadPrimitive(PrimitveType primitiveType, int spawnNumber, transformList2D transformList[])
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
	delete this;
}

void PrimitiveLoader::LoadQuads(int spawnNumber, transformList2D transformList[])
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

void PrimitiveLoader::LoadTris(int spawnNumber, transformList2D transformList[])
{
	/*for (int i = 0; i < spawnNumber; i++)
	{
		this->triList.push_back(Triangles(transformList[i].transform.x, transformList[i].transform.y, transformList[i].transform.scale));
		this->triList[i].Load();
	}*/
}




PrimitiveLoader::~PrimitiveLoader()
{
}

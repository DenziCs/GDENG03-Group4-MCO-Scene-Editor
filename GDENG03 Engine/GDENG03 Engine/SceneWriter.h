#pragma once

#include "AGameObject.h"
#include "Vector3D.h"
#include "GameObjectManager.h"
#include "PhysicsComponent.h"
#include "StringUtilities.h"
#include <string>
#include <vector>
#include <iostream>
#include <fstream>

class SceneWriter
{
public:
	static void WriteToFile(std::string inputFilePath);
	static void LoadFromFile(std::string inputFilePath);

	//std::string directory = ""; idk what sir was cooking with this so I'm cooking my own

private:
	SceneWriter();
	~SceneWriter();
};
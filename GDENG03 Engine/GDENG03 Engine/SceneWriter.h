#pragma once

#include "AGameObject.h"
#include "Vector3D.h"
#include "GameObjectManager.h"
#include <iostream>
#include <fstream>

class SceneWriter
{
public:
	SceneWriter();
	~SceneWriter();
	void WriteToFile();
	std::string directory = "";
};
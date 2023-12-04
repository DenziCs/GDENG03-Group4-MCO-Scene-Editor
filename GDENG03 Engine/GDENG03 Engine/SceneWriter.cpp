#include "SceneWriter.h"

SceneWriter::SceneWriter()
{
}

SceneWriter::~SceneWriter()
{
}

void SceneWriter::WriteToFile()
{
	std::string fileDir = this->directory + ".iet";

	if (this->directory.find(".iet") != std::string::npos)
	{
		fileDir = this->directory;
	}

	std::ofstream sceneFile;
	sceneFile.open(fileDir, std::ios::out);

	std::cout << "Selected filename" << fileDir << "\n";

	std::vector<AGameObject*> allObjects = GameObjectManager::getInstance()->getAllGameObjects();

	for (int i = 0; i < allObjects.size(); i++)
	{
		AGameObject* currentObject = allObjects[i];
		sceneFile << currentObject->getObjectName() << std::endl;
		Vector3D pos = currentObject->getLocalPosition();
		Vector3D rot = currentObject->getLocalRotation();
		Vector3D scale = currentObject->getLocalScale();

		sceneFile << "Type: " << currentObject->getObjectType() << std::endl;
		sceneFile << "Position: " << pos.x << " " << pos.y << " " << pos.z << std::endl;
		sceneFile << "Rotation: " << rot.x << " " << rot.y << " " << rot.z << std::endl;
		sceneFile << "Scale: " << scale.x << " " << scale.y << " " << scale.z << std::endl;
	}

	sceneFile.close();
}
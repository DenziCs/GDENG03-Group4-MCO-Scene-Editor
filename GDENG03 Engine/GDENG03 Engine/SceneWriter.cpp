#include "SceneWriter.h"

SceneWriter::SceneWriter()
{
}

SceneWriter::~SceneWriter()
{
}

void SceneWriter::WriteToFile(std::string inputFilePath)
{
	std::string filePath = "";
	if (inputFilePath.find(".iet") != std::string::npos)
	{
		filePath = inputFilePath;
	}
	else
	{
		filePath = inputFilePath + ".iet";
	}

	std::ofstream sceneFile;
	sceneFile.open(filePath, std::ios::out);

	std::cout << "FilePath: " << filePath << "\n";

	std::vector<AGameObject*> allObjects = GameObjectManager::getInstance()->getAllGameObjects();

	AGameObject* currentObject;
	AComponent* objectComponent;
	PhysicsComponent* physicsComponent;

	for (int i = 0; i < allObjects.size(); i++)
	{
		currentObject = allObjects[i];

		sceneFile << currentObject->getObjectName() << std::endl;
		Vector3D pos = currentObject->getLocalPosition();
		Vector3D rot = currentObject->getLocalRotation();
		Vector3D scale = currentObject->getLocalScale();

		sceneFile << "Type: " << currentObject->getObjectType() << std::endl;
		sceneFile << "Position: " << pos.x << " " << pos.y << " " << pos.z << std::endl;
		sceneFile << "Rotation: " << rot.x << " " << rot.y << " " << rot.z << std::endl;
		sceneFile << "Scale: " << scale.x << " " << scale.y << " " << scale.z << std::endl;

		if (currentObject->isActive())
		{
			sceneFile << "Active: 1" << std::endl;
		}
		else
		{
			sceneFile << "Active: 0" << std::endl;
		}

		objectComponent = currentObject->findComponentOfType(AComponent::PHYSICS);

		if (objectComponent)
		{
			physicsComponent = (PhysicsComponent*)objectComponent;

			sceneFile << "PhysicsComponent: 1" << std::endl;
			sceneFile << "Active: " << physicsComponent->isActive() << std::endl;
			sceneFile << "Static: " << physicsComponent->isStatic() << std::endl;
			sceneFile << "Gravity: " << physicsComponent->isGravityEnabled() << std::endl;
			sceneFile << "Mass: " << physicsComponent->getMass() << std::endl;
		}
		else
		{
			sceneFile << "PhysicsComponent: 0" << std::endl;
			sceneFile << "Active: 0" << std::endl;
			sceneFile << "Static: 0" << std::endl;
			sceneFile << "Gravity: 0" << std::endl;
			sceneFile << "Mass: 0" << std::endl;
		}

		objectComponent = nullptr;
		physicsComponent = nullptr;
	}

	sceneFile.close();
}

void SceneWriter::LoadFromFile(std::string inputFilePath)
{
	std::string filePath = "";
	if (inputFilePath.find(".iet") != std::string::npos)
	{
		filePath = inputFilePath;
	}
	else
	{
		filePath = inputFilePath + ".iet";
	}

	std::ifstream sceneFile;
	sceneFile.open(filePath, std::ios::out);
	if (sceneFile.fail())
	{
		std::cout << "ERROR: Failed to open file at path " << filePath << std::endl;
		return;
	}
	
	//delete all object in scene to prepare for loading
	std::vector<AGameObject*> allObjects = GameObjectManager::getInstance()->getAllGameObjects();
	for (int i = 0; i < allObjects.size(); i++)
	{
		std::cout << "Deleting: " << allObjects[i]->getObjectName();
		GameObjectManager::getInstance()->deleteObject(allObjects[i]);
	}

	std::string currentLine;
	int index = 0;

	std::string objectName = "";
	AGameObject::ObjectType objectType;
	Vector3D pos;
	Vector3D rot;
	Vector3D scale;

	bool isActive;
	bool hasPhysics;
	bool isPhysicsActive;
	bool isStatic;
	bool isGravityActive;
	float mass;

	while (std::getline(sceneFile, currentLine))
	{
		switch (index) {
		case 0:
		{
			objectName = currentLine;
			std::cout << objectName << std::endl;
			index++;

			break;
		}

		case 1:
		{
			std::vector<std::string> split = StringUtilities::split(currentLine, ' ');
			objectType = (AGameObject::ObjectType)std::stoi(split[1]);
			std::cout << objectType << std::endl;
			index++;

			break;
		}

		case 2:
		{
			std::vector<std::string> split = StringUtilities::split(currentLine, ' ');
			pos = Vector3D(std::stof(split[1]), std::stof(split[2]), std::stof(split[3]));
			std::cout << pos.x << " " << pos.y << " " << pos.z << std::endl;
			index++;

			break;
		}

		case 3:
		{
			std::vector<std::string> split = StringUtilities::split(currentLine, ' ');
			rot = Vector3D(std::stof(split[1]), std::stof(split[2]), std::stof(split[3]));
			std::cout << rot.x << " " << rot.y << " " << rot.z << std::endl;
			index++;

			break;
		}

		case 4:
		{
			std::vector<std::string> split = StringUtilities::split(currentLine, ' ');
			scale = Vector3D(std::stof(split[1]), std::stof(split[2]), std::stof(split[3]));
			std::cout << scale.x << " " << scale.y << " " << scale.z << std::endl;
			index++;

			break;
		}

		case 5:
		{
			std::vector<std::string> split = StringUtilities::split(currentLine, ' ');
			isActive = std::stoi(split[1]);
			std::cout << isActive << std::endl;
			index++;

			break;
		}

		case 6:
		{
			std::vector<std::string> split = StringUtilities::split(currentLine, ' ');
			hasPhysics = std::stoi(split[1]);
			std::cout << hasPhysics << std::endl;
			index++;

			break;
		}

		case 7:
		{
			std::vector<std::string> split = StringUtilities::split(currentLine, ' ');
			isPhysicsActive = std::stoi(split[1]);
			std::cout << isPhysicsActive << std::endl;
			index++;

			break;
		}

		case 8:
		{
			std::vector<std::string> split = StringUtilities::split(currentLine, ' ');
			isStatic = std::stoi(split[1]);
			std::cout << isStatic << std::endl;
			index++;

			break;
		}

		case 9:
		{
			std::vector<std::string> split = StringUtilities::split(currentLine, ' ');
			isGravityActive = std::stoi(split[1]);
			std::cout << isGravityActive << std::endl;
			index++;

			break;
		}

		case 10:
		{
			std::vector<std::string> split = StringUtilities::split(currentLine, ' ');
			mass = std::stof(split[1]);
			std::cout << mass << std::endl;
			index = 0;

			GameObjectManager::getInstance()->recreateObject(
				objectName,
				objectType,
				pos,
				rot,
				scale,
				hasPhysics,
				isPhysicsActive,
				isStatic,
				isGravityActive,
				mass
			);

			break;
		}

		}
	}
}
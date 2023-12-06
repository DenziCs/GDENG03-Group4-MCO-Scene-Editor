#pragma once
#include"AGameObject.h"
#include"AVertexBuffer.h"
#include"AIndexBuffer.h"
#include"AConstantBuffer.h"
#include"Matrix4x4.h"
#include "TexturedVertexBuffer.h"

#include "Texture.h"

class TexturedCube : public AGameObject
{
public:
	TexturedCube(std::string name);
	~TexturedCube();

	void update(float delta_time) override;
	void draw(int width, int height) override;

protected:
	//AVertexBuffer* mVertexBuffer;
	AIndexBuffer* mIndexBuffer;
	AConstantBuffer* mConstantBuffer;
	TexturedVertexBuffer* texVertexBuffer;
	AVertexBuffer* mVertexBuffer;

	Texture* texture;

	float mDeltaTime = 0.f;
	float mElapsedTime = 0.f;
};

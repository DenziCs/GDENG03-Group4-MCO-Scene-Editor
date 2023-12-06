#pragma once
#include "AUIPanel.h"
#include "SceneWriter.h"
#include <imfilebrowser.h>

class SceneLoadPanel : public AUIPanel
{
public:
	SceneLoadPanel(std::string name);
	~SceneLoadPanel();

	void draw() override;
	void openExplorer();
	void closeExplorer();

private:
	ImGui::FileBrowser* browser;
};
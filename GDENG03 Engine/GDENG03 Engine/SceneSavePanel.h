#pragma once
#include "AUIPanel.h"
#include "SceneWriter.h"
#include <imfilebrowser.h>

class SceneSavePanel : public AUIPanel
{
public:
	SceneSavePanel(std::string name);
	~SceneSavePanel();

	void draw() override;
	void openExplorer();
	void closeExplorer();

private:
	ImGui::FileBrowser* browser;
};
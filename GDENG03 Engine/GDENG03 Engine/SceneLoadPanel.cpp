#include "SceneLoadPanel.h"

SceneLoadPanel::SceneLoadPanel(std::string name) : AUIPanel::AUIPanel(name)
{
	browser = new ImGui::FileBrowser(ImGuiFileBrowserFlags_NoModal | ImGuiFileBrowserFlags_EnterNewFilename | ImGuiFileBrowserFlags_CreateNewDir);
	browser->SetTitle("Save as");
	browser->SetTypeFilters({ ".iet" });
}

SceneLoadPanel::~SceneLoadPanel()
{
	delete this->browser;
}

void SceneLoadPanel::draw()
{
	browser->Display();

	if (browser->HasSelected())
	{
		SceneWriter::LoadFromFile(browser->GetSelected().string());
		browser->Close();
	}
}

void SceneLoadPanel::openExplorer()
{
	browser->Open();
}

void SceneLoadPanel::closeExplorer()
{
	browser->Close();
}

bool SceneLoadPanel::isEnabled()
{
	return browser->IsOpened();
}
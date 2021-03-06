#pragma once
#include "GUIElement.h"
#include "GUIImage.h"
#include "GUILabel.h"
#include "GB_Rectangle.h"

class GUIButton :
	public GUIElement
{
public:
	GUIButton(GB_Rectangle<int> _position, 
			  GB_Rectangle<int> _standBySection, 
			  GB_Rectangle<int> _hoverSection, 
			  GB_Rectangle<int> _clickedSection,
			  std::string name,
			  int flags = STANDARD_PRESET,
			  char* text = nullptr, 
			  label_size _size = DEFAULT);
	GUIButton(const GUIButton &btn, std::string name, int flags = STANDARD_PRESET);
	~GUIButton();

	void OnUpdate(const GUIElement* mouseHover, const GUIElement* focus, float dt) override;
	void Draw() const override;
	void Serialize(pugi::xml_node node)override;
	void Deserialize(pugi::xml_node node)override;
	void SetText(std::string txt, label_size size = DEFAULT);

	GUIImage* image = nullptr;
	GUILabel* label = nullptr;

	GB_Rectangle<int> standBySection;
	GB_Rectangle<int> hoverSection;
	GB_Rectangle<int> clickedSection;
};


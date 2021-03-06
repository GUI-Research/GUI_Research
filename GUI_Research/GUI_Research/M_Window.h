#ifndef __M_WINDOW_H__
#define __M_WINDOW_H__

#include "Module.h"
#include "GB_Rectangle.h"
#include "p2Point.h"

//TODO: I dont like to include this here only for the events, maybe I should fix it...
#include "GUIElement.h"

struct SDL_Window;
struct SDL_Surface;

class M_Window : public Module
{
public:

	M_Window(bool startEnabled = true);

	// Destructor
	virtual ~M_Window();

	// Called before render is available
	bool Awake(pugi::xml_node&)override;

	// Called before quitting
	bool CleanUp()override;

	// Changae title
	void SetTitle(const char* newTitle);

	// Retrive window size
	void GetWindowSize(uint& width, uint& height) const;
	iPoint GetWindowSize() const;
	// Retrieve window scale
	uint GetScale() const;

	void DrawDebug()override;
	void GuiEvent(GUIElement* element, int64_t event) override;


public:
	//The window we'll be rendering to
	SDL_Window* window;

	//The surface contained by the window
	SDL_Surface* screenSurface;

private:
	std::string	title;
	uint		width;
	uint		height;
	uint		scale;
};

#endif // __M_WINDOW_H__
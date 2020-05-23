#pragma once
#ifndef BASE_OBJECT_H_
#define BASE_OBJECT_H_

#include "CommonFunction.h"

class BaseObject
{
public:
	BaseObject();
	~BaseObject();
	void setRect(const int& x, const int& y) { rect_.x = x, rect_.y = y; }
	SDL_Rect getRect() const { return rect_; }
	SDL_Texture* GetObject() const { return p_object_; } //Dam bao tinh chat che, chi lay ra

	virtual bool LoadImg(std::string path, SDL_Renderer* screen);  // Ham ao => ham ke thua co the chinh sua them
	void Render(SDL_Renderer* des, const SDL_Rect* clip = NULL);
	void Free();

protected:
	SDL_Texture* p_object_;	
	SDL_Rect rect_;
};


#endif // !BASE_OBJECT_H_


#pragma once
#ifndef MAIN_OBJECT_H_
#define MAIN_OBJECT_H_

#include "CommonFunction.h"
#include "BaseObject.h"

#define GRAVITY_SPEED 3
#define MAX_FALL_SPEED 8
#define PLAYER_SPEED 5
#define PLAYER_JUMP_VAL 0.5

class MainObject : public BaseObject
{
public:
	MainObject();
	~MainObject();

	enum Walk_Type
	{
		WALK_LEFT = 1,
		WALK_RIGHT = 0,
	};
	bool LoadImg(std::string path, SDL_Renderer* screen);
	void Show(SDL_Renderer* des); // show tung frame
	void HandleInputAction(SDL_Event events, SDL_Renderer* screen); 
	void setClips(); // tao hieu ung clip cho nhan vat

	void DoPlayer(Map &map_data); // Xu li di chuyen
	void CheckToMap(Map &map_data); // Kiem tra va cham
	void SetMapXY(const int map_x, const int map_y) { this->map_x_ = map_x; this->map_y_ = map_y; }   // set vi tri x y cua ban do
	void CenterEntityOnMap(Map &map_data);  // tinh toan thong so ban do de man hinh di chuyen theo nhan vat
	
private:
	float x_val_; //khi an phai, trai nhan vat se lui lai bao nhieu
	float y_val_;

	float x_pos_; // vi tri nhan vat
	float y_pos_;

	int width_frame_; // kich thuoc nhan vat
	int height_frame_;

	SDL_Rect frame_clip_[8];
	Input input_type_;
	int frame_;     // frame index
	int status_;    // nhan vat di chuyen sang phai or sang trai
	bool on_ground_;// nhan vat o tren mat dat hay khong

	int map_x_;
	int map_y_; // vi tri cua map khi nhan vat di chuyen

	int come_back_time_;
};



#endif // !MAIN_OBJECT_H_


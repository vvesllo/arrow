#pragma once
class InputController
{
public:

	// _Key  - one-time pressed
	//  Key  - pressed
	//  Key_ - one-time released
	// !Key  - released

	bool _A = false; bool A = false; bool A_ = false;
	bool _B = false; bool B = false; bool B_ = false;
	bool _C = false; bool C = false; bool C_ = false;
	bool _D = false; bool D = false; bool D_ = false;
	bool _E = false; bool E = false; bool E_ = false;
	bool _F = false; bool F = false; bool F_ = false;
	bool _G = false; bool G = false; bool G_ = false;
	bool _H = false; bool H = false; bool H_ = false;
	bool _I = false; bool I = false; bool I_ = false;
	bool _J = false; bool J = false; bool J_ = false;
	bool _K = false; bool K = false; bool K_ = false;
	bool _L = false; bool L = false; bool L_ = false;
	bool _M = false; bool M = false; bool M_ = false;
	bool _N = false; bool N = false; bool N_ = false;
	bool _O = false; bool O = false; bool O_ = false;
	bool _P = false; bool P = false; bool P_ = false;
	bool _Q = false; bool Q = false; bool Q_ = false;
	bool _R = false; bool R = false; bool R_ = false;
	bool _S = false; bool S = false; bool S_ = false;
	bool _T = false; bool T = false; bool T_ = false;
	bool _U = false; bool U = false; bool U_ = false;
	bool _V = false; bool V = false; bool V_ = false;
	bool _W = false; bool W = false; bool W_ = false;
	bool _X = false; bool X = false; bool X_ = false;
	bool _Y = false; bool Y = false; bool Y_ = false;
	bool _Z = false; bool Z = false; bool Z_ = false;
	bool _F1 = false; bool F1 = false; bool F1_ = false;
	bool _F2 = false; bool F2 = false; bool F2_ = false;
	bool _F3 = false; bool F3 = false; bool F3_ = false;
	bool _F4 = false; bool F4 = false; bool F4_ = false;
	bool _F5 = false; bool F5 = false; bool F5_ = false;
	bool _F6 = false; bool F6 = false; bool F6_ = false;
	bool _F7 = false; bool F7 = false; bool F7_ = false;
	bool _F8 = false; bool F8 = false; bool F8_ = false;
	bool _F9 = false; bool F9 = false; bool F9_ = false;
	bool _F10 = false; bool F10 = false; bool F10_ = false;
	bool _F11 = false; bool F11 = false; bool F11_ = false;
	bool _F12 = false; bool F12 = false; bool F12_ = false;
	bool _Space = false; bool Space = false; bool Space_ = false;
	bool _Return = false; bool Return = false; bool Return_ = false;
	bool _Escape = false; bool Escape = false; bool Escape_ = false;


	bool _LMouse = false; bool LMouse = false; bool LMouse_ = false;
	bool _RMouse = false; bool RMouse = false; bool RMouse_ = false;
	bool _X1Mouse = false; bool X1Mouse = false; bool X1Mouse_ = false;
	bool _X2Mouse = false; bool X2Mouse = false; bool X2Mouse_ = false;

	bool _Left = false; bool Left = false; bool Left_ = false;
	bool _Right = false; bool Right = false; bool Right_ = false;
	bool _Up = false; bool Up = false; bool Up_ = false;
	bool _Down = false; bool Down = false; bool Down_ = false;




	void update();

	void press_A();
	void press_B();
	void press_C();
	void press_D();
	void press_E();
	void press_F();
	void press_G();
	void press_H();
	void press_I();
	void press_J();
	void press_K();
	void press_L();
	void press_M();
	void press_N();
	void press_O();
	void press_P();
	void press_Q();
	void press_R();
	void press_S();
	void press_T();
	void press_U();
	void press_V();
	void press_W();
	void press_X();
	void press_Y();
	void press_Z();
	void press_F1();
	void press_F2();
	void press_F3();
	void press_F4();
	void press_F5();
	void press_F6();
	void press_F7();
	void press_F8();
	void press_F9();
	void press_F10();
	void press_F11();
	void press_F12();
	void press_Space();
	void press_Return();
	void press_Escape();

	void press_lmouse();
	void press_rmouse();
	void press_x1mouse();
	void press_x2mouse();

	void press_left();
	void press_right();
	void press_up();
	void press_down();


	void release_A();
	void release_B();
	void release_C();
	void release_D();
	void release_E();
	void release_F();
	void release_G();
	void release_H();
	void release_I();
	void release_J();
	void release_K();
	void release_L();
	void release_M();
	void release_N();
	void release_O();
	void release_P();
	void release_Q();
	void release_R();
	void release_S();
	void release_T();
	void release_U();
	void release_V();
	void release_W();
	void release_X();
	void release_Y();
	void release_Z();
	void release_F1();
	void release_F2();
	void release_F3();
	void release_F4();
	void release_F5();
	void release_F6();
	void release_F7();
	void release_F8();
	void release_F9();
	void release_F10();
	void release_F11();
	void release_F12();
	void release_Space();
	void release_Return();
	void release_Escape();

	void release_lmouse();
	void release_rmouse();
	void release_x1mouse();
	void release_x2mouse();

	void release_left();
	void release_right();
	void release_up();
	void release_down();
};


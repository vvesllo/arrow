#include "InputController.h"


void InputController::update() {
    _A = false;        A_ = false;
    _B = false;        B_ = false;
    _C = false;        C_ = false;
    _D = false;        D_ = false;
    _E = false;        E_ = false;
    _F = false;        F_ = false;
    _G = false;        G_ = false;
    _H = false;        H_ = false;
    _I = false;        I_ = false;
    _J = false;        J_ = false;
    _K = false;        K_ = false;
    _L = false;        L_ = false;
    _M = false;        M_ = false;
    _N = false;        N_ = false;
    _O = false;        O_ = false;
    _P = false;        P_ = false;
    _Q = false;        Q_ = false;
    _R = false;        R_ = false;
    _S = false;        S_ = false;
    _T = false;        T_ = false;
    _U = false;        U_ = false;
    _V = false;        V_ = false;
    _W = false;        W_ = false;
    _X = false;        X_ = false;
    _Y = false;        Y_ = false;
    _Z = false;        Z_ = false;
    _F1 = false;       F1_ = false;
    _F2 = false;       F2_ = false;
    _F3 = false;       F3_ = false;
    _F4 = false;       F4_ = false;
    _F5 = false;       F5_ = false;
    _F6 = false;       F6_ = false;
    _F7 = false;       F7_ = false;
    _F8 = false;       F8_ = false;
    _F9 = false;       F9_ = false;
    _F10 = false;      F10_ = false;
    _F11 = false;      F11_ = false;
    _Space = false;    Space_ = false;
    _Return = false;   Return_ = false;
    _Escape = false;   Escape_ = false;

    _LMouse = false;   LMouse_ = false;
    _RMouse = false;   RMouse_ = false;
    _X1Mouse = false;  X1Mouse_ = false;
    _X2Mouse = false;  X2Mouse_ = false;

    _Left = false;      Left_ = false;
    _Right = false;     Right_ = false;
    _Up = false;        Up_ = false;
    _Down = false;      Down_ = false;
}

// press

void InputController::press_A()
{
    if (!A) _A = true;
    A = true;
}
void InputController::press_B()
{
    if (!B) _B = true;
    B = true;
}
void InputController::press_C()
{
    if (!C) _C = true;
    C = true;
}
void InputController::press_D()
{
    if (!D) _D = true;
    D = true;
}
void InputController::press_E()
{
    if (!E) _E = true;
    E = true;
}
void InputController::press_F()
{
    if (!F) _F = true;
    F = true;
}
void InputController::press_G()
{
    if (!G) _G = true;
    G = true;
}
void InputController::press_H()
{
    if (!H) _H = true;
    H = true;
}
void InputController::press_I()
{
    if (!I) _I = true;
    I = true;
}
void InputController::press_J()
{
    if (!J) _J = true;
    J = true;
}
void InputController::press_K()
{
    if (!K) _K = true;
    K = true;
}
void InputController::press_L()
{
    if (!L) _L = true;
    L = true;
}
void InputController::press_M()
{
    if (!M) _M = true;
    M = true;
}
void InputController::press_N()
{
    if (!N) _N = true;
    N = true;
}
void InputController::press_O()
{
    if (!O) _O = true;
    O = true;
}
void InputController::press_P()
{
    if (!P) _P = true;
    P = true;
}
void InputController::press_Q()
{
    if (!Q) _Q = true;
    Q = true;
}
void InputController::press_R()
{
    if (!R) _R = true;
    R = true;
}
void InputController::press_S()
{
    if (!S) _S = true;
    S = true;
}
void InputController::press_T()
{
    if (!T) _T = true;
    T = true;
}
void InputController::press_U()
{
    if (!U) _U = true;
    U = true;
}
void InputController::press_V()
{
    if (!V) _V = true;
    V = true;
}
void InputController::press_W()
{
    if (!W) _W = true;
    W = true;
}
void InputController::press_X()
{
    if (!X) _X = true;
    X = true;
}
void InputController::press_Y()
{
    if (!Y) _Y = true;
    Y = true;
}
void InputController::press_Z()
{
    if (!Z) _Z = true;
    Z = true;
}
void InputController::press_F1()
{
    if (!F1) _F1 = true;
    F1 = true;
}
void InputController::press_F2()
{
    if (!F2) _F2 = true;
    F2 = true;
}
void InputController::press_F3()
{
    if (!F3) _F3 = true;
    F3 = true;
}
void InputController::press_F4()
{
    if (!F4) _F4 = true;
    F4 = true;
}
void InputController::press_F5()
{
    if (!F5) _F5 = true;
    F5 = true;
}
void InputController::press_F6()
{
    if (!F6) _F6 = true;
    F6 = true;
}
void InputController::press_F7()
{
    if (!F7) _F7 = true;
    F7 = true;
}
void InputController::press_F8()
{
    if (!F8) _F8 = true;
    F8 = true;
}
void InputController::press_F9()
{
    if (!F9) _F9 = true;
    F9 = true;
}
void InputController::press_F10()
{
    if (!F10) _F10 = true;
    F10 = true;
}
void InputController::press_F11()
{
    if (!F11) _F11 = true;
    F11 = true;
}
void InputController::press_F12()
{
    if (!F12) _F12 = true;
    F12 = true;
}
void InputController::press_Space()
{
    if (!Space) _Space = true;
    Space = true;
}
void InputController::press_Return()
{
    if (!Return) _Return = true;
    Return = true;
}
void InputController::press_Escape()
{
    if (!Escape) _Escape = true;
    Escape = true;
}
void InputController::press_lmouse()
{
    if (!LMouse) _LMouse = true;
    LMouse = true;
}
void InputController::press_rmouse()
{
    if (!RMouse) _RMouse = true;
    RMouse = true;
}
void InputController::press_x1mouse()
{
    if (!X1Mouse) _X1Mouse = true;
    X1Mouse = true;
}
void InputController::press_x2mouse()
{
    if (!X2Mouse) _X2Mouse = true;
    X2Mouse = true;
}

void InputController::press_left()
{
    if (!Left) _Left = true;
    Left = true;
}

void InputController::press_right()
{
    if (!Right) _Right = true;
    Right = true;
}

void InputController::press_up()
{
    if (!Up) _Up = true;
    Up = true;
}

void InputController::press_down()
{
    if (!Down) _Down = true;
    Down = true;
}

// release


void InputController::release_A()
{
    A_ = true; A = false;
}
void InputController::release_B()
{
    B_ = true; B = false;
}
void InputController::release_C()
{
    C_ = true; C = false;
}
void InputController::release_D()
{
    D_ = true; D = false;
}
void InputController::release_E()
{
    E_ = true; E = false;
}
void InputController::release_F()
{
    F_ = true; F = false;
}
void InputController::release_G()
{
    G_ = true; G = false;
}
void InputController::release_H()
{
    H_ = true; H = false;
}
void InputController::release_I()
{
    I_ = true; I = false;
}
void InputController::release_J()
{
    J_ = true; J = false;
}
void InputController::release_K()
{
    K_ = true; K = false;
}
void InputController::release_L()
{
    L_ = true; L = false;
}
void InputController::release_M()
{
    M_ = true; M = false;
}
void InputController::release_N()
{
    N_ = true; N = false;
}
void InputController::release_O()
{
    O_ = true; O = false;
}
void InputController::release_P()
{
    P_ = true; P = false;
}
void InputController::release_Q()
{
    Q_ = true; Q = false;
}
void InputController::release_R()
{
    R_ = true; R = false;
}
void InputController::release_S()
{
    S_ = true; S = false;
}
void InputController::release_T()
{
    T_ = true; T = false;
}
void InputController::release_U()
{
    U_ = true; U = false;
}
void InputController::release_V()
{
    V_ = true; V = false;
}
void InputController::release_W()
{
    W_ = true; W = false;
}
void InputController::release_X()
{
    X_ = true; X = false;
}
void InputController::release_Y()
{
    Y_ = true; Y = false;
}
void InputController::release_Z()
{
    Z_ = true; Z = false;
}
void InputController::release_F1()
{
    F1_ = true; F1 = false;
}
void InputController::release_F2()
{
    F2_ = true; F2 = false;
}
void InputController::release_F3()
{
    F3_ = true; F3 = false;
}
void InputController::release_F4()
{
    F4_ = true; F4 = false;
}
void InputController::release_F5()
{
    F5_ = true; F5 = false;
}
void InputController::release_F6()
{
    F6_ = true; F6 = false;
}
void InputController::release_F7()
{
    F7_ = true; F7 = false;
}
void InputController::release_F8()
{
    F8_ = true; F8 = false;
}
void InputController::release_F9()
{
    F9_ = true; F9 = false;
}
void InputController::release_F10()
{
    F10_ = true; F10 = false;
}
void InputController::release_F11()
{
    F11_ = true; F11 = false;
}
void InputController::release_F12()
{
    F12_ = true; F12 = false;
}
void InputController::release_Space()
{
    Space_ = true; Space = false;
}
void InputController::release_Return()
{
    Return_ = true; Return = false;
}
void InputController::release_Escape()
{
    Escape_ = true; Escape = false;
}
void InputController::release_lmouse()
{
    LMouse_ = true; LMouse = false;
}
void InputController::release_rmouse()
{
    RMouse_ = true; RMouse = false;
}
void InputController::release_x1mouse()
{
    X1Mouse_ = true; X1Mouse = false;
}
void InputController::release_x2mouse()
{
    X2Mouse_ = true; X2Mouse = false;
}

void InputController::release_left()
{
    Left_ = true; Left = false;
}

void InputController::release_right()
{
    Right_ = true; Right = false;
}

void InputController::release_up()
{
    Up_ = true; Up = false;
}

void InputController::release_down()
{
    Down_ = true; Down = false;
}

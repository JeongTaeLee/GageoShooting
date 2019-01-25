#pragma once

enum
{
	WINSIZEX = 1280,
	WINSIZEY = 720,
	WINDOWED = 0,
};

#include <functional>
#include <iostream>
#include <random>
#include <thread>
#include <vector>
#include <string>
#include <list>
#include <map>

using namespace std;

#define g_device DXUTGetD3D9Device()
#define WallColliderColor D3DXCOLOR(1.f, 0.f, 1.f, 1.f)
#define MINIMAP_S 15
#define PIXELCOLLISION 10
#define OrginColor D3DCOLOR_XRGB(255, 255, 255)

#define MINIMAPX 1153
#define MINIMAPY 121

#define MINIMAPUNITX (MINIMAPX) - 100
#define MINIMAPUNITY (MINIMAPY) - 100


#ifdef DEBUG
#define DEBUG_LOG(s) cout << s << endl
#else 
#define DEBUG_LOG(s) 
#endif

using Vector2 = D3DXVECTOR2;
using Vector3 = D3DXVECTOR3;
using Matrix = D3DXMATRIX;

#include "ObjectManager.h"
#include "ImageManager.h"
#include "SceneManager.h"
#include "InputManager.h"
#include "CameraManager.h"
#include "TimeManager.h"
#include "SoundManager.h"
#include "Func.h"

#include "GameObject.h"
#include "Component.h"
#include "Transform.h"
#include "Renderer.h"
#include "UIRenderer.h"
#include "Animater.h"
#include "Collider.h"
#include "PixelCollider.h"
#include "MiniMapUnit.h"
#include "UIText.h"
#include "Button.h"
#include "Effect.h"

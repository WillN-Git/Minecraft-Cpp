#ifndef MINECRAFT_SCENE_H
#define MINECRAFT_SCENE_H
#include "core.h"
#include "core/Ecs.h"

namespace Minecraft
{
	enum class GEventType : uint8
	{
		None = 0,
		SetDeltaTime,
		PlayerKeyInput,
		PlayerMouseInput,
		PlayerCharInput,
		PlayerMouseButtonInput,
		PlayerMouseScrollInput,
		MouseInitial,
		SetPlayerPos,
		SetPlayerViewAxis,
		SetPlayerOrientation,
		SetPlayerForward,
		FrameTick
	};

	struct GEvent
	{
		GEventType type;
		size_t size;
		void* data;
		bool freeData;
	};

	struct Camera;
	enum class SceneType : uint8
	{
		None,
		SinglePlayerGame,
		LocalLanGame,
		MultiplayerGame,
		MainMenu,
		Replay
	};

	namespace Scene
	{
		void init(SceneType type, Ecs::Registry& registry);

		void update();

		void changeScene(SceneType type);

		void reloadShaders();

		void queueMainEvent(GEventType type, void* eventData = nullptr, size_t eventDataSize = 0, bool freeData = false);
		void queueMainEventKey(int key, int action);
		void queueMainEventMouse(float xpos, float ypos);
		void queueMainEventChar(unsigned int codepoint);
		void queueMainEventMouseButton(int button, int action);
		void queueMainEventMouseScroll(float xoffset, float yoffset);
		void queueMainEventMoustInitial(float xpos, float ypos, float lastMouseX, float lastMouseY);

		void free(bool freeGlobalResources=true);

		bool isPlayingGame();

		Ecs::Registry* getRegistry();
		void resetRegistry();

		Camera& getCamera();

		extern bool serializeEvents;
		extern bool playFromEventFile;
	}
}

#endif 
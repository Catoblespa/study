//SDL�� ǥ������� ����
#include "include\SDL.h"
#include <iostream>

using namespace std;

//ȭ��ũ��
const int SCREEN_WIDTH = 640;
const int SCREEN_HEIGHT = 480;

// Ű �Է¿� ���� �ε��� �̹��� ��
const int MAX_IMAGE_COUNT = 5;

bool Init();
SDL_Surface* LoadSurface(string filePath);
void Close();

// ������ �� â (window)
SDL_Window* gwindow = NULL;

//window�� ���Խ�ų ǥ��(surface)
SDL_Surface* gscreenSurface = NULL;

//�̹����ϳ��� �ε��ؼ� ����� ǥ��
SDL_Surface* surfaces[MAX_IMAGE_COUNT] = { NULL, };
enum KeyPressState {
	KEY_PRESS_DEFAULT,
	KEY_PRESS_UP,
	KEY_PRESS_DOWN,
	KEY_PRESS_RIGHT,
	KEY_PRESS_LEFT
};

KeyPressState gKeyPressState = KEY_PRESS_DEFAULT;

string filePath[MAX_IMAGE_COUNT] = {
	"Hi.bmp",
	"UP.bmp",
	"Down.bmp",
	"Right.bmp",
	"Left.bmp",
};
int main(int argc, char* args[]) {
	if (!Init()) {
		cout << "Failed to initialized!" << endl;
		return 0;
	}

	for (int i = 0; i < MAX_IMAGE_COUNT; ++i) {
		surfaces[i] = LoadSurface("./Media/" + filePath[i]);
	}

	bool quit = false; // ���α׷� ������½� true�� �ٲ�� ����
	SDL_Event sdlEvent;
	SDL_Surface* currentSurface = surfaces[(int)KEY_PRESS_DEFAULT];
	while (!quit) {
		while (SDL_PollEvent(&sdlEvent) != 0) {
			if (sdlEvent.type == SDL_QUIT)
				quit = true;
			else if (sdlEvent.type == SDL_KEYDOWN) {
				switch (sdlEvent.key.keysym.sym) {
				case SDLK_UP:
					currentSurface = surfaces[(int)KEY_PRESS_UP];
					break;
				case SDLK_DOWN:
					currentSurface = surfaces[(int)KEY_PRESS_DOWN];
					break;
				case SDLK_LEFT:
					currentSurface = surfaces[(int)KEY_PRESS_LEFT];
					break;
				case SDLK_RIGHT:
					currentSurface = surfaces[(int)KEY_PRESS_RIGHT];
					break;
				default:
					currentSurface = surfaces[(int)KEY_PRESS_DEFAULT];
					break;
				}
			}
			else if (sdlEvent.type == SDL_KEYUP)
				currentSurface = surfaces[KEY_PRESS_DEFAULT];

		}

		//������� surface ä���
		SDL_FillRect(gscreenSurface, NULL, SDL_MapRGB(gscreenSurface->format, 0xFF, 0x88, 0x88));
		if (currentSurface != NULL)
			SDL_BlitSurface(currentSurface, NULL, gscreenSurface, NULL);
		//surface ������Ʈ
		SDL_UpdateWindowSurface(gwindow);
	}
	Close();
	return 0;
}

bool Init() {
	bool success = true;
	//SDL �ʱ�ȭ
	if (SDL_Init(SDL_INIT_EVERYTHING) < 0) {           // SDL �ʱ�ȭ ���н�
		printf("SDL could not initialize! SDL_Error: %s\n", SDL_GetError());
		success = false;
	}
	else {                                              // �ʱ�ȭ����
  //������ ����
		gwindow = SDL_CreateWindow(
			"SDL Tutorial",      // Ÿ��Ʋ
			SDL_WINDOWPOS_UNDEFINED, // x��ǥ
			SDL_WINDOWPOS_UNDEFINED, // y��ǥ
			SCREEN_WIDTH,            // ȭ��ʺ�
			SCREEN_HEIGHT,            // ȭ�����
			SDL_WINDOW_SHOWN         // â���̱�
		);
		if (gwindow == NULL) {
			printf("Window could not be created! SDL_Error: %s\n", SDL_GetError());
			success = false;
		}
		else {
			//Get window surface
			gscreenSurface = SDL_GetWindowSurface(gwindow);
		}
	}
	return success;
}

SDL_Surface* LoadSurface(string filePath) {

	SDL_Surface* surface = NULL;                         // �ε带 �ؼ� �ٷ� ���� Surface*
	SDL_Surface* optimizedSurface = NULL;                  // Screen�� ���� �������� ��ȯ�� Surfcae
	surface = SDL_LoadBMP(filePath.c_str());              // surface�� �ε�

	if (surface == NULL)
		cout << "Unable to load image " << filePath.c_str() << "SDL_Error : " << SDL_GetError() << endl;
	else {                                              // ��ũ�� Surfcae�� �������� ��ȯ surface�� ���̻� �ʿ� ����.
		optimizedSurface = SDL_ConvertSurface(surface, gscreenSurface->format, NULL);
		if (optimizedSurface == NULL) // ��ȯ����
			cout << "Unable to optimize image " << filePath.c_str() << "SDL_Error : " << SDL_GetError() << endl;
		SDL_FreeSurface(surface);                     // �ʿ���� surface*�� ���� 
	}
	return optimizedSurface;
}

void Close() {

	for (int i = 0; i < MAX_IMAGE_COUNT; ++i)
		SDL_FreeSurface(surfaces[i]);
	//â �ı�
	SDL_DestroyWindow(gwindow);
	//SDL �����ý��� ������
	SDL_Quit();
	return;
}

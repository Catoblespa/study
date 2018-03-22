//SDL�� ǥ������� ����
#include "include\SDL.h"
#include <stdio.h>

//ȭ��ũ��
const int SCREEN_WIDTH = 640;
const int SCREEN_HEIGHT = 480;

int main(int argc, char* args[]) {
	// ������ �� â (window)
	SDL_Window* window = NULL;

	//window�� ���Խ�ų ǥ��(surface)
	SDL_Surface* screenSurface = NULL;

	//SDL �ʱ�ȭ
	if (SDL_Init(SDL_INIT_VIDEO) < 0)
		printf("SDL could not initialize! SDL_Error: %s\n", SDL_GetError());
	else {
		//������ ����
		window = SDL_CreateWindow(
			"SDL Tutorial",      // Ÿ��Ʋ
			SDL_WINDOWPOS_UNDEFINED, // x��ǥ
			SDL_WINDOWPOS_UNDEFINED, // y��ǥ
			SCREEN_WIDTH,            // ȭ��ʺ�
			SCREEN_HEIGHT,            // ȭ�����
			SDL_WINDOW_SHOWN         // â���̱�
		);
		if (window == NULL) 
			printf("Window could not be created! SDL_Error: %s\n", SDL_GetError());
		else {
			//Get window surface
			screenSurface = SDL_GetWindowSurface(window);

			//������� surface ä���
			SDL_FillRect(screenSurface, NULL, SDL_MapRGB(screenSurface->format, 0xFF, 0xFF, 0xFF));

			//surface ������Ʈ
			SDL_UpdateWindowSurface(window);

			//2�� wait
			SDL_Delay(2000);
		}
	}
	
	//â �ı�
	SDL_DestroyWindow(window);

	//SDL �����ý��� ������
	SDL_Quit();

	return 0;
}
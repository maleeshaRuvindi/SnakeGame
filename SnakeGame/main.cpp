#include <iostream>
int width, height;
bool GameOver;
void Setup() {
	width = 20;
	height = 20;
	GameOver = false;
}
void Draw() {
	system("cls");
	for (int i = 0; i < height; i++) {
		for (int j = 0; j < width; j++) {
			if (i == 0) {
				std::cout << "#";
			}
			else if (j == 0) {
				std::cout << "#";
			}
			else if (j == width - 1) {
				std::cout << "#";
			}
			else if (i == height - 1) {
				std::cout << "#";
			}
			else {
				std::cout << " ";
			}
		}
		std::cout << std::endl;
	}
}
int main() {
	Setup();
	while (!GameOver) {
		Draw();
	}


}
#pragma once

extern HomeBrew::Application* HomeBrew::CreateApplication();

int main(int argc, char** argv) {
	auto app = HomeBrew::CreateApplication();
	app->Run();
	delete app;
}

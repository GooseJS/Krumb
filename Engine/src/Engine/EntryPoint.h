#pragma once

#include "Application.h"

extern KrumbEngine::Application* KrumbEngine::createApplication();

int main(int argc, char** argv)
{
	// TODO: Initialize Logger
	auto app = KrumbEngine::createApplication();
	app->run();
	delete app;
}
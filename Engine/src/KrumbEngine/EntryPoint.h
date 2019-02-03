#pragma once

#include "KrumbEngine/Core.h"
#include "KrumbEngine/Application.h"

extern KrumbEngine::Application* KrumbEngine::createApplication();

int main(int argc, char** argv)
{
	KrumbEngine::Logger::init();
	KRUMB_CORE_INFO("Initialized logger.");

	KRUMB_CORE_INFO("Creating application.");
	auto app = KrumbEngine::createApplication();
	app->run();
	delete app;
}
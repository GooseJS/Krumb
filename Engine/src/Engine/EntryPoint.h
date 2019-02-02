#pragma once

#include "Logger.h"
#include "Application.h"

extern KrumbEngine::Application* KrumbEngine::createApplication();

int main(int argc, char** argv)
{
	KrumbEngine::Logger::init();
	KMB_CORE_INFO("Initialized logger.");

	KMB_CORE_INFO("Creating application.");
	auto app = KrumbEngine::createApplication();
	app->run();
	delete app;
}
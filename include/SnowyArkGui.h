#pragma once
#include<iostream>
#include"../ImGui/imgui.h"

extern ImVec4 triangleColor;
extern ImVec4 backgroundColor;

void ShowSnowyArkWindow(bool* p_open);

static void ShowSnowyArkMainMenuBar();
static void ShowSnowyArkHelpWindow(bool* p_open);
static void ShowSnowyArkOverlay(bool* p_open);
static void ShowSnowyArkSetTestColorDemo(bool* p_open);
static void ShowSnowyArkSetFontStyleDemo(bool* p_open);

static void ShowSnowyArkStyleEditor(ImGuiStyle* ref = NULL);